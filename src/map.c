#include "../includes/structs.h"

/**
 * Constructor for a map, returns a pointer to the object
 * @param roomNb Number of rooms on the map
 * @param mapWidth Width of the map
 * @param mapHeight Height of the map
 * @param level Level of the map (May move in a future Game struct ?) 
 * @return A pointer to the map created
*/
Map * createMap(int roomNb, int mapWidth, int mapHeight, int level) {
    // allocate memory for map
    Map * map = malloc(sizeof(Map));
    // Allocate memory for the array of rooms
    Room ** rooms;
    rooms = malloc(roomNb * (sizeof(Room *)));
    map->rooms = rooms;
    
    // Map attributes
    map->height = mapHeight;
    map->width = mapWidth;
    map->level = level;
    // First room (may be a future function)
    Room * room;
    int minX = (mapWidth/2) - 10; // Magic numbers not good, to improve
    int maxX = (mapWidth/2) + 10;
    int minY = (mapHeight/2) - 10; 
    int maxY = (mapHeight/2) + 10;
    int roomX = 0;
    int roomWidth = rand() % (15 - 5 + 1) + 5;
    while(roomX == 0 || roomX + roomWidth >= map->width - roomX) {
        roomX = rand() % (maxX - minX + 1) + minX;
    }
    int roomY = 0;
    int roomHeight = rand() % (15 - 5 + 1) + 5;
    while(roomY == 0 || roomY + roomHeight >= map->height - roomY) {
        roomY = rand() % (maxY - minY + 1) + minY;
    }

    room = createRoom(roomX,roomY,roomWidth,roomHeight);
    rooms[0] = room;

    return map;
}
/**
 * Draws the map on terminal
 * @param map The map to draw
 * @return Zero if success
*/
int drawMap(Map * map) {
    for (int x = 2; x <= (map->width)+2; x++) {
        for (int y = 2; y <= (map->height)+2; y++) {
            mvprintw(y, x, "#");
        }
    }


    // Draw the first room
    drawRoom(map->rooms[0]);

    return 0;
}

int drawFirstRoom(Map * map, Room * room) {
    
    return 0;
}