#include "KeyPressHandler.h"
#include <X11/keysym.h>
#include <cstdlib> // For exit()

KeyPressHandler::KeyPressHandler() {
    // Initialization
}

void KeyPressHandler::handleEvent(XEvent& e) {
    if (e.type == KeyPress) {
        XKeyEvent& keyEvent = e.xkey;
        KeySym keysym = XLookupKeysym(&keyEvent, 0);

        if (keysym != NoSymbol && (keyEvent.state & Mod4Mask)) {
            if (keysym == XK_q) {
                // Exit the program
                exit(0);
            } else if (keysym == XK_Return) {
                // Open Alacritty terminal
                system("alacritty &");
            }
        }
    }
}