/******************************************************************************
filename:	RenderPlayerSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System for rendering player entities.

******************************************************************************/
#pragma once

struct RenderPlayerSystem : xecs::system::instance
{
    constexpr static auto typedef_v =
    xecs::system::type::child_update<RenderingSystem, RenderingSystem::update>
    {
        .m_pName = "RenderPlayerSystem"
    };

    using query = std::tuple
    <
        xecs::query::must<PlayerTag>
    >;

    void OnPreUpdate(void) noexcept
    {
        glBegin(GL_LINE_LOOP);
    }

    void OnPostUpdate(void) noexcept
    {
        glEnd();
    }

    void operator()(const Position& _position, const Scale& _scale) const noexcept
    {
        glColor3f(0.4f, 0.255f, 1.0f);


    }
};