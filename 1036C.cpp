// Classy Numbers

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
using ll = unsigned long long;

 
int _int(char c) {
    return c - '0';
}

int C(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    r = min(r, n - r); // C(n, r) == C(n, n - r)
    ll numerator = 1;
    ll denominator = 1;
    for (int i = 0; i < r; i++) {
        numerator *= (n - i);
        denominator *= (i + 1);
    }
    return numerator / denominator;
}

int get_nth_nonzero_pos(string &s, int n) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c != '0') {
            count++;
            if (count == n) {
                return i; // Return index
            }
        }
    }
    return -1; // Not found
}

ll get_C_sequence(int n, int r) {
    ll sum = 0;
    for (int i = 0; i <= r; i++) {
        sum += pow(9, i) * C(n, i);
    }
    return sum;
}

ll get_classy(string& s) {
    int n = s.size();
    ll classy_count = 0;

    
    for(int i = 1; i <= 3; i++) {
        int pos = get_nth_nonzero_pos(s, i);
        int digit;
        if (pos == -1) {
            break;
        } else
            digit = _int(s[pos]);
        // Suppose we are dealing with the digit = 4
        classy_count += (digit - 1) * get_C_sequence(n - pos - 1, 3 - i); // Calculates the classynumbers from 10..00 to 39..99
        classy_count += get_C_sequence(n - pos - 1, 3 - i + 1); // Calculates the classynumbers from 00...00 to 10..00

    }

    return classy_count;
}

void subtract_one(string &s) {
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] > '0') {
            s[i]--;
            break;
        } else {
            s[i] = '9';
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--) {
        string lower;
        string upper;
        cin >> lower >> upper;

        subtract_one(lower);
        cout << get_classy(upper) - get_classy(lower) << endl;
    }

} 