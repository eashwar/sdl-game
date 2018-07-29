#pragma once
#ifndef MAIN_H
#define MAIN_H

#include <string>

const int kScreenWidth = 320;
const int kScreenHeight = 240;

bool Init( SDL_Window* &window, SDL_Surface* &window_surface );
bool LoadImage( SDL_Surface* &image_surface, std::string &image );
void CleanupAndQuit( SDL_Window* &window, SDL_Surface* &image_surface );

int main( int argc, char* argv[] );

#endif