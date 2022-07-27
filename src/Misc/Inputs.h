#pragma once

struct Keys
{
    enum class KEY_TYPE : std::uint8_t
    {
        IS = (1 << 0)
        , UP = (1 << 1)
        , DOWN = (1 << 2)
    };

    using keys_array = std::array<std::uint8_t, 0xff + 1>;
    keys_array         m_keys;

    void setKeyState(char x, bool OnOff) noexcept
    {
        auto& key = m_keys[static_cast<std::uint8_t>(x)];

        if (OnOff)
        {
            if (!(key & static_cast<std::uint8_t>(KEY_TYPE::IS)))
            {
                key |= (static_cast<std::uint8_t>(KEY_TYPE::IS) | static_cast<std::uint8_t>(KEY_TYPE::DOWN));
            }
        }
        else
        {
            if (key & static_cast<std::uint8_t>(KEY_TYPE::IS))
            {
                key &= ~(static_cast<std::uint8_t>(KEY_TYPE::IS) | static_cast<std::uint8_t>(KEY_TYPE::DOWN));
                key |= static_cast<std::uint8_t>(KEY_TYPE::UP);
            }
        }
    }

    bool getKeyUp(char x) noexcept
    {
        return (m_keys[static_cast<std::uint8_t>(x)] & static_cast<std::uint8_t>(KEY_TYPE::UP));
    }

    bool getKeyDown(char x) noexcept
    {
        return (m_keys[static_cast<std::uint8_t>(x)] & static_cast<std::uint8_t>(KEY_TYPE::DOWN));
    }

    bool getKey(char x) noexcept
    {
        return (m_keys[static_cast<std::uint8_t>(x)] & static_cast<std::uint8_t>(KEY_TYPE::IS));
    }

    void Poll() noexcept
    {
        for (auto& K : m_keys)
        {
            K = K & (~(static_cast<std::uint8_t>(KEY_TYPE::UP) | static_cast<std::uint8_t>(KEY_TYPE::DOWN)));
        }
    }
};

struct Input
{
    std::uint32_t   m_mouseX;
    std::uint32_t   m_mouseY;
    bool            m_mouseLeftBtn;
    bool            m_mouseRightBtn;
    Keys            m_keys;
};