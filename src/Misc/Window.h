#pragma once

struct Window
{
    // Window data members
    std::uint32_t   m_width = 1024;
    std::uint32_t   m_height = 800;
    std::uint32_t   m_posX = 0;
    std::uint32_t   m_posY = 0;

    // Inputs
    Input m_inputs;
};
