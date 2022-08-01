/******************************************************************************
filename:	Window.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Defines a window instance

******************************************************************************/
#pragma once

struct Window
{
    // Window data members
    std::int32_t   m_width  = 1024;
    std::int32_t   m_height = 800;
    std::int32_t   m_posX   = 0;
    std::int32_t   m_posY   = 0;

    // Inputs
    Input m_inputs;

    // Text
    TextRenderer m_textRenderer;
};
