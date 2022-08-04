#pragma once

#include <Components\Position.h>
#include <Components\Scale.h>
#include <Components\Rotation.h>
#include <Components\Velocity.h>
#include <Components\GridCells.h>
#include <Components\Timer.h>
#include <Components\Direction.h>

#include <Components\Player.h>
#include <Components\FireBullet.h>
#include <Components\Bullet.h>

#define ALL_COMPONENTS \
    Position, Scale, Rotation, \
    Velocity, Direction, \
    Timer, \
    GridCell, \
    Player, FireBullet, Bullet