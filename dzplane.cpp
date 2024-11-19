#include <iostream>
using namespace std;

int main() {
    int distAB, distBC, weight, fuelAB, fuelBC;
    const int allFuel = 300;

    cout << "Enter distance from A to B : ";
    cin >> distAB;

    cout << "Enter distance from B to C: ";
    cin >> distBC;

    cout << "Enter weight (kg): ";
    cin >> weight;

    if (weight > 2000) {
        cout << "Plane cant fly with 2000kg weight" << endl;
 
    }
    if (weight <= 500)
        fuelAB = fuelBC = 1;
    else if (weight <= 1000)
        fuelAB = fuelBC = 4;
    else if (weight <= 1500)
        fuelAB = fuelBC = 7;
    else
        fuelAB = fuelBC = 9;

    int fuelNeededAB = distAB * fuelAB;
    int fuelNeededBC = distBC * fuelBC;

    if (fuelNeededAB > allFuel) {
        cout << "Distance is to big from A to B" << endl;
    }

    int fuelAfterAB = allFuel - fuelNeededAB;

    if (fuelNeededBC > allFuel) {
        cout << "Distance is to big from A to B" << endl;
    }

    if (fuelNeededBC > fuelAfterAB) {
        int refuel = fuelNeededBC - fuelAfterAB;
        cout << "Minimal refuel "  << refuel << " litters" << endl;
    }
    else {
        cout << "You dont need to refuel" << endl;
    }


}


