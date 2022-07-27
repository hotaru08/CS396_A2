#include <includes.h>

static struct Game
{
    // Window instance
    Window m_windowInst;
    
    // ECS instance
    std::unique_ptr<xecs::game_mgr::instance> m_gameMgr;

} sg_game;

// ----------------------------------------------------------------------------
void RegisterElements()
{
	sg_game.m_gameMgr->RegisterComponents
	<

	>();

	sg_game.m_gameMgr->RegisterSystems
	<
		RenderingSystem

	>();
}

void Initialize(Window& _window)
{
    sg_game.m_gameMgr = std::make_unique< xecs::game_mgr::instance >();
	RenderingSystem::m_windowPtr = &_window;

	RegisterElements();
}

void RefreshUpdate(int value)
{
    // Post re-paint request to activate display()
    glutPostRedisplay();

    // next timer call milliseconds later
    glutTimerFunc(15, RefreshUpdate, 0);
}

int main(int argc, char** argv)
{
    // Enable run-time memory check for debug builds.
#if defined(_DEBUG)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    xcore::Init("TowerDefense");

	sg_game.m_gameMgr = std::make_unique< xecs::game_mgr::instance >();
	Initialize(sg_game.m_windowInst);

	// Setup Window Instance, Graphics and GameLoop
	{
		glutInitWindowSize(sg_game.m_windowInst.m_width, sg_game.m_windowInst.m_height);
		glutInitWindowPosition(sg_game.m_windowInst.m_posX, sg_game.m_windowInst.m_posY);

		glutInit(&argc, argv);
		glutCreateWindow("CS396 Assignment 02");
		glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

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

				if (sg_game.m_windowInst.m_inputs.m_keys.getKey('s') || 
					sg_game.m_windowInst.m_inputs.m_keys.getKey('x'))
				{
					
					std::cout << "Help me" << std::endl;
				}

				sg_game.m_windowInst.m_inputs.m_keys.FrameUpdate();
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

            if (Button == GLUT_LEFT_BUTTON )
				sg_game.m_windowInst.m_inputs.m_mouseLeftBtn  = (State == GLUT_DOWN);
            else if (Button == GLUT_RIGHT_BUTTON)
                sg_game.m_windowInst.m_inputs.m_mouseRightBtn = (State == GLUT_DOWN);
        });

		glutMainLoop();
	}

    xcore::Kill();
}