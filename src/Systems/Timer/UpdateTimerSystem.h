/******************************************************************************
filename:	UpdateTimerSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System that handles the updating of time in the application.

******************************************************************************/
#pragma once

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
                _timer.m_value -= 0.01f;
            }
        );

        SendEventFrom<update>(this);
    }

    xecs::query::instance m_timerQuery;
};

struct UpdateTimerShootingSystem : xecs::system::instance
{
    constexpr static auto typedef_v =
    xecs::system::type::child_update<UpdateTimerSystem, UpdateTimerSystem::update>
    {
        .m_pName = "ShootingSystem"
    };

    void operator()(Timer& _timer, FireBullet& _fireBullet) const noexcept
    {
        if (_timer.m_value <= 0.0f)
        {
            _timer.m_value = 0.0f;
            _fireBullet.m_value = true;
        }
    }
};
