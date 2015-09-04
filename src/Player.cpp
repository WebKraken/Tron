#include "Player.h"

Player::Player( Position pos, Color c, Commands cmd )
        : pos( pos )
        , color( c )
        , commands( cmd ) {}

Player::~Player() {}
