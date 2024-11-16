#include <iostream>
#include <locale>
#include <random>
#include<ctime>
using namespace std;

int main()
{
	/*const int size = 10;
	int array[size];
	for (size_t i = 0; i < size; i++)
	{
		array[i] = rand() % 100 + 1;
		cout << array[i] << " ";
	}
	cout << endl;
	int min = array[0];
	int max = array[0];

	for (size_t i = 0; i < size; i++)
	{
		if (min > array[i]) {
			min = array[i];
		}
		if (max < array[i]) {
			max = array[i];
		}
	}

	cout << min << "    -min,  max-   " << max << " " << endl;*/


   /* ==========================================================*/

   /* srand(time(0));
    const int size = 12;
    int my_array[size];
    for (size_t i = 0; i < size; i++)
    {

        my_array[i] = rand() % 100 + 1;
        cout << my_array[i] << " : " << i << " : " << endl;

    }
    cout << endl;


    int user_max = 0;
    int user_min = 0;
    int index_min = 0;
    int index_max = 0;
    cout << "Enter max: ";
    cin >> user_max;
    cout << endl;
    cout << "Enter min: ";
    cin >> user_min;
    cout << endl;
    int min_array = my_array[user_min];
    int max_array = my_array[user_max];
    for (size_t i = user_min; i < user_max; i++)
    {
        if (min_array > my_array[i]) {
            min_array = my_array[i];
            index_min = i;
        }

    }
    for (size_t i = user_min; i < user_max; i++)
    {
        if (max_array < my_array[i]) {
            max_array = my_array[i];
            index_max = i;
        }
    }
    cout << "Min : " << min_array << " " << index_min << endl;
    cout << "Max : " << max_array << " " << index_max << endl;*/
	/*===========================================================*/
	/*srand(time(0));
	int array[10];

	int index_min = 0;
	int index_max = 0;
	for (size_t i = 0; i < 10; i++)
	{
		array[i] = rand() % 100 + 1 - 50;
		cout << array[i] << " ";
	}
	cout << endl;
	int min = array[0];
	int max = array[0];
	int sum = 0;
	int even = 0;
	for (size_t i = 0; i < 10; i++)
	{
		sum += array[i];
		if (min > array[i]) {
			min = array[i];
			index_min = i;

		}
		if (max < array[i]) {
			max = array[i];
			index_max = i;
		}
		if (array[i] % 2 == 0) {
			even += array[i];
		}

	}
	int sum_2 = 0;
	for (size_t i = index_min; i < index_max; i++)
	{
		sum_2 += array[i];
	}
	int last = 0;
	int first = 0;
	for (size_t i = 0; i < 10; i++)
	{
		if (array[i] < 0) {
			first = i;
			break;
		}
	}
	cout << "first -el: " << first << endl;
	for (size_t i = 0; i < 10; i++)
	{
		if (array[i] < 0) {
			last = i;
		}
	}
	cout << "last -el: " << last << endl;
	int sum__1 = 0;
	for (size_t i = first; i < last; i++)
	{
		sum__1 += array[i];
	}
	cout << "min index:"<<index_min << "  " <<"max index:"<< index_max << endl;
	cout << "sum"<<sum << endl;
	cout << "sum - el"<<sum__1 << endl;*/

}