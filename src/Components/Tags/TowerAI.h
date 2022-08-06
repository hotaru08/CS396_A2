/******************************************************************************
filename:	TowerAI.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Data relating to an AI that targets tower.

******************************************************************************/
#pragma once

struct TowerAI
{
    constexpr static auto typedef_v = xecs::component::type::tag
    {
        .m_pName = "TowerAI"
    };
};
