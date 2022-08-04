#pragma once

#include <Systems\UpdateTimerSystem.h>

#include <Systems\EventSystems\PlayerInputs_KeyEventsSystem.h>
#include <Systems\PlayerUpdateLogicSystem.h>

#include <Systems\FireBulletSystem.h>

#include <Systems\RenderCameraSystem.h>
#include <Systems\RenderTowerSystem.h>
#include <Systems\RenderTurretSystem.h>
#include <Systems\RenderPlayerSystem.h>
#include <Systems\RenderBulletSystem.h>
#include <Systems\RenderSpatialGridSystem.h>

#define ALL_SYSTEMS \
    UpdateTimerSystem, UpdateTimerShootingSystem, \
    PlayerInputs_OnKeyDown, PlayerInputs_OnKeyUp, PlayerUpdateLogicSystem, \
    TurretShootingSystem, FireBulletSystem, \
    RenderCameraSystem, RenderSpatialGridSystem, RenderPlayerSystem,\
    RenderTurretSystem, RenderTowerSystem, RenderBulletSystem