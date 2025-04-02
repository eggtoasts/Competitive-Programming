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
        int M, C;
        cin >> M >> C;

        vector<vector<int>> dp(C, vector<int>(M+1));
        vector<vector<int>> garments(C, vector<int>(21));
        for(int i = 0; i < C; i++){
            int sz;
            cin >> sz;
            garments[i][0] = sz;
            for(int k = 1; k <= sz; k++){
                cin >> garments[i][k];
            }
        }

        for(int price = 1; price <= garments[0][0]; price++){
            if(garments[0][price] <= M )
                dp[0][M - garments[0][price]] = 1;
        }
        
        for(int g = 1; g < C; g++){
            for(int budget = 0; budget <= M; budget++){
                if(dp[g-1][budget] == 1){
                    for(int k = 1; k <= garments[g][0]; k++){
                        if(budget - garments[g][k] >= 0){
                            dp[g][budget-garments[g][k]] = 1;
                        }
                    }
                }
            }
        }

        int f = -1;
        for(int budget = 0; budget < M; budget++){
            if(dp[C-1][budget] == 1){
                f = M - budget;
                break;
            }
        }

        if(f == -1){
            cout << "no solution\n";
        } else {
            cout << f << '\n';
        }
    }
}
