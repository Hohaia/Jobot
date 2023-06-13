#include <cpr/cpr.h>
#include <string>
#include <random>

#include "Secrets.h"

using std::mt19937;
using std::random_device;
using std::string;
using std::to_string;
using std::uniform_int_distribution;

/// Return a random fact (using api.api-ninjas.com)
string random_Fact() {
	auto response = cpr::Get(cpr::Url{"https://api.api-ninjas.com/v1/facts?limit=1"}, cpr::Header{{"X-Api-Key", apiKey}}); // Send GET request to API
	if (response.error)
		return "Request FAIL";                                                                                             // Return error message if request fails
	string fact = response.text.substr(11, response.text.size() - 14);                                                     // Remove "{'message':" and "}" from response
	fact = "Fact: " + fact + ".";

	return fact;
}

/// Return a random number between lowerLimit and upperLimit (betweeen 1 and 10 by default if no arguments are passed)
string random_number_generator(int lowerLimit = 1, int upperLimit = 10) {
	random_device rd;                                       // Obtain a random number from hardware
	mt19937 gen(rd());                                      // Seed the generator
	uniform_int_distribution<> dis(lowerLimit, upperLimit); // Define the range
	int num = dis(gen);                                     // Generate random number between lowerLimit and upperLimit

	return to_string(num);