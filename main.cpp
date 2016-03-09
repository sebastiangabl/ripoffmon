/*
 * main.cpp
 *
 *  Created on: 02. Jän. 2016
 *      Author: Sebastian
 */

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>

#include "Level.h"
#include "LevelData.h"
#include "LevelManager.h"
#include "MusicLoop.h"
#include "Player.h"
#include "Scene.h"
#include "TileSet.h"

using namespace std;
using namespace sf;

int main() {
  Level::debug_tiles.loadFromFile("tilesets/debug.png");
  Level::tiles.loadFromFile("tilesets/tiles.png");

  Level* level = LevelManager::getLevel(1);

  Player p(10, 10);
  p.updateFloor(level->data);

  float delta = 0;
  Clock delta_clock;

  RenderWindow win(VideoMode(1280, 720), "Ripoffmon", Style::Titlebar | Style::Close);
  win.setFramerateLimit(0);
  win.setVerticalSyncEnabled(true);
  Scene scene(1280 / 4, 720 / 4);

  MusicLoop test1, test2, test3;
  test1.openFromFile("music/1.ogg");
  test2.openFromFile("music/2.ogg");
  test3.openFromFile("music/3.ogg");
  test1.fadeIn(seconds(2));
  unsigned music_stage = 0;

  while (win.isOpen()) {
    Event e;
    while (win.pollEvent(e)) {
      switch (e.type) {
        case Event::Closed:
        win.close();
        break;

        case Event::KeyPressed:
        if (e.key.code == Keyboard::Return) {
          if (music_stage == 0) {
            test1.fadeOut(milliseconds(200), true);
            test2.play();
            music_stage = 1;
          } else if (music_stage == 1) {
            test2.fadeOut(milliseconds(200));
            test3.play();
            music_stage = 2;
          } else if (music_stage == 2) {
            test3.fadeOut(milliseconds(800));
            test1.fadeIn(milliseconds(2400));
            music_stage = 0;
          }
        }
        break;

        default:
        break;
      }
    }
    delta = delta_clock.restart().asSeconds();

    p.actions(level->data, Keyboard::isKeyPressed(Keyboard::Up), Keyboard::isKeyPressed(Keyboard::Left),
        Keyboard::isKeyPressed(Keyboard::Down), Keyboard::isKeyPressed(Keyboard::Right),
        Keyboard::isKeyPressed(Keyboard::LShift));
    p.update(delta, level->data);

    if (level->loaded && p.y < 0 && level->neighbour[Level::Neighbour::TOP].id) {
      Level* nlev = LevelManager::getLevel(level->neighbour[Level::Neighbour::TOP].id);
      p.move(-level->neighbour[Level::Neighbour::TOP].offset, nlev->data->height);
      p.updateFloor(nlev->data);
      level = nlev;
    } else if (level->loaded && p.y > level->data->height - 1 && level->neighbour[Level::Neighbour::BOTTOM].id) {
      Level* nlev = LevelManager::getLevel(level->neighbour[Level::Neighbour::BOTTOM].id);
      p.move(-level->neighbour[Level::Neighbour::BOTTOM].offset, -level->data->height);
      p.updateFloor(nlev->data);
      level = nlev;
    } else if (level->loaded && p.x < 0 && level->neighbour[Level::Neighbour::LEFT].id) {
      Level* nlev = LevelManager::getLevel(level->neighbour[Level::Neighbour::LEFT].id);
      p.move(nlev->data->width, -level->neighbour[Level::Neighbour::LEFT].offset);
      p.updateFloor(nlev->data);
      level = nlev;
    } else if (level->loaded && p.x > level->data->width - 1 && level->neighbour[Level::Neighbour::RIGHT].id) {
      Level* nlev = LevelManager::getLevel(level->neighbour[Level::Neighbour::RIGHT].id);
      p.move(-level->data->width, -level->neighbour[Level::Neighbour::RIGHT].offset);
      p.updateFloor(nlev->data);
      level = nlev;
    }

    scene.render(level, &p, Keyboard::isKeyPressed(Keyboard::Space));
    win.draw(scene);
    win.display();
  }
  LevelManager::free();
  cout << "Byebye!\n";
  return 0;
}

