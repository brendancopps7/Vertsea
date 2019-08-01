//
//  player.hpp
//  Overworld
//
//  Created by Brendan Coppinger on 12/24/16.
//  Copyright © 2016 Brendan Coppinger. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "textbox.hpp"


class player {
    
private:
    int screenwidth;
    int screenheight;
    float x;
    float y;
    float xoffset;
    float yoffset;
    bool ready;
    sf::Vector2f direction;
    sf::Sprite charsprite;
    sf::Sprite headsprite;
    sf::Texture chartexture;
    
public:
	player(int width, int height, int x_, int y_);
    sf::Sprite getcharsprite();
    sf::Sprite* getheadsprite();
    sf::Vector2f getposition();
    std::string gettext();
    void enterFight();
    void exitFight();
    bool isReady();
    void move(float xchange, float ychange);
    void moveto(sf::Vector2f coord);
    void draw(sf::RenderWindow & window);
    
    
    
};

#endif /* player_hpp */
