/******************************************************************************
filename:	PlayerUpdateLogic.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System that handles player update logic.

******************************************************************************/
#pragma once

void PlayerMovementSystem::operator()(Position& _position, Scale& _scale, Velocity& _velocity, GridCell& _gridcell) noexcept
{
    if (_position.m_value.m_X < _scale.m_value.m_X)
    {
        _position.m_value.m_X = _scale.m_value.m_X;
    }
    else if (_position.m_value.m_X > sg_game.m_windowInst.m_width - _scale.m_value.m_X)
    {
        _position.m_value.m_X = sg_game.m_windowInst.m_width - _scale.m_value.m_X;
    }

    if (_position.m_value.m_Y < _scale.m_value.m_Y)
    {
        _position.m_value.m_Y = _scale.m_value.m_Y;
    }
    else if (_position.m_value.m_Y > sg_game.m_windowInst.m_height - _scale.m_value.m_Y)
    {
        _position.m_value.m_Y = sg_game.m_windowInst.m_height - _scale.m_value.m_Y;
    }
}
