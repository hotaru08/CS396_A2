#pragma once

#include <Components\Position.h>
#include <Components\Scale.h>
#include <Components\Rotation.h>
#include <Components\Velocity.h>
#include <Components\GridCells.h>
#include <Components\Timer.h>
#include <Components\Color.h>

#include <Components\FireBullet.h>
#include <Components\Bullet.h>
#include <Components\Target.h>
#include <Components\Health.h>

#include <Components\Tags\Player.h>
#include <Components\Tags\TowerAI.h>
#include <Components\Tags\PlayerAI.h>
#include <Components\Tags\BomberAI.h>
#include <Components\Tags\PlayerAttackAISpawner.h>
#include <Components\Tags\TowerAttackAISpawner.h>

#define ALL_COMPONENTS \
    Position, Scale, Rotation,  \
    Velocity, Timer, GridCell,  \
    FireBullet, Bullet, Target, Health, Color

#define ALL_TAGS \
    Player, TowerAI, PlayerAI, BomberAI, \
    PlayerAttackAISpawner, TowerAttackAISpawner