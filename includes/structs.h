#ifndef STRUCTS_H
#define STRUCTS_H 

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


typedef struct Tile {
    char graphic;
    bool isCrossable;
} Tile;

/**
 * Defines a position x y
*/
typedef struct Position
{
    int x;
    int y;
} Position;

// typedef struct Gate {
//     int width;
//     int height;
//     Position * gatePos;
//     // Direction direction;
// } Gate;

/**
 * Struct for a room / cardinals[0]: N | [1]: W | [2]: S | [3]: E
*/
typedef struct Room
{
    Position * roomPos;
    char cardPoints[4];
    int width;
    int height;
    int roomNb;
    // Tile **tiles;
    
} Room;

typedef struct Connector {
    Position * connectorPos;
    int direction; // 0 : North
                   // 1 : West
                   // 2 : South
                   // 3 : East   
} Connector;

typedef struct Map 
{
    Room ** rooms;
    int level;
    int width;
    int height;
    Tile **tiles;
} Map;
int drawMap(Map *);
Map * createMap(int roomNb, int mapWidth, int mapHeight, int level);
int drawRoom(Room *);
Room * createRoom(int x, int y, int width, int height);
Room * createConnectedRoom(Connector *);
Connector * randomWallPosition(Map*);
#endif

