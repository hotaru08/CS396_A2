/******************************************************************************
filename:	RenderTowerSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System for rendering tower entities.

******************************************************************************/
#pragma once

struct RenderTowerSystem : xecs::system::instance
{
    constexpr static auto typedef_v = xecs::system::type::child_update<RenderingSystem, RenderingSystem::update>
    {
        .m_pName = "RenderTowers"
    };

    //using query = std::tuple
    //<
    //    xecs::query::one_of<entity>
    //>;

    void OnPreUpdate(void) noexcept
    {
        glBegin(GL_QUADS);
    }

    void OnPostUpdate(void) noexcept
    {
        glEnd();
    }

    void operator()(const Position& _position, const Scale& _scale) const noexcept
    {
        glColor3f(0.5f, 1.0f, 0.5f);

        glVertex2i(_position.m_value.m_X - _scale.m_value.m_X, _position.m_value.m_Y - _scale.m_value.m_Y);
        glVertex2i(_position.m_value.m_X - _scale.m_value.m_X, _position.m_value.m_Y + _scale.m_value.m_Y);
        glVertex2i(_position.m_value.m_X + _scale.m_value.m_X, _position.m_value.m_Y + _scale.m_value.m_Y);
        glVertex2i(_position.m_value.m_X + _scale.m_value.m_X, _position.m_value.m_Y - _scale.m_value.m_Y);
    }
};