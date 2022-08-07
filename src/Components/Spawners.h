/******************************************************************************
filename:	Spawners.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Data relating to a spawner that spawns AI that attacks.

******************************************************************************/
#pragma once

struct Spawner
{
    constexpr static auto typedef_v = xecs::component::type::data
    {
        .m_pName = "Spawner"
    };

    xcore::err Serialize(xecs::serializer::stream& TextFile, bool) noexcept
    {
        TextFile.Field("Can Spawn", m_canSpawn).clear();
        return{};
    }
    
    bool m_canSpawn;
};
