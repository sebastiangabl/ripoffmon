/*
 * Entity.cpp
 *
 *  Created on: 03. Feb. 2016
 *      Author: Sebastian
 */

#include "Entity.h"

#include "Flags.h"
#include "LevelData.h"

unsigned cl(int a, unsigned b) {
  if (a < 0) {
    return 0;
  } else if (unsigned(a) >= b) {
    return b - 1;
  }
  return a;
}

bool Entity::compare(Entity* first, Entity* second) {
  return (first->y < second->y);
}

Entity::Entity(short xx, short yy, Uint16 spriteid) {
  prev_x = xx;
  prev_y = yy;
  x = xx;
  y = yy;
  action_step = 0;
  facing = DOWN;
  behaviour = NONE;
  on_floor = LevelData::FLOOR1;
  movement = LevelData::FLOOR;
  blocking = true;
  visible = spriteid != 0;
  warp = 0;
  flag = 0;
}

Entity::~Entity() {

}

void Entity::update(float delta, LevelData* data) {
  if (Flags::get(flag)) {
    return;
  }
  if (!action_queue.empty()) {
    ActionPair ap = action_queue.front();

    if (action_step == 0) {
      switch (ap.first) {
        case LOOK_UP:
        facing = UP;
        break;

        case LOOK_LEFT:
        facing = LEFT;
        break;

        case LOOK_DOWN:
        facing = DOWN;
        break;

        case LOOK_RIGHT:
        facing = RIGHT;
        break;

        case MOVE_UP:
        case JUMP_UP:
        facing = UP;
        prev_y = y;
        y -= 1;
        updateFloor(data);
        break;

        case MOVE_LEFT:
        case JUMP_LEFT:
        facing = LEFT;
        prev_x = x;
        x -= 1;
        updateFloor(data);
        break;

        case MOVE_DOWN:
        case JUMP_DOWN:
        facing = DOWN;
        prev_y = y;
        y += 1;
        updateFloor(data);
        break;

        case MOVE_RIGHT:
        case JUMP_RIGHT:
        facing = RIGHT;
        prev_x = x;
        x += 1;
        updateFloor(data);
        break;

        case HIDE:
        visible = false;
        break;

        case SHOW:
        visible = true;
        break;
        default:
        break;
      }
    }
    action_step += delta * ap.second * 2.5;
    if (action_step > 1) {
      action_step = 0;
      action_queue.pop();
      prev_x = x;
      prev_y = y;
    }
  } else {

  }
}

void Entity::updateFloor(LevelData* data) {
  if (!data || x < 0 || unsigned(x) >= data->width || y < 0 || unsigned(y) >= data->height) {
    return;
  } else {
    if (!(data->floors[x][y] & LevelData::SEPERATE)) {
      on_floor = data->floors[x][y];
    }
    movement = data->movement[x][y];
  }
}

void Entity::setPosition(int xx, int yy) {
  prev_x = xx;
  prev_y = yy;
  x = xx;
  y = yy;
}

void Entity::move(int xx, int yy) {
  prev_x += xx;
  prev_y += yy;
  x += xx;
  y += yy;
}

bool Entity::canMove(int xx, int yy, LevelData* data) {
  if (!data) {
    return true;
  }
  Uint8 m = data->movement[cl(x + xx, data->width)][cl(y + yy, data->height)];
  Uint8 f = data->floors[cl(x + xx, data->width)][cl(y + yy, data->height)];
  if (m == LevelData::BLOCKED || ((m == LevelData::SURF || m == LevelData::WATERFALL) && (m != movement))) {
    return false;
  }
  if ((m == LevelData::LEDGE_RIGHT && xx != 1) || (m == LevelData::LEDGE_UP && yy != -1)
      || (m == LevelData::LEDGE_LEFT && xx != -1) || (m == LevelData::LEDGE_DOWN && yy != 1)) {
    return false;
  }
  return (f & on_floor);
}

void Entity::draw(sf::RenderTarget& rt, sf::RenderStates rs) const {
  if (!visible) {
    return;
  }
}
