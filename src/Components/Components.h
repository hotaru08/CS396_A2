#pragma once

#include <Components\Position.h>
#include <Components\Scale.h>
#include <Components\Rotation.h>
#include <Components\Velocity.h>
#include <Components\GridCells.h>
#include <Components\Timer.h>

#include <Components\Player.h>
#include <Components\FireBullet.h>
#include <Components\Bullet.h>
#include <Components\Target.h>

#define ALL_COMPONENTS \
    Position, Scale, Rotation,  \
    Velocity, Timer, GridCell,  \
    Player, FireBullet, Bullet, \
    Target