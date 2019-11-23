// MastermindsCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<memory>

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
	srand(time(NULL));
	std::unique_ptr<int[]> outputArray = std::make_unique<int[]>(4);
	for (size_t i = 0; i < 10; i++)
	{
		int x{};
		do {
			x = rand() % 10;
		} while (Contains(x, 10, outputArray.get()));

		outputArray[i] = x;
	}
	return outputArray;
}



int main()
{
	//This is the array that stores the input recieved from the user. 4 Numbers
	std::unique_ptr<int[]> inputArray = std::make_unique<int[]>(4);
	//This is the array that contains the answer for the mastermind game.
	std::unique_ptr<int[]> outputArray = std::make_unique<int[]>(4);

	//This group performs the input recieval fromm the user. [1].
	int count = 0; //[1]
	do // [1]
	{
		std::cout << "Enter in a number between 0-9 \n"; //[1]
		std::cin >> inputArray[count]; //[1]
		count++; //[1]
	} while (count < 4);

	outputArray = RandomCreator(); //This creates the answer key. [2]

	for (int i = 0; i < count; i++)
	{
		if (Contains(inputArray[i], count, outputArray.get()))
		{
			if (inputArray[i] == outputArray[i])
			{
				std::cout << "Correct: " << i << "\n";
			}
			else
			{
				std::cout << "Correct but wrong spot: " << i << "\n";
			}
		}
		else
		{
			std::cout << "Incorrect: " << i << "\n";
		}
	}
	//Correct
	//Correct but in wrong place
	//Incorrect
}
