// Median Partition

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int generate_diff(const vector<int>& a, const int median, vector<int>& diff, vector<int>& median_count) {
    /* Generates the diff array and returns the count of median elements */

    int diff_counter = 0; // diff counter
    int mc = 0; // median count

    for(int i = 0; i < a.size(); i++){
        if (a[i] == median){
            mc++;
            diff[i] = diff_counter;
        } else if (a[i] < median){
            diff[i] = --diff_counter;
        } else {
            diff[i] = ++diff_counter;
        }
        median_count[i] = mc;
    }
    return mc;
}

bool is_valid_part(const vector<int>& diff, const vector<int>& median_count, int start, int end) {
    /* Checks if the partition from start to end is valid */

    if ((end - start + 1) % 2 == 0) return false; // partition has to be odd

    int medians_in_part = median_count[end] - (start > 0 ? median_count[start - 1] : 0);
    int diff_in_part = diff[end] - (start > 0 ? diff[start - 1] : 0);

    if (medians_in_part == 0) return false; // partition has to contain at least one median

    if (abs(diff_in_part) < medians_in_part) return true; // valid partition if the absolute diff is less than or equal to the number of medians
    return false;

}

int main() {
    int t;
    cin >> t;
    
    while (t--){
        int n;
        cin >> n;
        int median;
        int mc = 0;

        vector<int> a(n);

        // diff[i] = (greater than median - lesser than median) for all entries in range [1..i]
        vector<int> diff(n);
        vector<int> median_count(n, 0); // median_count[i] = number of median elements in range [1..i]
        vector<int> temp(n); // temp duplicate of a for sorting
        vector<int> max_partitions(n, 0); // max_partitions[i] = maximum number of median partitions in range [1..i]

        for(int i = 0; i < n; i++){
            cin >> a[i];
            temp[i] = a[i];
        }

        sort(temp.begin(), temp.end());
        median = temp[n/2];

        mc = generate_diff(a, median, diff, median_count);

        for (int i = 0; i < n; i++){
            for (int j = 0; j <= i; j++){
                if (is_valid_part(diff, median_count, j, i)) {
                    if (j == 0)
                        max_partitions[i] = max(max_partitions[i], 1);
                    else
                        if (max_partitions[j-1] > 0) // Previous partitions have to be valid
                            max_partitions[i] = max(max_partitions[i], max_partitions[j-1] + 1);
                }
            }
        }
        

        cout << max_partitions[n-1] << endl;
    }
}