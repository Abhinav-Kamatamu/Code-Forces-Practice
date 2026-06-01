#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = unsigned long long;

int pick_no_1(int i, ll L, ll R) {
    int count = 0;
    for (int d1 = 1; d1 <= 9; d1++){
        long long num = 0;

        num += d1 * pow(10, i);
        if (num >= L && num <= R)
            count++;
    }
    return count;
}

int loopings(ll L, ll R, int ln, int rn) {
    int count = 0;

    for (int i = rn - 1; i >= ln - 1; i--) {
        for (int d1 = 1; d1 <= 9; d1++) {
            ll n1 = d1 * pow(10, i);
            if (n1 >= L && n1 <= R)
                count++;
            for (int j = i - 1; j >= 0; j--) {
                for (int d2 = 1; d2 <= 9; d2++) {
                    ll n2 = d2 * pow(10, j);
                    if (n1 + n2 >= L && n1 + n2 <= R)
                        count++;
                    for (int k = j - 1; k >= 0; k--) {
                        for (int d3 = 1; d3 <= 9; d3++) {
                            ll n3 = d3 * pow(10, k);
                            if (n1 + n2 + n3 >= L && n1 + n2 + n3 <= R)
                                count++;
                        }
                    } 
                }
            }
        }
    }

    return count;
}

int main()
{
    int t;
    cin >> t;
    // ll outs[t];
    for (int i = 0; i < t; i++) {
        ll L, R;

        cin >> L >> R;

        // if(L == R){
        //        // Case if L=R is classy
        //        // Case if L=R is not classy
        //       return 0;
        // }

        int l_n = 0;
        int r_n = 0;
        ll c = L;
        for (l_n = 0; c > 0; l_n++)
        {
            c = c / 10;
        }
        c = R;
        for (r_n = 0; c > 0; r_n++)
        {
            c = c / 10;
        }
 
        cout << loopings(L, R, l_n, r_n) << endl;
    }
    // for (ll out : outs)
    // {
    //     cout << out << endl;
    // }
}