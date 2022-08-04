/******************************************************************************
filename:	PlayerUpdateLogic.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System that handles player update logic.

******************************************************************************/
#pragma once

struct PlayerUpdateLogicSystem : xecs::system::instance
{
    constexpr static auto typedef_v = xecs::system::type::update
    {
        .m_pName = "PlayerUpdateLogicSystem"
    };

    void operator()(Velocity& _velocity, Direction& _direction, Position& _position, GridCell& _gridCell)
    {
        _position.m_value += _direction.m_value * _velocity.m_value;
        _gridCell = grid::ComputeGridCellFromWorldPosition(_position.m_value);
    }
};
