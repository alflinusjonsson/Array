#include <iostream>
#include "Array.h"

int main() {

	Array<std::string, 5> data;

	for (size_t i = 0; i < data.Size(); i++) {
		data[i] = "Hello World!";
	}

	std::cout << "Not using iterator" << std::endl;
	for (size_t i = 0; i < data.Size(); i++) {
		std::cout << data[i] << std::endl;
	}

	std::cout << "Using iterator" << std::endl;
	for (std::string s : data) {
		std::cout << s << std::endl;
	}

	Array<int, 5> values;

	for (size_t i = 0; i < values.Size(); i++) {
		values[i] = i;
	}

	std::cout << "Not using iterator" << std::endl;
	for (size_t i = 0; i < values.Size(); i++) {
		std::cout << values[i] << std::endl;
	}

	std::cout << "Using iterator" << std::endl;
	for (int value : values) {
		std::cout << value << std::endl;
	}

	std::cin.get();
}