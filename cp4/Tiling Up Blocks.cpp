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
    while(cin >> t){

        if(t == 0){
            break;
        }

        vector<pp> v(t);

        //get {l, m}
        for(int i = 0; i < t; i++){
            int a, b;
            cin >> a >> b;
            v[i] = {a, b};
        }

        //sort the blocks by increasing L
        sort(v.begin(), v.end(), [](pp a, pp b){
            if(a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        });

        vector<int> dp(t, 1);

        //find the LIS if l <= l' and m <= m'
        for(int i = 1; i < t; i++){
            for(int j = 0; j < i; j++){
                if(v[j].first <= v[i].first && v[j].second <= v[i].second){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        //get the max LIS length
        int ans = 0;
        for(int i = 0; i < t; i++){
            ans = max(ans, dp[i]);
        }

        cout << ans << '\n';
        
    }
    cout << "*\n";

}
