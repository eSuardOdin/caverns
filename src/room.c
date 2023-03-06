#include "../includes/structs.h"
int drawRoom(Room * room) {
    for (int x = 0; x < (room->width); x++) {
        for (int y = 0; y < (room->height); y++) {
            mvprintw(y+room->roomY, x+room->roomX, " ");
        }
    }

    return 0;
}