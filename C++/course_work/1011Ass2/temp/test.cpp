
#include <iostream>
#include <Windows.h>

int main()
{
    //get console handler
    HANDLE h = GetStdHandle(STD_INPUT_HANDLE);
    if (h == NULL)
    {
        return false; // console not found
    }
    //set console mode, enable window and mouse input
    DWORD cNumRead, fdwMode, i;
    fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    if (!SetConsoleMode(h, fdwMode))
        fprintf(stderr, "%s\n", "SetConsoleMode");
    //get input
    DWORD cc;
    INPUT_RECORD irec;
    KEY_EVENT_RECORD key;
    MOUSE_EVENT_RECORD mouse;
    for (;;)
    {
        ReadConsoleInput(h, &irec, 1, &cc);
        //mouse input
        if (irec.EventType == MOUSE_EVENT)
        {
            mouse = (MOUSE_EVENT_RECORD &)irec.Event;
            switch (mouse.dwButtonState)
            {
            case FROM_LEFT_1ST_BUTTON_PRESSED:
                std::cout << "mouse left click" << std::endl;
                std::cout << "   mouse pos:" << mouse.dwMousePosition.X << " " << mouse.dwMousePosition.Y << std::endl;
                break;
            case RIGHTMOST_BUTTON_PRESSED:
                std::cout << "mouse right click" << std::endl;
                std::cout << "   mouse pos:" << mouse.dwMousePosition.X << " " << mouse.dwMousePosition.Y << std::endl;
                break;
            case FROM_LEFT_2ND_BUTTON_PRESSED:
                std::cout << "mouse middle click" << std::endl;
                std::cout << "   mouse pos:" << mouse.dwMousePosition.X << " " << mouse.dwMousePosition.Y << std::endl;
                break;
            default:
                break;
            }

            switch (mouse.dwEventFlags)
            {
            case DOUBLE_CLICK:
                std::cout << "mouse DOUBLE_CLICK" << std::endl;
                break;
            case MOUSE_WHEELED:
                std::cout << "mouse MOUSE_WHEELED:" << HIWORD(mouse.dwButtonState) << std::endl;
                break;
            default:
                break;
            }
        }
        else if (irec.EventType == KEY_EVENT)
        {
            key = (KEY_EVENT_RECORD &)irec.Event;
            if (key.bKeyDown)
            {
                if (key.wVirtualKeyCode == VK_F1)
                {
                    std::cout << "F1" << std::endl;
                }
                else
                {
                    std::cout << "key: " << key.uChar.AsciiChar
                              << " code:  " << key.wVirtualKeyCode << std::endl;
                }
            }
        }
    }
}
