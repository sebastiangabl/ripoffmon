/*
 * Scene.cpp
 *
 *  Created on: 24. Feb. 2016
 *      Author: Sebastian
 */

#include "Scene.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Scene::Scene(unsigned width, unsigned height) {
  view.setSize(width, height);
  texture.create(width, height);
}

Scene::~Scene() {
}

void Scene::render(Level* l, Entity* e) {
  view.setCenter((e->prev_x * (1 - e->action_step) + e->x * e->action_step) * 24,
      (e->prev_y * (1 - e->action_step) + e->y * e->action_step) * 24);
  texture.setView(view);

  texture.clear(Color::Black);

  // Render main level
  if (l->loaded) {
    l->render();
    texture.draw(Sprite(l->texture_back.getTexture()));
  }
  // Render neighbours
  Sprite s;
  Level* n;
  if ((n = LevelManager::getLevel(l->neighbour[Level::Neighbour::RIGHT].id, true)) && n->loaded) {
    n->render();
    s.setTexture(n->texture_back.getTexture(), true);
    s.setPosition(l->data->width * 24, l->neighbour[Level::Neighbour::RIGHT].offset * 24);
    texture.draw(s);
  }
  if ((n = LevelManager::getLevel(l->neighbour[Level::Neighbour::TOP].id, true)) && n->loaded) {
    n->render();
    s.setTexture(n->texture_back.getTexture(), true);
    s.setPosition(l->neighbour[Level::Neighbour::TOP].offset * 24, -n->data->height * 24);
    texture.draw(s);
  }
  if ((n = LevelManager::getLevel(l->neighbour[Level::Neighbour::LEFT].id, true)) && n->loaded) {
    n->render();
    s.setTexture(n->texture_back.getTexture(), true);
    s.setPosition(-n->data->width * 24, l->neighbour[Level::Neighbour::LEFT].offset * 24);
    texture.draw(s);
  }
  if ((n = LevelManager::getLevel(l->neighbour[Level::Neighbour::BOTTOM].id, true)) && n->loaded) {
    n->render();
    s.setTexture(n->texture_back.getTexture(), true);
    s.setPosition(l->neighbour[Level::Neighbour::BOTTOM].offset * 24, l->data->height * 24);
    texture.draw(s);
  }

  texture.draw(*e);

  texture.display();
}

void Scene::draw(sf::RenderTarget& rt, sf::RenderStates rs) const {
  Vector2f source_size(texture.getSize());
  Vector2f target_size(rt.getSize());
  Sprite sprite(texture.getTexture());
  sprite.setScale(target_size.x / source_size.x, target_size.y / source_size.y);
  rt.draw(sprite, rs);
}
