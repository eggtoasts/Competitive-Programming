#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
typedef pair<ll, ll> pp;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
typedef tuple<int, int, int> triple;

int main(){
   
    while(1){
        int n;
        cin >> n;

        if(n == 0){
            break;
        }

        vector<int> v(32, -1);

        for(int i = 0; i < n; i++){
            string s;
            cin >> s;

            int a, b;

            if(s == "CLEAR"){
                cin >> a;

                v[a] = 0;
            }
            if(s == "SET"){
                cin >> a;
                v[a] = 1;
            }
            if(s == "OR"){
                cin >> a >> b;
                if(v[a] == 1 || v[b] == 1){
                    v[a] = 1;
                } else if (v[a] == 0 && v[b] == 0){
                    v[a] = 0;
                } else {
                    v[a] = -1;
                }
            }

            if(s == "AND"){
                cin >> a >> b;
                if(v[a] == 1 && v[b] == 1){
                    v[a] = 1;
                }else if (v[a] == 0 || v[b] == 0){
                    v[a] = 0;
                } else {
                    v[a] = -1;
                }
            }
        }

        reverse(v.begin(), v.end());

        for(auto i : v){
            if(i == -1){
                cout << '?';
            }else{
                cout << i;
            }
        }
        cout << '\n';

    }
}
