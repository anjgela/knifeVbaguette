#include "Menu.h"
#include <iostream>

int main() {
    Menu menu;
    while (menu.isWindowOpen()) {
        menu.update();
        menu.render();
    }

    return 0;
}
