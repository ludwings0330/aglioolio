#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;
    vector<int> tree_height(N, 0);

    int max_height;
    for(int i = 0; i < N; i++){
        cin >> tree_height[i];
        if(tree_height[i] > max_height) max_height = tree_height[i];
    }

    int left = 0;
    int right = max_height;
    int answer = 0;
    while(left <= right){
        int mid = (left + right) >> 1;
        ll total_gain = 0;
        for(int i = 0; i < N; i++){
            int gain = tree_height[i] - mid;
            if(gain > 0) total_gain += gain;
        }
        if(total_gain >= M){
            left = mid + 1;
            answer = mid;
        }
        else{
            right = mid - 1;
        }
    }
    cout << answer << '\n';

    return 0;
}