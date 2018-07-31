#include <stdio.h>

#include "image_loader.h"

ImageLoader::ImageLoader() : surface_format(NULL)
{
    int img_flags = IMG_INIT_PNG;
    if ( !( IMG_Init(img_flags) & img_flags))
    {
        printf("SDL Image did not initialize. SDL ERROR: %s\n", IMG_GetError());
    }
}

ImageLoader::ImageLoader(SDL_PixelFormat* _surface_format) : surface_format(_surface_format)
{
    int img_flags = IMG_INIT_PNG;
    if ( !( IMG_Init(img_flags) & img_flags))
    {
        printf("SDL Image did not initialize. SDL ERROR: %s\n", IMG_GetError());
    }
}

ImageLoader::~ImageLoader()
{
    IMG_Quit();
}

SDL_Surface* ImageLoader::LoadImageToSurface(std::string filename)
{
    if (!surface_format)
    {
        throw ImageLoadException ("surface_format is null. check the ImageLoader constructor\n");
    }
    SDL_Surface* loaded_surface = IMG_Load(filename.c_str());
    if ( !loaded_surface )
    {
        throw ImageLoadException( "Unable to load image " + filename + ". SDL ERROR: " + IMG_GetError() + "\n" );
    }
    SDL_Surface* optimized_surface = SDL_ConvertSurface( loaded_surface, surface_format, 0);
    SDL_FreeSurface(loaded_surface);
    if (!optimized_surface)
    {
        throw ImageLoadException( "Unable to optimize image " + filename + ". SDL ERROR: " + SDL_GetError() + "\n" );
    }
    return optimized_surface;
    
}
SDL_Texture* ImageLoader::LoadImageToTexture(std::string filename, SDL_Renderer* &renderer)
{
    if (!renderer)
    {
        throw ImageLoadException("renderer is null.\n");
    }
    SDL_Surface* loaded_surface = IMG_Load( filename.c_str());
    if ( !loaded_surface )
    {
        throw ImageLoadException( "Unable to load image " + filename + ". SDL ERROR: " + IMG_GetError() + "\n" );
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
    SDL_FreeSurface(loaded_surface);
    if (!texture)
    {
        throw ImageLoadException( "Unable to create texture from image" + filename + ". SDL ERROR: " + IMG_GetError() + "\n" );
    }
    return texture;
}

