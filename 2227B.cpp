// Party Monster

#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t>0){
        int n;
        cin >> n;

        char c;
        int balancer =0;

        for(int i=0; i<n; i++){
            cin >> c;
            if (c == '(')
                balancer++;
            else 
                balancer--;
        }
        
        if(n%2 != 0){cout << "NO\n"; t--; continue;}
        if(balancer == 0) {cout << "YES\n";}
        else
            cout << "NO\n";
        t--;

    }
}