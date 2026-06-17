// Median Partition

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int foo(vector<int>& a, int median, int start, int depth, int tmc){
    if(depth > tmc) return 0;
    
    int bc = 0;
    int sc = 0;
    int mc = 0;

    int biggest_partitions = 0;
    for(int i = start; i < a.size(); i+=2){
        if (a[i] > median) bc++;
        else if (a[i] < median) sc++;
        else mc++;

        if (i - start > 0 && a[i - 1] > median) bc++;
        else if (i - start > 0 && a[i - 1] < median) sc++;
        else if (i - start > 0) mc++;

        if (mc > 0 &&abs(bc - sc) <= mc) {
            int current_partitions = foo(a, median, i + 1, depth + 1, tmc);

            biggest_partitions = max(biggest_partitions, current_partitions + 1);
        }
    }
    return biggest_partitions;
}



int main() {
    int t;
    cin >> t;
    
    while (t--){
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> t(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
            t[i] = a[i];
        }

        sort(t.begin(), t.end());
        int median = t[n/2];
        int mc = 0;
        for(int i = 0; i < n; i++){
            if (a[i] == median){
                mc++;
            }

        }
        

        cout << foo(a, median, 0, 1, mc) << endl;
    }
}