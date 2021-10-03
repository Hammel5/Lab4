/*
	Dalton Hammel
	C++ Fall 2021
	Due: 10/13/2021
	Lab 4 Temperature Output

	Design and write a C++ program that inputs a series of hourly temperature from a file, and outputs a bar chart 
	(using stars) of the temperatures. The temperature should be printed to the left of the corresponding bar, and 
	there should be a heading that gives the scale of the chart. The range of temperatures should be from  -30 to 120. 
	Because it is hard to display 150 characters on the screen, you should have each star represent a range of 3 degrees. 
	That way, the bars will be at most 50 characters wide. Use meaningful variable names, proper indentation, and appropriate 
	comments. Thoroughly test the program using your own data sets. Make sure to vet the values from the input file.
*/

#include <iostream> // Allows the ability to input and output 
#include <fstream> // Allows for File Read and Write

using namespace std;

int rounding(int b);
int stars(int d);

int main()
{
	ifstream inFile;
	inFile.open("TemperatureInputs.dat");

	int Temperature;

	cout << "Every * is a repsentation of 3 degrees. Like 15 is equal to ***** " << endl << "The range of the graph is - 30 to 120. The | is the 0 mark" << endl << endl;
	while (!inFile.eof()) // Run the program until it reads everything in the file
	{
		inFile >> Temperature;
		cout << Temperature << "\t" << "- ";
		int rounded = rounding(Temperature);
		stars(rounded);
		cout << endl;
	}

	inFile.close();
}

int rounding(int b) // Rounds the temp to a multiple of 3
{
	int c = b % 3;
	if (c == 2 || c == -1)
	{
		b = b + 1;
	}
	else if (c == 1 || c == -2)
	{
		b = b - 1;
	}
	return b;
}

int stars(int d)
{
	if (d < -30) // Changes the Temp to be in the acceptable range -30 to 120
	{
		d = -30;
	}
	else if (d > 120)
	{
		d = 120;
	}

	int star = 0;
	int divided = d / 3;
	int temp = 10 + divided;
	int e = 0;

	if (d >= 0)
	{
		cout << "          |";
		while (divided > star)
		{
			cout << "*";
			star = star + 1;
		}
	}
	else
	{
		while (e < temp) // Creates the spacing for the bar to line up
		{
			cout << " ";
			e = e + 1;
		}
		
		while (divided < star)
		{
			cout << "*";
			star = star - 1;
		}
		cout << "|";
	}
	return 0;
}

// heading to give scale of bar graph
// Ask about how bar is actually supposed to look like
// better variable names
// appropriate comments
// 