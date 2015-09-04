#include "TronInit.h"
#include "FileReader.h"

#include "Image_SDL.h"
#include <sstream>
#include <iostream>

using namespace std;


void TronInit::initAssetMap( map<string, Asset*>* assetMap )
{
    string imageDirectory = "./assets/images/";
    FileReader fileReader;
    vector<string> content = fileReader.getContent( imageDirectory );
    string ext;
    string body;
    stringstream path;
    Image_SDL* tronImage;
    SDL_Surface* screen;

    for ( string filename : content )
    {
        ext = fileReader.getExt( filename );
        body = fileReader.getBody( filename );
        path.str( "" );
        if ( !body.empty() )
        {
            path << imageDirectory << filename;
            tronImage = new Image_SDL( path.str(), body, screen );
            ( *assetMap )[ body ] = tronImage;
            cout << tronImage->getPath() << endl;
        }
    }
    tronImage->init();

}
