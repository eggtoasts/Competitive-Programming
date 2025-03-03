#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
typedef pair<ll, ll> pp;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
typedef tuple<int, int, int> triple;


int check(ll m, vi & v){
    ll k = m;

    //we also need to check from ground to the first ring!
    if(v[0] - 0 == k)k-=1;
    else if(v[0] - 0> k) return 0;

    //check if our current strength works
    for(int i = 0; i < v.size()-1; i++){
        if(v[i+1]-v[i] == k ) k-=1;
        else if(v[i+1] - v[i] > k) return 0;
    }
    return 1;
}

int main(){

    int t;
    cin >> t;
    int curr = 1;
    while(t--){
        //we need to find minimum K strength
        //so i can reach top rung

        int n;
        cin >> n;

        vi v(n);

        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        ll l = 0;
        ll r = 1e10;

        while(l + 1 < r){
            //m is our current K (strength)
            ll m = (l + r)/2;

            if(check(m, v)){
                r = m;
            }else {
                l = m;
            }
        }

        cout << "Case " << curr << ": " << r << '\n';
        curr++;
    }
    
}
