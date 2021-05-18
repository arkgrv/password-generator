#include "PasswordGenerator.h"

int main(int argc, char** argv)
{
	PwdGen::PasswordGenerator generator;
	generator.Charset() = 
		PwdGen::CharType::LOWER_CASE | PwdGen::CharType::DIGITS
		| PwdGen::CharType::PUNCT;
	std::cout << generator.Generate(10) << std::endl;
	return 0;
}
