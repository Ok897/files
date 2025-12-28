#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ofstream ofile("arr.txt");
	if (ofile.is_open()) {
		ofile << "5" << std::endl;
		ofile << "1 3 6 8 7" << std::endl;
	}
	ofile.close();

	std::ifstream ifile("arr.txt");
	if (ifile.is_open()) {
		std::string data{};

		int size{};
		ifile >> size;

		int* array = new int[size]();

		for (int i = (size - 1); i >= 0; i--) {
			ifile >> data;
			array[i] = std::stoi(data);
		}

		for (int i = 0; i < size; i++) {
			std::cout << array[i] << ' ';
		}

		delete[] array;
	}
	ifile.close();

	return EXIT_SUCCESS;
}