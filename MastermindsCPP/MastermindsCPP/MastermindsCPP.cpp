// MastermindsCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<memory>
#include <time.h>

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

	std::cout << "Congratulations! You have won in " << tries << " tries.";
	//Correct
	//Correct but in wrong place
	//Incorrect
}
