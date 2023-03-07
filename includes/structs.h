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
    SOUTH,
    EAST,
    WEST
} Direction;

typedef struct Gate {
    int size;
    Direction direction;
} Gate;

typedef struct Room
{
    Position * roomPos;
    int width;
    int height;
} Room;
int drawRoom(Room *);
Room * createRoom(int x, int y, int width, int height);




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