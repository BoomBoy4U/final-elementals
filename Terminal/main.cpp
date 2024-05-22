#include "GameMenu.h"
#include "Player.h"

int main() {
    Player* player = new Player("", "elementalless", 0, 0, 0, 0);
    GameMenu gameMenu(player);
    gameMenu.start();
    delete player;
    return 0;
}
