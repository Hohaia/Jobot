#include <iostream>

#include "Includes/Commands.h"
#include "Includes/Secrets.h"

int main() {
	string fact = randomFact();
	std::cout << fact << std::endl;
}