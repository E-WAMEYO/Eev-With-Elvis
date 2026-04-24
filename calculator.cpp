#include <iostream>
int main() {
	using namespace std;

char o;
int num1;
int num2;

int results;

cout <<"*********CALCULATOR***********" << endl;
cout << "enter either (* - + / %) : ";
cin >> o;

cout << "enter #1 : ";
cin >> num1;

cout << "enter #2 : ";
cin >> num2;




switch(o){
	
	
	case '+':
	results = num1 + num2;
	cout <<" results  = " <<results << endl;
	break;
	
	case '-':
	results = num1 - num2;
	cout <<"results =  " << results << endl;
	break;
	

case '*':
	results = num1 * num2;
	cout <<"results  = " << results << endl;
	break;
	
case '/':
	results = num1 / num2;
	cout <<"results  = " << results << endl;
	break;
	
case '%':
	results = num1 % num2;
	cout <<"results  = " << results << endl;
	break;

	
	default :
		cout <<" that was not avalid response" << endl;
		break;
	}
		
		cout <<"*********CALCULATOR******** :" << endl;
	 return 0;
}
	