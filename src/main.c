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
    map = createMap(2, 100, 50, 1);
    drawMap(map);
    randomWallPosition(map);
    while((userInput = getch()) != 'x'){
        
    }
    endwin();
    return 0;
}