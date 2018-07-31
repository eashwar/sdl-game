#pragma once
#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class ImageLoader
{
    private:
        // format to optimize surfaces to
        SDL_PixelFormat* surface_format;
    
    public:
        // If using textures, no need to set format
        ImageLoader();

        // If using surfaces, keep format
        ImageLoader(SDL_PixelFormat* _surface_format);

        ~ImageLoader();

        // loads the image specified by `filename` to a surface
        // Throws ImageLoadException if surface_format is NULL NULL, this will ret
        // or if there are issues.
        SDL_Surface* LoadImageToSurface(std::string filename);

        // loads the image specified by `filename` to a texture
        // using the renderer provided. Throws ImageLoadException
        // if renderer is NULL or if there are issues.
        SDL_Texture* LoadImageToTexture(std::string filename, SDL_Renderer* &renderer);
};

class ImageLoadException
{
    private:
        std::string error;
    public:
        ImageLoadException(std::string _error) : error(_error) {}
        const char* GetError() { return error.c_str(); }
};

#endif