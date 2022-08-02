/******************************************************************************
filename:	PlayerUpdateLogic.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System that handles player update logic.

******************************************************************************/
#pragma once

struct PlayerUpdateLogicSystem : xecs::system::instance
{
    constexpr static auto typedef_v = xecs::system::type::update
    {
        .m_pName = "PlayerUpdateLogicSystem"
    };

    //void OnGameStart()
    //{
    //    m_playerInputQuery.m_Must.AddFromComponents< Player >();
    //}

    void operator()(Player& _player, Velocity& _velocity, Position& _position)
    {
        if (_player.m_moveStates[static_cast<std::uint8_t>(Player::MOVE_STATE::UP)])
        {
            _velocity.m_value.m_Y = -10.0f;
        }
        else if (_player.m_moveStates[static_cast<std::uint8_t>(Player::MOVE_STATE::DOWN)])
        {
            _velocity.m_value.m_Y = 10.0f;
        }
        else if (_player.m_moveStates[static_cast<std::uint8_t>(Player::MOVE_STATE::LEFT)])
        {
            _velocity.m_value.m_X = -10.0f;
        }
        else if (_player.m_moveStates[static_cast<std::uint8_t>(Player::MOVE_STATE::RIGHT)])
        {
            _velocity.m_value.m_X = 10.0f;
        }
        else if (_player.m_moveStates[static_cast<std::uint8_t>(Player::MOVE_STATE::NONE)])
        {
            _velocity.m_value = xcore::vector2{ 0.0f, 0.0f };
        }

        _position.m_value += _velocity.m_value;
    }


    //void OnEvent(const unsigned char _key) noexcept
    //{
    //    // Seach for entities with Player component to update movement state
    //    Foreach
    //    (
    //        Search(m_playerInputQuery),
    //        [&](Player& _player)
    //        {
    //            // Update 
    //            switch (_key)
    //            {
    //            case 'w':
    //                _player.m_moveStates[static_cast<std::uint8_t>(Player::MOVE_STATE::UP)] = true;
    //                break;
    //            case 's':
    //                _player.m_moveStates[static_cast<std::uint8_t>(Player::MOVE_STATE::DOWN)] = true;
    //                break;
    //            case 'a':
    //                _player.m_moveStates[static_cast<std::uint8_t>(Player::MOVE_STATE::LEFT)] = true;
    //                break;
    //            case 'd':
    //                _player.m_moveStates[static_cast<std::uint8_t>(Player::MOVE_STATE::RIGHT)] = true;
    //                break;
    //            }
    //        }
    //    );
    //}

    //xecs::query::instance m_playerInputQuery;
};
