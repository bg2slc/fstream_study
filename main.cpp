#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int SIZE = 20; //max number of goblins

struct Goblin {
	string name;
	int strength;
	double height;
};

/** prototypes */
int load_array(ifstream&, Goblin[]);
void os_exit();

int main()	{
	Goblin goblins[SIZE];
	int length;

	ifstream fin("input.dat");
	if (!fin.is_open())	{
		cout << "error opening file for input." << endl;
		exit(-1);
	}
	ofstream fout("output.dat");
	if (!fout.is_open())	{
		cout << "error opening file for output." <<endl;
		exit(-1);
	}

	length = load_array(fin, goblins);

	//end of program
	os_exit();
}

int load_array(ifstream& fin, Goblin goblins[])	{
	int length = 0;
	for (int index = 0; index < SIZE; index++)	{
		
	}
	return length;
}

void sort_goblins_by_strength(Goblin goblins[], int length)	{
	
}


//allows compiler to select exit command based on OS (not fully tested yet)
void os_exit()	{
	#ifdef linux
		system("echo end of program");
	#endif
	#ifdef _WIN32
		system("type end of program");
	#endif
	exit(0);
}
