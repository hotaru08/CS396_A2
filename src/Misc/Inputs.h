#pragma once

struct Keys
{
    enum class KEY_STATE : std::uint8_t
    {
        HOLD        = (1 << 0), 
        RELEASED    = (1 << 1),
        TRIGGERED   = (1 << 2)
    };
    std::array<std::uint8_t, 0xff + 1> m_keys;

    void SetKeyState(char x, bool OnOff) noexcept
    {
        auto& key = m_keys[static_cast<std::uint8_t>(x)];

        if (OnOff)
        {
            if (!(key & static_cast<std::uint8_t>(KEY_STATE::HOLD)))
            {
                key |= (static_cast<std::uint8_t>(KEY_STATE::HOLD) | static_cast<std::uint8_t>(KEY_STATE::TRIGGERED));
            }
        }
        else
        {
            if (key & static_cast<std::uint8_t>(KEY_STATE::HOLD))
            {
                key &= ~(static_cast<std::uint8_t>(KEY_STATE::HOLD) | static_cast<std::uint8_t>(KEY_STATE::TRIGGERED));
                key |= static_cast<std::uint8_t>(KEY_STATE::RELEASED);
            }
        }
    }

    bool GetKeyUp(char x) noexcept
    {
        return (m_keys[static_cast<std::uint8_t>(x)] & static_cast<std::uint8_t>(KEY_STATE::RELEASED));
    }

    bool GetKeyDown(char x) noexcept
    {
        return (m_keys[static_cast<std::uint8_t>(x)] & static_cast<std::uint8_t>(KEY_STATE::TRIGGERED));
    }

    //bool getKey(char x) noexcept
    //{
    //    return (m_keys[static_cast<std::uint8_t>(x)] & static_cast<std::uint8_t>(KEY_STATE::HOLD));
    //}

    void Poll() noexcept
    {
        for (auto& K : m_keys)
        {
            K = K & (~(static_cast<std::uint8_t>(KEY_STATE::RELEASED) | static_cast<std::uint8_t>(KEY_STATE::TRIGGERED)));
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