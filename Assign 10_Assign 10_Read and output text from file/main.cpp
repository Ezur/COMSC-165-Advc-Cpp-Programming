//============================================================================
// Name        : PA 10 Read and output text from a file
// Author      : Elise Zur
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

void read_file(ifstream&, char*);
void output_data(int*, const string*);
void file_statistics(char*, int*, int);
void print_highest(const char*, int*);

const int NUM_OF_MONTHS = 3;
const int NUM_OF_DAYS = 30;
const int NUM_TYPES = 3;

int main()
{
	// this 2D array stores the 90 values from the RainOrShine.txt text file
	char weather[NUM_OF_MONTHS][NUM_OF_DAYS];
	char* ptr = &weather[0][0];  // this pointer points to the beginning of the 2Darray
								 // Remember -- no using the brackets/subscripts ([]'s)!
								 // Everything should be handled with pointer offset notation
								 // and/or pointer arithmetic

	int totals[NUM_OF_MONTHS + 1][NUM_TYPES] = { };
	int* counter = &totals[0][0];

	const string MONTHS[NUM_OF_MONTHS] = {"June", "July", "August"};
	const string* month_names = &MONTHS[0];

	int maxRange = (NUM_OF_MONTHS + 1) * (NUM_TYPES);

	string fileName = "RainOrShine.txt";

	ifstream fin(fileName);
	read_file(fin, ptr);
	fin.close();

	file_statistics(ptr, counter, maxRange);

	output_data(counter, month_names);

	print_highest(ptr, counter);

	return 0;

}

// COMMENT ONE
// read_file function receives an ifstream file input object
// and ptr which points to the beginning of the 2D array.
// using input validation, the function prints out ERROR
// when there is a problem accessing the file.
// the while loop will push the values into an array
// that ptr is pointing to.
void read_file(ifstream &fin, char* ptr)
{
	char input;

	if(!fin)
		cout << "ERROR";
	else
		while (fin >> input)
		{
			*ptr = input;
			ptr++;
		}
}

// COMMENT TWO
// output_data function will traverse through the array
// using pointer notation to output the results and information
// that was stored inside of the array.
void output_data(int* counter, const string* month_names)
{
	cout << "\tSummer Weather Report\n\n";
	cout << "Month" << setw(11) << "Rainy" << setw(10) << "Cloudy" << setw(8) << "Sunny" << endl;
	cout << "_____________________________________" << endl;

	// COMMENT THREE
	// the for loop goes through the array, 4 times, (NUM_OF_MONTHS + 1),
	// and outputs the months. the inner for loop will output the
	// data values associated with each condition
	// that are accumulated in file_statistics function.
	for(int month = 0; month < NUM_OF_MONTHS + 1; month++)
		{
			cout << endl << left << *(month_names + month) << "\t";
			for(int condition = 0; condition < NUM_TYPES; condition++)
				cout << setw(9) << right << *(counter + condition);
			counter += 3;
		}
}

// for loop traversing through array using ptr pointer.
// counter is being used to keep track of number of times each R/C/S shows up
// maxRange is total number of array elements
// offset is var set to 0 that will set the pointer's position to our next array element
// not actually moving pointer

// COMMENT FOUR
// file_statistics function has nested for loops that step through
// the array via the number of months (outer loop) and then through
// the number of days in the months (inner loop). the function
// receives a pointer, counter pointer, and variable maxRange.
void file_statistics(char* ptr, int* counter, int maxRange)
{
	int offset = 0;

	// COMMENT FIVE
	// the counter variable is being used to keep track of number
	// of times each condition shows up.
	// maxRange variable is the total number of array elements.
	for(int month = 0; month < NUM_OF_MONTHS; month++)
	{

		// COMMENT SIX
		// the inner for loop uses pointer notation to access
		// the array through the counter pointer. line 130
		// is the daily count incrementing for each month.
		// line 133 is the total number of conditions
		// for one month at a time.
		for(int day = 0; day < NUM_OF_DAYS; day++)
		{
			if(*(ptr) == 'R')
			{
				(*(counter + offset))++;
				(*(counter + maxRange - 3))++;
			}
			if(*(ptr) == 'C')
			{
				(*(counter + offset + 1))++;
				(*(counter + maxRange - 2))++;
			}
			if(*(ptr) == 'S')
			{
				(*(counter + offset + 2))++;
				(*(counter + maxRange - 1))++;
			}
			ptr++;
		}
		// COMMENT SEVEN
		// the offset variable here is used to help correctly
		// traverse through the array. it does this by incrementing
		// the variable by 3.
		// the variable jumps through the array in order to access
		// each condition one month at a time.
		offset += 3;
	}

}

// COMMENT EIGHT
// print_highest function receives a constant char pointer, and
// uses a pointer named counter to point at the totals array.
// the totals array will keep track of the total number of
// conditions that appear throughout the 3 months.
void print_highest(const char* ptr, int* counter)
{
	// COMMENT NINE
	// the variable, highest, is set to the dereferenced value of the
	// pointer named counter. it is then used inside the for loop
	// with pointer notation to step through the rainy conditions
	// for each month.
	int highest = (*(counter));

	for (int i = 0; i < NUM_OF_MONTHS; i++)
		if (*(counter + (i * 3)) > highest)
			highest = *(counter + (i * 3));

	// COMMENT TEN
	// this block of if/else if statements will compare the rainy
	// row of data values for each month. it will compare the values
	// and output which month has the highest value.
	if(highest == *(counter))
		cout << "\n\nJune has the most rainy days.";
	else if(highest == *(counter + 3))
		cout << "\n\nJuly has the most rainy days.";
	else if(highest == *(counter + 6))
		cout << "\n\nAugust has the most rainy days.";

}
