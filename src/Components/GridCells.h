/******************************************************************************
filename:	GridCells.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Data regarding grid cells that are used for spatial partitioning.

******************************************************************************/
#pragma once

struct GridCell
{
    constexpr static auto typedef_v = xecs::component::type::share
    {
        .m_pName = "GridCell"
    ,   .m_bBuildFilter = true
    };

    xcore::err Serialize(xecs::serializer::stream& TextFile, bool) noexcept
    {
        TextFile.Field("X", m_X).clear();
        TextFile.Field("Y", m_Y).clear();
        return {};
    }

    std::int16_t m_X; // col of which cell to render
    std::int16_t m_Y; // row of which cell to render
};

property_begin(GridCell)
{
    property_var(m_X).Flags(property::flags::SHOW_READONLY),
    property_var(m_Y).Flags(property::flags::SHOW_READONLY)
}
property_end()