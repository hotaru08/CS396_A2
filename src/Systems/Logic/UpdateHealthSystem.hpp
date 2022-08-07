/******************************************************************************
filename:	UpdateHealthSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System that handles turrent shooting logic.

******************************************************************************/
#pragma once

void UpdateHealthSystem::operator()(xecs::component::entity& _ent, Health& _health) noexcept
{
    if (_health.m_value <= 0.0f)
    {
        sg_game.m_gameOver = true;
        DeleteEntity(_ent);
    }
}
