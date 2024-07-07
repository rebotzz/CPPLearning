#include "game.hpp"

using namespace std;

void test()
{
	Table table(10, 20);
	table.Print();
	table.printBinary();
	cout << endl;

	Pattern("T").printPattern();
	Pattern("��").printPattern();
	Pattern("һ").printPattern();
	Pattern("L").printPattern();
	//Pattern("?").printPattern();
}

// ����˹����
int main()
{
	srand((unsigned int)time(nullptr));
	Game game;
	game.start();

	return 0;
}