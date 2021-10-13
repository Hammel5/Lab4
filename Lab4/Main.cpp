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
#include <iomanip> // Allows to use the setw() function

using namespace std;

int rounding(int a);
int stars(int rTemp);

int main()
{
	ifstream inFile;
	inFile.open("TemperatureInputs.dat");

	int Temperature;

	cout << "Range: \t -30" << setw(9) << "0" << setw(11) << "30" << setw(10) << "60" << setw(10) << "90" << setw(10) << "120" << endl;
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

int rounding(int a) // Rounds the temp to a multiple of 3. Contains temporary variables for the calucations
{
	int b = a % 3;
	if (b == 2 || b == -1)
	{
		a = a + 1;
	}
	else if (b == 1 || b == -2)
	{
		a = a - 1;
	}
	return a;
}

int stars(int rTemp) // rTemp is the rounded temp
{
	if (rTemp < -30) // Runs and Outputs if the temperature is lower than the acceptable range
	{
		cout << "TEMPERATURE IS TOO LOW. IT IS OUTSIDE THE ACCEPTABLE RANGE";
	}
	else if (rTemp > 120) // Runs and Outputs if the temperature is higher than the acceptable range
	{
		cout << "TEMPERATURE IS TOO HIGH. IT IS OUTSIDE THE ACCEPTABLE RANGE";
	}
	else // Runs and Outputs if the temperature is in the acceptable range
	{
		int star = 0;
		int divided = rTemp / 3;
		int spacing = 10 + divided;
		int count = 0;

		if (rTemp >= 0) // Translates the number to stars for the positive numbers 
		{
			cout << setw(11) << "|";
			while (divided > star)
			{
				cout << "*";
				star = star + 1;
			}
		}
		else
		{
			while (count < spacing) // Creates the spacing for the bar to line up
			{
				cout << " ";
				count = count + 1;
			}

			while (divided < star) // Translates the number to stars for the negative numbers
			{
				cout << "*";
				star = star - 1;
			}
			cout << "|";
		}
	}
	return 0;
}