#include <iostream>
using namespace std;
#include <random>;

int main()
{
    srand(time(0));
    int user_result = 0, computer_result = 0;
    string username;
    cout << "--------------CUBS--------------"<<endl;
    cout << "Enter username" << endl;
    cin >> username;
    for (size_t i = 1; i < 4; i++) {
        cout << "-----------------------" << i << "round-----------------------" << endl;
        cout << username << " throw cubs" << endl;
        int ucub1 = rand() % 6 + 1;
        int ucub2 = rand() % 6 + 1;
        cout << ucub1 << ","<<ucub2 << endl;
        user_result += ucub1 + ucub2;
        cout << "Computer" << " throw cubs" << endl;
        int ccub1 = rand() % 6 + 1;
        int ccub2 = rand() % 6 + 1;
        cout << ccub1<<"," << ccub2 << endl;
        computer_result += ccub1 + ccub2;
    }
    cout << "--------------------Final results----------------------" << endl;
    cout << username << "sum=" << user_result << endl;
    cout << "Computer" << "sum=" << computer_result << endl;
    if (computer_result > user_result) {
        cout << "You lose, computer won!" << endl;
    }
    else if (computer_result < user_result) {
        cout << "Computer lose, You won!Congratulations!" << endl;
    }
    else {
        cout << "Draw!" << endl;
    }
   
   

}

