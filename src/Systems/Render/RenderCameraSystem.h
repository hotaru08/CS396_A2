/******************************************************************************
filename:	RenderCameraSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Base Rendering System that handles the buffer rendering.

******************************************************************************/
#pragma once

struct RenderSystem : xecs::system::instance
{
    // Aliases
    using update = xecs::event::instance<>;
    using events = std::tuple< update >;

    constexpr static auto typedef_v = xecs::system::type::update
    {
        .m_pName = "RenderSystem"
    };

    void OnUpdate() noexcept;
};

struct RenderCameraSystem : xecs::system::instance
{
    constexpr static auto typedef_v =
    xecs::system::type::child_update<RenderSystem, RenderSystem::update>
    {
        .m_pName = "RenderCameraSystem"
    };

    void OnUpdate() noexcept;
};
