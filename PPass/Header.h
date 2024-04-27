#pragma once
#include <string>

namespace PPass {
	std::string pass_gen(int length, int count, bool useNumbers, bool useSmallLetters, bool useBigLetters, bool useSpecialSymbols);
}
