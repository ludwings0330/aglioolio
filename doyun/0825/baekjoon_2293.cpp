#include <iostream>
#include <vector>

using namespace std;

vector<int> coin;

int DP[10001];

// ���� 2293 - ���� 1
// DP, ��� 5
// ��ȭ�� -> DP[i] = DP[i] + DP[i - coin[j]];
// ���� ���������� ������(���� ������ ���� �� ��)��
// ���� ������ ���Ե� �������� �����Ѵ�.
// ������ ������ ���Ե� ���������� �� ������ �� ��� ���

int main()
{
	int n, k, c;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> c;
		coin.push_back(c);
	}

	DP[0] = 1;

	for (int j = 0; j < coin.size(); j++)
	{
		for (int i = coin[j]; i <= k; i++)
		{
			DP[i] = DP[i] + DP[i - coin[j]]; // ��ȭ��
		}
	}
	
	cout << DP[k];

	return 0;
}