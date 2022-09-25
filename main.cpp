#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int SIZE = 10; //max number of goblins

struct Goblin {
	string name;
	int strength;
	double height;
};

/** prototypes */
int loadArray(ifstream&, Goblin[]);
void printArray(const Goblin[], const int);
void os_exit();
bool goblinCompare(Goblin, Goblin);
void merge(Goblin[], int const, int const, int const);
void mergeSort(Goblin [], int const, int const);

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
	length = loadArray(fin, goblins);
	printArray(goblins, length);
	mergeSort(goblins, 0, length - 1);
	printArray(goblins, length);
	//end of program
	os_exit();
}

/** use input file to populate arrays, stop when reaching MAX limit or eof */
int loadArray(ifstream& fin, Goblin goblins[])	{
	int length = 0;
	for(; length < SIZE; length++)	{
		getline(fin, goblins[length].name);
		fin >> goblins[length].strength;
		fin >> goblins[length].height;
		fin.ignore(80,'\n');
		if(fin.eof()) break;
	}
	return length;
}

/** helper function for mergeSort */
void merge(Goblin goblins[], int const left, int const mid, int const right)	{
	//set subarray lengths.
	int const subA = mid - left + 1;
	int const subB = right - mid;
	//create sub arrays
	Goblin *leftArray = new Goblin[subA],
		*rightArray = new Goblin[subB];

	// Copy to sub arrays
	for(int index = 0; index < subA; index++)
		leftArray[index] = goblins[left + index];
	for(int index = 0; index < subB; index++)
		rightArray[index] = goblins[mid + 1 + index];
	
	int indexOfSubA = 0,
		indexOfSubB = 0,
		indexOfMerge = left;
	//while either subarray A or subarry B has elements left...
	while(indexOfSubA < subA && indexOfSubB < subB) {
		if(goblinCompare(rightArray[indexOfSubB],leftArray[indexOfSubA]))	{
			goblins[indexOfMerge] = leftArray[indexOfSubA];
			indexOfSubA++;
		}
		else	{
			goblins[indexOfMerge] = rightArray[indexOfSubB];
			indexOfSubB++;
		}
		indexOfMerge++;
	}
	//Copy remaining elements of left[] or right[] after other is inserted.
	while(indexOfSubA < subA)	{
		goblins[indexOfMerge] = leftArray[indexOfSubA];
		indexOfSubA++;
		indexOfMerge++;
	}
	while(indexOfSubB < subB)	{
		goblins[indexOfMerge] = rightArray[indexOfSubB];
		indexOfSubB++;
		indexOfMerge++;
	}

	delete[] leftArray;
	delete[] rightArray;
}

/** mergeSort call function */
void mergeSort(Goblin goblins[], int const left, int const right)	{
	cout << left << " > " << right << " = " << (left > right) << endl;
	if (left < right)	{
		int mid = left + (left - right) / 2;
		cout << "sorting between index " << left << ", " << mid << endl;
		mergeSort(goblins, left, mid);
		cout << "sorting between index " << mid + 1 << ", " << right << endl;
		mergeSort(goblins, mid + 1, right);
		merge(goblins, left, mid, right);
	}
	//else, if left >= right then do nothing.
}

//returns true if Goblin A is greater than or equal to Goblin B.
bool goblinCompare(Goblin a, Goblin b)	{
	bool aIsGreater = false;
	if (a.strength >= b.strength)	aIsGreater = true;
	else
		if (a.height >= b.height)	aIsGreater = true;
	return aIsGreater;
}

void printArray(const Goblin goblins[], const int length)	{
	cout << setw(15) << left << "Name" << setw(9) << right << "Strength" << setw(9) << right << "Height" << endl;
	for (int index = 0; index < length; index++)	{
		cout << setw(15) << left << goblins[index].name << setw(9) << right << goblins[index].strength << setw(9) << right << goblins[index].height << endl;
	}
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
