#include <iostream>
#include <ncurses/ncurses.h>//lib used

void showAboutPage() {
    int rows, cols;

    initscr(); // Initialize the library
    getmaxyx(stdscr, rows, cols); // Get the terminal size

    
    int yPos = rows / 2 - 6;
    int xPos = (cols - 48) / 2; //text centering


    mvprintw(yPos, xPos,         "==============================================");
    mvprintw(yPos + 1, xPos,     "                   ABOUT US                  ");
    mvprintw(yPos + 2, xPos,     "==============================================");
	
	mvprintw(yPos + 4, xPos + 2, "		      Created by:             ");    
	mvprintw(yPos + 5, xPos + 2, "        Silverogue Development Team             ");
    mvprintw(yPos + 7, xPos + 2, "             Top contributors:                  ");
    mvprintw(yPos + 8, xPos + 2, "              #1 Hafizh (99%)              ");
    mvprintw(yPos + 9, xPos, "");
	mvprintw(yPos + 10, xPos,     "==============================================");

    refresh(); // Refresh the screen
    getch(); // Wait for a key press
    endwin(); // End the library
}

int main() {
    showAboutPage();//output
    return 0;
}
