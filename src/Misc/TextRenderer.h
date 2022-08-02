/******************************************************************************
filename:	Game.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Defines the data related to a Game instance.

******************************************************************************/
#pragma once

struct Window;
struct TextRenderer
{
    TextRenderer(const Window& _windowInst)
        : m_windowInst { _windowInst }
    { }


private:

    const Window& m_windowInst;
};
