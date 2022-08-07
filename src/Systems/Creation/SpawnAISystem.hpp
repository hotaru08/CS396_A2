/******************************************************************************
filename:	SpawnAISystem.hpp
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System that spawns AIs, timing varies, AI spawn varies.

******************************************************************************/
#pragma once

void SpawnAISystem::operator()(Timer& _timer, Spawner& _spawner) noexcept
{
    if (!_spawner.m_canSpawn)
        return;

    // Spawn AI
    CreatePrefabInstance
    (
        1, sg_game.m_prefabGUIDs[Game::PREFAB_TYPES::TOWER_ATTACKING_AI],
        [&](Position& _position, Rotation& _rotation, Scale& _scale,
            Velocity& _velocity, Target& _target, Timer& _timer) noexcept
        {
            // Find for that one tower and set target
            Foreach
            (
                Search(m_towerQuery),
                [&](Position& _towerPos)
                {
                    _target.m_value = _towerPos.m_value;
                }
            );

            switch (std::rand() % 4)
            {
            case 0:
                _position.m_value = xcore::vector2
                {
                    -_scale.m_value.m_X,
                    static_cast<float>(std::rand() % sg_game.m_windowInst.m_height)
                };
                break;
            case 1:
                _position.m_value = xcore::vector2
                {
                    sg_game.m_windowInst.m_width + _scale.m_value.m_X,
                    static_cast<float>(std::rand() % sg_game.m_windowInst.m_height)
                };
                break;
            case 2:
                _position.m_value = xcore::vector2
                {
                    static_cast<float>(std::rand() % sg_game.m_windowInst.m_width),
                    -_scale.m_value.m_Y,
                };
                break;
            case 3: // btm
                _position.m_value = xcore::vector2
                {
                    static_cast<float>(std::rand() % sg_game.m_windowInst.m_width),
                    sg_game.m_windowInst.m_height + _scale.m_value.m_X,
                };
                break;
            }

            // Update rotation and velocity to tower
            xcore::vector2 dir = (_target.m_value - _position.m_value).Normalize();
            _rotation.m_value = -xcore::math::ATan2(dir.m_Y, dir.m_X).getDegrees().m_Value;
            _velocity.m_value = dir * 2.5f;
        }
    );

    // Reset timer and other states
    _spawner.m_canSpawn = false;
    _timer.m_value = m_spawnInterval;
}
