#include <iostream>
#include <vector>

int main()
{
	int numCourses;

	float totalWeightedGradePoints{}, totalCredits{};

	std::vector<float> Grade;
	std::vector<float> Credit;

	std::cout << "Quantos cursos: ";
	std::cin >> numCourses;

	for (int i = 0; i < numCourses; i++)
	{
		float grade, credit;
		std::cout << "Enter grade and credit for course " << (i + 1) << ": ";
		std::cin >> grade >> credit;

		Grade.push_back(grade);
		Credit.push_back(credit);
	}

	for (int i = 0; i < numCourses; i++) {
		totalWeightedGradePoints += Grade[i] * Credit[i];
		totalCredits += Credit[i];
	}

	float CGPA = totalWeightedGradePoints / totalCredits;
	if (totalCredits != 0) {
		CGPA = totalWeightedGradePoints / totalCredits;
	}

	float CGPAPercen = CGPA * 9.5;
	float GPAPercen = (CGPA / 10) * 100;
	
	std::cout << "CGPA: " << CGPA << std::endl;
	std::cout << "CGPA Percentage: " << CGPAPercen << "%" << std::endl;
	std::cout << "GPA Percentage: " << GPAPercen << "%" << std::endl;


	std::cin.get();
}