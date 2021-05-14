//[アダムスカ-シャラシャスカ] Adamska-Shalansanska X/V/MMXXI

#include "header.h" //header/functions

/*checking struct*/
struct checking::check {
	bool number;
	bool alpha;
};

/*generation part*/

/*isn't an assembler register or the value is much bigger*/
bool pass::isValid(const int val) { return ((val >= avoid) && (val <= maxAscii)); }

/*generate the ascii vector*/
Ascii pass::generation(const int length){
	Ascii a;
	int i = 0;

	while(i < length){
		int val = rand() %maxAscii + 1;
		if (!isValid(val)) continue;
		a.push_back(val);
		i++;
	}
	return a;
}

/*convert the ascii code to the ascii characters*/
word pass::createPassword(const Ascii& v) {
	if (v.empty()) throw - 2;
	word passwd;

	for (unsigned int i = 0; i < v.size(); i++) passwd += (char)v.at(i); //a simple way to convert an integer to char without functions
	return passwd;
}

/*Checking conditions part*/

/*init all fields (size of passwd)*/
void checking::setAll(Fields& f){ for(unsigned int i = 0; i < f.size(); i++) f.at(i).number = f.at(i).alpha = false;}

bool checking::isNumber(char c) { return(c >= '0' && c <= '9'); }

bool checking::isAlpha(char c) { return (((c >= ' ') && (c <= '/')) || ((c >= ':') && (c <= '@')) || ((c >= '[') && (c <= '`')) || ((c >= '{') && (c <= '~'))); }

/*check if the conditions are satisfied*/
bool checking::AoP(checking::Fields f) {
	int i = 0;
	while ((! f.at(i).alpha) && (! f.at(i).number)) i++;
	return (i != f.size());
}

/*check all-conditions
  - there is almost a number;
  - there is almost a alphanumerical character;
*/
bool checking::testConditions(word p) {
	checking::Fields f(p.size());
	setAll(f);

	for(unsigned int i = 0; i < p.size(); i++) {
		if (isNumber(p[i])) f.at(i).number = true;
		if (isAlpha(p[i])) f.at(i).alpha = true;
	}

	return AoP(f);
}

/*print the ascii vector*/
void print(const Ascii& v) {
	if (v.empty()) throw - 2;
	for (unsigned int i = 0; i < v.size(); i++) std::cout << v.at(i) << (i < (v.size() - 1) ? " " : "\n");
}

void backup(std::ofstream& ofs, word passwd) { ofs << passwd << "\n"; }

/*Phantom Pain is behind you*/
word exceptions(int val) {
	switch (val) {
		case -1: return FILES;
		case -2: return VECTOR;
		case -3: return INPUT;
	}
}