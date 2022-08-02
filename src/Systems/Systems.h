#pragma once

#include <Systems\EventSystems\PlayerInputs_OnKeyHold.h>
#include <Systems\PlayerUpdateLogicSystem.h>

#include <Systems\RenderCameraSystem.h>
#include <Systems\RenderTowerSystem.h>
#include <Systems\RenderPlayerSystem.h>
#include <Systems\RenderSpatialGridSystem.h>

#define ALL_SYSTEMS \
    PlayerInputs_OnKeyHold, PlayerInputs_OnKeyUp, \
    PlayerUpdateLogicSystem, \
    RenderCameraSystem, RenderSpatialGridSystem, RenderPlayerSystem, RenderTowerSystem