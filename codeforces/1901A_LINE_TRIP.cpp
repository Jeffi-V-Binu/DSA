#include<iostream>
#include<vector>
#include<climits>

using namespace std;

auto fastIO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

void solve(){
    int n , k;
    cin >> n >> k;
    int max_dis = INT_MIN;
    
    int prev_dis = 0;
    int curr_dis;
    for(int i = 1 ; i <= n ; ++i){
        cin >> curr_dis;
        max_dis = max(max_dis , curr_dis - prev_dis);
        prev_dis = curr_dis;
    }
    max_dis = max(max_dis ,2 * (k - prev_dis));
    cout << max_dis << "\n";
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}