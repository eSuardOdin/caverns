#ifndef STRUCTS_H
#define STRUCTS_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/**
 * Defines a position x y
*/
// typedef struct Position
// {
//     int x;
//     int y;
// } Position;
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
    // Position * roomPos;
    int roomX;
    int roomY;
    int width;
    int height;
} Room;
int drawRoom(Room *);

typedef struct Map 
{
    Room ** rooms;
    int level;
    int width;
    int height;
} Map;
int drawMap(Map *);

#endif