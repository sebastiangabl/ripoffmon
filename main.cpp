/*
 * main.cpp
 *
 *  Created on: 02. Jän. 2016
 *      Author: Sebastian
 */

#include "LevelManager.h"
#include "Player.h"
#include "Scene.h"
#include "MusicLoop.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "utils/File.h"

using namespace std;
using namespace sf;

int main() {
  Level::debug_tiles.loadFromFile("tilesets/debug.png");
  Level::tiles.loadFromFile("tilesets/tiles.png");

  Level* level = LevelManager::getLevel(1);

  Player p(level->data->width / 2, level->data->height / 2);
  p.updateFloor(level->data);

  float delta = 0;
  Clock delta_clock;

  RenderWindow win(VideoMode(1280, 720), "Ripoffmon", Style::Titlebar | Style::Close);
  win.setFramerateLimit(0);
  win.setVerticalSyncEnabled(true);
  Scene scene(640, 360);

  MusicLoop test("music/2.ogg");
  test.play();

  while (win.isOpen()) {
    Event e;
    while (win.pollEvent(e)) {
      if (e.type == sf::Event::Closed) {
        win.close();
      }
    }
    delta = delta_clock.restart().asSeconds();

    p.actions(level->data, Keyboard::isKeyPressed(Keyboard::Up), Keyboard::isKeyPressed(Keyboard::Left),
        Keyboard::isKeyPressed(Keyboard::Down), Keyboard::isKeyPressed(Keyboard::Right),
        Keyboard::isKeyPressed(Keyboard::LShift));
    p.update(delta, level->data);

    if (p.y < 0 && level->neighbour[Level::Neighbour::TOP].id != 0) {
      Level* nlev = LevelManager::changeLevel(level->neighbour[Level::Neighbour::TOP].id);
      p.move(-level->neighbour[Level::Neighbour::TOP].offset, nlev->data->height);
      p.updateFloor(nlev->data);
      level = nlev;
    } else if (p.y > level->data->height - 1 && level->neighbour[Level::Neighbour::BOTTOM].id != 0) {
      Level* nlev = LevelManager::changeLevel(level->neighbour[Level::Neighbour::BOTTOM].id);
      p.move(-level->neighbour[Level::Neighbour::BOTTOM].offset, -level->data->height);
      p.updateFloor(nlev->data);
      level = nlev;
    } else if (p.x < 0 && level->neighbour[Level::Neighbour::LEFT].id != 0) {
      Level* nlev = LevelManager::changeLevel(level->neighbour[Level::Neighbour::LEFT].id);
      p.move(nlev->data->width, -level->neighbour[Level::Neighbour::LEFT].offset);
      p.updateFloor(nlev->data);
      level = nlev;
    } else if (p.x > level->data->width - 1 && level->neighbour[Level::Neighbour::RIGHT].id != 0) {
      Level* nlev = LevelManager::changeLevel(level->neighbour[Level::Neighbour::RIGHT].id);
      p.move(-level->data->width, -level->neighbour[Level::Neighbour::RIGHT].offset);
      p.updateFloor(nlev->data);
      level = nlev;
    }

    scene.render(LevelManager::getCurrentLevel(), &p, Keyboard::isKeyPressed(Keyboard::Space));
    win.draw(scene);
    win.display();
  }
  LevelManager::free();
  cout << "Byebye!\n";
  return 0;
}

