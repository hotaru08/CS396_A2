/******************************************************************************
filename:	DestroyBulletSystem.hpp
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System for destroying bullets when to destroy.

******************************************************************************/
#pragma once

void DestroyBulletSystem::operator()(xecs::component::entity& _entity, const Position& _position, const Scale& _scale) noexcept
{
    // Check for bullet going out of bounds
    if (_position.m_value.m_X > sg_game.m_windowInst.m_width + _scale.m_value.m_X ||
        _position.m_value.m_X < 0.0f ||
        _position.m_value.m_Y > sg_game.m_windowInst.m_height + _scale.m_value.m_Y ||
        _position.m_value.m_Y < 0.0f)
    {
        DeleteEntity(_entity);
    }
}
