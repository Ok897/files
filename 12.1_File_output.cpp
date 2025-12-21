#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::ofstream ofile{ "file.txt" };
	if (ofile.is_open()) {
		ofile << "Potato cabbage" << std::endl;
		ofile << "raspberry strawberry cherry" << std::endl;
		ofile << "apple pear orange" << std::endl;
	}
	ofile.close();

	std::ifstream ifile{ "file.txt" };
	if (ifile.is_open()) {
		std::string data{};

		while (ifile >> data) {
			std::cout << data << std::endl;
		}
	}
	ifile.close();

	return EXIT_SUCCESS;
}