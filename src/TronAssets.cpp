#include "TronAssets.h"

TronAssets::TronAssets()
{
    TronInit::initAssetMap( &assetMap );
}

TronAssets::~TronAssets()
{
    //dtor
}
