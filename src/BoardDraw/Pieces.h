#pragma once
#include <SFML\Graphics.hpp>

class Pieces
{

private:

       
public:

    Pieces();
    int Board[8][8] = { -1,-2,-3,-4,-5,-3,-2,-1,
                        -6,-6,-6,-6,-6,-6,-6,-6,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         6, 6, 6, 6, 6, 6, 6, 6,
                         1, 2, 3, 4, 5, 3, 2, 1,};

    
    void LoadPosition();
    void update();
};

