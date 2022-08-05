/******************************************************************************
filename:	DestroyBulletSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System for destroying bullets when to destroy.

******************************************************************************/
#pragma once

struct DestroyBulletSystem : xecs::system::instance
{
    constexpr static auto typedef_v = xecs::system::type::update
    {
        .m_pName = "DestroyBulletSystem"
    };

    using query = std::tuple
    <
        xecs::query::must< Bullet >
    >;

    void operator()(xecs::component::entity& _entity, const Position& _position, const Scale& _scale) noexcept;
};