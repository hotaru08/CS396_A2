/******************************************************************************
filename:	RenderCameraSystem.hpp
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Base Rendering System that handles the buffer rendering.

******************************************************************************/
#pragma once

void RenderSystem::OnUpdate() noexcept
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);
    glClearColor(0.25f, 0.25f, 0.25f, 1.0f);

    // Call child system to update
    SendEventFrom<update>(this);

    glColor3f(1.0f, 1.0f, 1.0f);
    if (sg_game.m_gameOver)
    {
        Text::PrintText
        (
            sg_game.m_windowInst.m_width / 2 - 50.0f,
            sg_game.m_windowInst.m_height / 2,
            "GAME OVER!"
        );
    }

    Text::PrintText
    (
        15.0f, 15.0f,
        "Elapsed Time: %f", sg_game.m_elapsedTime
    );

    glutSwapBuffers();

    // Setup viewport for rendering camera
    glViewport(0, 0, sg_game.m_windowInst.m_width, sg_game.m_windowInst.m_height);
}

void RenderCameraSystem::OnUpdate() noexcept
{
    // Setup viewport for rendering camera
    glViewport(0, 0, sg_game.m_windowInst.m_width, sg_game.m_windowInst.m_height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, sg_game.m_windowInst.m_width, 0, sg_game.m_windowInst.m_height, -1, 1);
    glScalef(1, -1, 1);
    glTranslatef(0, -sg_game.m_windowInst.m_height, 0);
}
