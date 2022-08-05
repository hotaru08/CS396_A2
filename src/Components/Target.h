/******************************************************************************
filename:	Target.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Data regarding target, where entities will travel to.

******************************************************************************/
#pragma once

struct Target
{
    constexpr static auto typedef_v = xecs::component::type::data
    {
        .m_pName = "Target"
    };

    xcore::err Serialize(xecs::serializer::stream& TextFile, bool) noexcept
    {
        TextFile.Field("Target", m_target).clear();
        return{};
    }

    xecs::component::entity m_target; //<! Target entity that current entity is going for
};

property_begin(Target)
{
    property_var(m_target)
}
property_end()
