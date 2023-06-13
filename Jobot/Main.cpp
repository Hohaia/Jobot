#include <iostream>

#include "Includes/Commands.h"
#include "Includes/Secrets.h"

int main() {
	// TEST AREA
	string fact = random_Fact();
	std::cout << fact << std::endl;

	string random = random_number_generator(10, 20);
	std::cout << random << std::endl;
	// TEST AREA END
}