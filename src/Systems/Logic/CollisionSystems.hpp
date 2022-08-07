/******************************************************************************
filename:	CollisionSystem.hpp
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System that handles turrent shooting logic.

******************************************************************************/
#pragma once

void CollisionSystem::OnUpdate() noexcept
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
                        *this, *pShareFilter, X, Y, m_playerTowerQuery,
                        [&](xecs::component::entity& _ent, const Position& _otherPos, Scale& _otherScale, Health& _health)  constexpr noexcept
                        {
                            if (_ent.isZombie()) return false;

                            const auto enemyDist    = _scale.m_value.getLengthSquared()      * 0.5f;
                            const auto playerDist   = _otherScale.m_value.getLengthSquared() * 0.5f;
                            if ((_otherPos.m_value - _position.m_value).getLengthSquared() < enemyDist + playerDist)
                            {
                                _health.m_value -= Definitions::MELEE_ATTACK_DMG;
                                DeleteEntity(_enemyEnt);
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

void OutOfBoundsSystem::operator()(xecs::component::entity& _ent, Position& _position, Scale& _scale) noexcept
{
    if (_ent.isZombie()) return;

    // Check for bullet going out of bounds
    if (_position.m_value.m_X > sg_game.m_windowInst.m_width + _scale.m_value.m_X * 2.0f ||
        _position.m_value.m_X < -_scale.m_value.m_X * 2.0f ||
        _position.m_value.m_Y > sg_game.m_windowInst.m_height + _scale.m_value.m_Y * 2.0f ||
        _position.m_value.m_Y < -_scale.m_value.m_Y * 2.0f)
    {
        DeleteEntity(_ent);
    }
}
