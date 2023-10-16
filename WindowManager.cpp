#include "WindowManager.h"
#include "EventHandler.h"
#include "KeyPressHandler.h"
#include <stdexcept>

WindowManager::WindowManager() : keyPressHandler() {
    display_ = XOpenDisplay(nullptr);
    if (display_ == nullptr) {
        throw std::runtime_error("Failed to open X display");
    }
    root_ = DefaultRootWindow(display_);
}

WindowManager::~WindowManager() {
    XCloseDisplay(display_);
}

void WindowManager::onMapRequest(const XMapRequestEvent& e) {
    XMapWindow(display_, e.window);
}


void WindowManager::run() {
    XSelectInput(display_, root_, SubstructureRedirectMask | SubstructureNotifyMask | KeyPressMask);

    XEvent e;

    while (true) {
        XNextEvent(display_, &e);
        switch (e.type) {
            case KeyPress:
                keyPressHandler.handleEvent(e);
                break;
            case MapRequest:
                onMapRequest(e.xmaprequest);
                break;
        }
    }
}