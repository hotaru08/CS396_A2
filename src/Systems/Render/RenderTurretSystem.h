/******************************************************************************
filename:	RenderTurrentSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System for rendering turrents entities.

******************************************************************************/
#pragma once

struct RenderTurretSystem : xecs::system::instance
{
    constexpr static auto typedef_v =
    xecs::system::type::child_update<RenderSystem, RenderSystem::update>
    {
        .m_pName = "RenderTurrentSystem"
    };

    using query = std::tuple
    <
        xecs::query::none_of< Player >
    >;

    void operator()(
        const Position& _position, const Rotation& _rotation,
        const Scale& _scale, const FireBullet& _fireBullet,
        const Color& _color) const noexcept
    {
        glColor3f(_color.m_value.m_X, _color.m_value.m_Y, _color.m_value.m_Z);

        // Apply Transformation Matrix to quad
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glTranslatef(_position.m_value.m_X, _position.m_value.m_Y, 0.0f);
        glRotatef(_rotation.m_value, 0.0f, 0.0f, -1.0f);
        glScalef(_scale.m_value.m_X, _scale.m_value.m_Y, 0.0f);

        // Render a quad
        glBegin(GL_TRIANGLES);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.5f, 0.5f);
        glEnd();

        glPopMatrix();
    }
};
