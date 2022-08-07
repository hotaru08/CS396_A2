/******************************************************************************
filename:	MoveToTargetSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System that handles moving of entities towards a target position.

******************************************************************************/
#pragma once

struct RotateToTargetSystem : xecs::system::instance
{
    constexpr static auto typedef_v = xecs::system::type::update
    {
        .m_pName = "RotateToTargetSystem"
    };

    void OnGameStart() noexcept
    {
        m_turretQuery.m_Must.AddFromComponents< FireBullet >();
        m_turretQuery.m_NoneOf.AddFromComponents< Player >();

        m_enemyQuery.m_Must.AddFromComponents< TowerAI >();
    }

    void OnUpdate() noexcept
    {
        for (std::int16_t Y = 0; Y < grid::cell_y_count; ++Y)
        {
            for (std::int16_t X = 0; X < grid::cell_x_count; ++X)
            {
                auto pShareFilter = findShareFilter(GridCell{ .m_X = X, .m_Y = Y });
                if (pShareFilter == nullptr) continue;

                Foreach
                (
                    *pShareFilter, m_turretQuery,
                    [&](Target& _target) constexpr noexcept
                    {
                        grid::Search
                        (
                            *this, *pShareFilter, X, Y, m_enemyQuery,
                            [&](xecs::component::entity& _enemyEnt, const Position& _position)  constexpr noexcept
                            {
                                if (_enemyEnt.isZombie())
                                    return false;

                                _target.m_value = _position.m_value;
                                return false;
                            }
                        );
                    }
                );
            }
        }
    }

    xecs::query::instance m_enemyQuery;
    xecs::query::instance m_turretQuery;
};
