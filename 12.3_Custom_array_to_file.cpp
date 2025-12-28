#include <iostream>
#include <fstream>
#include <string>

int main()
{
	int size{};
	std::cout << "Enter an array's size: ";
	std::cin >> size;

	int* arr = new int[size]();

	for (int i = 0; i < size; i++)
	{
		std::cout << "arr[" << i << "] = ";
		std::cin >> arr[i];
	}

	std::ofstream ofile("out.txt");
	if (ofile.is_open()) {
		ofile << size << std::endl;
		for (int i = 0; i < size; i++) {
			ofile << arr[i] << " ";
		}
	}
	ofile.close();

	delete[] arr;

	return EXIT_SUCCESS;
}