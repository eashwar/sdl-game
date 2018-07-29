#include <SDL2/SDL.h>
#include <stdio.h>
#include "main.h"

int main( int argc, char* argv[] )
{
    SDL_Window* window = NULL;
    SDL_Surface* window_surface = NULL;
    SDL_Surface* image_surface = NULL;

    std::string image_name( "res/hello.bmp" );

    if ( !Init( window, window_surface ) )
    {
        printf( "Failed to initialize\n" );
    }

    if ( !LoadImage( image_surface, image_name ) )
    {
        printf( "Failed to load image\n" );
    }

    SDL_BlitSurface( image_surface, NULL, window_surface, NULL );
    SDL_UpdateWindowSurface( window );
    SDL_Delay( 6000 );

    CleanupAndQuit( window, image_surface );
    return 0;
}

bool Init( SDL_Window* &window, SDL_Surface*  &window_surface )
{
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL ERROR: %s\n", SDL_GetError() );
        return false;
    }

    window = SDL_CreateWindow( "owo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, kScreenWidth, kScreenHeight, SDL_WINDOW_SHOWN );
    if ( !window )
    {
        printf( "Failure creating window. SDL ERROR: %s\n", SDL_GetError() );
        return false;
    }

    window_surface = SDL_GetWindowSurface( window );
    return true;
}

bool LoadImage( SDL_Surface* &image_surface, std::string &image )
{
    image_surface = SDL_LoadBMP( image.c_str() );
    if ( !image_surface )
    {
        printf( "Unable to load image. SDL ERROR: %s\n", SDL_GetError() );
        return false;
    }
    return true;
}

void CleanupAndQuit( SDL_Window* &window, SDL_Surface* &image_surface )
{
    SDL_FreeSurface( image_surface );
    image_surface = NULL;

    SDL_DestroyWindow( window );
    window = NULL;

    SDL_Quit();
}

