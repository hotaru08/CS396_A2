/******************************************************************************
filename:	TurretShootingSystem.hpp
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System that handles turrent shooting logic.

******************************************************************************/
#pragma once

void TurretShootingSystem::operator()(
    xecs::component::entity& _entity, FireBullet& _fireBullet, Target* _target,
    Timer& _timer, Position& _turrentPos, Rotation& _turretRot)
{
    if (_fireBullet.m_value)
    {
        // Create bullet instance to fire
        CreatePrefabInstance
        (
            1, sg_game.m_prefabGUIDs[Game::PREFAB_TYPES::BULLET],
            [&](Position& _position, Velocity& _velocity, GridCell& _cell, Bullet& _bullet) noexcept
            {
                xcore::vector2 dir;
                if (_target)
                {
                    dir = (_target->m_value - _turrentPos.m_value).NormalizeSafe();
                    _turretRot.m_value = -xcore::math::ATan2(dir.m_Y, dir.m_X).getDegrees().m_Value;
                }
                else
                {
                    dir.m_X = std::cosf(xcore::math::DegToRad(_turretRot.m_value));
                    dir.m_Y = -std::sinf(xcore::math::DegToRad(_turretRot.m_value));
                }
                _velocity.m_value = dir * m_bulletSpeed;

                _bullet.m_owner = _entity;
                _position.m_value = xcore::vector2{ _turrentPos.m_value.m_X, _turrentPos.m_value.m_Y };

                _cell = grid::ComputeGridCellFromWorldPosition(_position.m_value);
            }
        );

        // Reset timer and other states
        _fireBullet.m_value = false;
        _timer.m_value = _fireBullet.m_shootInterval;
    }
}
