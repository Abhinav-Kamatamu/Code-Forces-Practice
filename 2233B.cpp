// Different Distances

#include <iostream>
#include <vector>

using namespace std;


void foo(int i, int n){
    int var = n - i + 1;
    if (var == 2){
        cout << i << " " << i+1 << " " << i << " " << i << " " << i+1 << " " << i+1 << " " << i << " " << i+1 << endl;
        return;
    }
    else if (var == 3){
        cout << i << " " << i +2 << " " << i+1 << " " << i+1 << " " << i+2 << " " << i << " " << i+1 << " " << i << " " << i+2 << " " << i+2 << " " << i << " " << i+1 << endl;
        return;
    }
    else
        cout << i << " " << i+1 << " " << i << " " << i << " " << i+1 << " " << i+1 << " " << i << " " << i+1 << " ";
        foo(i+2, n);
    return;
}

int main() {
    int t;

    cin >> t;

    while (t > 0) {
        int n;
        cin >> n;
        t--;

        foo(1, n);
    }
}