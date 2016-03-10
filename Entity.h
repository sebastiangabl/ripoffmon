/*
 * Entity.h
 *
 *  Created on: 03. Feb. 2016
 *      Author: Sebastian
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Config.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <queue>
#include <utility>

class LevelData;

using std::queue;
using std::pair;
using sf::Uint8;
using sf::Uint16;

typedef pair<int, float> ActionPair;

class Entity: public sf::Drawable {
  public:
    static bool compare(Entity*, Entity*);

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

    short prev_x, prev_y, x, y;
    queue<ActionPair> action_queue;
    float action_step;
    Direction facing;
    Behaviour behaviour;
    Uint8 on_floor;
    Uint8 movement;
    bool visible;
    Uint16 flag;

    Entity(short = 0, short = 0, Uint16 = 0);
    virtual ~Entity();

    void update(float, LevelData*);
    virtual void performActions(LevelData*);

    void updateFloor(LevelData*);

    void setPosition(int, int);
    void move(int, int);
    bool canMove(int, int, LevelData*);

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif /* ENTITY_H_ */
