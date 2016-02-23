/*
 * CreatureBase.cpp
 *
 *  Created on: 02. Jän. 2016
 *      Author: Sebastian
 */

#include "CreatureBase.h"

CreatureBase::CreatureBase() {
  name = "";
  type[0] = NORMAL;
  type[1] = NONE;
  gender_ratio = 0.5;
  catch_rate = 255;
  base_friendship = 70;
  egg_group[0] = UNKNOWN;
  egg_group[1] = UNKNOWN;
  egg_steps = 5120;
}
