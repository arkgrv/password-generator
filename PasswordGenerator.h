#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <random>
#include <iostream>
#include <string>
#include <chrono>

namespace PwdGen {
	enum CharType {
		LOWER_CASE = 1,
		UPPER_CASE = 2,
		DIGITS = 4,
		PUNCT = 8
	};

	class PasswordGenerator {
	public:
		PasswordGenerator();
		explicit PasswordGenerator(unsigned charset);

		std::string Generate(size_t length) const;

		unsigned& Charset();
		const unsigned Charset() const;

		std::string GetEffectiveCharset() const;
	private:
		static const std::string S_LowerCaseLetters;
		static const std::string S_UpperCaseLetters;
		static const std::string S_Digits;
		static const std::string S_Punct;
		
		unsigned M_Charset;

		// Non-static members
		mutable std::mt19937_64 M_RandomGenerator;
	};
}

#endif
