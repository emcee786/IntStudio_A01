#include <iostream>
using namespace std;

// CS103 Assessment 1, Emma Corkery - Question 2.
    
// Checks the array for positive numbers, using pointer as an argument. Adds any positive integers to the sum.
int sum_positive_num (int *num_array, int size) {
    int a;
    int sum = 0;

    for (a = 0; a < size; a++) {
        if (num_array[a] > 0) {
        sum += num_array[a];
        }
    }
    cout << "The sum of the positive numbers in your array is : " << sum << endl << endl; 
    return sum;
}


// Creates the array. Allowing the user to set the size of the array and input the integers.
// INPUT: Array size, array values. 
void create_array() {            
    int size;                   
    cout << "How many numbers are in your list?" <<endl;
    cin >> size;
    cout << "Your list requires " << size << " numbers: \n";

    int num_array[size];    
    for (int i = 0; i < size; i++) {
        cout << "Assign a number to position [" << i << "] : ";
        cin >> *(num_array + i);
    }
    int sum = sum_positive_num (num_array, size);
}


// Initiates create array
int main () {
    create_array();
}