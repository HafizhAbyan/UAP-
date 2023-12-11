#include <ncurses/ncurses.h>
#include <string>

void showAboutPage(WINDOW*menuwin) {
    int rows, cols;

    
    getmaxyx(stdscr, rows, cols); // Get the terminal size

    
    int yPos = rows / 2 - 6;
    int xPos = (cols - 48) / 2; //text centering
	
	clear();
	refresh();

    mvprintw(yPos, xPos,         "==============================================");
    mvprintw(yPos + 1, xPos,     "                   ABOUT US                  ");
    mvprintw(yPos + 2, xPos,     "==============================================");
	
	mvprintw(yPos + 4, xPos + 2, "		      Created by:             ");    
	mvprintw(yPos + 5, xPos + 2, "        Silverogue Development Team             ");
    mvprintw(yPos + 7, xPos + 2, "             Top contributors:                  ");
    mvprintw(yPos + 8, xPos + 2, "              #1 Hafizh (99%)              ");
    mvprintw(yPos + 9, xPos, ""														);
	mvprintw(yPos + 10, xPos,     "==============================================");


	refresh();	
	getch();
	wclear(menuwin);
	box(menuwin, 1, 1);
	wrefresh(menuwin);
	
}


using namespace std;

int main(int argc, char ** argv){
	
		string choices[3] = {"Start", "About", "Exit"};
	int choice;
	int highlight = 0;
		
	
	// NCURSES START 
	initscr();
	noecho();
	cbreak();
	
	// COLOR CODE
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);   
	init_pair(2, COLOR_YELLOW, COLOR_BLACK); 
	init_pair(3, COLOR_BLUE, COLOR_BLACK);   
	
	do{
	

	// SCREEN SIZE
	int yMax, xMax;
	getmaxyx (stdscr, yMax, xMax);
	
	//PRINTING GAME TITLE
    mvprintw(3, (xMax - 83)/ 2, "   xxxxx    x   xxxx    x     xxxx               x    x      xxxx    x       xxx    x    ");
	mvprintw(4, (xMax - 83)/ 2, "  xxxxxxxxxx   xxxxxxxxxx    xx xxxx    x       xxx        xxxxxxx  x     xxxxxxxxx     ");  
	mvprintw(5, (xMax - 83)/ 2, " x   xxxxxx   x    xxxxx     x   xxxx  x xx    xxxxx     xxxx   xxx      xx xxxxxx      ");
	mvprintw(6, (xMax - 83)/ 2, "xx     xx              x    xx    xxx x  xx      xxx      xxx      xxx   xx    xx        ");
	mvprintw(7, (xMax - 83)/ 2, "xx                    xx    xx    xx     xxx     xxx   xxxx     xxx   xx              ");
	mvprintw(8, (xMax - 83)/ 2, " xx     xxx          xxx    xx   xx       xxx    xxx  xx xx    xxx    xx   xxxxxxx    ");
	mvprintw(9, (xMax - 83)/ 2, " xxxxxxxxxxx         xxx    xx            xxx    xxx     xx   xxx    xx   xx    xxx   ");
	mvprintw(10, (xMax - 83)/ 2, "  xxxxx  xxxx        xxx    xx             xx    xx      xx xxx      xx   xxx   xxxx  ");
	mvprintw(11, (xMax - 83)/ 2, "   xxx    xxx        xxx    xx             xx    xx      xx  xxx     xx   xx     xxx  ");
	mvprintw(12, (xMax - 83)/ 2, " xx  xxx   xx        xxx   xx              xx   xx       xx   xxx     xx  x      xx   ");
	mvprintw(13, (xMax - 83)/ 2, "xx    xxx  xx        xxx   x                xx  x        xx    xx     xxx        xx   ");
	mvprintw(14, (xMax - 83)/ 2, "xx    xx   xx    x   xx   xxxxx     x       xx x         xx    xx      xxx       x    ");
	mvprintw(15, (xMax - 83)/ 2, " xx   x   xx    xx   xx   xxxxxx  xx         xxx         xxx   xxx  x  xxxxxx   xx    ");
	mvprintw(16, (xMax - 83)/ 2, "  xxxx   xx    xxx  xx   x   xxxxxx    x     xx          xx     xxxx    xxxxxxxxx     ");
	mvprintw(17, (xMax - 83)/ 2, "    xxxxxx      xxxx           xxx           x           x       xx       xxxxx       ");
	
	     
	refresh(); //SAME OUTPUT TIME
	
	// WINDOW INPUT
	WINDOW * menuwin = newwin(6, xMax-12, yMax-8, 5);
	box(menuwin, 0, 0);
	wrefresh(menuwin);
	
	// CHOICES 
	keypad(menuwin, true);
	

	while (1) {
    for (int i = 0; i < 3; i++) {
        if (i == highlight) {
            if (i == 1) {
                wattron(menuwin, COLOR_PAIR(2) | A_REVERSE); // HIGHLIGHT COLORING
            } else if (i == 2) {
                wattron(menuwin, COLOR_PAIR(3) | A_REVERSE);
            } else {
                wattron(menuwin, COLOR_PAIR(1) | A_REVERSE);
            }
        }
        mvwprintw(menuwin, i + 1, 1, choices[i].c_str());
        wattroff(menuwin, COLOR_PAIR(1) | COLOR_PAIR(2) | COLOR_PAIR(3) | A_REVERSE);
    }
    choice = wgetch(menuwin);

    switch (choice) { //KEY CONTROL
        case KEY_UP:
            highlight--;
            break;

        case KEY_DOWN:
            highlight++;
            break;
        case 10:
        	if(highlight==2){
        		endwin();         //EXIT CLOSE PROGRAM
        		return 0;
			}
			else if(highlight==1){
				showAboutPage(menuwin);	//ABOUT PAGE
				wclear(stdscr); //CLEAR ABOUT PAGE
				box(menuwin, 0, 0);
				refresh();;
			}
			break;
			
        default:
            break;
    }
	
    if (highlight < 0) {
        highlight = 2;  
    } else if (highlight > 2) {
        highlight = 0;  
    }

    if (choice == 10)
        break;
        
        wrefresh(menuwin);
}
	
}while(choice !=0);
	
	// PROGRAM WAIT TIME 
	getch();
	endwin();


	return 0;
}
