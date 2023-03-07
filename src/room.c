#include "../includes/structs.h"


/**
 * Draws the room on the terminal
 * @param room A pointer to the room to draw
 * @return Zero if no problem
*/
int drawRoom(Room * room) {
    for (int x = 0; x < (room->width); x++) {
        for (int y = 0; y < (room->height); y++) {
            mvprintw(y+room->roomPos->y, x+room->roomPos->x, " ");
        }
    }
    return 0;
}


/**
 * Constructor for a room, returns a pointer to the object
 * @param x X axis position on the map
 * @param y Y axis position on the map
 * @param width Width of the room
 * @param height Height of the room
 * @return A pointer to the room created
*/
Room * createRoom(int x, int y, int width, int height) {
    // Allocate memory for the room
    Room * room;
    room = malloc(sizeof(Room));
    // Allocate memory for the position
    Position * roomPos;
    roomPos = malloc(sizeof(Position));
    // Attributes
    room->roomPos = roomPos;
    room->roomPos->x = x;
    room->roomPos->y = y;
    room->height = width;
    room->width = height;

    return room;
}