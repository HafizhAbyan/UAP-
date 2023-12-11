#include <ncurses/ncurses.h> //library used




#define board_DIM 28
#define height board_DIM //defining board size
#define width board_DIM *3

int main(int argc, char **argv){
	
	initscr();// ncurses initial
	refresh();
	
	int xMax, yMax;
	getmaxyx(stdscr, yMax, xMax); //getting size of terminal screen
	
	WINDOW * board_win = newwin(height, width, (yMax/2)- (height/2) , (xMax/2) - (width/2)); //board size and centering board process
	box(board_win, 0, 0);
	wrefresh(board_win);
	
	getch();
	endwin();
		
	
	return 0;
}
