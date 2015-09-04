#ifndef TRONINIT_H
#define TRONINIT_H

#include "Asset.h"
#include <map>

using namespace std;

class TronInit
{
    public:
        const static size_t assetGridWidth = 1;
        const static size_t assetGridHeight = 2;
        static void initAssetMap( map<string, Asset*>* );
};

#endif // TRONINIT_H
