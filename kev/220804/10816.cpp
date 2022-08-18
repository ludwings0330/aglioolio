#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int N, M;


void solve();

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}

void solve(){
    cin >> N;
    vector<int> cards(N);
    for(int i = 0; i < N; i++){
        cin >> cards[i];
    }

    cin >> M;
    vector<int> keys(M);
    for(int i = 0; i < M; i++){
        cin >> keys[i];
    }

    unordered_map<int, int> hand;
    for(const auto& c: cards){
        hand[c]++;
    }

    for(int key: keys){
        auto found = hand.find(key);
        if(found != hand.end()) cout << found->second << " ";
        else cout << 0 << " ";
    }
    cout << '\n';
    
}