#ifndef TRONASSETS_H
#define TRONASSETS_H

#include "Asset.h"
#include <map>
#include <string>
#include "TronInit.h"


class TronAssets
{
    public:
        TronAssets();
        virtual ~TronAssets();
    private:
        std::map<std::string, Asset*> assetMap;
};

#endif // TRONASSETS_H
