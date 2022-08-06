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

property_begin(Health)
{
    property_var(m_value)
}
property_end()
