#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Object {
	int weight;
	int value;
};

bool cmp(Object A, Object B) {
	if (A.value > B.value)
		return true;
	if (A.value < B.value)
		return false;
	if (A.weight > B.value)
		return true;
	if (A.value < B.value)
		return false;
	return false;
}

int N, K;
vector<Object>vec;
int dp[100001];

int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int W, V;
		cin >> W >> V;
		vec.push_back({ W,V });
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 1; i <= K; i++) {
		dp[i] = -2134567890;
	}

	for (int i = 1; i <= K; i++) {
		int sum = 0;
		int maxPrevVal = -2134567890;
		for (int j = 0; j < vec.size(); j++) {

			int a;
			if (vec[j].weight > i) {
				a = 0;
			}
			else
				a = vec[j].value + dp[i - vec[j].weight];
			
			maxPrevVal = max(maxPrevVal, a);
		}

		dp[i] = maxPrevVal;
	}

	cout << dp[K];

}