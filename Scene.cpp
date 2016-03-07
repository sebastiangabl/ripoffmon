/*
 * Scene.cpp
 *
 *  Created on: 24. Feb. 2016
 *      Author: Sebastian
 */

#include "Scene.h"

#include <SFML/Graphics/BlendMode.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <algorithm>
#include <cmath>

#include "Flags.h"
#include "Level.h"
#include "LevelData.h"
#include "LevelManager.h"
#include "TileSet.h"

using namespace std;
using namespace sf;

Scene::Scene(unsigned width, unsigned height) {
  view.setSize(width, height);
  texture.create(width, height);
}

Scene::~Scene() {
}

void Scene::drawEntities(vector<Entity*> ents, Level* l) {
  sort(ents.begin(), ents.end(), Entity::compare);
  for (unsigned i = 0; i < ents.size(); i++) {
    Entity* e = ents[i];
    if (!e->visible || Flags::get(e->flag)) {
      // skip invisible or disabled entities
      continue;
    }
    texture.draw(*e);
    if ((l->tiles.getTileFlags(l->data->tiles_front[e->x][e->y]) & TileSet::FOREGROUND)
        || (e->on_floor << 1) < l->data->floors[e->x][e->y]) {
      Sprite front(l->texture_front.getTexture(), IntRect(e->x * 24, e->y * 24, 24, 24));
      front.setPosition(e->x * 24, e->y * 24);
      texture.draw(front);
    }
    if (e->y - 1 >= 0 && (e->on_floor << 1) < l->data->floors[e->x][e->y - 1]) {
      Sprite front(l->texture_front.getTexture(), IntRect(e->x * 24, (e->y - 1) * 24, 24, 24));
      front.setPosition(e->x * 24, (e->y - 1) * 24);
      texture.draw(front);
    }
    if (e->prev_x >= 0 && e->prev_x < l->data->width && e->prev_y >= 0 && e->prev_y < l->data->height
        && ((l->tiles.getTileFlags(l->data->tiles_front[e->prev_x][e->prev_y]) & TileSet::FOREGROUND)
            || (e->on_floor << 1) < l->data->floors[e->prev_x][e->prev_y])) {
      Sprite front(l->texture_front.getTexture(), IntRect(e->prev_x * 24, e->prev_y * 24, 24, 24));
      front.setPosition(e->prev_x * 24, e->prev_y * 24);
      texture.draw(front);
    }
    if (e->prev_x >= 0 && e->prev_x < l->data->width && e->prev_y - 1 >= 0 && e->prev_y - 1 < l->data->height
        && (e->on_floor << 1) < l->data->floors[e->prev_x][e->prev_y - 1]) {
      Sprite front(l->texture_front.getTexture(), IntRect(e->prev_x * 24, (e->prev_y - 1) * 24, 24, 24));
      front.setPosition(e->prev_x * 24, (e->prev_y - 1) * 24);
      texture.draw(front);
    }
  }
}

void Scene::render(Level* l, Entity* e, bool debug) {
  view.setCenter((e->prev_x * (1 - e->action_step) + e->x * e->action_step) * 24,
      (e->prev_y * (1 - e->action_step) + e->y * e->action_step) * 24);
  texture.setView(view);

  texture.clear(Color::Black);

  if (l->loaded) {
    /* Draw main level outside texture */
    Vector2u size = texture.getSize();
    Vector2f c = view.getCenter();
    Sprite out(l->texture_outside.getTexture(), IntRect(0, 0, size.x + 48, size.y + 48));
    out.setPosition(Vector2f(floor((c.x - size.x / 2) / 48) * 48, floor((c.y - size.y / 2) / 48) * 48));
    texture.draw(out);
  }

  // Render neighbours
  Level* n[4];
  Sprite s;
  if ((n[0] = LevelManager::getLevel(l->neighbour[Level::Neighbour::RIGHT].id, true)) && n[0]->loaded) {
    n[0]->render();
    s.setPosition(l->data->width * 24, l->neighbour[Level::Neighbour::RIGHT].offset * 24);
    s.setTexture(n[0]->texture_back.getTexture(), true);
    texture.draw(s);
    s.setTexture(n[0]->texture_front.getTexture(), true);
    texture.draw(s);
  }
  if ((n[1] = LevelManager::getLevel(l->neighbour[Level::Neighbour::TOP].id, true)) && n[1]->loaded) {
    n[1]->render();
    s.setPosition(l->neighbour[Level::Neighbour::TOP].offset * 24, -n[1]->data->height * 24);
    s.setTexture(n[1]->texture_back.getTexture(), true);
    texture.draw(s);
    s.setTexture(n[1]->texture_front.getTexture(), true);
    texture.draw(s);
  }
  if ((n[2] = LevelManager::getLevel(l->neighbour[Level::Neighbour::LEFT].id, true)) && n[2]->loaded) {
    n[2]->render();
    s.setPosition(-n[2]->data->width * 24, l->neighbour[Level::Neighbour::LEFT].offset * 24);
    s.setTexture(n[2]->texture_back.getTexture(), true);
    texture.draw(s);
    s.setTexture(n[2]->texture_front.getTexture(), true);
    texture.draw(s);
  }
  if ((n[3] = LevelManager::getLevel(l->neighbour[Level::Neighbour::BOTTOM].id, true)) && n[3]->loaded) {
    n[3]->render();
    s.setPosition(l->neighbour[Level::Neighbour::BOTTOM].offset * 24, l->data->height * 24);
    s.setTexture(n[3]->texture_back.getTexture(), true);
    texture.draw(s);
    s.setTexture(n[3]->texture_front.getTexture(), true);
    texture.draw(s);
  }
  // Render main level
  if (l && l->loaded) {
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

  // Draw entities
  vector<Entity*> ents;
  if (n[Level::Neighbour::TOP] && n[Level::Neighbour::TOP]->loaded) {
    ents = n[Level::Neighbour::TOP]->entities;
    drawEntities(ents, n[Level::Neighbour::TOP]);
  }
  if (n[Level::Neighbour::RIGHT] && n[Level::Neighbour::RIGHT]->loaded) {
    ents = n[Level::Neighbour::RIGHT]->entities;
    drawEntities(ents, n[Level::Neighbour::RIGHT]);
  }
  if (n[Level::Neighbour::LEFT] && n[Level::Neighbour::LEFT]->loaded) {
    ents = n[Level::Neighbour::LEFT]->entities;
    drawEntities(ents, n[Level::Neighbour::LEFT]);
  }
  if (n[Level::Neighbour::BOTTOM] && n[Level::Neighbour::BOTTOM]->loaded) {
    ents = n[Level::Neighbour::BOTTOM]->entities;
    drawEntities(ents, n[Level::Neighbour::BOTTOM]);
  }
  if (l && l->loaded) {
    ents = l->entities;
    ents.push_back(e);
    drawEntities(ents, l);
  }

  texture.display();
}

void Scene::draw(sf::RenderTarget& rt, sf::RenderStates rs) const {
  Vector2f source_size(texture.getSize());
  Vector2f target_size(rt.getSize());
  Sprite sprite(texture.getTexture());
  sprite.setScale(target_size.x / source_size.x, target_size.y / source_size.y);
  rt.draw(sprite, rs);
}
