#pragma once

#include <X11/Xlib.h>

class WindowManager {
public:
    WindowManager();
    ~WindowManager();
    void run();

private:
    Display* display_;
    Window root_;

    void onMapRequest(const XMapRequestEvent& e);
};