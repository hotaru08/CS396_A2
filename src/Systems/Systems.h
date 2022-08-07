#pragma once

#include <Systems\Timer\UpdateTimerSystem.h>
#include <Systems\Events\PlayerInputs_KeyEventsSystem.h>

#include <Systems\Logic\UpdateMovementSystem.h>
#include <Systems\Logic\DestroyBulletSystem.h>
#include <Systems\Logic\TurretShootingSystem.h>
#include <Systems\Logic\MeleeAttackSystem.h>
#include <Systems\Logic\CollisionSystems.h>
#include <Systems\Logic\UpdateHealthSystem.h>
#include <Systems\Logic\RotateToTargetSystem.h>
#include <Systems\Creation\SpawnAISystem.h>

#include <Systems\Render\RenderCameraSystem.h>
#include <Systems\Render\RenderTowerSystem.h>
#include <Systems\Render\RenderTurretSystem.h>
#include <Systems\Render\RenderMoveablesSystem.h>
#include <Systems\Render\RenderBulletSystem.h>
#include <Systems\Render\RenderMeleeAttack.h>
#include <Systems\Render\RenderHealthSystem.h>
#include <Systems\Render\RenderSpatialGridSystem.h>


#define ALL_SYSTEMS \
    UpdateTimerSystem, UpdateTimerShootingSystem, UpdateTimerSpawner, UpdateTimerMeleeAttack, \
    PlayerInputs_OnMouseMoved, PlayerInputs_OnKeyDown, PlayerInputs_OnMouseButtonDown, PlayerInputs_OnKeyUp,  \
    UpdateMovementSystem, MeleeAttackSystem, UpdateHealthSystem, \
    TurretShootingSystem, DestroyBulletSystem, SpawnAISystem, \
    RotateToTargetSystem, OutOfBoundsSystem, PlayerMovementSystem, CollisionSystem, \
    RenderSystem, RenderCameraSystem, \
    RenderMoveablesSystem, RenderMeleeAttack, \
    RenderBulletSystem, RenderTurretSystem, RenderTowerSystem, RenderHealthSystem
