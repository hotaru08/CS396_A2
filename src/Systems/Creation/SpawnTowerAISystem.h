/******************************************************************************
filename:	SpawnTowerAISystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System that handles spawning of tower at specified period of random timings.

******************************************************************************/
#pragma once

struct SpawnTowerAISystem : xecs::system::instance
{
    // Aliases
    using update = xecs::event::instance<>;
    using events = std::tuple< update >;

    using query = std::tuple
    <
        xecs::query::must< Target >,
        xecs::query::one_of< TowerAI >,
        xecs::query::one_of< BomberAI >
    >;

    SpawnTowerAISystem(xecs::game_mgr::instance& _inst)
        : xecs::system::instance{ _inst }
    { };
    
    constexpr static auto typedef_v = xecs::system::type::update
    {
        .m_pName = "SpawnTowerAISystem"
    };

    void OnUpdate() noexcept
    {

    }

private:

};
