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

    int count = 1;
    while(t--){
        cout << "Case #" << count << ": ";
        
        //  1010(1)1101       odd
        // S = 1
        //101(0)(1)(1)101     even, we take the 1 right
        //S = 11
        //101(0)(1)(X)(1)01    odd, we take the zero
        //S = 110

        string s;
        cin >> s;

        int n = s.size();

        int currSize = n;

        string S = "";

        //lets us know if i took left or right spot
        int r = 0;

        int middleR = n / 2;
        int middleL = n / 2 - 1;
        for(int i = 0; i < n; i++){
            if(currSize % 2 == 0){
                if(s[middleL] <= s[middleR]){
                    r = 1;
                    S += s[middleR];
                    middleR++;
                } else {
                    r = 0;
                    S += s[middleL];
                    middleL--;
                }
            } else {
                if(r){
                    S += s[middleL];
                    middleL--;
                }
                else{
                    S += s[middleR];
                    middleR++;
                }
            }
            currSize--;
        }

        //precompute our powers of 2 since our upper bound is 2^(10^5)
        vector<ll> precomp(100001);
        precomp[0] = 1;
        for(int i = 1; i < 100001; i++){
            precomp[i] = (precomp[i-1] * 2) % 1000000007;
        }

        ll ans = 0;
        for(int i = 0; i < n; i++){
            //we add up our powers of 2 
            ans +=  precomp[n - i - 1] * (S[i] - '0');
            ans %= 1000000007;
        }

        cout << ans << '\n';
        count++;
        
    }
}
