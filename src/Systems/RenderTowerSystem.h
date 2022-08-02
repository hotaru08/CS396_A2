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
    constexpr static auto typedef_v = 
    xecs::system::type::child_update<RenderCameraSystem, RenderCameraSystem::update>
    {
        .m_pName = "RenderTowersSystem"
    };

    using query = std::tuple
    <
        xecs::query::none_of< Player >
    >;

    void operator()(const Position& _position, const Scale& _scale) const noexcept
    {
        glColor3f(0.5f, 1.0f, 0.5f);

        // Apply Transformation Matrix to quad
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glTranslatef(_position.m_value.m_X, _position.m_value.m_Y, 0.0f);
        glRotatef(0.0f, 0.0f, 0.0f, -1.0f);
        glScalef(_scale.m_value.m_X, _scale.m_value.m_Y, 0.0f);

        // Render a quad
        glBegin(GL_QUADS);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.5f, 0.5f);
        glEnd();

        glPopMatrix();
    }
};
