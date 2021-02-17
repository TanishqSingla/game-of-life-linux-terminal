#include <ncurses.h>
#include "universe.h"
using namespace std;

int main(int argc, char **argv)
{
	initscr();
	Universe universe = Universe();

	move(20, 50);

	// universe.render();

	// while (true)
	// {
	// 	universe.tick();
	// 	universe.render();
	// 	system("clear");
	// }
	getch();
	endwin();

	return 0;
}
