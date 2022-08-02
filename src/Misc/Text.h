/******************************************************************************
filename:	Text.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Defines functions to render text onto screen.

******************************************************************************/
#pragma once

namespace Text
{
    template < typename... TArgs >
    void PrintText(const int _x, const int _y, const char* const _str, TArgs&&... _args) noexcept;
}