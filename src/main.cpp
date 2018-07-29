#include <SDL2/SDL.h>
#include <stdio.h>
#include "main.h"

int main( int argc, char* argv[] )
{
    SDL_Window* window = NULL;
    SDL_Surface* window_surface = NULL;

    SDL_Surface* image_surfaces[KEY_PRESS_SURFACE_TOTAL];
    SDL_Surface* current_surface = NULL;

    std::string image_names[KEY_PRESS_SURFACE_TOTAL] =
    {
        "res/hello.bmp",
        "res/up.bmp",
        "res/down.bmp",
        "res/left.bmp",
        "res/right.bmp"
    };

    if ( !Init( window, window_surface ) )
    {
        printf( "Failed to initialize\n" );
        CleanupAndQuit( window, image_surfaces, ( int ) KEY_PRESS_SURFACE_TOTAL );
        return 1;
    }

    if ( !LoadImages( image_surfaces, image_names, ( int ) KEY_PRESS_SURFACE_TOTAL ) )
    {
        printf( "Failed to load images\n" );
        CleanupAndQuit( window, image_surfaces, ( int ) KEY_PRESS_SURFACE_TOTAL );
        return 1;
    }

    bool quit = false;
    SDL_Event e;

    current_surface = image_surfaces[KEY_PRESS_SURFACE_DEFAULT];

    while ( !quit )
    {
        while ( SDL_PollEvent( &e ) != 0 )
        {
            if ( e.type == SDL_QUIT )
            {
                quit = true;
            }
            else if ( e.type == SDL_KEYDOWN )
            {
                switch( e.key.keysym.sym )
                {
                    case SDLK_UP:
                        current_surface = image_surfaces[KEY_PRESS_SURFACE_UP];
                        break;
                    case SDLK_DOWN:
                        current_surface = image_surfaces[KEY_PRESS_SURFACE_DOWN];
                        break;
                    case SDLK_LEFT:
                        current_surface = image_surfaces[KEY_PRESS_SURFACE_LEFT];
                        break;
                    case SDLK_RIGHT:
                        current_surface = image_surfaces[KEY_PRESS_SURFACE_RIGHT];
                        break;
                    case SDLK_ESCAPE:
                        quit = true;
                        break;
                    default:
                        current_surface = image_surfaces[KEY_PRESS_SURFACE_DEFAULT];
                        break;
                }
            }
        }


        SDL_BlitSurface( current_surface, NULL, window_surface, NULL );
        SDL_UpdateWindowSurface( window );
    }

    CleanupAndQuit( window, image_surfaces, ( int ) KEY_PRESS_SURFACE_TOTAL );
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

bool LoadImages( SDL_Surface* image_surfaces[], std::string images[], int size )
{
    for ( int i = 0; i < size; ++i )
    {
        image_surfaces[i] = SDL_LoadBMP( images[i].c_str() );
        if ( !image_surfaces[i] )
        {
            printf( "Unable to load image. SDL ERROR: %s\n", SDL_GetError() );
            return false;
        }
    }
    return true;
}

void CleanupAndQuit( SDL_Window* &window, SDL_Surface* image_surfaces[], int size )
{
    for ( int i = 0; i < size; ++i )
    {
        SDL_FreeSurface( image_surfaces[i] );
        image_surfaces[i] = NULL;
    }

    SDL_DestroyWindow( window );
    window = NULL;

    SDL_Quit();
}

