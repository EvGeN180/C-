#include <iostream>
using namespace std;
int main()
{
	/*task1*/
	//int num1 = 1;
	//int num2 = 2;
	//int* ptr_num1 = &num1;
	//int* ptr_num2 = &num1;
	//if (*ptr_num1 < *ptr_num2) {
	//	cout << "The biggest num is " << *ptr_num2 << endl;
	//}
	//else {
	//	cout << "The biggest num is" << *ptr_num1 << endl;
	//}
	///*task2*/
	//int number;
	//cout << "Enter num" << endl;
	//cin >> number;
	//int* ptr_number = &number;
	//if (*ptr_number > 0) {
	//	cout << "Number bigger than 0" << endl;
	//}
	//else if (*ptr_number < 0) {
	//	cout << "Number lower than 0" << endl;
	//}
	//else if (*ptr_number = 0) {
	//	cout << "Number is 0" << endl;
	//}
	//else {
	//	cout << "Something went wrong" << endl;
	//}
	/*task3*/
	//int n1, n2;
	//cout << "Enter num1" << endl;
	//cin >> n1;
	//cout << "Enter num2" << endl;
	//cin >> n2;
	//int* ptr_n1 = &n1; 
	//int* ptr_n2 = &n2;
	//int ptr_n3 = *ptr_n1;
	//*ptr_n1 = *ptr_n2;
	//*ptr_n2 = ptr_n3;
	//cout << "1:" << n1 << endl;;
	//cout << "2:" << n2 << endl;;
	///*task4*/
	int first, second;
	int* ptr_first = &first;
	int* ptr_second = &second;
	char action;
	char* ptr_action = &action;
	cout << "Enter nums" << endl;
	cin >> first >> second;
	cout << "Choose action" << endl;
	cin >> action;
	if (*ptr_action == '+') {
		cout << "Result: " << *ptr_first + *ptr_second << endl;
	}
	else if (*ptr_action == '-') {
		cout << "Result: " << *ptr_first - *ptr_second << endl;
	}
	else if (*ptr_action == '*') {
		cout << "Result: " << *ptr_first * *ptr_second << endl;
	}
	else if (*ptr_action == '/' && *ptr_second!=0) {
		cout << "Result: " << *ptr_first / *ptr_second << endl;
	}
	
}