#include <iostream>
#include <cmath>

class Calculator
{
private:
	float num1, num2;
	float result;

	void sum(float num1, float num2)
	{
		float res = num1 + num2;
		std::cout << "Resultado: " << res << std::endl;
	};

public:
	~Calculator() {};
	Calculator() {};

	void run()
	{
		std::cout << "Digite o primeiro numero: ";
		std::cin >> num1;
		std::system("cls");

		std::cout << "Digite o sergundo numero: ";
		std::cin >> num2;
		std::system("cls");

		sum(num1, num2);
	};
};

int main()
{
	Calculator calc;
	calc.run();

	std::cin.get();
}