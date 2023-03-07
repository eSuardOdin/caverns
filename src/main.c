#include "../includes/structs.h"

int main (void) {
    // Init of screen :
    int userInput;
    initscr();
    curs_set(0); // Hide cursor
    printw("CAVERNS (Type 'x' to quit)");
    noecho();
    refresh();

    Map * map;
    map = malloc(sizeof(Map));
    map->height = 50;
    map->width = 200;
    Room ** rooms;
    rooms = malloc(2*sizeof(Room *));
    map->rooms = rooms;


    Position * roomPos;
    roomPos = malloc(sizeof(Position));

    Room * room;
    room = createRoom(5,5,20,35);
    rooms[0] = room;
    drawMap(map);
    drawRoom(rooms[0]); // To put in DrawMap
    while((userInput = getch()) != 'x'){
        
    }
    endwin();
    return 0;
}