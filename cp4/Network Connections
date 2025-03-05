#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
typedef pair<ll, ll> pp;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
typedef tuple<int, int, int> triple;

vector<int> ranks;
vector<int> parents;

int findSet(int x){
    if(x == parents[x])
        return x;

    return parents[x] = findSet(parents[x]);
}

int sameSet(int a, int b){
    return findSet(a) == findSet(b);
}

void unionSet(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if(a != b){
        //we want a to be smaller :p
        if(a > b)
            swap(a, b);

        //the smaller's parent is now pointing to the bigger one 
        parents[a] = b;
        ranks[b] += ranks[a];
    }
}

int main(){
    int t;

    cin >> t;
    
    int cnt = 1;
    while(t--){
        
        int n;
        scanf("\n%d\n", &n);

        ranks.assign(n, 1);
        parents.assign(n, 0);

        int ans[2] = {0,0};

        for(int i = 0; i < n; i++){
            parents[i] = i;
        }

        string s;
        while(getline(cin, s)){
            if(s.empty()) break;

            istringstream tmp(s);
            char x;
            tmp>>x;
            int a, b;
            tmp >> a >> b;
            a--;
            b--;

            if(x == 'c'){
                unionSet(a, b);
            } else if(x=='q'){
                if(sameSet(a, b)){
                    ans[0]++;
                } else {
                    ans[1]++;
                }
            }
        }
        if(cnt != 1) cout<<'\n';
        cout << ans[0] << "," << ans[1]<<'\n';
        cnt++;
    }
   
}
