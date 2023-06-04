#include <string>
#include <cpr/cpr.h>

#include "Secrets.h"

using std::string;

/// <summary>
/// Returns a random fact from the API
/// </summary>
/// <returns></returns>
string randomFact() {
	auto response = cpr::Get(cpr::Url{"https://api.api-ninjas.com/v1/facts?limit=1"}, cpr::Header{{"X-Api-Key", apiKey}});
	if (response.error)
		return "Request FAIL";

	string fact = response.text.substr(11, response.text.size() - 14); // Remove "{'message':" and "}" from response
	fact = "Fact: " + fact + ".";

	return fact;
}