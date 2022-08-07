/******************************************************************************
filename:	OnMouseMoved.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Defines an event that is published when a mouse button is down.

******************************************************************************/
#pragma once

struct OnMouseMoved : xecs::event::instance<const xcore::vector2&>
{
    constexpr static auto typedef_v = xecs::event::type::global
    {
        .m_pName = "OnMouseMoved"
    };
};
