/******************************************************************************
filename:	Player.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Data relating to a player.

******************************************************************************/
#pragma once

struct Player
{
    constexpr static auto typedef_v = xecs::component::type::tag
    {
        .m_pName = "Player"
    };
};