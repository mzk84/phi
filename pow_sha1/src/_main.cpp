#include "_includes.h"
#include "_mzk84_utils.h"
#include "PoW_SHA1.h"

int main() {

	std::cout << "\n************************************************************\n";
	std::cout << "Proof of Work SHA1 Test\n\n";

	size_t prefix_len = 64;
	size_t difficulty = 6;

	for (auto i = 0; i < 5; i++) {
		std::string prefix = mzk84_utils::get_random_string(prefix_len);
		PoW_SHA1_Runner(prefix, difficulty, 1);
	}
}