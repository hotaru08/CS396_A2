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
    xecs::system::type::child_update<RenderCameraSystem, RenderCameraSystem::update>
    {
        .m_pName = "RenderPlayerSystem"
    };

    using query = std::tuple
    <
        xecs::query::must<Player>
    >;

    void operator()(const Position& _position, const Rotation& _rotation, const Scale& _scale) const noexcept
    {
        glColor3f(0.4f, 0.255f, 1.0f);

        // Apply Transformation Matrix to circle
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glTranslatef(_position.m_value.m_X, _position.m_value.m_Y, 0.0f);
        glRotatef(_rotation.m_value, 0.0f, 0.0f, -1.0f);
        glScalef(_scale.m_value.m_X, _scale.m_value.m_Y, 0.0f);

        // Render a Circle
        glBegin(GL_TRIANGLE_FAN);
        unsigned slices = 16;
        auto degSlice = xcore::math::PI2.m_Value / slices;

        glVertex2f(0.0f, 0.0f);
        for (unsigned slice = 0; slice < slices; ++slice)
        {
            glVertex2f
            (
                std::cosf(slice * degSlice),
                std::sinf(slice * degSlice)
            );
        }
        glVertex2f(1.0f, 0.0f);
        glEnd();

        glPopMatrix();
    }
};
