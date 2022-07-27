/******************************************************************************
filename:	RenderingTowerSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Rendering System that renders Tower Entities.

******************************************************************************/
#pragma once

struct RenderTowerSystem : xecs::system::instance
{
    constexpr static auto typedef_v = 
        xecs::system::type::child_update<RenderingSystem, RenderingSystem::update>
    {
        .m_pName = "RenderingTowerSystem"
    };

    void OnPreUpdate() noexcept
    {
        glBegin(GL_QUADS);
    }

    void OnPostUpdate() noexcept
    {
        glEnd();
    }

    // Update
    void operator()(const entity& _entity, const Position& _position, const Timer* _timer) const noexcept
    {
        std::cout << "enter here " << _position.m_value.m_X << " / " << _position.m_value.m_Y << std::endl;
        constexpr auto Size = 3;
       
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(_position.m_value.m_X - Size, _position.m_value.m_Y - Size);
        glVertex2i(_position.m_value.m_X - Size, _position.m_value.m_Y + Size);
        glVertex2i(_position.m_value.m_X + Size, _position.m_value.m_Y + Size);
        glVertex2i(_position.m_value.m_X + Size, _position.m_value.m_Y - Size);
    }
};