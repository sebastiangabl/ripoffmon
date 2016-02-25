/*
 * CreatureBase.h
 *
 *  Created on: 02. Jän. 2016
 *      Author: Sebastian
 */

#ifndef CREATUREBASE_H_
#define CREATUREBASE_H_

#include <string>
#include <vector>
#include "Stats.h"
#include "Ability.h"
#include <SFML/Config.hpp>

using std::string;
using std::vector;
using sf::Uint8;
using sf::Uint16;

enum Type {
  NONE = -1, NORMAL = 0, FIGHTING, FYLING, POISON, GROUND, ROCK, BUG, GHOST,
  STEEL, FIRE, WATER, GRASS, ELECTRIC, PSYCHIC, ICE, DRAGON, DARK, FAIRY
};

static float TypeChart[18][18] = {{1,  1,  1,  1,  1, .5,  1,  0, .5,  1,  1,  1,  1,  1,  1,  1,  1,  1},
                           {2,  1, .5, .5,  1,  2, .5,  0,  2,  1,  1,  1,  1, .5,  2,  1,  2, .5},
                           {1,  2,  1,  1,  1, .5,  2,  1, .5,  1,  1,  2, .5,  1,  1,  1,  1,  1},
                           {1,  1,  1, .5, .5, .5,  1, .5,  0,  1,  1,  2,  1,  1,  1,  1,  1,  2},
                           {1,  1,  0,  2,  1,  2, .5,  1,  2,  2,  1, .5,  2,  1,  1,  1,  1,  1},
                           {1, .5,  2,  1, .5,  1,  2,  1, .5,  2,  1,  1,  1,  1,  2,  1,  1,  1},
                           {1, .5, .5, .5,  1,  1,  1, .5, .5, .5,  1,  2,  1,  2,  1,  1,  2, .5},
                           {0,  1,  1,  1,  1,  1,  1,  2,  1,  1,  1,  1,  1,  2,  1,  1, .5,  1},
                           {1,  1,  1,  1,  1,  2,  1,  1, .5, .5, .5,  1, .5,  1,  2,  1,  1,  2},
                           {1,  1,  1,  1,  1, .5,  2,  1,  2, .5, .5,  2,  1,  1,  2, .5,  1,  1},
                           {1,  1,  1,  1,  2,  2,  1,  1,  1,  2, .5, .5,  1,  1,  1, .5,  1,  1},
                           {1,  1, .5, .5,  2,  2, .5,  1, .5, .5,  2, .5,  1,  1,  1, .5,  1,  1},
                           {1,  1,  2,  1,  0,  1,  1,  1,  1,  1,  2, .5, .5,  1,  1, .5,  1,  1},
                           {1,  2,  1,  2,  1,  1,  1,  1, .5,  1,  1,  1,  1, .5,  1,  1,  0,  1},
                           {1,  1,  2,  1,  2,  1,  1,  1, .5, .5, .5,  2,  1,  1, .5,  2,  1,  1},
                           {1,  1,  1,  1,  1,  1,  1,  1, .5,  1,  1,  1,  1,  1,  1,  2,  1,  0},
                           {1, .5,  1,  1,  1,  1,  1,  2,  1,  1,  1,  1,  1,  2,  1,  1, .5, .5},
                           {1,  2,  1, .5,  1,  1,  1,  1, .5, .5,  1,  1,  1,  1,  1,  2,  2,  1}};

class CreatureBase {
  public:
    enum EggGroup {
      UNKNOWN, DITTO, MONSTER, WATER1, WATER2, WATER3, BUG, FLYING,
      FIELD, FAIRY, GRASS, HUMANLIKE, MINERAL, AMORPHOUS, DRAGON
    };
    string name;
    Type type[2];
    Stats base_stats, effort_reward;
    float gender_ratio; // 0 = male, 1 = female, >1 = none
    vector<Ability*> abilities, hidden_abilities;
    Uint8 catch_rate, base_friendship;
    EggGroup egg_group[2];
    Uint16 egg_steps;

    CreatureBase();
};

#endif /* CREATUREBASE_H_ */
