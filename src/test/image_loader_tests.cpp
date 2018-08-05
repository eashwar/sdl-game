#include "catch.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "resource_loader/image_loader.h"

TEST_CASE( "LoadImageToSurface throws ImageLoadException for null surface_format", "[image_loader]" )
{
	ImageLoader image_loader;
	REQUIRE_THROWS_AS(image_loader.LoadImageToSurface("res/hello.png"), ImageLoadException);	
}

TEST_CASE( "LoadImageToTexture throws ImageLoadException for null renderer", "[image_loader]" )
{
	ImageLoader image_loader;
	SDL_Renderer* renderer;
	REQUIRE_THROWS_AS(image_loader.LoadImageToTexture("res/hello.png", renderer), ImageLoadException);
}
