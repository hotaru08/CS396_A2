/******************************************************************************
filename:	PlayerAttackAISpawner.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Data relating to a spawner that spawns AI that attacks player.

******************************************************************************/
#pragma once

struct PlayerAttackAISpawner
{
    constexpr static auto typedef_v = xecs::component::type::tag
    {
        .m_pName = "PlayerAttackAISpawner"
    };
};