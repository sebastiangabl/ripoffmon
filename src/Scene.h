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
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>

#include "Entity.h"

class Level;

using std::vector;
using sf::RenderTexture;
using sf::View;
using sf::Vector2u;
using sf::Shader;
using sf::Texture;
using sf::Vertex;
using sf::Clock;

class Scene: public sf::Drawable {
  private:
    RenderTexture texture;
    Texture daylight_texture;
    View view;
    Shader shader_lighting;
    Vertex particles[100];
    Clock clock;
    float time;
    void drawEntities(vector<Entity*>, Level*);
  public:
    Scene(unsigned, unsigned);
    ~Scene();

    void updateAndRender(Level*, Entity*, bool = false);

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif /* SCENE_H_ */
