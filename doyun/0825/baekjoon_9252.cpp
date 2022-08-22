#include <iostream>
#include <string>

using namespace std;

// 백준 9252 - LCS 2
// DP, LCS
// 골드 4
// LCS 수열 : 끝에서 반대로 올라가면서 찾는다.

int DP[1001][1001];

int main()
{
	string s1, s2;
	string res = "";
	cin >> s1 >> s2;
	s1 = "/" + s1;
	s2 = "." + s2;

	for (int i = 1; i < s1.length(); i++)
	{
		for (int j = 1; j < s2.length(); j++)
		{
			if (s1[i] == s2[j]) // 같다면 +1
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

	if (DP[s1.length() - 1][s2.length() - 1] != 0)
	{
		cout << DP[s1.length() - 1][s2.length() - 1] << '\n';

		// 역순으로 올라가기 -> 수열 찾기
		int tmp_y = s1.length() - 1;
		int tmp_x = s2.length() - 1;
		
		while (tmp_y > 0 && tmp_x > 0)
		{
			if (DP[tmp_y][tmp_x] == DP[tmp_y - 1][tmp_x])
			{
				tmp_y--;
			}
			else if (DP[tmp_y][tmp_x] == DP[tmp_y][tmp_x - 1])
			{
				tmp_x--;
			}
			else
			{
				res = s2[tmp_x] + res;
				tmp_x--;
				tmp_y--;
			}
		}
		cout << res;
	}
	else cout << 0;

	return 0;
}