#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//bfs로 접근
int N, M;
vector<int> network[10001];
int result[10001];

void init(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int src, dest;
        cin >> src >> dest;
        network[dest].push_back(src);
    }
}

void bfs(int start){
    bool visited[10001] = {false,};
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    int cnt = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 0; i < (int)network[cur].size(); i++){
            int next = network[cur][i];
            if(visited[next]) continue;
            visited[next] = true;
            cnt++;
            q.push(next);
        }
    }
    result[start] = cnt;
}

void solve(){
    int max_value = 1;
    for(int i = 1; i <= N; i++){          
        bfs(i);
        max_value = result[i] > max_value ? result[i] : max_value;
    }
    
    for(int i = 1; i <= N; i++){
        if(result[i] == max_value) cout << i << " ";
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solve();
    return 0;
}