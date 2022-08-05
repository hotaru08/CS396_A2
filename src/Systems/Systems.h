#pragma once

#include <Systems\Timer\UpdateTimerSystem.h>

#include <Systems\Events\PlayerInputs_KeyEventsSystem.h>

#include <Systems\Logic\PlayerUpdateLogicSystem.h>
#include <Systems\Logic\FireBulletSystem.h>
#include <Systems\Logic\TurretShootingSystem.h>


#include <Systems\Render\RenderCameraSystem.h>
#include <Systems\Render\RenderTowerSystem.h>
#include <Systems\Render\RenderTurretSystem.h>
#include <Systems\Render\RenderPlayerSystem.h>
#include <Systems\Render\RenderBulletSystem.h>
#include <Systems\Render\RenderSpatialGridSystem.h>

#define ALL_SYSTEMS \
    UpdateTimerSystem, UpdateTimerShootingSystem, \
    PlayerInputs_OnKeyDown, PlayerInputs_OnKeyUp, PlayerUpdateLogicSystem, \
    TurretShootingSystem, FireBulletSystem, \
    RenderCameraSystem, RenderSpatialGridSystem, RenderPlayerSystem,\
    RenderTurretSystem, RenderTowerSystem, RenderBulletSystem

