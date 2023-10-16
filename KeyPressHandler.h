#pragma once
#include "EventHandler.h"

class KeyPressHandler : public EventHandler {
public:
    KeyPressHandler();
    void handleEvent(XEvent& e) override;
};
