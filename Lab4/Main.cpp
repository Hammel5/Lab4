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

int main()
{
	ifstream inFile;

	inFile.open("TemperatureInputs.dat");
	
	while (!inFile.eof())
	{
		int a;
		inFile >> a;
		cout << a;
		rounding(a);
		cout << endl;
	}

	inFile.close();
}

int rounding(int b)
{
	int c = b % 3;
	cout << " " << c;
	return 0;
}

// bar of stars with the temp to the bar left of the bar
// heading to give scale of bar graph
// range -30 to 120
// one star = 3 degrees
// 
// 

