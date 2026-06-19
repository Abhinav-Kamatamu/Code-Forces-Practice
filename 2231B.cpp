// Another Sorting Problem

#include<iostream>
#include<vector>

using namespace std;


int main() {
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;

        vector<int> a(n);

        int k_min = 0;
        bool fail = false;
        
        for (int i = 0; i < n; i++){
            cin >> a[i];
            if (i > 0 && a[i] < a[i - 1]) k_min = max(k_min, a[i - 1] - a[i]);
        }   

             
        for (int i = 1; i < n; i++){
            if (a[i] < a[i - 1]) {
                a[i] += k_min;
            }
            if (a[i] < a[i - 1]) {
                cout << "NO" << endl;
                fail = true;
                break;
            }
        }

        if (!fail) cout << "YES" << endl;
    }
}