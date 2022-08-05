/******************************************************************************
filename:	RenderSpatialGridSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System for rendering grids used for spatial partitioning.

******************************************************************************/
#pragma once

struct RenderSpatialGridSystem : xecs::system::instance
{
    constexpr static auto typedef_v =
    xecs::system::type::child_update<RenderCameraSystem, RenderCameraSystem::update>
    {
        .m_pName = "RenderSpatialGrids"
    };

    using query = std::tuple
    <
        xecs::query::must<xecs::component::share_as_data_exclusive_tag>
    >;

    void operator()(const GridCell& _gridCell, const xecs::component::share_filter& _shareFilter) noexcept
    {
        // Hide nodes where there are not entities
        //if constexpr (false)
        {
            int nEntities = 0;
            for (auto& ArchetypeCell : _shareFilter.m_lEntries)
                for (auto& Family : ArchetypeCell.m_lFamilies)
                    nEntities += static_cast<int>(Family->m_DefaultPool.Size());
            if (nEntities == 0) return;
        }

        const float X = ((_gridCell.m_X - 1) + 0.5f + (_gridCell.m_Y & 1) * 0.5f) * grid::cell_width_v;
        const float Y = (_gridCell.m_Y + 0.5f) * grid::cell_height_v;
        constexpr auto SizeX = grid::cell_width_v / 2.0f - 1;
        constexpr auto SizeY = grid::cell_height_v / 2.0f - 1;

        // Render the grid cell
        glBegin(GL_QUADS);
        glColor3f(0.25f, 0.25f, 0.25f);
        glVertex2i(X - SizeX, Y - SizeY);
        glVertex2i(X - SizeX, Y + SizeY);
        glVertex2i(X + SizeX, Y + SizeY);
        glVertex2i(X + SizeX, Y - SizeY);
        glEnd();
    }
};
