package com.kugemi.poemwriter.infrastructure.di

import android.app.Application
import androidx.room.Room
import com.kugemi.poemwriter.infrastructure.clients.ServerClient
import com.kugemi.poemwriter.infrastructure.clients.interfaces.IServerClient
import com.kugemi.poemwriter.infrastructure.database.PoemDatabase
import com.kugemi.poemwriter.repositories.LocalPoemRepository
import com.kugemi.poemwriter.repositories.RemoteRhymeRepository
import com.kugemi.poemwriter.repositories.interfaces.IPoemRepository
import com.kugemi.poemwriter.repositories.interfaces.IRhymeRepository
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.android.components.ApplicationComponent
import javax.inject.Singleton

@Module
@InstallIn(ApplicationComponent::class)
class ApplicationModule {

    @Provides
    @Singleton
    fun provideServerClient() : IServerClient {
        return ServerClient()
    }

    @Provides
    fun provideRhymesRepo(serverClient: IServerClient) : IRhymeRepository {
        return RemoteRhymeRepository(serverClient)
    }

    @Provides
    fun providePoemRepo(database: PoemDatabase) : IPoemRepository {
        return LocalPoemRepository(database)
    }

    @Provides
    fun provideRoom(application: Application) : PoemDatabase {
        return Room.databaseBuilder(
            application, PoemDatabase::class.java,
            "PoemDataBase")
            .fallbackToDestructiveMigration()
            .build()
    }
}