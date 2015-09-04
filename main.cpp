#include <iostream>
#include "Grid.h"
////#include "Player.h"
#include "TronAssets.h"


int main( int argc, char *argv[] )
{
    Grid<int> g( 111, 111, 0 );
    Grid<int> g2(3,3);
    g2(1,1) = 3;
    TronAssets* assets = new TronAssets();
    //assetData.get("name");//Map

//    Player peter( Player::Position, Player::Color, Player::Commands );
//    cout << g2(1,1) << endl;
    return 0;
}

