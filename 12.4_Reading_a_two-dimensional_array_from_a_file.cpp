#include <iostream>
#include <string>
#include <fstream>

int** create_two_dim_array(int rows, int columns);

int main()
{
	int rows{}, columns{};

	std::ofstream ofile("in.txt");
	if (ofile.is_open()) {
		ofile << "2 5" << std::endl;
		ofile << "1 3 5 7 8" << std::endl;
		ofile << "2 4 6 9 0" << std::endl;
	}
	ofile.close();

	std::ifstream ifile("in.txt");
	if (ifile.is_open()) {
		ifile >> rows;
		ifile >> columns;

		int** arr;
		arr = create_two_dim_array(rows, columns);

		for (int i = 0; i < rows; i++) {
			for (int j = (columns - 1); j >= 0; j--) {
				ifile >> arr[i][j];
			}
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				std::cout << arr[i][j] << ' ';
			}
			std::cout << std::endl;
		}

		for (int i = 0; i < rows; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}
	ifile.close();

	return EXIT_SUCCESS;
}

int** create_two_dim_array(int rows, int columns)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[columns];
	}
	return arr;
}