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
    constexpr static auto typedef_v =
    xecs::system::type::update
    {
        .m_pName = "FireBulletSystem"
    };

    using query = std::tuple
    <
        xecs::query::none_of< Player >
    >;

    void operator()(
        Position& _position, const Direction& _direction,
        const Velocity& _velocity, const FireBullet& _fireBullet) const noexcept
    {
        _position.m_value += !_fireBullet.m_value * _direction.m_value * _velocity.m_value;
    }
};