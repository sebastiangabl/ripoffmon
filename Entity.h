/*
 * Entity.h
 *
 *  Created on: 03. Feb. 2016
 *      Author: Sebastian
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <queue>
#include <utility>
#include "defines.h"
#include "LevelData.h"
#include <SFML/Graphics/Drawable.hpp>

using std::queue;
using std::pair;

typedef pair<int, float> ActionPair;

class Entity: public sf::Drawable {
  public:
    enum Direction {
      RIGHT, UP, LEFT, DOWN
    };
    enum Action {
      LOOK_RIGHT, LOOK_UP, LOOK_LEFT, LOOK_DOWN,
      MOVE_RIGHT, MOVE_UP, MOVE_LEFT, MOVE_DOWN,
      JUMP_RIGHT, JUMP_UP, JUMP_LEFT, JUMP_DOWN,
      WAIT,
      HIDE,
      SHOW
    };
    enum Behaviour {
      NONE, LOOK_RANDOM
    };
    int prev_x, prev_y, x, y;
    queue<ActionPair> action_queue;
    float action_step;
    Direction facing;
    Behaviour behaviour;
    byte floor;
    byte movement;
    bool blocking;
    bool visible;

    Entity(int = 0, int = 0);
    virtual ~Entity();
    void update(float, LevelData*);
    void updateFloor(LevelData*);
    void setPosition(int, int);
    void move(int, int);
    bool canMove(int, int, LevelData*);

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif /* ENTITY_H_ */
