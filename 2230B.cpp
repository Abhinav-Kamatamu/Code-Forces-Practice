// Digit String

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;


int find_next_odd(vector<char>& list, int start, int &twos) {
    for (int i = start; i < list.size(); i++) {
        if (list[i] == '1' || list[i] == '3') {
            return i;
        } else
            twos--;
    }
    return -1;
}

int find_prev_two(vector<char>& list, int start, int &ones) {
    for (int i = start; i >= 0; i--) {
        if (list[i] == '2') {
            return i;
        } else
            ones--;
    }
    return -1;
}

int main() {
    int t;
    
    cin >> t;

    char dummy;
    cin.get(dummy); // Consume the newline after the integer input
    
    while (t--) {
        
        vector<char> list;
        
        int count = 0;
        int odds = 0;
        int twos = 0;
        int fours = 0;
        int leftmost_odd = -1;
        int rightmost_two = -1;

        // Collect the inputs
        char c;
        int i = 0;
        while (cin.get(c) && c != '\n') {
            if (c == '4') {
                count ++;
                fours++;
            }
            else {
                if (c == '1' || c == '3') {
                    leftmost_odd = leftmost_odd == -1 ? i - fours : leftmost_odd;
                    odds++;
                }
                else {
                    rightmost_two = i - fours;
                    twos++;
                }
                list.push_back(c);
            }
            i++;
        }

        for (int i = rightmost_two; i < list.size(); i++) {
            if (list[i] == '1' || list[i] == '3') {
                odds--;
            }
        }

        for (int i = leftmost_odd; i >= 0; i--) {
            if (list[i] == '2') {
                twos--;
            }
        }

        while (leftmost_odd < rightmost_two && leftmost_odd != -1 && rightmost_two != -1) {
            if (twos < odds) {
                twos--;
                rightmost_two = find_prev_two(list, rightmost_two - 1, odds);
            }
            else {
                odds--;
                leftmost_odd = find_next_odd(list, leftmost_odd + 1, twos);
            }
            count++;
        }

        cout << count << endl;

    }
}
