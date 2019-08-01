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
    x=int(floor(screenwidth*.75));
    y=50;
    
	//Set up initial enemy aiming position
	aimx = 0;
	aimy = 0;
	grounded = 0;
	slashing = 0;
	slashtime = 0;
	slow = 0;
	
	//Set up intitial Position and Velocity
	xArmAngleOffset = 0;
	xArmOffset = 0;
	xdirection = 0;
	xvelocity = 0;

	yArmAngleOffset = 0;
	yArmOffset = 0;
	yvelocity = 0;


    //Draw and Position Character
    //if (!chartexture.loadFromFile(resourcePath() + "PlayerStandIn.png")) {
    //    return EXIT_FAILURE;
    //}
	chartexture.loadFromFile(resourcePath() + "PlayerStandIn.png");
    charsprite.setTexture(chartexture);
    charsprite.setPosition(x, y);
    charsprite.scale(charscale, charscale);
}
