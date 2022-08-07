/******************************************************************************
filename:	CollisionSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System that handles turrent shooting logic.

******************************************************************************/
#pragma once

struct CollisionSystem : xecs::system::instance
{
    constexpr static auto typedef_v = xecs::system::type::update
    {
        .m_pName = "CollisionSystem"
    };

    void OnGameStart() noexcept
    {
        m_playerTowerQuery.m_OneOf.AddFromComponents< Player, Tower >();
        m_enemyQuery.m_Must.AddFromComponents< TowerAI >();
    }

    void OnUpdate() noexcept;


    xecs::query::instance m_playerTowerQuery;
    xecs::query::instance m_enemyQuery;
};

struct OutOfBoundsSystem : xecs::system::instance
{
    constexpr static auto typedef_v = xecs::system::type::update
    {
        .m_pName = "OutOfBoundsSystem"
    };

    void operator()(xecs::component::entity& _ent, Position& _position, Scale& _scale) noexcept;
};
