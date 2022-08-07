/******************************************************************************
filename:	MeleeAttackSystem.hpp
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Contains systems that updates melee attacks.

******************************************************************************/
#pragma once

void MeleeAttackSystem::operator()(
    xecs::component::entity& _entity, MeleeAttack& _meleeAttack,
    Timer& _timer, Position& _entPos, Rotation& _entRot)
{
    if (_meleeAttack.m_value)
    {
        // Create melee effect
        //CreatePrefabInstance
        //(
        //    1, sg_game.m_prefabGUIDs[Game::PREFAB_TYPES::RENDER_MELEE],
        //    [&](Position& _position, Rotation& _rotation, Timer& _timer) noexcept
        //    {
        //        xcore::vector2 dir
        //        {
        //            std::cosf(xcore::math::DegToRad(_entRot.m_value)),
        //            -std::sinf(xcore::math::DegToRad(_entRot.m_value))
        //        };
        //        _rotation.m_value = _entRot.m_value - 90.0f;

        //        _position.m_value = _entPos.m_value + dir * 5.0f;
        //        _timer.m_value = m_attackInterval - 0.16f;
        //    }
        //);

        // Fire bullet
        CreatePrefabInstance
        (
            1, sg_game.m_prefabGUIDs[Game::PREFAB_TYPES::BULLET],
            [&](Position& _position, Velocity& _velocity, GridCell& _cell, Bullet& _bullet) noexcept
            {
                xcore::vector2 dir
                {
                    std::cosf(xcore::math::DegToRad(_entRot.m_value)),
                    -std::sinf(xcore::math::DegToRad(_entRot.m_value))
                };
                _velocity.m_value = dir * 5.0f;

                _bullet.m_owner = _entity;
                _position.m_value = _entPos.m_value + _velocity.m_value;

                _cell = grid::ComputeGridCellFromWorldPosition(_position.m_value);
            }
        );

        // Reset timer and other states
        _meleeAttack.m_value = false;
        _timer.m_value = m_attackInterval;
    }
}
