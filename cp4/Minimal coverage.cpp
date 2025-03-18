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

        //cover segment [0, M]
        int M;
        cin >> M;
        
        vector<pp> v;

        while(1){
            ll l, r;
            cin >> l >> r;

            if(l == 0 && r == 0) break;

            v.push_back({l, r});
        }

        //sorts by ascending L and descending R
        sort(v.begin(), v.end(), [](pp a, pp b){
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first < b.first;
        });

        vector<pp> segments;

        int max_r = 0;
        int ans = 0;
        int filled = 0;
        
        int i = 0;
        while(i < v.size()){
            int curr_best_r = max_r;

            int indx = -1;

            //selects the segment that we can cover the furthest
            while(i < v.size() && v[i].first <= max_r){ //our current L is less than max_r to avoid missing segments
                if(v[i].second > curr_best_r){
                    indx = i;
                    curr_best_r = v[i].second;
                }
                i++;
            }

            if(indx == -1) break;

            segments.push_back(v[indx]);

            max_r = curr_best_r;

            if(max_r >= M){
                filled = 1; //succesfully covered all [0, M]
                break;
            }

        }

        if(filled){
            cout << segments.size() << '\n';
            for(int i = 0; i < segments.size(); i++){
                cout << segments[i].first << " " << segments[i].second << '\n';
            }
        }else{
            cout << "0\n";
        }

        if(t >= 1)
            cout << "\n";
       
    }

    return 0;
}
