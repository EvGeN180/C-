#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter num: ";
    cin >> n;
    int arr[2][3] = { {n, n * 2, n * 4}, {n, n *3 , n * 6} };

    cout << "N*2,4;N*3,,6: " << endl;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
