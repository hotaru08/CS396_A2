/******************************************************************************
filename:	RenderCameraSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Base Rendering System that handles the buffer rendering.

******************************************************************************/
#pragma once

struct RenderCameraSystem : xecs::system::instance
{
    // Aliases
    using update = xecs::event::instance<>;
    using events = std::tuple< update >;

    constexpr static auto typedef_v = xecs::system::type::update
    {
        .m_pName = "RenderCameraSystem"
    };

    void OnUpdate() noexcept;
};
