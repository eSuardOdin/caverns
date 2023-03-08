#include "../includes/structs.h"

int main (void) {

    srand(time(NULL));
    // Init of screen :
    int userInput;
    initscr();
    curs_set(0); // Hide cursor
    printw("CAVERNS (Type 'x' to quit)");
    noecho();
    refresh();

    Map * map;
    map = createMap(4, 100, 50, 1);
    // // while ((int) sizeof(map->rooms) / sizeof(Room*) < map->roomNb) {
    // while (map->roomIndex < map->roomNb) {
    //     createConnectedRoom(map);
    //     map->roomIndex += 1;
    // }
    randomWallPosition(map);
    drawMap(map);
    while((userInput = getch()) != 'x'){
        
    }
    endwin();
    return 0;
}