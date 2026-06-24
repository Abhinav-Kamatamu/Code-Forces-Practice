// Euclid, Sequence and Two Numbers

#include <bits/stdc++.h>
#

using namespace std;

bool is_valid_seq(vector<int> seq) {
    for (int i = 2; i < seq.size(); i++)
        if (seq[i - 2] % seq[i - 1] != seq[i]) return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> seq(n);
        for (int i = 0; i < n; i++) {
            cin >> seq[i];
        }
        sort(seq.begin(), seq.end(), greater<int>());


        if (is_valid_seq(seq)) {
            cout << seq[0] << " " << seq[1] << endl;
        } else {
            cout << -1 << endl;
        }
    }
}