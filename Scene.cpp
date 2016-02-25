/*
 * Scene.cpp
 *
 *  Created on: 24. Feb. 2016
 *      Author: Sebastian
 */

#include "Scene.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

Scene::Scene(unsigned width, unsigned height) {
  view.setSize(width, height);
  texture.create(width, height);
}

Scene::~Scene() {
}

void Scene::render(Level* l, Entity* e, bool debug) {
  view.setCenter((e->prev_x * (1 - e->action_step) + e->x * e->action_step) * 24,
      (e->prev_y * (1 - e->action_step) + e->y * e->action_step) * 24);
  texture.setView(view);

  texture.clear(Color::Black);

  Sprite s;
  // Render main level
  if (l->loaded) {
    /* Draw outside level texture */
    Vector2u size = texture.getSize();
    Vector2f c = view.getCenter();
    Sprite out(l->texture_outside.getTexture(), IntRect(0, 0, size.x + 48, size.y + 48));
    out.setPosition(Vector2f(floor((c.x - size.x / 2) / 48) * 48, floor((c.y - size.y / 2) / 48) * 48));
    texture.draw(out);

    l->render();
    s.setPosition(0, 0);
    s.setTexture(l->texture_back.getTexture(), true);
    texture.draw(s);
    s.setTexture(l->texture_front.getTexture(), true);
    texture.draw(s);
    if (debug) {
      s.setTexture(l->texture_debug.getTexture(), true);
      texture.draw(s, BlendMultiply);
    }
  }
  // Render neighbours
  Level* n;
  if ((n = LevelManager::getLevel(l->neighbour[Level::Neighbour::RIGHT].id, true)) && n->loaded) {
    n->render();
    s.setPosition(l->data->width * 24, l->neighbour[Level::Neighbour::RIGHT].offset * 24);
    s.setTexture(n->texture_back.getTexture(), true);
    texture.draw(s);
    s.setTexture(n->texture_front.getTexture(), true);
    texture.draw(s);
  }
  if ((n = LevelManager::getLevel(l->neighbour[Level::Neighbour::TOP].id, true)) && n->loaded) {
    n->render();
    s.setPosition(l->neighbour[Level::Neighbour::TOP].offset * 24, -n->data->height * 24);
    s.setTexture(n->texture_back.getTexture(), true);
    texture.draw(s);
    s.setTexture(n->texture_front.getTexture(), true);
    texture.draw(s);
  }
  if ((n = LevelManager::getLevel(l->neighbour[Level::Neighbour::LEFT].id, true)) && n->loaded) {
    n->render();
    s.setPosition(-n->data->width * 24, l->neighbour[Level::Neighbour::LEFT].offset * 24);
    s.setTexture(n->texture_back.getTexture(), true);
    texture.draw(s);
    s.setTexture(n->texture_front.getTexture(), true);
    texture.draw(s);
  }
  if ((n = LevelManager::getLevel(l->neighbour[Level::Neighbour::BOTTOM].id, true)) && n->loaded) {
    n->render();
    s.setPosition(l->neighbour[Level::Neighbour::BOTTOM].offset * 24, l->data->height * 24);
    s.setTexture(n->texture_back.getTexture(), true);
    texture.draw(s);
    s.setTexture(n->texture_front.getTexture(), true);
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
