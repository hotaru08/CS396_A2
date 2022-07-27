#pragma once

struct Keys
{
    enum class type : std::uint8_t
    {
        IS = (1 << 0),
        UP = (1 << 1),
        DOWN = (1 << 2)
    };

    using keys_array = std::array<std::uint8_t, 0xff + 1>;
    keys_array m_keys;

    void setKeyState(char x, bool OnOff) noexcept
    {
        std::uint8_t& Key = m_keys[static_cast<std::uint8_t>(x)];

        if (OnOff)
        {
            if (!(Key & static_cast<std::uint8_t>(type::IS)))
            {
                Key |= (static_cast<std::uint8_t>(type::IS) | static_cast<std::uint8_t>(type::DOWN));
            }
        }
        else
        {
            if (Key & static_cast<std::uint8_t>(type::IS))
            {
                Key &= ~(static_cast<std::uint8_t>(type::IS) | static_cast<std::uint8_t>(type::DOWN));
                Key |= static_cast<std::uint8_t>(type::UP);
            }
        }
    }

    bool getKeyUp(char x) noexcept
    {
        return m_keys[static_cast<std::uint8_t>(x)] & static_cast<std::uint8_t>(type::UP);
    }

    bool getKeyDown(char x) noexcept
    {
        return m_keys[static_cast<std::uint8_t>(x)] & static_cast<std::uint8_t>(type::DOWN);
    }

    bool getKey(char x) noexcept
    {
        return m_keys[static_cast<std::uint8_t>(x)] & static_cast<std::uint8_t>(type::IS);
    }

    void FrameUpdate(void) noexcept
    {
        for (auto& K : m_keys)
        {
            K = K & (~(static_cast<std::uint8_t>(type::UP) | static_cast<std::uint8_t>(type::DOWN)));
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