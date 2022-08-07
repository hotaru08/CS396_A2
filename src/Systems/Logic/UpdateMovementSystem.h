/******************************************************************************
filename:	PlayerUpdateLogic.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System that handles player update logic.

******************************************************************************/
#pragma once

struct UpdateMovementSystem : xecs::system::instance
{
    constexpr static auto typedef_v = xecs::system::type::update
    {
        .m_pName = "UpdateMovementSystem"
    };

    void operator()(Velocity& _velocity, Position& _position, GridCell& _gridCell)
    {
        _position.m_value += _velocity.m_value;
        _gridCell = grid::ComputeGridCellFromWorldPosition(_position.m_value);
    }
};

struct PlayerMovementSystem : xecs::system::instance
{
    constexpr static auto typedef_v = xecs::system::type::update
    {
        .m_pName = "PlayerMovementSystem"
    };

    using query = std::tuple
    <
        xecs::query::must<Player>
    >;

    void operator()(Position& _position, Scale& _scale, Velocity& _velocity, GridCell& _gridcell) noexcept;
};