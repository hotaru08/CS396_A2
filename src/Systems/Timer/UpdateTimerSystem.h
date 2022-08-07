/******************************************************************************
filename:	UpdateTimerSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System that handles the updating of time in the application.

******************************************************************************/
#pragma once

// Updates Timer by counting down from a specified value
struct UpdateTimerSystem : xecs::system::instance
{
    constexpr static auto typedef_v = xecs::system::type::update
    {
        .m_pName = "UpdateTimerSystem"
    };

    using update = xecs::event::instance< >;
    using events = std::tuple< update >;
    using query = std::tuple
    <
        xecs::query::must<Timer>
    >;

    void OnGameStart() noexcept
    {
        m_timerQuery.AddQueryFromTuple<query>();
    }

    void OnUpdate() noexcept
    {
        Foreach
        (
            Search(m_timerQuery),
            [&](Timer& _timer)
            {
                _timer.m_value -= Definitions::FIXED_DELTA_TIME;
            }
        );

        SendEventFrom<update>(this);
    }

    xecs::query::instance m_timerQuery;
};


// Update Timer countdown for triggering being able to fire
struct UpdateTimerShootingSystem : xecs::system::instance
{
    constexpr static auto typedef_v =
    xecs::system::type::child_update<UpdateTimerSystem, UpdateTimerSystem::update>
    {
        .m_pName = "UpdateTimerShootingSystem"
    };

    using query = std::tuple
    <
        xecs::query::none_of< Player >
    >;

    void operator()(Timer& _timer, FireBullet& _fireBullet) const noexcept
    {
        if (_timer.m_value <= 0.0f)
        {
            _timer.m_value = 0.0f;
            _fireBullet.m_value = true;
        }
    }
};


// Update Timer countdown for triggering the spawning of AI
struct UpdateTimerSpawner : xecs::system::instance
{
    constexpr static auto typedef_v =
    xecs::system::type::child_update<UpdateTimerSystem, UpdateTimerSystem::update>
    {
        .m_pName = "UpdateTimerSpawner"
    };

    void operator()(Timer& _timer, Spawner& _spawner) const noexcept
    {
        if (_timer.m_value <= 0.0f)
        {
            _timer.m_value = 0.0f;
            _spawner.m_canSpawn = true;
        }
    }
};


// Update Timer countdown for rendering melee effect
struct UpdateTimerMeleeAttack : xecs::system::instance
{
    constexpr static auto typedef_v =
    xecs::system::type::child_update<UpdateTimerSystem, UpdateTimerSystem::update>
    {
        .m_pName = "UpdateTimerMeleeAttack"
    };

    using query = std::tuple
    <
        xecs::query::must< RenderMelee >
    >;

    void operator()(xecs::component::entity& _ent, Timer& _timer) const noexcept
    {
        if (_timer.m_value <= 0.0f)
        {
            DeleteEntity(_ent);
        }
    }
};
