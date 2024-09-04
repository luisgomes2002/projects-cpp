#include <iostream>
#include <cmath>

class Calculator {
private:
	float num1, num2;
	int choiseFuc;

	void Sum(float num1, float num2)
	{
		float result = num1 + num2;
		std::cout << "Result: " << result << std::endl;
	}

	void Subtraction(float& num1, float& num2)
	{
		float result = num1 - num2;
		std::cout << "Result: " << result << std::endl;
	}

	void Multiplication(float& num1, float& num2)
	{
		float result = num1 * num2;
		std::cout << "Result: " << result << std::endl;
	}

	void Division(float& num1, float& num2)
	{
		if (!num2 == 0)
		{
			float result = num1 / num2;
			std::cout << "Result: " << result << std::endl;
		}

		std::cout << "Error!" << std::endl;
	}

	void Pow(float& num1, float& num2)
	{
		float result = std::pow(num1, num2);
		std::cout << "Result: " << result << std::endl;
	}

	void Sin(float& num1)
	{
		float result = std::sin(num1);
		std::cout << "Result: " << result << std::endl;
	}

	void Cos(float& num1)
	{
		float result = std::cos(num1);
		std::cout << "Result: " << result << std::endl;
	}

	void Tg(float& num1)
	{
		float result = std::tan(num1);
		std::cout << "Result: " << result << std::endl;
	}

public:
	Calculator() {};

	~Calculator() {};

	void Run()
	{
		Functions();

		if (choiseFuc <= 5)
		{
			std::cout << "Param 1: ";
			std::cin >> num1;
			std::system("cls");

			std::cout << "Param 2: ";
			std::cin >> num2;
			std::system("cls");
		}
		else
		{
			std::cout << "Param 1: ";
			std::cin >> num1;
			std::system("cls");
		}
		

		switch (choiseFuc) {
		case 1: Sum(num1, num2); break;
		case 2: Subtraction(num1, num2); break;
		case 3: Multiplication(num1, num2); break;
		case 4: Division(num1, num2); break;
		case 5: Pow(num1, num2); break;
		case 6: Sin(num1); break;
		case 7: Cos(num1); break;
		case 8: Tg(num1); break;
		default: std::cout << "Invalid choice!" << std::endl; break;
		}

		std::cout << "New calculation?" << std::endl;
		std::cout << " (1) Yes (2) No" << std::endl;
		std::cin >> choiseFuc;

		if (choiseFuc == 1) Run();
	}

	void Functions()
	{
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "+  (1) Sum             (5) Pow    +" << std::endl;
		std::cout << "+  (2) Subtraction     (6) Sin    +" << std::endl;
		std::cout << "+  (3) Multiplication  (7) Cos    +" << std::endl;
		std::cout << "+  (4) division        (8) Tg     +" << std::endl;
		std::cout << "-----------------------------------" << std::endl;
		std::cin >> choiseFuc;
		std::system("cls");
	}
};

int main()
{
	Calculator calculator;
	calculator.Run();

	std::cin.get();
}