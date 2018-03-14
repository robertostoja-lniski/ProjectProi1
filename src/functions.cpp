#include <functions.h>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* Robert Ostoja - Lniski
nr indexu 293110
prowadzacy zajecia: Wiktor Kusmirek
termin zajec: czw 8:15
*/
/* the File contains desciptions
of functions declared in functions.h file
*/

// Default constructor
Number::Number(){
	decNum = 0;
	binNum = '0';
}
// Constructor with a given number and string
Number::Number(int a) {

	decNum = a;
}
/*Overloaded ostream operator, which
prints decNum as a binary number
using the mask - 2^31-1 */

ostream& operator<< (ostream &print, Number const& next)
{
   string binNum ="";
   bool nulls = 0, minusSign=0;
   int Num=next.decNum;
 	if(next.decNum<0) {
		minusSign=1;
		Num=-next.decNum;
 	}
	for(unsigned m = 2147483648; m > 0; m >>= 1) {

		if(Num & m)
			nulls = 1;
		if(nulls)
			 ((Num & m) ? binNum+="1" : binNum+="0");
	}
	if(minusSign)
		binNum="-"+binNum;
   print << binNum << endl;
   return print;
}
/*Overloaded instream operator, which
reads (and checks the correctness) of the
binary number (string) and then
creates decimal number - decNum */
istream& operator>> (istream &read, Number& next)
{
   bool check;
   do{
	   check=0;
	   read >> next.binNum;
	   if(next.binNum.size() >=15) {
			cout << "Number is too big" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			check = 1;
	   }
	   else {
		   for(int i=0; i<=next.binNum.size()-1; i++)
				if(next.binNum[i]!='1' && next.binNum[i]!='0' && (i!=0 && next.binNum[i]!='-')) {
					cout << "Enter the correct binary number" << endl;
					cin.clear();
					cin.ignore(256, '\n');
					check = 1;
					break;
				}
	   }
   }while(check);

   int toDec = 0;
   int minusSign = 0;
   if(next.binNum[0]== '-') {
	   minusSign = 1;
   }
   for(int i =0+minusSign; i<next.binNum.size()-1; i++) {
		toDec = (toDec + (int)next.binNum[i]-48)*2;
   }
   toDec += (int)next.binNum[next.binNum.size()-1]-48;
   if(minusSign==1) {
   		toDec*=(-1);
   }
   next.decNum = toDec;
   return read;
}

Number Number::operator+ (Number const& next)
{
   Number tmp(decNum + next.decNum);
   return tmp;
}
Number Number::operator- (Number const& next)
{
   Number tmp(decNum - next.decNum);
   return tmp;
}
Number Number::operator* (Number const& next)
{
   Number tmp(decNum * next.decNum);
   return tmp;
}
Number Number::operator/ (Number const& next)
{
   Number tmp(decNum / next.decNum);
   return tmp;
}
// function requesting the user to enter data
void enterRequest() {
	Number n1,n2;
	cout << "Enter first number(binary)" << endl;
	cin >> n1;
	cout << "Enter second number(binary)" << endl;
	cin >> n2;
	menu(n1,n2);
}
// function that enables the user to choose certain action
void menu(Number& n1, Number& n2) {

	cout << "Choose operation: + - * / " << endl;
	char c = readChar();

	switch(c) {
		case '+': {cout << "the result equals " << n1+n2 << endl; break;}
		case '-': {cout << "the result equals " << n1-n2 << endl; break;}
		case '/': {cout << "the result equals " << n1/n2 << endl; break;}
		case '*': {cout << "the result equals " << n1*n2 << endl; break;}
	}
	cout << "Enter 1 to choose new operation, 2 to choose new numbers, or 3 to exit"  << endl;
	c = readChar('1','2', '3');

	if(c=='1')
		menu(n1,n2);
	if(c=='2')
		enterRequest();
	if(c=='3')
		return;
}
//function that reads a sign + - * /
char readChar() {
	char c;
	bool check;
   	do{
		check = 0;
	 	cin >> c;
	 	if(!cin) {
			check = 1;
			cin.clear();
			cin.ignore(256, '\n');
	 	} else {
	 		if(c!='+' && c!='-' && c!='*' && c!='/') {
				check = 1;
				cout << "Wrong symbol" << endl;
				cin.clear();
				cin.ignore(256, '\n');
			}

	 	}

   }while(check);
   return c;
}
// function that reads only three signs given as arguments
char readChar(char a, char b, char d) {
	char c;
	bool check;
   	do{
		check = 0;
	 	cin >> c;
	 	if(!cin) {
			check = 1;
			cin.clear();
			cin.ignore(256, '\n');
	 	} else {
	 		if(c!=a && c!=b && c!=d) {
				check = 1;
				cout << "Wrong symbol" << endl;
				cin.clear();
				cin.ignore(256, '\n');
			}

	 	}

   }while(check);
   return c;

}
