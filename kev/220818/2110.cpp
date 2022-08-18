#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
using ll = long long;

bool determine(const vector<int>& x, int target_dist, int count){
    // 맨 첫 번째 집에는 항상 공유기를 설치한다
    count--;
    auto prev = x.begin();
    int min_dist = INT_MAX;
    do{
        auto lb = lower_bound(prev, x.end(), *prev + target_dist);
        
        if(lb == x.end()) return false;
        
        int cur_dist = *lb - *prev;
        if(cur_dist < min_dist) min_dist = cur_dist;
        
        prev = lb;
        
        count--;
    }while(count > 0);
    
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, C;
    cin >> N >> C;
    vector<int> x(N);
    for(int i = 0; i < N; i++) cin >> x[i];

    sort(x.begin(), x.end());

    int left = 1, right = x[N - 1] - x[0];
    int answer = 0;
    while(left <= right){
        int mid = (left + right) >> 1;
        
        bool is_valid_dist = determine(x, mid, C);

        if(is_valid_dist){
            // 늘려본다
            left = mid + 1;
            answer = mid;
        }
        else{
            // 줄인다
            right = mid - 1;
        }
    }
    
    cout << answer << '\n';

    return 0;
}