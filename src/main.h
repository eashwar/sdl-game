#pragma once
#ifndef MAIN_H
#define MAIN_H

#include <string>

const int kScreenWidth = 320;
const int kScreenHeight = 240;

enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

bool Init( SDL_Window* &window, SDL_Surface* &window_surface );
bool LoadImages( SDL_Surface* image_surfaces[], std::string images[], int size );
void CleanupAndQuit( SDL_Window* &window, SDL_Surface* image_surfaces[], int size );

int main( int argc, char* argv[] );

#endif