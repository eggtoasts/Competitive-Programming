#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
typedef pair<ll, ll> pp;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
typedef tuple<int, int, int> triple;

int main(){

    int t;
    cin >> t;
    while(t--){

        vector<ll> contain(230, -1);

        int n, q;
        cin >> n >> q;

        vector<ll> vec(n);
        for(auto & i: vec){
            cin >> i;
        }

        vector<ll> queries(q);
        for(auto & i : queries){
            cin >> i;
        }

        //we have a maximum of 0 < a < 229
        //so we can precompute
        for(int i = 0; i < q; i++){
            ll currQ = queries[i];

            if(contain[currQ] != -1) {
                cout << contain[currQ] << '\n';
                continue;
            }

            ll mx = 0;
            for(int j = 0; j < n; j++){
                ll x = (currQ & vec[j]);
                mx = max(mx, x);
            }

            contain[currQ] = mx;

            cout << contain[currQ] << '\n';
        }

    }
}
