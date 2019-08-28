// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <array>

/*
Method to check if the date stamp matches the correct one
*/
bool checkDateStamp(std::string dataLine, std::string dateStamp, int lineNum) {
	//creates a substring that contains only the date
	std::string dateCheck = dataLine.substr(0, dataLine.find(','));
	//checks if the substring doesn't match the correct one
	if (dateCheck != dateStamp) {
		//prints out the error message
		std::cout << "Non-matching date stamp " << dateCheck << " at line " << lineNum << ".\n";
		return false;
	}
	else {
		return true;
	}

}

/*
Method to check if the time stamp is unique
*/
bool checkTimeStamp(std::string dataLine, std::set<std::string>& timeStamps, int lineNum) {
	//gets the initial size of the set
	int timeStampStartSize = timeStamps.size();
	//makes a substring of everything except the date
	std::string dataLineMinusDate = dataLine.substr(dataLine.find(',') + 1);
	//makes a substring of the time stamp
	std::string timeStampToCheck = dataLineMinusDate.substr(0, dataLineMinusDate.find(','));
	//attempts to insert the time stamp into the set
	timeStamps.insert(timeStampToCheck);

	//if the size of the set did not increase then the time stamp was not unique
	if (timeStampStartSize == timeStamps.size()) {
		//prints out error message
		std::cout << "Duplicate time stamp " << timeStampToCheck << " at line " << lineNum << "\n";
		return false;
	}
	else {
		return true;
	}

}

int main()
{
	//declare variables
    int dataLineNum = 1;
	std::string initialDateStamp = "";

	//declare array to contain data from each line and vector to hold all time stamps
	std::string drillingData[18];
	std::set<std::string> timeStamps;

	//declares variable to store file line in and then skips the first line
	std::string line = "";
	std::cin.ignore(1000, '\n');

	//while loop to iterate through the file collecting data line by line
	while (std::getline(std::cin, line)) {
		//assign date stamp
		if (initialDateStamp == "") {
			initialDateStamp = line.substr(0, line.find(','));
		}

		if (checkDateStamp(line, initialDateStamp, dataLineNum)) {
			std::cout << "Date stamp worked\n";
			
			if (checkTimeStamp(line, timeStamps, dataLineNum)) {
				std::cout << "Time stamp worked\n";
			}
		}

		dataLineNum++;
	}
	
	
	
	//check if date stamp does not match
	

	//check if time stamp is unique
	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
