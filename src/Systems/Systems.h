#pragma once

#include <Systems\EventSystems\PlayerInputs_OnKeyHold.h>

#include <Systems\RenderCameraSystem.h>
#include <Systems\RenderTowerSystem.h>
#include <Systems\RenderPlayerSystem.h>
#include <Systems\RenderSpatialGridSystem.h>

#define ALL_SYSTEMS \
    PlayerInputs_OnKeyHold, \
    RenderCameraSystem, RenderSpatialGridSystem, RenderPlayerSystem, RenderTowerSystem