#include <iostream>
#include <string>

using namespace std;

// 백준 9251 - LCS
// DP
// 골드 5
// LCS(Longest Common Subsequence) 기본 문제

int DP[1001][1001];

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	for (int i = 1; i <= s1.length(); i++)
	{
		for (int j = 1; j <= s2.length(); j++)
		{
			if (s1[i - 1] == s2[j - 1]) // 같다면 +1
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else // 더 큰 수열로 갱신
			{
				if (DP[i][j - 1] > DP[i - 1][j])
				{
					DP[i][j] = DP[i][j - 1];
				}
				else
				{
					DP[i][j] = DP[i-1][j];
				}
			}
		}
	}

	cout << DP[s1.length()][s2.length()];

	return 0;
}