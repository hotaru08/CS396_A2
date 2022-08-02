/******************************************************************************
filename:	OnKeyhold.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Defines an event that is published when a key is on hold.

******************************************************************************/
#pragma once

struct OnKeyHold : xecs::event::instance<const unsigned char>
{
    constexpr static auto typedef_v = xecs::event::type::global
    {
        .m_pName = "OnKeyHold"
    };
};
