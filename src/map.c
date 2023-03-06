#include "../includes/structs.h"

int drawMap(Map * map) {
    for (int x = 2; x <= (map->width)+2; x++) {
        for (int y = 2; y <= (map->height)+2; y++) {
            mvprintw(y, x, "#");
        }
    }

    return 0;
}