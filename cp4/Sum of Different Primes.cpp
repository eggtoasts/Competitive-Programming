#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
typedef pair<ll, ll> pp;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
typedef tuple<int, int, int> triple;

int main(){
    //build primes first
    vector<int> isPrime(1121, 1);
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i <= 1120; i++){
        if(isPrime[i] == 1){
            for(int j = i * i; j <= 1120; j += i){
                isPrime[j] = 0;
            }
        }
    }

    vector<int> primes;
    for(int i = 0; i < isPrime.size(); i++){
        if(isPrime[i] == 1) primes.push_back(i);
    }

    //our max N and Ks
    int N = 1120;
    int K = 14;

    vector<vector<ll>> dp(K + 1, vector<ll>(N + 1, 0));
        
    //one way to achieve 0
    dp[0][0] = 1;

    //dp[i][j] = number of ways we can have i primes add up to sum j
    //i = number of distinct primes we've used
    //j = sum we're currently on

    //consider every prime then iterate backwards to avoid overwriting
    for(auto p : primes){
        for(int i = K-1; i >= 0; i--){
            for(int j = N - 1; j >= 0; j--){
                if(j + p <= N)
                    dp[i + 1][j + p] += dp[i][j];
            }
        }
    }

    int n, k;
    while(cin >> n >> k){
        // for(auto p : primes){
        //     for(int i = k; i >  0; i--){
        //         for(int j = n; j > 0; j--){
        //             if(j - p >= 0)
        //                 dp[i][j] += dp[i-1][j-p]; 
        //         }
        //     }
        // }
        if(n == 0 && k == 0) break;
        cout << dp[k][n] << '\n';
    }
}
