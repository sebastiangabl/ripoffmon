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
  private:
    static Player* instance;
    Player();
    Player(Player&);
  public:
    static Player* get();

    void performActions(LevelData*);

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif /* PLAYER_H_ */
