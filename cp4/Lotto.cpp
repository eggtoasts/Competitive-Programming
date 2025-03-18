#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
typedef pair<ll, ll> pp;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
typedef tuple<int, int, int> triple;

vector<ll> v;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    while(1){
        int n;
        cin >> n;

        if(n == 0) break;

        v.assign(n, 0);

        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        //6 choose n, 6 < n < 13

        for(int i = 0; i < n; i++){
            for(int a = i + 1; a < n - 4; a++){
                for(int b = a + 1; b < n - 3; b++){
                    for(int c = b + 1; c < n - 2; c++){
                        for(int d = c + 1; d < n - 1; d++){
                            for(int e = d + 1; e < n; e++){
                                cout << v[i] << " " << v[a] << " " << v[b] << " " << v[c] << " " << v[d] << " " << v[e] << "\n";
                            }
                        }
                    }
                }
            }
        }

        cout << '\n';

    }
    
    return 0;
}
