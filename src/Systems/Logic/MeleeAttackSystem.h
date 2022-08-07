/******************************************************************************
filename:	UpdateMeleeAttacks.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Contains systems that updates melee attacks.

******************************************************************************/
#pragma once

struct MeleeAttackSystem : xecs::system::instance
{
    // Aliases
    using start_melee_countdown = xecs::event::instance<>;
    using events = std::tuple< start_melee_countdown >;

    constexpr static auto typedef_v = xecs::system::type::update
    {
        .m_pName = "MeleeAttackSystem"
    };

    MeleeAttackSystem(xecs::game_mgr::instance& _inst)
        : xecs::system::instance{ _inst }
    { };

    void operator()(
        xecs::component::entity& _entity, MeleeAttack& _meleeAttack,
        Timer& _timer, Position& _entPos, Rotation& _entRot);

private:
    static constexpr float m_attackInterval = 0.2f;
};
