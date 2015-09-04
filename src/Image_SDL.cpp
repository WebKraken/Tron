#include "Image_SDL.h"
#include <stdio.h>
#include <iostream>



Image_SDL::Image_SDL( std::string path, std::string name, SDL_Surface* screen ) : path( path ), name( name ), screen( screen )
{
}

Image_SDL::~Image_SDL()
{
    SDL_FreeSurface( thisImage );
}

std::string Image_SDL::getName(){ return name; }
std::string Image_SDL::getPath(){ return path; }

bool Image_SDL::init()
{
    if( screen == NULL )
    {
        printf( "This image's target screen is not set ( use it as parameter in this constructor )." );
        return initialized = false;
    }
    else if( path.empty() )
    {
        printf( "This image's path is not set ( use setPath() )." );
        return initialized = false;
    }
    else if( name.empty() )
    {
        printf( "This image's name is not set ( use setName() )." );
        return initialized = false;
    }

    thisImage = SDL_LoadBMP( path.c_str() );
    if( !thisImage )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", name.c_str(), SDL_GetError() );
        return initialized = false;
    }
    return initialized = true;
}

bool Image_SDL::draw()
{
    return draw( nullptr, nullptr );
}

bool Image_SDL::draw( SDL_Rect* section, SDL_Rect* target )
{
    if ( initialized )
    {
        SDL_BlitSurface( thisImage, section, screen, target );
        return true;
    }
    else
    {
        printf( "The image %s is not yet initialized!", name.c_str() );
        return false;
    }
}

SDL_Surface* Image_SDL::get()
{
    if ( initialized )
    {
        return thisImage;
    }
    else
    {
        printf( "Unable to get() image %s! Image not initialized.", name.c_str() );
        return NULL;
    }
}

