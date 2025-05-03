#include <iostream>
#include <vector>


int main() {
    std::vector<int> vec = { 1,2,3,1,2,3,1,2,3,1,2,3,4,4,4,5,5,5,65,1,6,1,5,7,7,8,5,43,3 };

    std::vector<int> numbers; 
    std::vector<int> counts;

    for (int i = 0; i < vec.size(); i++) {
        int num = vec[i];
        bool found = false;

        for (int j = 0; j < numbers.size(); j++) {
            if (numbers[j] == num) {
                counts[j]++;
                found = true;
                break;
            }
        }

        if (!found) {
            numbers.push_back(num);
            counts.push_back(1);
        }
    }
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << "\nNumber: " << numbers[i] << " counts : " << counts[i];
    }

}


