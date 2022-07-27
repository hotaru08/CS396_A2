/******************************************************************************
filename:	main.cpp
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Entry point of application.

******************************************************************************/
#include <includes.h>

void InitializeGame() noexcept
{
    sg_game.m_gameMgr->getOrCreateArchetype< Position, Velocity, Timer >()
        .CreateEntities(1, 
            [&](Position& position, Velocity& velocity, Timer& timer) noexcept
            {
                position.m_value = xcore::vector2{ static_cast<float>(std::rand() % sg_game.m_windowInst.m_width)
                                                     , static_cast<float>(std::rand() % sg_game.m_windowInst.m_height)
                };

                //Cell = grid::ComputeGridCellFromWorldPosition(Position.m_Value);

                velocity.m_value.m_X = std::rand() / static_cast<float>(RAND_MAX) - 0.5f;
                velocity.m_value.m_Y = std::rand() / static_cast<float>(RAND_MAX) - 0.5f;
                velocity.m_value.Normalize();

                timer.m_value = std::rand() / static_cast<float>(RAND_MAX) * 8;
            });
}

void RefreshUpdate(int value) noexcept
{
    // Post re-paint request to activate display()
    glutPostRedisplay();

    // next timer call milliseconds later
    glutTimerFunc(15, RefreshUpdate, 0);
}

int main(int argc, char** argv)
{
    sg_game.Initialize();
    InitializeGame();

    {
        glutInitWindowSize(sg_game.m_windowInst.m_width, sg_game.m_windowInst.m_height);
        glutInitWindowPosition(sg_game.m_windowInst.m_posX, sg_game.m_windowInst.m_posY);

        glutInit(&argc, argv);
        glutCreateWindow(xcore::get().m_pAppName);

        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
        glutReshapeFunc
        (
            [](int w, int h) noexcept
            {
                sg_game.m_windowInst.m_width = w;
                sg_game.m_windowInst.m_height = h;
            }
        );
        glutDisplayFunc
        (
            []()
            {
                sg_game.m_gameMgr->Run();
                sg_game.m_windowInst.m_inputs.m_keys.Poll();
            }
        );
        glutTimerFunc(0, RefreshUpdate, 0);

        glutKeyboardFunc([](unsigned char Key, int MouseX, int MouseY) noexcept
        {
            sg_game.m_windowInst.m_inputs.m_keys.setKeyState(Key, true);
            sg_game.m_windowInst.m_inputs.m_mouseX = MouseX;
            sg_game.m_windowInst.m_inputs.m_mouseY = MouseY;
        });
        glutKeyboardUpFunc([](unsigned char Key, int MouseX, int MouseY) noexcept
        {
            sg_game.m_windowInst.m_inputs.m_keys.setKeyState(Key, false);
            sg_game.m_windowInst.m_inputs.m_mouseX = MouseX;
            sg_game.m_windowInst.m_inputs.m_mouseY = MouseY;
        });
        glutMouseFunc([](int Button, int State, int MouseX, int MouseY) noexcept
        {
            sg_game.m_windowInst.m_inputs.m_mouseX = MouseX;
            sg_game.m_windowInst.m_inputs.m_mouseY = MouseY;

            if (Button == GLUT_LEFT_BUTTON)
                sg_game.m_windowInst.m_inputs.m_mouseLeftBtn = (State == GLUT_DOWN);
            else if (Button == GLUT_RIGHT_BUTTON)
                sg_game.m_windowInst.m_inputs.m_mouseRightBtn = (State == GLUT_DOWN);
        });

        glutMainLoop();
    }

    sg_game.CleanUp();
}
