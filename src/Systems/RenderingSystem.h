/******************************************************************************
filename:	RenderingSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Base rendering system that other renderers inherit from.

******************************************************************************/
#pragma once

struct RenderingSystem : xecs::system::instance
{
    // Aliases
    using update = xecs::event::instance<>;
    using events = std::tuple< update >;

    // Data Members
    inline static Window* m_windowPtr = nullptr;

    constexpr static auto typedef_v = xecs::system::type::update
    {
        .m_pName = "RenderingSystem"
    };

    void OnPreUpdate(void) noexcept
    {

    }

    void OnPostUpdate(void) noexcept
    {
        // Send an event to update all child updates that refers to this system
        SendEventFrom<update>(this);
        glutSwapBuffers();
    }

    void OnUpdate(void) noexcept
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glDisable(GL_DEPTH_TEST);
        glClearColor(0.0f, 1.0f, 1.0f, 1.0f);

        glViewport(0, 0, m_windowPtr->m_width, m_windowPtr->m_height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, m_windowPtr->m_width, 0, m_windowPtr->m_height, -1, 1);
        glScalef(1, -1, 1);
        glTranslatef(0, -m_windowPtr->m_height, 0);
    }
};
