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
#include <cmath>
#include <chrono>

#define GLUT_STATIC_LIB
#include <GL\glut.h>

// Misc ----------------------------------------------------------------------
#include <Misc\Inputs.h>
#include <Misc\Text.h>
#include <Misc\Window.h>

// ECS ----------------------------------------------------------------------
#include <Events\Events.h>
#include <Components\Components.h>

#include <Misc\Grid.h>
#include <Systems\Systems.h>

// Game ----------------------------------------------------------------------
#include <Misc\Game.h>
