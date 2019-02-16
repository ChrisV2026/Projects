#include <windows.h>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

    int i,window1,window2;

    LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

    HWND textfield, play, instructions, exitgame,exityes,map1,map2,map3;

    char szClassName[ ] = "CodeBlocksWindowsApp";

    int WINAPI WinMain (HINSTANCE hThisInstance,
                         HINSTANCE hPrevInstance,
                         LPSTR lpszArgument,
                         int nCmdShow)
    {
        HWND hwnd;
        MSG messages;
        WNDCLASSEX wincl;

        wincl.hInstance = hThisInstance;
        wincl.lpszClassName = szClassName;
        wincl.lpfnWndProc = WindowProcedure;
        wincl.style = CS_DBLCLKS;
        wincl.cbSize = sizeof (WNDCLASSEX);

        wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
        wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
        wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
        wincl.lpszMenuName = NULL;
        wincl.cbClsExtra = 0;
        wincl.cbWndExtra = 0;
        wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

        if (!RegisterClassEx (&wincl))
            return 0;

        hwnd = CreateWindowEx (
                               0,
                               szClassName,
                               "Tutorial 4: Button Actions",
                               WS_MINIMIZEBOX | WS_SYSMENU,
                               CW_USEDEFAULT,
                               CW_USEDEFAULT,
                               500,
                               500,
                               HWND_DESKTOP,
                               NULL,
                               hThisInstance,
                               NULL
                               );

        ShowWindow (hwnd, nCmdShow);


        while(GetMessage (&messages, NULL, 0, 0))
        {
            TranslateMessage(&messages);
            DispatchMessage(&messages);
        }

        return messages.wParam;
    }

    LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        switch (message)
        {
        case WM_CREATE:

            textfield = CreateWindow("STATIC",
                                     "Fire Emblem",
                                     WS_VISIBLE | WS_CHILD,
                                     20,20,100,20,
                                     hwnd,NULL,NULL,NULL);


            play = CreateWindow("BUTTON",
                                  "PLAY",
                                  WS_VISIBLE | WS_CHILD | WS_BORDER,
                                  150,50,150,30,
                                  hwnd,(HMENU) 1,NULL,NULL);

            instructions = CreateWindow("BUTTON",
                                  "INSTRUCTIONS",
                                  WS_VISIBLE | WS_CHILD | WS_BORDER,
                                  150,100,150,40,
                                  hwnd,(HMENU) 2,NULL,NULL);

            exitgame = CreateWindow("BUTTON",
                                  "EXIT",
                                  WS_VISIBLE | WS_CHILD | WS_BORDER,
                                  150,140,150,40,
                                  hwnd,(HMENU) 3,NULL,NULL);


            break;

        case WM_COMMAND:

            switch(LOWORD(wParam))
            {
                case 1:

                DestroyWindow(play);
                DestroyWindow(instructions);
                DestroyWindow(exitgame);

                map1 = CreateWindow("BUTTON",
                                  "MAP1",
                                  WS_VISIBLE | WS_CHILD | WS_BORDER,
                                  150,50,150,30,
                                  hwnd,(HMENU) 4,NULL,NULL);

                map2 = CreateWindow("BUTTON",
                                  "MAP2",
                                  WS_VISIBLE | WS_CHILD | WS_BORDER,
                                  150,100,150,30,
                                  hwnd,(HMENU) 5,NULL,NULL);

                map3 = CreateWindow("BUTTON",
                                  "MAP3",
                                  WS_VISIBLE | WS_CHILD | WS_BORDER,
                                  150,150,150,30,
                                  hwnd,(HMENU) 6,NULL,NULL);

                break;

                case 2:
                system("notepad.exe instructions.txt");
                break;

                case 3:
                ::MessageBeep(MB_ICONERROR);
                if(MessageBox(hwnd,"Are you sure?","Exit",MB_YESNO) == IDYES)
                    PostQuitMessage(0);
                break;

                case 4:
                    window1=initwindow(1248,600);
                    /////////////////////////////////////       Map 1
                    outtextxy(18, 6,   "                                                                                        F           F          F           F                      R                       F           F          F           F                                                                       S2         S2");
                    outtextxy(18, 30,  "                                                                                        F           F          F                                   B                                    F          F           F                                                                       S2         S2");
                    outtextxy(18, 54,  "                                                                                        F           F                                               R                                                F           F                                                                       S2         S2");
                    outtextxy(18, 78, "                                       F          F           F                      F                                                R          R          R                                                 F                      F           F           F");
                    outtextxy(18, 102, "F                        F           F          F           F                                                            B          R          R          R          B                                                            F           F          F          F");
                    outtextxy(18, 126, "F                        F           F          F           F                                               R          B                                                B          R                                                F           F          F          F");
                    outtextxy(18, 150, "F                        F           F          F           F                                   R          R                                   F                                    R         R                                    F           F          F          F");
                    outtextxy(18, 174, "F                                     F          F                                   R           R                                   F          F          F                                    R          R                                    F          F");
                    outtextxy(18, 198, "F                                     F                                    R         R                                                F          F          F                                                 R         R                                    F");
                    outtextxy(18, 222, "F                                                              B          R                                  M          M         M          F          M          M          M                                  R          B");
                    outtextxy(18, 246, "                                                   R          B                                               M          M         M                      M          M          M                                               B         R");
                    outtextxy(18, 270, "                                      R          R                                   F           F          M          M         M                      M          M          M         F           F                                   R          R");
                    outtextxy(18, 294, "R           B          R          R                                   F          F           F          F                                                                          F          F           F          F                                   R          R          B          R");                outtextxy(18, 294, "R           B          R          R                                   F          F           F          F                                                                          F          F           F          F                                   R          R          B          R");
                    outtextxy(18, 318, "                                      R          R                                   F           F          M          M         M                      M          M          M         F           F                                   R          R");
                    outtextxy(18, 342, "                                                   R          B                                               M          M         M                      M          M          M                                               B         R");
                    outtextxy(18, 366, "F                                                              B          R                                  M          M         M          F          M          M          M                                  R          B");
                    outtextxy(18, 390, "F                                     F                                    R         R                                                F          F          F                                                 R         R                                    F");
                    outtextxy(18, 414, "F                                     F          F                                   R           R                                   F          F          F                                    R          R                                    F          F");
                    outtextxy(18, 438, "F                        F           F          F           F                                   R          R                                   F                                    R         R                                    F           F          F          F");
                    outtextxy(18, 462, "F                        F           F          F           F                                               R          B                                                B          R                                                F           F          F          F");
                    outtextxy(18, 486, "F                        F           F          F           F                                                            B          R          R          R          B                                                            F           F          F          F");
                    outtextxy(18, 510, "                                       F          F           F                      F                                                R          R          R                                                 F                      F           F           F");
                    outtextxy(18, 534,  "S1        S1                                                                        F           F                                               R                                                F           F");
                    outtextxy(18, 558,  "S1        S1                                                                        F           F          F                                   B                                    F          F           F");
                    outtextxy(18, 582,  "S1        S1                                                                        F           F          F           F                      R                       F           F          F           F");

                    /////////////////////////////////////
                    for (i=0;i<=1248;i++)
                        line(i*50, 0, i*50, getmaxy());     //Prints the grid of the map
                    for (i=0;i<=600;i++)
                        line(0, i*24, getmaxx(), i*24);

                    window2=initwindow(600,600);
                    for (i=0;i<=600;i++)
                        line(i*24, 0, i*24, getmaxy());
                    for (i=0;i<=600;i++)
                        line(0, i*24, getmaxx(), i*24);
                    break;


                case 5:
                    window1=initwindow(1248,600);
                    /////////////////////////////////////       Map 2
                    outtextxy(18,6,     "W         W         W         W         W         W          /            /            /           /          W         W         W         W         W         W         W         W         W         W         W         W         W         W         W");
                    outtextxy(18,30,    "W         S1        S1                                 W          /            /            /           /          W                                                                                                                                                                            W");
                    outtextxy(18,54,    "W         S1        S1                                 W          /            /            /           /          W                                                                                                                          W         W         W                     W");
                    outtextxy(18,78,    "W         S1        S1                                 W          /            /            /           /          W                      W         W                      W         W         W         W                     W          /           W                     W");
                    outtextxy(18,102,   "W         W        W                                   W          /            /            /           /          W                      W         W                      W          /            /          W                    W          /           W                     W");
                    outtextxy(18,126,   "  /           /          W                                  W          /            /            /           /          W                      W         W                      W         /            /          W                     W          W         W                     W");
                    outtextxy(18,150,   "  /           /          W                                  W          /            /          W         W          W                     W         W                      W         /            /          W                                                                       W");
                    outtextxy(18,174,   "W         W         W                                 W          W         W         W                                                            W                     W          /           /           W                                                                       W");
                    outtextxy(18,198,   "W                                                                                                                                                                W                     W         /            /           W                      W         W         W                     W");
                    outtextxy(18,222,   "W                                                                                                                                                                W                     W         W         W         W                      W         /           W                     W");
                    outtextxy(18,246,   "W                                  W         W         W         W         W         W         W                                                                                                                                       W        W         W                      W");
                    outtextxy(18,270,   "W                                  W          /            /            /           /            /         W                                                                                                                                                                                         W");
                    outtextxy(18,294,   "W                                  W          /            /            /           /            /         W                                  W         W         W                                                                        W                                              W");
                    outtextxy(18,318,   "W                                  W          /            /            /           /            /         W                                  W           /          W                                                                        W                                              W");
                    outtextxy(18,342,   "W                                  W          /            /            /           /            /         W                                  W           /          W                                                                        W                                              W");
                    outtextxy(18,366,   "W                                  W         W         W          W         W         W        W                                  W           /          W                                                                        W                                              W");
                    outtextxy(18,390,   "W                                                                                                                                                   W          /          W                                                                        W                                              W");
                    outtextxy(18,414,   "W                                  W         W         W          W                     W        W         W                      W           /          W                                                                        W                                              W");
                    outtextxy(18,438,   "W                                  W           /           /           W                     W          /          W                      W          /          W                                                                        W                                              W");
                    outtextxy(18,462,   "W                                  W         W         W          W                     W          /          W                     W           /          W                                                                        W                     S2        S2        W");
                    outtextxy(18,486,   "W                                                                                                 W          /          W                      W          /          W                                                           W         W         W         S2        S2        W");
                    outtextxy(18,510,   "W                                  W        W         W           W        W          W         /           W                      W         W         W                                              W         W         /           W         S2        S2        W");
                    outtextxy(18,534,   "W         W         W         W           /           /           /             /           /          /           W                                                                                     W         W          /           /            /          W         W        W");
                    outtextxy(18,558,   "  /           /           /           /             /           /           /             /           /          /           W         W         W         W         W         W         W         W           /           /           /            /           /           /           /");
                    outtextxy(18,582,   "  /           /           /           /             /           /           /             /           /          /            /           /             /           /           /             /           /           /           /           /           /             /           /           /           /");


                    /////////////////////////////////////
                    for (i=0;i<=1248;i++)
                        line(i*50, 0, i*50, getmaxy());     //Prints the grid of the map
                    for (i=0;i<=600;i++)
                        line(0, i*24, getmaxx(), i*24);

                    window2=initwindow(600,600);
                    for (i=0;i<=600;i++)
                        line(i*24, 0, i*24, getmaxy());
                    for (i=0;i<=600;i++)
                        line(0, i*24, getmaxx(), i*24);
                    break;

                 case 6:
                    window1=initwindow(1248,600);
                    /////////////////////////////////////       Map 3
                    outtextxy(18,6,     "D         S2         S2         S2         D         D          D          D          D          D           D         D          D          D          D          D          D          D          D          D          D          D");
                    outtextxy(18,30,    "D         S2         S2         S2         D         D          D          D          D          D           D         D          D          D          D          D          D                                                D          D");
                    outtextxy(18,54,    "D          D          D          D          D          D          D          D          D                                   D          D          D                                                             D                                  D           D          D          D");
                    outtextxy(18,78,    "D          D          D          D          D          D          D          D          D                                   D          D                                                            D           D         D                                    D          D          V");
                    outtextxy(18,102,    "D          D          D          D                       D          D          D                                               D                                                 D         D          D          D          D          D                       D          V          V");
                    outtextxy(18,126,    "D          D          D                                                                                                                                                    D           D         D          D          D          D          D          B           V          V          V");
                    outtextxy(18,150,    "D          D          D                                                                                                  D                                                D           D         D          D          D          D          D          B           V          V          V");
                    outtextxy(18,174,    "D          D          D                                                                                       D        D          D                                   D           D         D          V           V          V           V          B           V          V          D");
                    outtextxy(18,198,    "D          D          D          D         D                                                               D        D          D                                   D           D         V          V           V          V           V          B           V          D          D");
                    outtextxy(18,222,    "D          D          D          D         D          D                                                  D         D         D           B          B          D           D         V          V           V          V           V          B           V          D          D");
                    outtextxy(18,246,    "D          D          D          D         D          D            D                      D          D         D           V          B          B          V           V          V           V          D           D          D          B          D         D          D");
                    outtextxy(18,270,    "D          D          D          D         D          D            D                      D          D         V           V          B          B          V           V          V           V          D           D          D                                   D          D");
                    outtextxy(18,294,    "D          D          D          D         D          D            D          B          D          V         V           V          B          B          V           V          D           D          D           D          D                                   D          D");
                    outtextxy(18,318,    "D          D          D          D         D          D            V          B          V          V         V           D          B          B          D           D          D           D          D           D          D                                   D          D");
                    outtextxy(18,342,    "D          D          D          D         D          V            V          B          V          V         D           D                                   D           D          D           D          D           D                                            D          D");
                    outtextxy(18,366,    "D          D          D          D         V          V            V          B          V          D         D           D                                   D           D          D           D          D           D                                            D          D");
                    outtextxy(18,390,    "D          D          D            V         V          V            D          B          D          D         D           D                                                          D           D          D           D                                D         D          D");
                    outtextxy(18,414,    "D          D          V          V         V          D            D                      D          D         D           D                                                            D           D                                                           D          D          D");
                    outtextxy(18,438,    "V          V          V          V         D          D            D                                    D         D           D                                                            D                                                                        D          D          D");
                    outtextxy(18,462,    "V          V          V          D         D          D            D                                               D                                                 D                                                           D                                     D          D          D");
                    outtextxy(18,486,    "V          V          D          D         D          D            D         D                                                                                      D                                               D          D                                     D          D          D");
                    outtextxy(18,510,    "V          D          D          D         D          D            D         D                                                                                     D                                                D          D                                     D          D          D");
                    outtextxy(18,534,    "D          D          D          D         D          D            D         D         D         D                          D          D                                  D          D          D          D          D          D          D          D          D          D");
                    outtextxy(18,558,    "D          D          D                                                 D          D          D          D           D         D          D          D          D          D          D          D          D          D          D        S1        S1        S1        D");
                    outtextxy(18,582,    "D          D          D                                                 D          D          D          D           D         D          D          D          D          D          D          D          D          D          D        S1        S1        S1        D");


                    /////////////////////////////////////
                    for (i=0;i<=1248;i++)
                        line(i*50, 0, i*50, getmaxy());     //Prints the grid of the map
                    for (i=0;i<=600;i++)
                        line(0, i*24, getmaxx(), i*24);

                    window2=initwindow(600,600);
                    for (i=0;i<=600;i++)
                        line(i*24, 0, i*24, getmaxy());
                    for (i=0;i<=600;i++)
                        line(0, i*24, getmaxx(), i*24);
                    break;
            }

            for (i=0;i<=1248;i++)
                line(i*50, 0, i*50, getmaxy());     //Prints the grid of the map
            for (i=0;i<=600;i++)
                line(0, i*24, getmaxx(), i*24);

            window2=initwindow(600,600);
            for (i=0;i<=600;i++)
                line(i*24, 0, i*24, getmaxy());
            for (i=0;i<=600;i++)
                line(0, i*24, getmaxx(), i*24);
            //game();
            break;

        case WM_DESTROY:
            PostQuitMessage (0);
            break;

        default:
            return DefWindowProc (hwnd, message, wParam, lParam);
        }

        return 0;
}

