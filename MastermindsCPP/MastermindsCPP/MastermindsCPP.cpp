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

	auto stuff = SplitString("this is a test", ' ');

	;
	/*
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

	*/

	int tries = 4;
	//std::ifstream file("HighScore");
	//std::string str;
	//std::string file_contents;

	//std::cout << "Enter in your name!";
	//std::string name;
	///*std::cin >> name;*/
	//std::getline(std::cin, name);

	//std::ofstream HighScore;
	//HighScore.open("HighScore.txt", std::ios_base::app);

	//int ind = 0;
	//while (std::getline(file, str))
	//{
	//	auto stuff = SplitString(str, ':');
	//	int num = std::stoi(stuff[1]);
	//	if (tries < num)
	//	{
	//		break;
	//	}
	//	file_contents += num;
	//	file_contents.push_back('\n');
	//	ind++;
	//}



	//HighScore << name << ":" << tries << "\n";
	////figure out how to put the position at ind
	//HighScore.close();


	///
	//Our goal is to take a file
	//Add to it for every line we see as correct
	//Place our high score in the right sport
	//Release the information

	std::cout << "Enter in your name!";
	std::string name;
	std::getline(std::cin, name);

	std::ifstream HighScore;
	HighScore.open("HighScore.txt");

	if (!HighScore)
	{
		std::cout << "Unable to open file";
		exit(1);
	}

	std::string line;
	std::vector<std::string> file;
	for (int i = 0; std::getline(HighScore, line); i++)
	{
		auto stuff = SplitString(line, ':');
		int num = std::stoi(stuff[1]);
		if (tries < num)
		{
			std::ostringstream oss;
			oss << name << ":" << tries;
			std::string var = oss.str();
			file.push_back(var);
		}
		file.push_back(line);
		//If it is a highscore. Add
	}

	HighScore.close();

	std::ofstream HighScoreOut;
	HighScoreOut.open("HighScore.txt", std::ios_base::app);

	/*for (size_t i = 0; i < file.capacity(); i++)
	{
		HighScoreOut << line << "\n";
	}*/

	HighScoreOut.close();
	//Correct
	//Correct but in wrong place
	//Incorrect

	return 0;
}