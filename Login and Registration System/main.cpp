#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>

bool studentExists(const std::string& username) {
	std::ifstream file("userDB.txt");
	std::string line, storedStudent;

	while (std::getline(file, line)) {
		std::istringstream iss(line);
		if (std::getline(iss, storedStudent, ',') && storedStudent == username) {
			return true;
		}
	}

	return false;
}

void registerStudent() {
	std::string username, password;

	std::cout << "Digite seu login";
	std::cin >> username;

	if (studentExists(username)) {
		std::cout<< "Usuário já existe.\n";
		return;
	}

	std::cout << "Digite sua senha";
	std::cin >> password;

	std::ofstream file("userDB.txt", std::ios::app);
	if (file.is_open()) {
		file << username << "," << password <<"\n";
		file.close();
		std::cout << "Usuário registrado com sucesso!\n";
	}
	else {
		std::cerr << "Erro ao abrir o arquivo.\n";
	}

}

bool login() {
	std::string username, password, line, storedStudent, storedPassword;

	std::cout << "Digite o nome de usuário: ";
	std::cin >> username;
	std::cout << "Digite a senha: ";
	std::cin >> password;

	std::ifstream file("userDB.txt");

	if (!file.is_open()) {
		std::cerr << "Erro ao abrir o arquivo.\n";
		return false;
	}

	while (std::getline(file, line)) {
		std::istringstream iss(line);
		if (std::getline(iss, storedStudent, ',')) {

		}
	}
}

int main()
{


	std::cin.get();
}
