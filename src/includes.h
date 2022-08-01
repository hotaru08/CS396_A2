/******************************************************************************
filename:	includes.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Header including other files.

******************************************************************************/
#pragma once

// STL libraries -------------------------------------------------------------
#include <xecs.h>
#include <limits>
#include <random>
#include <bitset>
#include <iostream>
#include <cstdint>
#include <tuple>

#define GLUT_STATIC_LIB
#include <GL\glut.h>

// Misc ----------------------------------------------------------------------
#include <Misc\Inputs.h>
#include <Misc\Window.h>

// ECS ----------------------------------------------------------------------
#include <Events\OnKeyHold.h>
#include <Events\OnKeyDown.h>
#include <Events\OnKeyUp.h>

#include <Components\Components.h>

#include <Tags\PlayerTag.h>

#include <Misc\Grid.h>
#include <Systems\Systems.h>

// Game ----------------------------------------------------------------------
#include <Misc\Game.h>