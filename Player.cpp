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

Player::Player(int xx, int yy) : Entity(xx, yy) {

}

void Player::movement(LevelData* data, bool up, bool left, bool down, bool right, bool run) {
  if (!action_queue.empty()) {
    return;
  }
  if (up) {
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
  RectangleShape shp(Vector2f(24, 40));
  shp.setOrigin(12, 28);
  shp.setPosition((prev_x * (1 - action_step) + x * action_step) * 24 + 12,
      (prev_y * (1 - action_step) + y * action_step) * 24 + 12);
  shp.setFillColor(Color(floor * 100, 0, 255));
  rt.draw(shp, rs);

  CircleShape cshp(8, 3);
  cshp.setOrigin(8, 8);
  cshp.setRotation(90 - facing * 90);
  cshp.setPosition((prev_x * (1 - action_step) + x * action_step) * 24 + 12,
      (prev_y * (1 - action_step) + y * action_step) * 24 + 12);
  cshp.setFillColor(Color(0, 0, 0, 100));
  rt.draw(cshp, rs);
}
