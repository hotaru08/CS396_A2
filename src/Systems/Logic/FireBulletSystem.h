/******************************************************************************
filename:	FireBulletSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System for firing bullet when they can be fired.

******************************************************************************/
#pragma once

struct FireBulletSystem : xecs::system::instance
{
    constexpr static auto typedef_v = xecs::system::type::update
    {
        .m_pName = "FireBulletSystem"
    };

    void operator()(Velocity& _velocity, Position& _position, GridCell& _gridCell, Bullet& _bullet)
    {
        _position.m_value += _velocity.m_value;
        _gridCell = grid::ComputeGridCellFromWorldPosition(_position.m_value);
    }
};