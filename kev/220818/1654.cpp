#include <iostream>
#include <vector>
#include <limits>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int K, N;
    cin >> K >> N;
    
    vector<int> cable_length(K);
    int max_cable_length = 0;
    
    for(int i = 0; i < K; i++){
        cin >> cable_length[i];
    }

    ll left = 1, right = numeric_limits<int>::max();
    int max_scale = 1;

    while(left <= right){
        ll mid = (left + right) >> 1;
        
        if(mid <= 0){
            break;
        }
        
        ll total_gain = 0;
        for(int i = 0; i < K; i++){
            int gain = cable_length[i] / mid;
            if(gain <= 0) continue;
            total_gain += gain;
        }
        
        if(total_gain >= (ll)N){
            left = mid + 1;
            max_scale = mid;
        }
        else{
            right = mid - 1;
        }
    }
    cout << max_scale << '\n';
    
    return 0;
}