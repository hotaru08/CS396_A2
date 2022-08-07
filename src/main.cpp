/******************************************************************************
filename:	main.cpp
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Entry point of application.

******************************************************************************/
#include <includes.h>

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
    sg_game.InitializeGame();

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

                if (!sg_game.m_gameOver)
                    sg_game.m_elapsedTime += Definitions::FIXED_DELTA_TIME;
            }
        );
        glutTimerFunc(0, RefreshUpdate, 0);

        // Poll for key and mouse inputs
        glutKeyboardFunc
        (
            [](unsigned char Key, int MouseX, int MouseY) noexcept
            {
                sg_game.m_windowInst.m_inputs.m_keys.SetKeyState(Key, true);
                sg_game.m_gameMgr->SendGlobalEvent< OnKeyDown >(Key);
            }
        );
        glutKeyboardUpFunc
        (
            [](unsigned char Key, int MouseX, int MouseY) noexcept
            {
                sg_game.m_windowInst.m_inputs.m_keys.SetKeyState(Key, false);
                sg_game.m_gameMgr->SendGlobalEvent< OnKeyUp >(Key);
            }
        );
        glutMouseFunc
        (
            [](int Button, int State, int MouseX, int MouseY) noexcept
            {
                bool down = State == GLUT_DOWN;

                if (Button == GLUT_LEFT_BUTTON)
                    sg_game.m_windowInst.m_inputs.m_mouseLeftBtn = down;
                else if (Button == GLUT_RIGHT_BUTTON)
                    sg_game.m_windowInst.m_inputs.m_mouseRightBtn = down;

                if (down)
                    sg_game.m_gameMgr->SendGlobalEvent< OnMouseButtonDown >(Button);
            }
        );

        auto updateMouse =
        [](const int _x, const int _y)
        {
            sg_game.m_windowInst.m_inputs.m_mouseX = _x;
            sg_game.m_windowInst.m_inputs.m_mouseY = _y;

            sg_game.m_gameMgr->SendGlobalEvent< OnMouseMoved >
            (
                xcore::vector2
                {
                    static_cast<float>(_x),
                    static_cast<float>(_y)
                }
            );
        };
        glutMotionFunc(updateMouse);
        glutPassiveMotionFunc(updateMouse);
        glutSetCursor(GLUT_CURSOR_FULL_CROSSHAIR);

        glutMainLoop();
    }

    sg_game.CleanUp();
}
