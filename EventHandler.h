#pragma once
#include <X11/Xlib.h>

class EventHandler {
public:
    virtual void handleEvent(XEvent& e) = 0;
};