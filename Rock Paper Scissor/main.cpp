#include <iostream>
#include <cstdlib>
#include <ctime> 

int main()
{
	int player, computer;
	int playerWin = 0;
	int computerWin = 0;
	std::srand(std::time(nullptr));

	std::cout << "(1) For Rock" << std::endl;
	std::cout << "(2) For Paper" << std::endl;
	std::cout << "(3) For Scissor " << std::endl;
	
	for (int i = 0; i < 3; i++) {
		while (true)
		{
			std::cout << "Choise: ";
			std::cin >> player;

			if (player < 0 || player > 3) std::cout << "Invalid input. Please enter a number between 1 and 3." << std::endl;
			else break;
		}

		computer = std::rand() % 3 + 1;

		if (player == 1)
		{
			if (computer == 1) std::cout << "Draw" << std::endl;
			if (computer == 2) {
				std::cout << "You lose" << std::endl;
				computerWin++;
			}
			if (computer == 3) {
				std::cout << "You Win" << std::endl;
				playerWin++;
			}
		}
		else if (player == 2)
		{
			if (computer == 1) {
				std::cout << "You Win" << std::endl;
				playerWin++;
			}
			if (computer == 2) std::cout << "Draw" << std::endl;
			if (computer == 3) {
				std::cout << "You lose" << std::endl;
				computerWin++;
			}
		}
		else
		{
			if (computer == 1) {
				std::cout << "You lose" << std::endl;
				computerWin++;
			}
			if (computer == 2) {
				std::cout << "You Win" << std::endl;
				playerWin++;
			}
			if (computer == 3) std::cout << "Draw" << std::endl;
		}
	}

	std::cout << "------------------------------------------------" << std::endl;
	if (playerWin < computerWin) std::cout << "Player Lose" << std::endl;
	else if (playerWin > computerWin) std::cout << "Player Win" << std::endl;
	else std::cout << "+ DRAW +" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;

	std::cin.get();
}