/******************************************************************************
filename:	RenderHealthSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System for rendering health.

******************************************************************************/
#pragma once

struct RenderHealthSystem : xecs::system::instance
{
    constexpr static auto typedef_v =
    xecs::system::type::child_update<RenderSystem, RenderSystem::update>
    {
        .m_pName = "RenderHealthSystem"
    };

    using query = std::tuple
    <
        xecs::query::must< HealthBar >,
        xecs::query::none_of< Player, Tower >
    >;

    void OnGameStart()
    {
        m_healthQuery.m_Must.AddFromComponents < Health >();
    }

    void operator()(const Position& _position, const Scale& _scale, Color& _color, HealthBar& _bar) const noexcept
    {
        glColor3f(_color.m_value.m_X, _color.m_value.m_Y, _color.m_value.m_Z);

        // Apply Transformation Matrix to circle
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glTranslatef(_position.m_value.m_X, _position.m_value.m_Y, 0.0f);

        Foreach
        (
            Search(m_healthQuery),
            [&](xecs::component::entity& _ent, Health& _health)
            {
                if (_ent != _bar.m_value)
                    return;
                
                glScalef
                (
                    (_health.m_value / Definitions::TOWER_HEALTH) * _scale.m_value.m_X,
                    _scale.m_value.m_Y, 0.0f
                );
            }
        );
        

        // Render a Circle
        glBegin(GL_QUADS);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(0.5f, 0.5f);
        glEnd();

        glPopMatrix();
    }

    xecs::query::instance m_healthQuery;
};
