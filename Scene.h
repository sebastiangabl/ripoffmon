/*
 * Scene.h
 *
 *  Created on: 24. Feb. 2016
 *      Author: Sebastian
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Shader.hpp>
#include "LevelManager.h"

using sf::RenderTexture;
using sf::Sprite;
using sf::View;
using sf::Shader;
using sf::Vector2u;

class Scene: public sf::Drawable {
  private:
    RenderTexture texture;
    View view;
  public:
    Scene(unsigned, unsigned);
    ~Scene();
    void render(Level*, Entity*, bool = false);

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif /* SCENE_H_ */
