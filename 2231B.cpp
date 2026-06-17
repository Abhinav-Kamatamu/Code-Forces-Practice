#include<iostream>

using namespace std;

void print_stats(int largest, int group_biggest, int jump_lb, int jump_ub) {
    cout << "largest: " << largest << endl;
    cout << "group_biggest: " << group_biggest << endl;
    cout << "jump_lb: " << jump_lb << endl;
    cout << "jump_ub: " << jump_ub << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        

        int largest = 0;
        bool grouping = false;
        int jump_lb = -1;
        int jump_ub = -1;
        int group_biggest = 0;
        bool early_exit = false;
        bool already_grouped = false;
        bool deactivate_grouping = false;

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;

            if (early_exit) continue;

            if(deactivate_grouping) {
                deactivate_grouping = false;
                if (num - largest < jump_lb) {
                    grouping = false;
                    jump_ub = largest - group_biggest;
                    group_biggest = 0;
                } else {
                    group_biggest = largest;
                }
                print_stats(largest, group_biggest, jump_lb, jump_ub);
            }

            if (jump_ub != -1)
                if (jump_ub - jump_lb < 0) {
                    cout << "NO" << endl;
                    early_exit = true;
                    continue;
                }

            if (num >= largest) {
                largest = num;
                if (grouping) {
                    deactivate_grouping = true;
                }
                continue;
            }

            if (!grouping) {
                grouping = true;
                group_biggest = num;
                jump_lb = jump_lb > 0 ? jump_lb : largest - num;
                if (already_grouped) {
                    if (largest - num > jump_ub) {
                        cout << "NO" << endl;
                        early_exit = true;
                        continue;
                    }
                }
                already_grouped = true;
                continue;
            }



            if (num < group_biggest) {
                cout << "NO" << endl;
                early_exit = true;
                continue;
            }

            group_biggest = num;
        }

        if(early_exit) continue;

        if (jump_ub != -1){
            if (jump_ub - jump_lb >= 0) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else
            cout << "YES" << endl;



    }
}