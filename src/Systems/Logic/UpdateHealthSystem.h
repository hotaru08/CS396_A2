/******************************************************************************
filename:	UpdateHealthSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System that handles turrent shooting logic.

******************************************************************************/
#pragma once

struct UpdateHealthSystem : xecs::system::instance
{
    constexpr static auto typedef_v = xecs::system::type::update
    {
        .m_pName = "UpdateHealthSystem"
    };

    void operator()(xecs::component::entity& _ent, Health& _health) noexcept;
};
