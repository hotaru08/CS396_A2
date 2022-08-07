/******************************************************************************
filename:	SpawnTowerAISystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System that spawns AIs, timing varies, AI spawn varies.

******************************************************************************/
#pragma once

struct SpawnAISystem : xecs::system::instance
{
    constexpr static auto typedef_v = xecs::system::type::update
    {
        .m_pName = "SpawnAISystem"
    };

    SpawnAISystem(xecs::game_mgr::instance& _inst)
        : xecs::system::instance{ _inst }
    { };

    void OnGameStart()
    {
        m_towerQuery.m_Must.AddFromComponents< Tower >();
    }

    // For both spawners in scene, once the timer for each is countdown, can spawn
    void operator()(Timer& _timer, Spawner& _spawner) noexcept;

private:
    static constexpr float m_spawnInterval = 0.5f;
    xecs::query::instance m_towerQuery;
};
