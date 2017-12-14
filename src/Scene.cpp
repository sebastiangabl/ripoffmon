/*
 * Scene.cpp
 *
 *  Created on: 24. Feb. 2016
 *      Author: Sebastian
 */

#include "Scene.h"

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <ctime>
#include <cmath>

#include "Managers/Flags.h"
#include "Managers/LevelManager.h"
#include "TileSet.h"

using namespace std;
using namespace sf;

Scene::Scene(unsigned width, unsigned height) {
  view.setSize(width, height);
  texture.create(width, height);
  shader_lighting.loadFromFile("shaders/lighting.frag", Shader::Fragment);
  shader_lighting.setUniform("texture", Shader::CurrentTexture);
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
    if ((l->tiles->getTileFlags(l->data->tiles_front[e->x][e->y]) & TileSet::FOREGROUND) || (e->on_floor << 1) < l->data->floors[e->x][e->y]) {
      Sprite front(l->texture_front.getTexture(), IntRect(e->x * TileSet::tile_size, e->y * TileSet::tile_size, TileSet::tile_size, TileSet::tile_size));
      front.setPosition(e->x * TileSet::tile_size, e->y * TileSet::tile_size);
      texture.draw(front);
    }
    if (e->y - 1 >= 0 && (e->on_floor << 1) < l->data->floors[e->x][e->y - 1]) {
      Sprite front(l->texture_front.getTexture(), IntRect(e->x * TileSet::tile_size, (e->y - 1) * TileSet::tile_size, TileSet::tile_size, TileSet::tile_size));
      front.setPosition(e->x * TileSet::tile_size, (e->y - 1) * TileSet::tile_size);
      texture.draw(front);
    }
    if (e->prev_x >= 0 && e->prev_x < l->data->width && e->prev_y >= 0 && e->prev_y < l->data->height
        && ((l->tiles->getTileFlags(l->data->tiles_front[e->prev_x][e->prev_y]) & TileSet::FOREGROUND)
            || (e->on_floor << 1) < l->data->floors[e->prev_x][e->prev_y])) {
      Sprite front(l->texture_front.getTexture(),
          IntRect(e->prev_x * TileSet::tile_size, e->prev_y * TileSet::tile_size, TileSet::tile_size, TileSet::tile_size));
      front.setPosition(e->prev_x * TileSet::tile_size, e->prev_y * TileSet::tile_size);
      texture.draw(front);
    }
    if (e->prev_x >= 0 && e->prev_x < l->data->width && e->prev_y - 1 >= 0 && e->prev_y - 1 < l->data->height
        && (e->on_floor << 1) < l->data->floors[e->prev_x][e->prev_y - 1]) {
      Sprite front(l->texture_front.getTexture(),
          IntRect(e->prev_x * TileSet::tile_size, (e->prev_y - 1) * TileSet::tile_size, TileSet::tile_size, TileSet::tile_size));
      front.setPosition(e->prev_x * TileSet::tile_size, (e->prev_y - 1) * TileSet::tile_size);
      texture.draw(front);
    }
  }
}

