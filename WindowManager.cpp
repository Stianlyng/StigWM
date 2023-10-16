#include "WindowManager.h"
#include <stdexcept>

WindowManager::WindowManager() {
    display_ = XOpenDisplay(nullptr);
    if (display_ == nullptr) {
        throw std::runtime_error("Failed to open X display");
    }
    root_ = DefaultRootWindow(display_);

    // Set blue background for as a test.. 
    XColor blueColor;
    Colormap colormap = DefaultColormap(display_, 0);
    XParseColor(display_, colormap, "#0000FF", &blueColor);
    XAllocColor(display_, colormap, &blueColor);
    XSetWindowBackground(display_, root_, blueColor.pixel);
    XClearWindow(display_, root_);
}

WindowManager::~WindowManager() {
    XCloseDisplay(display_);
}

void WindowManager::run() {
    XSelectInput(display_, root_, SubstructureRedirectMask | SubstructureNotifyMask);
    XEvent e;

    while (true) {
        XNextEvent(display_, &e);
        switch (e.type) {
        case MapRequest:
            onMapRequest(e.xmaprequest);
            break;
        }
    }
}

void WindowManager::onMapRequest(const XMapRequestEvent& e) {
    XMapWindow(display_, e.window);
    XSync(display_, false);
}
