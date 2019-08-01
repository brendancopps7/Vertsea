//
//  realtimesprite.cpp
//  Overworld
//
//  Created by Brendan Coppinger on 9/14/17.
//  Copyright © 2017 Brendan Coppinger. All rights reserved.
//

#include "realtimesprite.hpp"
#include "ResourcePath.hpp"

realtimesprite::realtimesprite(){
    x=0;
    y=0;
    xvel=0;
    yvel=0;
    gravity = 0;
	screenwidth = 600;
	screenheight = 400;

}

realtimesprite::realtimesprite(std::string resourcepath, int x_, int y_, int width, int height){
    screenwidth = width;
    screenheight = height;
    
    x=x_;
    y=y_;
	xvel = 0;
	yvel = 0;
    //if (!chartexture.loadFromFile(resourcePath() + resourcepath)) {
    //    return EXIT_FAILURE;
    //}
	chartexture.loadFromFile(resourcePath() + resourcepath);
    charsprite.setTexture(chartexture);
    charsprite.setPosition(x, y);
    gravity = 1;
    
}

void realtimesprite::update(float elapsedtime){
    if(gravity){
        bool grounded = false;
        if(y>=screenheight*.75)
        {
            grounded = true;
        }
        if(!grounded){
            yvel += .5;
        }
    }
    
    //get x from xvelocity
    x=x+xvel*elapsedtime*60;
    if (x>=screenwidth-64){
        x=screenwidth-64;
        xvel=0;
    }
    else if (x<0){
        x=0;
        xvel=0;
    }
    
    //get y from yvelocity
    y=y+yvel*elapsedtime*60;
    if (y>=screenheight*.75){
        y=screenheight*.75;
        yvel = 0;
    }
    
    
    //update sprite position
    charsprite.setPosition(x, y);
}

void realtimesprite::draw(sf::RenderWindow &window){
    window.draw(charsprite);
}

void realtimesprite::moveTo(int x_, int y_){
    x=x_;
    y=y_;
    charsprite.setPosition(x, y);
}

void realtimesprite::moveTo(sf::Vector2i coord){
    x=coord.x;
    y=coord.y;
    charsprite.setPosition(x, y);
}
