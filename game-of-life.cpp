#include <ncurses.h>
#include "universe.h"
using namespace std;

int main(int argc, char **argv)
{
	initscr();
	Universe universe = Universe();

	universe.render();
	refresh();
	while (true)
	{
		universe.tick();
		universe.render();
		refresh();
	}
	getch();
	endwin();

	return 0;
}
