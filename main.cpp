#include "WindowManager.h"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        WindowManager wm;
        wm.run();
    } catch (const std::exception& e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}