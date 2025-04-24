#include "Menu.h"
#include <iostream>

int main() {
    /*Menu menu;
    while (menu.isWindowOpen()) {
        menu.update();
        menu.render();
    }*/
    Match match;
    std::cout << match.isWindowOpen() << std::endl;
    std::cout << match.checkGameStatus() << std::endl;
    while (match.isWindowOpen()) {
        match.update();
        match.render();
    }
    return 0;
}
