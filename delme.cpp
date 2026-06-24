#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

// A program that generates a list of random numbers in increasing list order

// Step one: print number of test cases
// Step two: print number of elements in the list (Has to be an odd number between 1 and 5000) (Also has to be in increasing order)
// Step three: print the list of numbers (randomly generated in any order)

int main() {
    int t = 10000; // Number of test cases
    cout << t << endl;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000000000);

    for (int i = 0; i < t; i++) {
        int n = dis(gen) % 5000 + 1; // Number of elements in the list (between 1 and 5000)
        if (n % 2 == 0) n++; // Ensure n is odd
        cout << n << endl;

        vector<int> numbers(n);
        for (int j = 0; j < n; j++) {
            numbers[j] = 1; // Generate random numbers between 1 and 1e9
        }


        for (int num : numbers) {
            cout << num << " "; // Print the sorted list of numbers
        }
        cout << endl;
    }

    return 0;
}