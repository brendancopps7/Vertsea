//
//  realtimesprite.hpp
//  Overworld
//
//  Created by Brendan Coppinger on 9/14/17.
//  Copyright © 2017 Brendan Coppinger. All rights reserved.
//

#ifndef realtimesprite_hpp
#define realtimesprite_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


class realtimesprite
{
private:
    //General Constants
    float screenwidth;
    float screenheight;
    
    //Specific Values
    int x;
    int y;
    float xvel;
    float yvel;
    sf::Sprite charsprite;
    sf::Texture chartexture;
    bool gravity;
    
public:
    realtimesprite();
    realtimesprite(std::string resourcepath, int x_, int y_, int height, int width);
    void update(float elapsedtime);
    void draw(sf::RenderWindow & window);
    void moveTo(int x_, int y_);
    void moveTo(sf::Vector2i);
};

#endif /* realtimesprite_hpp */
