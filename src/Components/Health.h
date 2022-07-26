/******************************************************************************
filename:	Health.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Data regarding health.

******************************************************************************/
#pragma once

struct Health
{
    constexpr static auto typedef_v = xecs::component::type::data
    {
        .m_pName = "Health"
    };

    xcore::err Serialize(xecs::serializer::stream& TextFile, bool) noexcept
    {
        TextFile.Field("Value", m_value).clear();
        return{};
    }

    float m_value;
};

struct HealthBar
{
    constexpr static auto typedef_v = xecs::component::type::data
    {
        .m_pName = "HealthBar"
    };

    xcore::err Serialize(xecs::serializer::stream& TextFile, bool) noexcept
    {
        TextFile.Field("Value", m_value).clear();
        return{};
    }

    xecs::component::entity m_value;
};
