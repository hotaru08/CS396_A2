/******************************************************************************
filename:	OnKeyDown.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Defines an event that is published when a key is down.

******************************************************************************/
#pragma once

struct OnKeyDown : xecs::event::instance<const unsigned char>
{
    constexpr static auto typedef_v = xecs::event::type::global
    {
        .m_pName = "OnKeyDown"
    };
};
