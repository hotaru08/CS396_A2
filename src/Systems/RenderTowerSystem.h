/******************************************************************************
filename:	RenderingTowerSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Base rendering system that other renderers inherit from.

******************************************************************************/
#pragma once

struct RenderingTowerSystem :xecs::system::instance
{
    constexpr static auto typedef_v = xecs::system::type::child_update<renderer, renderer::update>
    {
        .m_pName = "RenderingTowerSystem"
    };

    //using query = std::tuple
    //<
    //    xecs::query::must_have<TowerEntity>
    //>;

    void OnPreUpdate(void) noexcept
    {
        glBegin(GL_QUADS);
    }

    void OnPostUpdate(void) noexcept
    {
        glEnd();
    }

    // Update
    __inline void operator()(const position& Position, const timer* pTimer) const noexcept
    {
        constexpr auto Size = 3;
        pTimer ? glColor3f(1.0, 1.0, 1.0) : glColor3f(0.5, 1.0, 0.5);

        glVertex2i(Position.m_Value.m_X - Size, Position.m_Value.m_Y - Size);
        glVertex2i(Position.m_Value.m_X - Size, Position.m_Value.m_Y + Size);
        glVertex2i(Position.m_Value.m_X + Size, Position.m_Value.m_Y + Size);
        glVertex2i(Position.m_Value.m_X + Size, Position.m_Value.m_Y - Size);
    }
};