/******************************************************************************
filename:	RenderMeleeAttack.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System for rendering tower entities.

******************************************************************************/
#pragma once

struct RenderMeleeAttack : xecs::system::instance
{
    constexpr static auto typedef_v = 
    xecs::system::type::child_update< RenderSystem, RenderSystem::update >
    {
        .m_pName = "RenderMeleeAttack"
    };

    using query = std::tuple
    <
        xecs::query::must< RenderMelee >
    >;

    void operator()(Position& _position, Rotation& _rotation, Scale& _scale, Color& _color) const noexcept
    {
        glColor3f(_color.m_value.m_X, _color.m_value.m_Y, _color.m_value.m_Z);

        // Apply Transformation Matrix to semi circle
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glTranslatef(_position.m_value.m_X, _position.m_value.m_Y, 0.0f);
        glRotatef(_rotation.m_value, 0.0f, 0.0f, -1.0f);
        glScalef(_scale.m_value.m_X, _scale.m_value.m_Y, 0.0f);

        // Render a Circle
        glBegin(GL_TRIANGLE_FAN);
        unsigned slices = 4;
        auto degSlice = xcore::math::PI.m_Value / slices;

        glVertex2f(0.0f, 0.0f);
        for (unsigned slice = 0; slice <= slices; ++slice)
        {
            glVertex2f
            (
                std::cosf(slice * degSlice),
                -std::sinf(slice * degSlice)
            );
        }
        glVertex2f(0.0f, 0.0f);
        glEnd();

        glPopMatrix();
    }
};
