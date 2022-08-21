#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

int N, M;

unordered_map<string, long long>ingredient;
vector<string>unsolved;

bool cmp(string A, string B) {
	int len;
	if (A.length() < B.length())
		len = A.length();
	else
		len = B.length();

	for (int i = 0; i < len; i++) {
		if (A[i] > B[i])
			return true;
		if (A[i] < B[i])
			return false;
	}
	return false;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		int a;
		cin >> str >> a;
		ingredient.insert(make_pair(str, a));
	}

	for (int i = 0; i < M; i++) {
		string equation;
		cin >> equation;

		equation += "+";

		unsolved.push_back(equation);
	}

	int cnt = 0;

	//sort(unsolved.begin(), unsolved.end(), cmp);

	while (true) {
		if (cnt == M * M)
			break;

		int flag = 0;

		string equation = unsolved[0];
		unsolved.erase(unsolved.begin());

		string str;

		int a = 0;
		int b = 0;

		b = equation.find("=", a);
		str = equation.substr(a, b - a);

		a = b + 1;

		long long sum = 0;

		while (true) {
			b = equation.find("+", a);

			if (b == -1) {
				if (ingredient.count(str) == 0)
					ingredient[str] = sum;
				else if (ingredient[str] > sum)
					ingredient[str] = sum;
				break;
			}

			string ing = equation.substr(a, b - a);

			int price = stoi(ing.substr(0, 1));

			ing.erase(0, 1);

			if (ingredient.count(ing) == 0) {
				unsolved.push_back(equation);
				flag = 1;
				break;
			}
			else {
				sum += price * ingredient[ing];
				if (sum > 1000000000)
					sum = 1000000001;
			}

			a = b + 1;
		}

		cnt++;

		if (flag == 0)
			unsolved.push_back(equation);
	}

	if (ingredient.count("LOVE") == 0)
		cout << -1;
	else if (ingredient["LOVE"] > 1000000000)
		cout << 1000000001;
	else
		cout << ingredient["LOVE"];

	return 0;
}