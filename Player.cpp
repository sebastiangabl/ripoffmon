/*
 * Player.cpp
 *
 *  Created on: 03. Feb. 2016
 *      Author: Sebastian
 */

#include "Player.h"
#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

Player::Player(int xx, int yy) : Entity(1, xx, yy) {

}

void Player::actions(LevelData* data, bool up, bool left, bool down, bool right, bool run) {
  if (!action_queue.empty()) {
    return;
  }

  if (movement == LevelData::LEDGE_R) {
    action_queue.push(ActionPair(JUMP_RIGHT, 1));
  } else if (movement == LevelData::LEDGE_T) {
    action_queue.push(ActionPair(JUMP_UP, 1));
  } else if (movement == LevelData::LEDGE_L) {
    action_queue.push(ActionPair(JUMP_LEFT, 1));
  } else if (movement == LevelData::LEDGE_B) {
    action_queue.push(ActionPair(JUMP_DOWN, 1));
  } else if (up) {
    if (canMove(0, -1, data) && facing == UP) {
      action_queue.push(ActionPair(MOVE_UP, 1.5 + 1.5 * run));
    } else {
      action_queue.push(ActionPair(LOOK_UP, 4));
    }
  } else if (left) {
    if (canMove(-1, 0, data) && facing == LEFT) {
      action_queue.push(ActionPair(MOVE_LEFT, 1.5 + 1.5 * run));
    } else {
      action_queue.push(ActionPair(LOOK_LEFT, 4));
    }
  } else if (down) {
    if (canMove(0, 1, data) && facing == DOWN) {
      action_queue.push(ActionPair(MOVE_DOWN, 1.5 + 1.5 * run));
    } else {
      action_queue.push(ActionPair(LOOK_DOWN, 4));
    }
  } else if (right) {
    if (canMove(1, 0, data) && facing == RIGHT) {
      action_queue.push(ActionPair(MOVE_RIGHT, 1.5 + 1.5 * run));
    } else {
      action_queue.push(ActionPair(LOOK_RIGHT, 4));
    }
  }
}

void Player::draw(sf::RenderTarget& rt, sf::RenderStates rs) const {
  short off = 0;
  if (!action_queue.empty()) {
    ActionPair ap = action_queue.front();
    if (ap.first == JUMP_DOWN || ap.first == JUMP_LEFT || ap.first == JUMP_RIGHT || ap.first == JUMP_UP) {
      off = -12 * (1 - abs((action_step - 0.5) * 2));
    }
  }

  CircleShape cshp(12, 12);
  cshp.setOrigin(12, 12);
  cshp.setScale(1, 0.5);
  cshp.setPosition((prev_x * (1 - action_step) + x * action_step) * 24 + 12,
      (prev_y * (1 - action_step) + y * action_step) * 24 + 12 + 6);
  cshp.setFillColor(Color(0, 0, 0, 100));
  rt.draw(cshp, rs);

  RectangleShape shp(Vector2f(24, 40));
  shp.setOrigin(12, 28);
  shp.setPosition((prev_x * (1 - action_step) + x * action_step) * 24 + 12,
      (prev_y * (1 - action_step) + y * action_step) * 24 + 12 + off);
  shp.setFillColor(Color(on_floor * 100, 0, 255));
  rt.draw(shp, rs);

  cshp.setRadius(8);
  cshp.setPointCount(3);
  cshp.setOrigin(8, 8);
  cshp.setScale(1, 1);
  cshp.setRotation(90 - facing * 90);
  cshp.setPosition((prev_x * (1 - action_step) + x * action_step) * 24 + 12,
      (prev_y * (1 - action_step) + y * action_step) * 24 + 12 + off);
  cshp.setFillColor(Color(0, 0, 0, 100));
  rt.draw(cshp, rs);
}
