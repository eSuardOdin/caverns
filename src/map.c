#include "../includes/structs.h"

// Kind of constructor, I guess.
Map * createMap(int roomNb, int mapWidth, int mapHeight, int level) {
    // allocate memory for map
    Map * map = malloc(sizeof(Map));
    // Allocate memory for the array of rooms
    Room ** rooms;
    rooms = malloc(roomNb * (sizeof(Room *)));
    map->rooms = rooms;
    
}
int drawMap(Map * map) {
    for (int x = 2; x <= (map->width)+2; x++) {
        for (int y = 2; y <= (map->height)+2; y++) {
            mvprintw(y, x, "#");
        }
    }

    return 0;
}