#include <iostream>
#include <queue>
using namespace std;

typedef struct node{
    int y;
    int x;
    int fert = 0;
}Node;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, -1, 0, 1};

int N, M;
int total_tomatoes;
int last_fert;

vector<vector<int>> storage;
vector<vector<bool>> visited;

void init();
void bfs(const vector<Node>& starts);
void solve();

int main(){
    init();
    solve();
    return 0;
}

void init(){
    cin >> M >> N;
    vector<vector<int>> tmp_storage(N, vector<int>(M, 0));
    total_tomatoes = N * M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> tmp_storage[i][j];
        }
    }
    swap(storage, tmp_storage);

    vector<vector<bool>> tmp_visited(N, vector<bool>(M, false));
    swap(visited, tmp_visited);
}

void bfs(const vector<Node>& starts){
    queue<Node> q;
    for(const auto& s: starts) q.push(s);

    while(!q.empty()){
        Node cur = q.front();
        q.pop();

        if(visited[cur.y][cur.x]) continue;
        visited[cur.y][cur.x] = true;
        last_fert = cur.fert;
        total_tomatoes--;

        for(int k = 0; k < 4; k++){
            int ny = cur.y + dy[k];
            int nx = cur.x + dx[k];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(storage[ny][nx] == -1) continue;
            if(visited[ny][nx]) continue;

            q.push({ny, nx, cur.fert + 1});
        }
    }
}

void solve(){
    vector<Node> starts;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(storage[i][j] == 1){
                starts.push_back({i, j, 0});
            }
            if(storage[i][j] == -1){
                total_tomatoes--;
            }
        }
    }
    
    bfs(starts);
    
    if(total_tomatoes > 0) cout << -1 << '\n';
    else cout << last_fert << '\n';
}