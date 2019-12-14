// MastermindsCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<memory>
#include <time.h>
#include <fstream>
#include<vector>
#include <string>
#include <sstream>

bool Contains(int number, int count, int* outputArray)
{
	for (size_t i = 0; i < count; i++)
	{
		if (number == outputArray[i])
		{
			return true;
		}
	}
	return false;
}

std::unique_ptr<int[]> RandomCreator()
{
	std::unique_ptr<int[]> outputArray = std::make_unique<int[]>(4);
	for (size_t i = 0; i < 4; i++)
	{
		int x{};
		do {
			x = rand() % 10;
		} while (Contains(x, 4, outputArray.get()));

		outputArray[i] = x;
	}
	return outputArray;
}

std::vector<std::string> SplitString(std::string input, char split)
{
	input += split;

	std::vector<std::string> words;

	std::string temp = "";
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] != split)
		{
			temp += input[i];
		}
		else
		{
			words.push_back(temp);
			temp = "";
		}
	}


	return words;
}



int main()
{
	srand(time(NULL));

	int finishedCount = 0;
	std::unique_ptr<int[]> outputArray = RandomCreator(); //This creates the answer key. [2]
	int tries = 0;

	do
	{
		//This is the array that stores the input recieved from the user. 4 Numbers
		std::unique_ptr<int[]> inputArray = std::make_unique<int[]>(4);
		//This is the array that contains the answer for the mastermind game.

		//This group performs the input recieval fromm the user. [1].
		int count = 0; //[1]
		do // [1]
		{
			std::cout << "Enter in a number between 0-9 \n"; //[1]
			std::cin >> inputArray[count]; //[1]
			count++; //[1]
		} while (count < 4);

		finishedCount = 0;

		for (int i = 0; i < 4; i++)
		{
			if (Contains(inputArray.get()[i], count, outputArray.get()))
			{
				if (inputArray.get()[i] == outputArray.get()[i])
				{
					std::cout << "Correct: " << inputArray.get()[i] << "\n";
					finishedCount++;
				}
				else
				{
					std::cout << "Correct but wrong spot: " << inputArray.get()[i] << "\n";
				}
			}
			else
			{
				std::cout << "Incorrect: " << inputArray.get()[i] << "\n";
			}
		}
		tries++;
	} while (finishedCount < 4);

	std::cout << "Congratulations! You have won in " << tries << " tries. \n";

	///
	//Our goal is to take a file
	//Add to it for every line we see as correct
	//Place our high score in the right sport
	//Release the information

	std::cin.ignore();

	std::cout << "Enter in your name!";
	std::string name;
	std::getline(std::cin, name);


	std::string line;
	std::vector<std::string> file;
	bool added = false;
	std::ostringstream oss;
	oss << name << ":" << tries;
	std::string var = oss.str();


	std::ifstream HighScore("HighScore.txt");
	//HighScore.open("HighScore.txt");

	//std::cin.ignore();

	if (!HighScore.is_open())
	{
		std::cout << "Unable to open file";
		exit(1);
	}

	for (int i = 0; std::getline(HighScore, line); i++)
	{
		auto stuff = SplitString(line, ':');
		int num = std::stoi(stuff[1]);
		if (tries < num)
		{
			file.push_back(var);
			added = true;
		}
		file.push_back(line);
		//If it is a highscore. Add
	}

	if (!added)
	{
		file.push_back(var);
	}

	HighScore.close();

	std::ofstream HighScoreOut;
	HighScoreOut.open("HighScore.txt", std::ofstream::out | std::ofstream::trunc);

	/*for (size_t i = 0; i < file.capacity(); i++)
	{
		HighScoreOut << line << "\n";
	}*/

	for (size_t i = 0; i < file.capacity(); i++)
	{
		HighScoreOut << file[i] << "\n";
	}

	HighScoreOut.close();
	//Correct
	//Correct but in wrong place
	//Incorrect

	return 0;
}