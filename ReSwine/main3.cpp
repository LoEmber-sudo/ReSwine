#include "main2.h"
#include "game/SuperWindow.h" // Your wrapper class
#include "Globals.h"
#include "resource.h" // For resource IDs
void main3()
{
    SuperWindow = new SSuperWindow();

    // Initialize / create the window with resources and title
    SuperWindow->Create(103, 32512, L"S.W.I.N.E. HD Remaster");

    // Start the main loop or play the game
    SuperWindow->Play();

    // Cleanup
    if (SuperWindow)
    {
        delete SuperWindow;
        SuperWindow = nullptr;
    }
}
