#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
typedef pair<ll, ll> pp;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
typedef tuple<int, int, int> triple;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    ll n;
    while(cin >> n){
        //total corners 
        ll total = 1 << n;

        vector<vector<ll>> vec(total, vector<ll> (n, 0));

        vector<ll> weight(total, 0);
        for(int i = 0; i < total; i++){
            cin >> weight[i];
        }

        for(int i = 0; i < total; i++){
            int currNumber = i;
            //then we generate our corners
            for(int k = 0; k < n; k++){
                //we shift to right of every i 
                //and toggle it.
                currNumber ^= (1 << k);
                vec[i][k] = currNumber;

                //toggle it back for next iteration
                currNumber ^= (1 << k);
            }
        }

        //now we store the sums of every corner exluding itself
        vector<ll> sums(total, 0);

        for(int i = 0; i < total; i++){
            ll currNumber = i;
            for(int k = 0; k < n; k++){
                sums[currNumber] += weight[vec[currNumber][k]];
                //cout << vec[currNumber][k] << ' ';
            }
            //cout << '\n';
        }

        ll mx = 0;
        //now find the sum of two neighbouring pairs
        for(int i = 0; i < total; i++){
            ll currSum = sums[i];
            for(int k = 0; k < n; k++){
                mx = max(mx, currSum + sums[vec[i][k]]);
            }
        }

        cout << mx << '\n';
    }
    return 0;


}
