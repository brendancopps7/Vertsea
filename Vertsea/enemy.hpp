//
//  enemy.hpp
//  Overworld
//
//  Created by Brendan Coppinger on 12/23/17.
//  Copyright © 2017 Brendan Coppinger. All rights reserved.
//

#ifndef enemy_hpp
#define enemy_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "realtimesprite.hpp"
#include "bullet.hpp"

//enum direction {up, down, left, right};

class enemy :public realtimesprite {
    
private:
    //General Constants
    float screenwidth;
    float screenheight;
    
    //Sprites and Textures
    sf::Sprite charsprite;
    sf::Texture chartexture;
    sf::Sprite armsprite;
    sf::Texture armtexture;
    sf::Sprite swordslashsprite;
    sf::Texture swordslashtexture;
    int charscale;
    
    
    //Position and Velocity
    float xvelocity;
    float yvelocity;
    float x;
    float y;
    float xdirection;
    //direction facing;
    
    //Friction and Gravity
    bool grounded;
    bool slow;
    
    //Aim and Arm Position
    float aimx;
    float aimy;
    float xArmOffset;
    float yArmOffset;
    float xArmAngleOffset;
    float yArmAngleOffset;
    
    //Bullets and Sword Children
    std::vector <bullet *> bullets;
    bool slashing;
    int slashtime;
    
    
public:
    //Constructor
    enemy(float height, float width);
    
    //Inspector
    sf::Sprite getcharsprite();
    
    //Mutators
    void setXSpeed(float xdirection);
    void setYSpeed(float ydirection);
    //void setDirection(direction facing_);
    
    void walk(float xdirection);
    
    //Facilitators
    void jump();
    void shoot();
    void slowing();
    void moveto(sf::Vector2f coord);
    void aim(sf::Vector2i direction);
    void slash();
    
};

#endif /* enemy_hpp */
