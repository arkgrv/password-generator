//[アダムスカ-シャラシャスカ] Adamska-Shalansaska X/V/MMXXI

#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/*Standard for the source*/
#include <cstdlib> //srand and rand functions
#include <ctime> //time manipulation
#include <fstream> //file I/O functions
#include <iostream> //I/O standard
#include <string> //Handling Strings
#include <vector> //Handling Vectors

/*Global alias*/
typedef std::string word; //alias for std::string
typedef std::vector<int> Ascii; //alias for std::vector<int> (i'm lazy)

/*min-length and max-length of token And limitations of generation*/
const int minSize = 8; //min/size of token
const int maxSize = 30; //max-size of token
const int avoid = 31;  //avoid the value range 1-31, because there are used by Assembler.
const int maxAscii = 128; //Extended ASCII

/*Error strings*/
const word FILES = "EMPTY_FILE";
const word INPUT = "EMPTY_INPUT";
const word VECTOR = "EMPTY_VECTOR";

/*Generation*/
namespace pass{
	bool isValid(const int); //check if value generate is not am assembly istruction

	Ascii generation(const int); //generate a random Ascii vector
	
	word createPassword(const Ascii&); //create the token piece to piece
}

/*Checking all fields*/
namespace checking{
	struct check; //declaration of a struct
	typedef std::vector<check> Fields; //Alias for the check variables

	void setAll(Fields&); //init all fields to true

	bool isNumber(char); //the character is a number?
	bool isAlpha(char); //the character is an alphanumericall?
	bool AoP(Fields); //check if a fields had his fields false (this is a trick :) )
	bool testConditions(word); //if this fail, the password is not valid
}

/*Auxiliary functions*/

void print(const Ascii&); //print the Ascii vector
void backup(std::ofstream&, word); //write a backup file

bool readFromFiles(word); //read the tokens from a file, if there is a file.

word exceptions(int); //throw an exception

#endif
