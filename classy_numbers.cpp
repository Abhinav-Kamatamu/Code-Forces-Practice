#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
using ll = unsigned long long;

int pick_no_3(int i, int j, int k, ll L, ll R){
	int count = 0;
	for (int d1 = 1; d1 <= 9; d1++) {
        for (int d2 = 1; d2 <= 9; d2++) {
            for (int d3 = 1; d3 <= 9; d3++) {

                long long num = 0;

                num += d1 * pow(10, i);
                num += d2 * pow(10, j);
                num += d3 * pow(10, k);

                if (num >= L && num <= R) {
					count++;
                }
            }
        }
    }
	return count;
}
int pick_no_2(int i, int j, ll L, ll R){
	int count = 0;
	for (int d1 = 1; d1 <= 9; d1++) {
        for (int d2 = 1; d2 <= 9; d2++) {

                long long num = 0;

                num += d1 * pow(10, i);
                num += d2 * pow(10, j);

                if (num >= L && num <= R) {
					count++;
                }
            }
        }
	return count;
}
int pick_no_1(int i, ll L, ll R){
	int count = 0;
	for (int d1 = 1; d1 <= 9; d1++) {

                long long num = 0;

                num += d1 * pow(10, i);

                if (num >= L && num <= R) {
					count++;
                }
        }
	return count;
}

int loopings(ll L, ll R, int ln, int rn){
	int count = 0;

	if (rn>=3){
		for(int i=0; i<rn; i++){
			for(int j=i+1; j<rn; j++){
				for(int k=j+1; k<rn; k++){
						count += pick_no_3(i, j, k, L, R);
				}
			}
		}
	}
	if(rn >= 2){
		for(int i=0; i<rn; i++){
			for(int j=i+1; j<rn; j++){
						count += pick_no_2(i, j, L, R);
			}
		}
	}
	if(rn >= 1){
		for(int i=0; i<rn; i++){
						count += pick_no_1(i, L, R);
		}
	}
	return count;
}

int main(){
	int t;
	cin >> t;
	ll outs[t];
	for(int i=0; i<t; i++){
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
		for(l_n=0; c>0; l_n++){c = c / 10;}
		c = R;
		for(r_n=0; c>0; r_n++){c = c / 10;}
		
		outs[i] = loopings(L, R, l_n, r_n);
	}	
	for(ll out : outs){
		cout << out << endl;
	}
}
