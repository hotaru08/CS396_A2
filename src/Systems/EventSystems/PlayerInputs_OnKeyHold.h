/******************************************************************************
filename:	PlayerInputs_OnKeyHold.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System that handles any key hold events for player inputs.

******************************************************************************/
#pragma once

struct PlayerInputs_OnKeyHold : xecs::system::instance
{
    constexpr static auto typedef_v =
    xecs::system::type::global_event< OnKeyDown >
    {
        .m_pName = "PlayerInputs_OnKeyDown"
    };

    void OnGameStart()
    {
        m_playerInputQuery.m_Must.AddFromComponents< Player >();
    }

    void OnEvent(const unsigned char _key) noexcept
    {
        // Seach for entities with Player component to update movement state
        Foreach
        (
            Search(m_playerInputQuery),
            [&](Player& _player)
            {
                _player.m_moveStates.reset();

                // Update 
                switch (_key)
                {
                case 'w':
                    _player.m_moveStates[static_cast<std::uint8_t>(Player::MOVE_STATE::UP)] = true;
                    break;
                case 's':
                    _player.m_moveStates[static_cast<std::uint8_t>(Player::MOVE_STATE::DOWN)] = true;
                    break;
                case 'a':
                    _player.m_moveStates[static_cast<std::uint8_t>(Player::MOVE_STATE::LEFT)] = true;
                    break;
                case 'd':
                    _player.m_moveStates[static_cast<std::uint8_t>(Player::MOVE_STATE::RIGHT)] = true;
                    break;
                }
            }
        );
    }

    xecs::query::instance m_playerInputQuery;
};

struct PlayerInputs_OnKeyUp : xecs::system::instance
{
    constexpr static auto typedef_v =
    xecs::system::type::global_event< OnKeyUp >
    {
        .m_pName = "PlayerInputs_OnKeyUp"
    };

    void OnGameStart()
    {
        m_playerInputQuery.m_Must.AddFromComponents< Player >();
    }

    void OnEvent(const unsigned char _key) noexcept
    {
        // Seach for entities with Player component to update movement state
        Foreach
        (
            Search(m_playerInputQuery),
            [&](Player& _player)
            {
                _player.m_moveStates.reset();
                _player.m_moveStates[static_cast<std::uint8_t>(Player::MOVE_STATE::NONE)] = true;
            }
        );
    }

    xecs::query::instance m_playerInputQuery;
};
