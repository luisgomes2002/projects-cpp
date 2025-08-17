#include <iostream>
#include <cstdlib>

class Casino {
private:
	int numbers[3];
	float coin;
	int choice;
	std::string playerName;
	float value;
	int matchesPlayed;

	int RandNum()
	{
		int randN = (std::rand() % 9) + 1;
		return randN;
	}

	void VerifyMatch(const int(&numbers)[3])
	{
		if (numbers[0] == numbers[1] && numbers[1] == numbers[2])
		{
			std::cout << "You Win" << std::endl;
			coin += 3.5;
		}
		else std::cout << "You Lose" << std::endl;

		std::cout << "Play again?" << std::endl;
	}

	void Display(const int(&numbers)[3])
	{
		std::cout << "-------------------" << std::endl;
		std::cout << "|  " << numbers[0] << "  |  " << numbers[1] << "  |  " << numbers[2] << "  |" << std::endl;
		std::cout << "-------------------" << std::endl;
	}

	void Play()
	{
		for (int& num : numbers) {
			num = RandNum();
		}
	}

public:
	Casino() : coin(10), matchesPlayed(1)
	{
		std::cout << "What is your name?" << std::endl;
		std::cin >> playerName;

		std::system("cls");

		std::cout << playerName << " Welcome to Casino" << std::endl;
	}

	~Casino() {}

	void Run()
	{
		if (coin <= 2.0)
		{
			std::cout << "Not enough coins!" << std::endl;
			AddCoins();
		}

		coin -= 2.0;
		matchesPlayed++;
		
		Play();
		Display(numbers);
		VerifyMatch(numbers);


		Menu();
	}

	void PrintInfos()
	{
		std::cout << "Player: " << playerName << std::endl;
		std::cout << "Wallet: " << coin << std::endl;
		std::cout << " " << std::endl;

		Menu();
	}

	void Menu()
	{
		std::cout << "-------------------" << std::endl;
		std::cout << "+    (1) Play     +" << std::endl;
		std::cout << "+    (2) Wallet   +" << std::endl;
		std::cout << "+    (3) Exit     +" << std::endl;
		std::cout << "-------------------" << std::endl;
		std::cin >> choice;

		std::system("cls");

		if (choice < 1 || choice > 3) {
			Menu();
			std::cout << "Invalid number try again!" << std::endl;
		}

		if (choice == 1) Run();
		if (choice == 2) PrintInfos();
		if (choice ==  3) system("exit");
	}

	void AddCoins()
	{
		std::cout << "Add more coins?" << std::endl;
		std::cout << "+    (1) Yes (2) No    +" << std::endl;
		std::cin >> choice;

		std::system("cls");

		if (choice == 1)
		{
			std::cout << "Value: ";
			std::cin >> value;
			std::system("cls");

			coin += value;
			AddCoins();
		}
		if (choice == 2) Menu();
	}
};

int main()
{
	Casino casino;
	casino.Menu();

	std::cin.get();
}