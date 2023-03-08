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

    // Create wall tiles
    Tile wall;
    wall.graphic = '#';
    wall.isCrossable = false;

    // Create floor tiles
    Tile floor;
    floor.graphic = ' ';
    floor.isCrossable = false;

    // allocate memory for map
    Map * map = malloc(sizeof(Map));
    // // Allocate memory for the array of rooms
    Room ** rooms;
    rooms = malloc(roomNb * (sizeof(Room *)));
    map->rooms = rooms;
    
    // Map attributes
    map->roomNb = roomNb;
    map->height = mapHeight;
    map->width = mapWidth;
    map->level = level;
    
    //Allocate memory for the tiles 
    map->tiles = (Tile**) malloc(map->width * sizeof(Tile*));
    for(int i = 0; i < map->width; i++) {
        map->tiles[i] = (Tile *) malloc(map->height * sizeof(Tile));
    }
    // Populate map array
    for(int x = 0; x < map->width; x++) {
        for(int y = 0; y < map->height; y++) {
            map->tiles[x][y] = wall;
        }
    }
    
    // First room (may be a future function)
    Room * room;
    int roomX = 25;
    int roomY = 20;
    // Setting room height between 5 and 15
    int roomHeight = 10;
    int roomWidth = 20;

    room = createRoom(roomX,roomY,roomWidth,roomHeight);
    rooms[0] = room;
    map->roomIndex = 1; // To move

    // Populate map from room tiles
    for(int x = room[0].roomPos->x; x <= room[0].roomPos->x + room[0].width; x++) {
        for(int y = room[0].roomPos->y; y <= room[0].roomPos->y + room->height; y ++) {
            map->tiles[x][y] = floor;
        }
    }

    return map;
}
/**
 * Draws the map on terminal
 * @param map The map to draw
 * @return Zero if success
*/
int drawMap(Map * map) {

    for(int x = 0; x < map->width; x++) {
        for(int y = 0; y < map->height; y++) {
            mvaddch(y + 5, x + 5, map->tiles[x][y].graphic);
        }
    }

    // Draw the first room
    // drawRoom(map->rooms[0]);

    return 0;
}


Connector * randomWallPosition(Map*map){
    int x;
    int y;
    Position * pos = (Position*) malloc(sizeof(Position));
    Connector * connector = (Connector*) malloc(sizeof(Connector));
    Tile connectorTile;
    connectorTile.graphic = ' ';
    connectorTile.isCrossable = true; 
    while(1) {
        x = rand() % (map->width);
        y = rand() % (map->height);
        if(x > 0 && y > 0 && x < map->width-1 && y < map->height-1 
           &&  map->tiles[x][y].graphic == '#'
           && (map->tiles[x-1][y].graphic == ' '
           ||  map->tiles[x+1][y].graphic == ' '
           ||  map->tiles[x][y-1].graphic == ' '
           ||  map->tiles[x][y+1].graphic == ' '
           )) {
            if(map->tiles[x-1][y].graphic == ' ')      connector->direction = 3;
            else if(map->tiles[x+1][y].graphic == ' ') connector->direction = 1;
            else if(map->tiles[x][y-1].graphic == ' ') connector->direction = 2;
            else                                       connector->direction = 0; 
            pos->x = x;
            pos->y = y;
            connector->connectorPos = pos;
            map->tiles[x][y].graphic = connectorTile.graphic;
            drawMap(map);
            break;
        } 
    }
    return connector;
}

int createConnectedRoom(Map * map) {
    Connector * connector = (Connector*) malloc(sizeof(Connector));
    Room * room;
    connector = randomWallPosition(map);
    if(connector->direction == 0) {         // N
        room = createRoom(
            connector->connectorPos->x,
            connector->connectorPos->y+1,
            3,
            5
         );
    } else if (connector->direction == 1) { // W
        room = createRoom(
            connector->connectorPos->x+1,
            connector->connectorPos->y,
            5,
            3
         );
    } else if (connector->direction == 2) { // S
        room = createRoom(
            connector->connectorPos->x,
            connector->connectorPos->y-1,
            3,
            5
         );
    } else {                                // E
        room = createRoom(
            connector->connectorPos->x-1,
            connector->connectorPos->y,
            5,
            3
         );
    }
    map->rooms[map->roomIndex] = room;
    return 0;
}





// Random first room
/*
// First room (may be a future function)
    Room * room;
    // Setting the top left spawn for room
    int minX = (mapWidth/2) - 8; // Magic numbers not good, to improve
    int maxX = (mapWidth/2) + 8;
    int minY = (mapHeight/2) - 8; 
    int maxY = (mapHeight/2) + 8;
    int roomX = 0;
    // Setting room width between 5 and 15
    int roomWidth = rand() % (15 - 5 + 1) + 5;
    while(roomX == 0 || roomX + roomWidth >= map->width - roomX ) {
        roomX = rand() % (maxX - minX + 1) + minX;
    }
    int roomY = 0;
    // Setting room height between 5 and 15
    int roomHeight = rand() % (15 - 5 + 1) + 5;
    while(roomY == 0 || roomY + roomHeight >= map->height - roomY) {
        roomY = rand() % (maxY - minY + 1) + minY;
    }

    room = createRoom(roomX,roomY,roomWidth,roomHeight);
    rooms[0] = room;

*/
