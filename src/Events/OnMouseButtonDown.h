/******************************************************************************
filename:	OnMouseButtonDown.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Defines an event that is published when a mouse button is down.

******************************************************************************/
#pragma once

struct OnMouseButtonDown : xecs::event::instance<const unsigned char>
{
    constexpr static auto typedef_v = xecs::event::type::global
    {
        .m_pName = "OnMouseButtonDown"
    };
};
