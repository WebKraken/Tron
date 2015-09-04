#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    struct Direction
    {
        int dx = 0;
        int dy = 0;
    };

    class Color {};

    struct Commands
    {
        int up_command = 0;
        int down_command = 0;
        int right_command = 0;
        int left_command = 0;
    };

    struct Position
    {
        int x = 0;
        int y = 0;
    };

    Player( Position, Color, Commands );
    virtual ~Player();

private:
    Direction dir;
    Position pos;

    Color color;
    Commands commands;
};

#endif // PLAYER_H
