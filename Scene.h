/*
 * Scene.h
 *
 *  Created on: 24. Feb. 2016
 *      Author: Sebastian
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/View.hpp>
#include <vector>

#include "Entity.h"

class Level;

using std::vector;
using sf::RenderTexture;
using sf::View;
using sf::Vector2u;
using sf::Shader;

class Scene: public sf::Drawable {
  private:
    RenderTexture texture;
    View view;
    Shader daylight_cycle;
    void drawEntities(vector<Entity*>, Level*);
  public:
    Scene(unsigned, unsigned);
    ~Scene();
    void render(Level*, Entity*, bool = false);

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif /* SCENE_H_ */
