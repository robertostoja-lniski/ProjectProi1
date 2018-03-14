#ifndef NUM_H_INCLUDED
#define NUM_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

/* Robert Ostoja - Lniski
nr indexu 293110
prowadzacy zajecia: Wiktor Kusmirek
termin zajec: czw 8:15
*/

/* the File contains declarations of class Number,
operators and functions used in the programme
*/

/*the class enables the user to add
substract, multiply, or substract binary numbers
using overloaded operators as well as
a number in both decimal and binary representation
*/
class Number
{
 // decNum is decimal number and binNum is its
 // binary value
 private:
      int decNum;
      string binNum;
 public:
 	Number();
 	Number(int);
 	// overloaded operator for this class
 	friend ostream& operator<< (ostream&,Number const&);
 	friend istream& operator>> (istream&,Number&);
 	Number operator+ (Number const&);
 	Number operator- (Number const&);
 	Number operator* (Number const&);
 	Number operator/ (Number const&);
};

// functions creating the layout of programme
void enterRequest();
void menu(Number&, Number&);
// functions that check the correctness of read data
char readChar();
char readChar(char, char, char );
#endif // NUM_H_INCLUDED
