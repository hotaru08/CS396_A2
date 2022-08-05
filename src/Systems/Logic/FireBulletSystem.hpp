/******************************************************************************
filename:	FireBulletSystem.hpp
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System for firing bullet when they can be fired.

******************************************************************************/
#pragma once

void FireBulletSystem::operator()(Velocity& _velocity, Position& _position, GridCell& _gridCell, Bullet& _bullet) noexcept
{
    // Update Movement of Bullets
    _position.m_value += _velocity.m_value;
    _gridCell = grid::ComputeGridCellFromWorldPosition(_position.m_value);

    // Check bullet if out of bounds / collision -> destroy bullet
        
}
