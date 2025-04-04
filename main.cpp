#include <iostream>
#include "Graph.h"
#include "MapSearch.h"
#include "stlastar.h"
#include "Character.h"
#include "Game.h"
#include "Menu.h"
#include <windows.h>

int main() {
    Menu menu;
    while (menu.isWindowOpen()) {
        menu.update();
        menu.render();
    }
    return 0;
}
