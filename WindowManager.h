#pragma once

#include <X11/Xlib.h>
#include "KeyPressHandler.h"

class WindowManager {
public:
    WindowManager();
    ~WindowManager();
    void run();

private:
    Display* display_;
    Window root_;
    KeyPressHandler keyPressHandler; // Added this member

    void onMapRequest(const XMapRequestEvent& e);
};