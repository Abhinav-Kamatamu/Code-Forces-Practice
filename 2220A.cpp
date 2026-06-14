// Blocked

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
    int t;
    cin >> t;
    while (t>0){
        int n;
        cin >> n;

        vector<int> numbers;

        for(int i=0; i<n; i++){
            int num;
            cin >> num;
            numbers.push_back(num);
        }

        sort(numbers.begin(), numbers.end());

        int previous_num = -1;
        int num;
        bool fail = false;
        for(int i=0; i<n; i++){
            num = numbers.back();
            numbers.pop_back();
            if (num == previous_num){
                cout << "-1\n";
                fail = true;
                break;
            }
            previous_num = num;
        }

        if (!fail){
            for(int i=0; i<n; i++){
                cout << numbers[n - 1 - i] << " ";
            }
            cout << "\n";
        }

        t--;
    }
}