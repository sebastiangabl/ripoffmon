/*
 * Player.h
 *
 *  Created on: 03. Feb. 2016
 *      Author: Sebastian
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Entity.h"

class Player: public Entity {
  public:
    Player(int = 0, int = 0);

    void performActions(LevelData*);

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif /* PLAYER_H_ */
