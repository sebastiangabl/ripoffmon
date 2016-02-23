/*
 * main.cpp
 *
 *  Created on: 02. Jän. 2016
 *      Author: Sebastian
 */

#include "LevelManager.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main() {
  Level* level = LevelManager::getCurrentLevel();

  Player p(level->data->width / 2, level->data->height / 2);
  p.floor = level->data->floors[p.x][p.y];

  float delta = 0;
  Clock delta_clock;

  RenderWindow win(VideoMode(1280, 720), "Ripoffmon", Style::Titlebar | Style::Close);
  win.setFramerateLimit(0);
  win.setVerticalSyncEnabled(true);
  View view(sf::Vector2f(p.x * 24, p.y * 24), sf::Vector2f(640, 360));
  RenderTexture render_target;
  render_target.create(view.getSize().x, view.getSize().y);
  Sprite render_sprite(render_target.getTexture());
  render_sprite.setScale(float(win.getSize().x) / float(render_target.getSize().x),
      float(win.getSize().y) / float(render_target.getSize().y));

  Texture tex_debug;
  tex_debug.loadFromFile("tilesets/debug.png");

  while (win.isOpen()) {
    Event e;
    while (win.pollEvent(e)) {
      if (e.type == sf::Event::Closed) {
        win.close();
      }
    }
    delta = delta_clock.restart().asSeconds();

    p.movement(level->data, Keyboard::isKeyPressed(Keyboard::Up), Keyboard::isKeyPressed(Keyboard::Left),
        Keyboard::isKeyPressed(Keyboard::Down), Keyboard::isKeyPressed(Keyboard::Right),
        Keyboard::isKeyPressed(Keyboard::LShift));
    p.update(delta, level->data);

    if (p.y < 0 && level->neighbour[Neighbour::TOP].id != 0) {
      Level* nlev = LevelManager::changeLevel(level->neighbour[Neighbour::TOP].id);
      p.move(-level->neighbour[Neighbour::TOP].offset, nlev->data->height);
      p.floor = nlev->data->floors[p.x][p.y];
      level = nlev;
    } else if (p.y > level->data->height - 1 && level->neighbour[Neighbour::BOTTOM].id != 0) {
      Level* nlev = LevelManager::changeLevel(level->neighbour[Neighbour::BOTTOM].id);
      p.move(-level->neighbour[Neighbour::BOTTOM].offset, -level->data->height);
      p.floor = nlev->data->floors[p.x][p.y];
      level = nlev;
    } else if (p.x < 0 && level->neighbour[Neighbour::LEFT].id != 0) {
      Level* nlev = LevelManager::changeLevel(level->neighbour[Neighbour::LEFT].id);
      p.move(nlev->data->width, -level->neighbour[Neighbour::LEFT].offset);
      p.floor = nlev->data->floors[p.x][p.y];
      level = nlev;
    } else if (p.x > level->data->width - 1 && level->neighbour[Neighbour::RIGHT].id != 0) {
      Level* nlev = LevelManager::changeLevel(level->neighbour[Neighbour::RIGHT].id);
      p.move(-level->data->width, -level->neighbour[Neighbour::RIGHT].offset);
      p.floor = nlev->data->floors[p.x][p.y];
      level = nlev;
    }

    view.setCenter((p.prev_x * (1 - p.action_step) + p.x * p.action_step) * 24,
        (p.prev_y * (1 - p.action_step) + p.y * p.action_step) * 24);
    render_target.setView(view);

    render_target.clear(Color::Black);
    render_target.draw(*level, &tex_debug);
    render_target.draw(p);
    render_target.display();

    win.draw(render_sprite);
    win.display();
  }
  LevelManager::free();
  return 0;
}

