//
//  enemy.cpp
//  Overworld
//
//  Created by Brendan Coppinger on 12/23/17.
//  Copyright © 2017 Brendan Coppinger. All rights reserved.
//

#include "enemy.hpp"

enemy::enemy(float height, float width){
    //General Constants
    screenwidth = width;
    screenheight = height;
    charscale = 4;
    
    //Initial position
    x=screenwidth*.75;
    y=50;
    
    //Draw and Position Character
    if (!chartexture.loadFromFile(resourcePath() + "PlayerStandIn.png")) {
        return EXIT_FAILURE;
    }
    charsprite.setTexture(chartexture);
    charsprite.setPosition(x, y);
    charsprite.scale(charscale, charscale);
}
