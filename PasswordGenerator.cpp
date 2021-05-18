#include "PasswordGenerator.h"

namespace PwdGen {
	const std::string PasswordGenerator::S_LowerCaseLetters =
		"abcdefghijklmnopqrstuvwxyz";
	const std::string PasswordGenerator::S_UpperCaseLetters =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const std::string PasswordGenerator::S_Digits =
		"0123456789";
	const std::string PasswordGenerator::S_Punct =
		"!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~";

	PasswordGenerator::PasswordGenerator()
	: M_Charset(0), M_RandomGenerator(std::random_device{}()) {}

	PasswordGenerator::PasswordGenerator(unsigned charset)
		: M_Charset(charset),
		M_RandomGenerator(std::random_device{}()) {}

	std::string PasswordGenerator::Generate(size_t length) const
	{
		std::string charset = GetEffectiveCharset();
		std::uniform_int_distribution<size_t> dist(0, charset.length() - 1);
		std::string password = "";
		for (size_t i = 0; i < length; ++i)
			password.push_back(charset[dist(M_RandomGenerator)]);
		return password;
	}

	unsigned& PasswordGenerator::Charset() { return M_Charset; }

	const unsigned PasswordGenerator::Charset() const { return M_Charset; }

	std::string PasswordGenerator::GetEffectiveCharset() const
	{
		std::string charset = "";
		if (M_Charset & CharType::LOWER_CASE)
			charset.append(S_LowerCaseLetters);
		if (M_Charset & CharType::UPPER_CASE)
			charset.append(S_UpperCaseLetters);
		if (M_Charset & CharType::DIGITS)
			charset.append(S_Digits);
		if (M_Charset & CharType::PUNCT)
			charset.append(S_Punct);
		return charset;
	}
}