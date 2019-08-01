//
//  player.cpp
//  Overworld
//
//  Created by Brendan Coppinger on 12/24/16.
//  Copyright © 2016 Brendan Coppinger. All rights reserved.
//

#include "player.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

player::player(int width, int height, int x_, int y_) {
    //Pass in some global variables
    //I may or may not use these, but its good to have access to all these globals
    screenwidth = width;
    screenheight = height;
    
    //Deal with the positioning of the main character
    //This is the positioning that will change whenever the sprite moves;
    xoffset = 0;
    yoffset = -32;
    float charscale = 4;
    x=x_*64 + xoffset;
    y=y_*64 + yoffset;
    
    //Load the texture and main character sprite from file
    //if (!chartexture.loadFromFile(resourcePath() + "PlayerStandIn.png")) {
    //    return EXIT_FAILURE;
    //}
	chartexture.loadFromFile(resourcePath() + "PlayerStandIn.png");
    charsprite.setTexture(chartexture);
    charsprite.setPosition(x, y);
    charsprite.scale(charscale, charscale);
    //Check main.cpp : the float in the following line should match the global const SCALE
    charsprite.scale(1, 1);
    
    //Load the texture and head sprite from file for talking.
    //TODO: headscale will eventually be replaced with better sprites
    //TODO: Create texture/load texture for headsprite
    float headscale = 2;
    headsprite.setTexture(chartexture);
    headsprite.setPosition(headscale*xoffset,screenheight-(2*64));
    headsprite.scale(headscale*charscale, headscale*charscale);
    
    ready=false;
};

sf::Sprite player::getcharsprite(){
    return charsprite;
}

sf::Sprite* player::getheadsprite(){
    return &headsprite;
}

sf::Vector2f player::getposition(){
    sf::Vector2f pos(x-xoffset, y-yoffset);
    return pos;
}

std::string player::gettext(){
    return "Here is some text";
}

void player::enterFight(){
    ready = true;
}

void player::exitFight(){
    ready = false;
}

bool player::isReady(){
    return ready;
}

void player::move(float xchange, float ychange){
    //Generate newx and newy
    int newx=x+xchange*64;
    int newy=y+ychange*64;
    
    //Make sure that newx and newy are on the screen
    //TODO: make space for warps that can be off the screen
    if (newx>=screenwidth + xoffset)
        newx=screenwidth + xoffset - 64;
    else if (newx<xoffset)
        newx=xoffset;
    if (newy>=screenheight + yoffset)
        newy=screenheight + yoffset - 64;
    else if (newy<yoffset)
        newy=yoffset;
    
    charsprite.setPosition(newx, newy);
    x=newx;
    y=newy;
    direction.x = xchange;
    direction.y = ychange;
};

void player::moveto(sf::Vector2f coord){
    x=(coord.x * 64) + xoffset;
    y=(coord.y * 64) + yoffset;
    charsprite.setPosition(x, y);
};

void player::draw(sf::RenderWindow & window){
    window.draw(charsprite);
};
