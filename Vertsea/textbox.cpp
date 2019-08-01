//
//  textbox.cpp
//  Overworld
//
//  Created by Brendan Coppinger on 6/18/17.
//  Copyright © 2017 Brendan Coppinger. All rights reserved.
//

#include "textbox.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

//private:
//    int TILE_WIDTH;
//    int TILE_HEIGHT;
//    int RESOLUTION;
//    sf::Font font;
//    sf::Text text;
//    sf::Vector2f size;
//    sf::RectangleShape background;
//    sf::Sprite *CurrentHeadSprite;
    
textbox::textbox(int tilewidth, int tileheight, int resolution){
    TILE_WIDTH = tilewidth;
    TILE_HEIGHT = tileheight;
    RESOLUTION = resolution;
    background.setFillColor(sf::Color::Black);
    size.x = float(TILE_WIDTH*RESOLUTION);
    size.y = float(2*RESOLUTION);
    background.setSize(size);
    background.setPosition(0, float((TILE_HEIGHT - 2)*RESOLUTION));
	visible = false;

	//CurrentHeadSprite.setTexture(NULL);

	font.loadFromFile(resourcePath() + "sansation.ttf");
    text.setString("Haven't put in doors yet, give me a minute");
    text.setFont(font);
    text.setCharacterSize(RESOLUTION/2);
    text.setFillColor(sf::Color::White);
    text.setPosition(float(2*RESOLUTION), float((TILE_HEIGHT - 2)*RESOLUTION));
    text.setStyle(sf::Text::Regular);
    
    }
    
/*
void textbox::setHeadSprite(sf::Sprite *headsprite){
    CurrentHeadSprite = headsprite;
    return;
    }
*/
void textbox::setText(std::string text_){
    
    }

bool textbox::isVisible()
{
    return visible;
}

std::string textbox::getText(){
	return "Well Fuck Me";
    }

void textbox::draw(sf::RenderWindow & window){
    if(isVisible())
    {
        window.draw(background);
        //window.draw(*CurrentHeadSprite);
        window.draw(text);
    }
}

void textbox::makeVisible(){
    visible = true;
}

void textbox::makeInvisible(){
    visible = false;
}
    
    
    
    
