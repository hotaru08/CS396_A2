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

struct TurretShootingSystem : xecs::system::instance
{
    constexpr static auto typedef_v =
    xecs::system::type::update
    {
        .m_pName = "TurretShootingSystem"
    };

    TurretShootingSystem(xecs::game_mgr::instance& _inst)
        : xecs::system::instance{ _inst }
    { 
        void;
    };

    void OnGameStart()
    {
        // Create Player Prefab
        m_bulletGUID =
        CreatePrefab<Bullet, Position, Scale, GridCell, Direction, Velocity>
        (
            [&](Scale& _scale, Velocity& _velocity) noexcept
            {
                _scale.m_value     = xcore::vector2{ 5.0f, 5.0f };
                _velocity.m_value  = xcore::vector2{ 10.0f, 10.0f };
            }
        );
    }

    void operator()(
        xecs::component::entity& _entity, FireBullet& _fireBullet,
        Timer& _timer, Bullet& _bullet, Position& _turrentPos)
    {
        if (_fireBullet.m_value)
        {
            // Create bullet instance to fire
            CreatePrefabInstance
            (
                1, m_bulletGUID,
                [&](Position& _position, GridCell& _cell, Bullet& _bullet) noexcept
                {
                    _bullet.m_owner = _entity;
                    _position.m_value = xcore::vector2{ _turrentPos.m_value.m_X, _turrentPos.m_value.m_Y };
                    _cell = grid::ComputeGridCellFromWorldPosition(_position.m_value);
                }
            );

            // Reset timer and other states
            _fireBullet.m_value = false;
            _timer.m_value = 3.0f;
        }
    }

private:
    xecs::prefab::guid m_bulletGUID;
};
