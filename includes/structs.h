#ifndef STRUCTS_H
#define STRUCTS_H 

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/**
 * Defines a position x y
*/
typedef struct Position
{
    int x;
    int y;
} Position;
/**
 * Directions
*/
typedef enum {
    NORTH,
    WEST,
    SOUTH,
    EAST
} Direction;

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
    // Gate ** gates;
    int width;
    int height;
    // Direction ** cardinals;
} Room;
int drawRoom(Room *);
Room * createRoom(int x, int y, int width, int height);
void removeCardinal(Room * room, Direction cardinal);



typedef struct Map 
{
    Room ** rooms;
    int level;
    int width;
    int height;
} Map;
int drawMap(Map *);
Map * createMap(int roomNb, int mapWidth, int mapHeight, int level);
int drawFirstRoom(Map * map, Room * room);

#endif