#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
typedef pair<ll, ll> pp;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
typedef tuple<int, int, int> triple;

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int count = 1;
    while(1){
        int n, d;
        cin >> n >> d;

        if(n == 0 && d == 0) break;

        cout << "Case " << count << ": ";

        vector<pair<double,double>> islands(n);

        for(int i = 0; i < n; i++){
            double x, y;
            cin >> x >> y;
            islands[i] = {x,y};
        }

        //island (xi, yi)
        //calculate that island's x range

        //in a right triangle, to get a leg is sqrt(h^2 - x^2)

        // x is within [ xi + sqrt(d^2 - y^2), xi - sqrt(d^2 - y^2)]

        //       (xi,yi)
        //  <------O----->
        //  |     /
        //y |   / d
        //  | /   
        //  /
        // ------------------------  y = 0

        vector<pair<double,double>> intervals;
        int impossible = 0;
        for(int i = 0; i < n; i++){
            double x = islands[i].first, y = islands[i].second;

            //must be within d's (radius) range
            if(y > d){
                impossible = 1;
                break;
            }
            
            //calculating island's interval
            double delta = sqrt(d*d - y * y);
            double start = x - delta;
            double end = x + delta;

            intervals.push_back({start, end});
        }

        if(impossible){
            cout << "-1\n";
            count++;
            continue;
        }
        
        sort(intervals.begin(), intervals.end(), [](pair<double, double> a, pair<double,double> b){
            return a.second < b.second;
        });

        double latestRadar = -1e9;
        int ans = 0;
        for(auto interval : intervals){

            double start = interval.first;
            double end = interval.second;

            //if our last radar placement doesn't overlap, we add a radar
            if(start > latestRadar){
                latestRadar = end;
                ans++;
            }

        }
        cout << ans << '\n';

        count++;
    }

    return 0;
}
