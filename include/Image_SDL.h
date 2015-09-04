#ifndef IMAGE_SDL_H
#define IMAGE_SDL_H

#include "Asset.h"
#include <string>
#include <SDL.h>


class Image_SDL : public Image
{
public:
    Image_SDL( std::string path, std::string name, SDL_Surface* screen );
    virtual ~Image_SDL();
    std::string getName();
    std::string getPath();
    SDL_Surface* get();
    bool init();
    bool draw();
    bool draw( SDL_Rect* section, SDL_Rect* target );

private:
    enum ImageType { BITMAP };
    ImageType type = BITMAP;
    std::string path = "";
    std::string name = "";
    bool initialized = false;

    SDL_Surface* thisImage = nullptr;
    SDL_Surface* screen = nullptr;
};

#endif // IMAGE_SDL_H
