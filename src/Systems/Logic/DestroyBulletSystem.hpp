/******************************************************************************
filename:	DestroyBulletSystem.hpp
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System for destroying bullets when to destroy.

******************************************************************************/
#pragma once

void DestroyBulletSystem::OnUpdate() noexcept
{
    for (std::int16_t Y = 0; Y < grid::cell_y_count; ++Y)
    {
        for (std::int16_t X = 0; X < grid::cell_x_count; ++X)
        {
            auto pShareFilter = findShareFilter(GridCell{ .m_X = X, .m_Y = Y });
            if (pShareFilter == nullptr) continue;

            Foreach
            (
                *pShareFilter, m_enemyQuery,
                [&](xecs::component::entity& _enemyEnt, const Position& _position, Scale& _scale) constexpr noexcept
                {
                    // If I am dead because some other bullet killed me then there is nothing for me to do...
                    if (_enemyEnt.isZombie()) return;

                    grid::Search
                    (
                        *this, *pShareFilter, X, Y, m_bulletAndMeleeQuery,
                        [&](xecs::component::entity& _ent, const Position& _otherPos, Scale& _otherScale)  constexpr noexcept
                        {
                            if (_ent.isZombie()) return false;

                            const auto enemyDist = _scale.m_value.getLengthSquared() * 0.5f;
                            const auto playerDist = _otherScale.m_value.getLengthSquared() * 0.5f;
                            if ((_otherPos.m_value - _position.m_value).getLengthSquared() < enemyDist + playerDist)
                            {
                                DeleteEntity(_enemyEnt);
                                DeleteEntity(_ent);
                                return true;
                            }

                            return false;
                        }
                    );
                }
            );
        }
    }
}