void Scene::updateAndRender(Level* l, Entity* e, bool debug) {
  if (!l || !l->loaded) {
    return;
  }
  view.setCenter((e->prev_x * (1 - e->action_step) + e->x * e->action_step) * TileSet::tile_size,
      (e->prev_y * (1 - e->action_step) + e->y * e->action_step) * TileSet::tile_size);
  texture.setView(view);

  texture.clear(Color::Black);

  /* Draw main level outside texture */
  Vector2u size = texture.getSize();
  Vector2f c = view.getCenter();
  Sprite out(l->texture_outside.getTexture(), IntRect(0, 0, size.x + TileSet::tile_size * 2, size.y + TileSet::tile_size * 2));
  out.setPosition(
      Vector2f(std::floor((c.x - size.x / 2) / (TileSet::tile_size * 2)) * (TileSet::tile_size * 2),
          std::floor((c.y - size.y / 2) / (TileSet::tile_size * 2)) * (TileSet::tile_size * 2)));
  texture.draw(out);

  // Render neighbours
  Level* n[] = { 0, 0, 0, 0 };
  Sprite s;
  if (l->neighbour[Level::Neighbour::RIGHT].id && (n[0] = LevelManager::getLevel(l->neighbour[Level::Neighbour::RIGHT].id, true)) && n[0]->loaded) {
    n[0]->render();
    s.setPosition(l->data->width * TileSet::tile_size, l->neighbour[Level::Neighbour::RIGHT].offset * TileSet::tile_size);
    s.setTexture(n[0]->texture_back.getTexture(), true);
    texture.draw(s);
    s.setTexture(n[0]->texture_front.getTexture(), true);
    texture.draw(s);
  }
  if (l->neighbour[Level::Neighbour::TOP].id && (n[1] = LevelManager::getLevel(l->neighbour[Level::Neighbour::TOP].id, true)) && n[1]->loaded) {
    n[1]->render();
    s.setPosition(l->neighbour[Level::Neighbour::TOP].offset * TileSet::tile_size, -n[1]->data->height * TileSet::tile_size);
    s.setTexture(n[1]->texture_back.getTexture(), true);
    texture.draw(s);
    s.setTexture(n[1]->texture_front.getTexture(), true);
    texture.draw(s);
  }
  if (l->neighbour[Level::Neighbour::LEFT].id && (n[2] = LevelManager::getLevel(l->neighbour[Level::Neighbour::LEFT].id, true)) && n[2]->loaded) {
    n[2]->render();
    s.setPosition(-n[2]->data->width * TileSet::tile_size, l->neighbour[Level::Neighbour::LEFT].offset * TileSet::tile_size);
    s.setTexture(n[2]->texture_back.getTexture(), true);
    texture.draw(s);
    s.setTexture(n[2]->texture_front.getTexture(), true);
    texture.draw(s);
  }
  if (l->neighbour[Level::Neighbour::BOTTOM].id && (n[3] = LevelManager::getLevel(l->neighbour[Level::Neighbour::BOTTOM].id, true)) && n[3]->loaded) {
    n[3]->render();
    s.setPosition(l->neighbour[Level::Neighbour::BOTTOM].offset * TileSet::tile_size, l->data->height * TileSet::tile_size);
    s.setTexture(n[3]->texture_back.getTexture(), true);
    texture.draw(s);
    s.setTexture(n[3]->texture_front.getTexture(), true);
    texture.draw(s);
  }
  // Render main level
  if (l && l->loaded) {
    l->update();
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
  if (n[Level::Neighbour::TOP] && n[Level::Neighbour::TOP]->loaded) {
    drawEntities(n[Level::Neighbour::TOP]->entities, n[Level::Neighbour::TOP]);
  }
  if (n[Level::Neighbour::RIGHT] && n[Level::Neighbour::RIGHT]->loaded) {
    drawEntities(n[Level::Neighbour::RIGHT]->entities, n[Level::Neighbour::RIGHT]);
  }
  if (n[Level::Neighbour::LEFT] && n[Level::Neighbour::LEFT]->loaded) {
    drawEntities(n[Level::Neighbour::LEFT]->entities, n[Level::Neighbour::LEFT]);
  }
  vector<Entity*> ents = l->entities;
  ents.push_back(e);
  drawEntities(ents, l);
  if (n[Level::Neighbour::BOTTOM] && n[Level::Neighbour::BOTTOM]->loaded) {
    drawEntities(n[Level::Neighbour::BOTTOM]->entities, n[Level::Neighbour::BOTTOM]);
  }

  texture.display();

  time_t t = time(0);
  struct tm * now = localtime(&t);
  //shader_lighting.setUniform("time", float(now->tm_hour) + float(now->tm_min) / 60.f);
  shader_lighting.setUniform("time", (float(now->tm_sec) / 60.f) * 24.f);
}

void Scene::draw(sf::RenderTarget& rt, sf::RenderStates rs) const {
  Vector2f source_size(texture.getSize());
  Vector2f target_size(rt.getSize());
  Sprite sprite(texture.getTexture());

  float xscale = target_size.x / source_size.x;
  float yscale = target_size.y / source_size.y;

  sprite.setOrigin(source_size.x / 2, source_size.y / 2);
  sprite.setPosition(target_size.x / 2, target_size.y / 2);
  sprite.setScale(min(xscale, yscale), min(xscale, yscale));

  RenderStates r(rs);
  r.shader = &shader_lighting;
  rt.draw(sprite, r);
}
