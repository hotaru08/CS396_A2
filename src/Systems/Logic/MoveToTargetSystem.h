/******************************************************************************
filename:	MoveToTargetSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System that handles moving of entities towards a target position.

******************************************************************************/
#pragma once

struct MoveToTargetSystem : xecs::system::instance
{
    constexpr static auto typedef_v = xecs::system::type::system_event<
    {
        .m_pName = "MoveToTargetSystem"
    };

    void operator()(Position& _position, Target& _target, Velocity& _velocity)
    {
        xcore::vector2 dir = _target.m_target - _position.m_value
    }
};
