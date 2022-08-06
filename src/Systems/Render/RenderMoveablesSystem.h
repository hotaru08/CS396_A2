/******************************************************************************
filename:	RenderMoveablesSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System for rendering entities that can move.

******************************************************************************/
#pragma once

struct RenderMoveablesSystem : xecs::system::instance
{
    constexpr static auto typedef_v =
    xecs::system::type::child_update<RenderCameraSystem, RenderCameraSystem::update>
    {
        .m_pName = "RenderMoveablesSystem"
    };

    using query = std::tuple
    <
        xecs::query::one_of<Player>,
        xecs::query::one_of<Target>,

        xecs::query::none_of<Bullet>
    >;

    void operator()(const Position& _position, const Rotation& _rotation, const Scale& _scale, const Color& _color, Target* _target) const noexcept
    {
        glColor3f(_color.m_value.m_X, _color.m_value.m_Y, _color.m_value.m_Z);

        // Apply Transformation Matrix to quad
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glTranslatef(_position.m_value.m_X, _position.m_value.m_Y, 0.0f);
        glRotatef(_rotation.m_value, 0.0f, 0.0f, -1.0f);
        glScalef(_scale.m_value.m_X, _scale.m_value.m_Y, 0.0f);

        // Render a cursor shape
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.25f, 0.0f);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(0.5f, 0.0f);
        glEnd();

        glPopMatrix();
    }
};
