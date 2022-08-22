#include <iostream>
#include <string>

using namespace std;

// 백준 1958 - LCS 3
// DP, LCS
// 골드 3
// (첫번째, 두번째), (두번째, 세번째) LCS 구한 후
// 다시 그 두개로 LCS 구한다. -> X 틀림

// LCS가 정확히 한개가 아님, 세개를 한번에 구하는 것이 가장 정확
// -> 3차원 DP로 구하자.
// 2차원 DP랑 유사함.

int DP[101][101][101];

int main()
{
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	s1 = "." + s1;
	s2 = "/" + s2; // 인덱스 DP 배열과 맞추기 위해
	s3 = "@" + s3;

	for (int i = 1; i < s1.length(); i++)
	{
		for (int j = 1; j < s2.length(); j++)
		{
			for (int k = 1; k < s3.length(); k++)
			{
				if (s1[i] == s2[j] && s2[j] == s3[k])
				{
					// 문자 같을 때
					DP[i][j][k] = DP[i - 1][j - 1][k - 1] + 1;
				}
				else
				{					
					// 문자 같지 않으면 -> 모든 가짓수 중 최댓값 넣기
					int max = -1000000;
					if (DP[i - 1][j - 1][k] > max) max = DP[i - 1][j - 1][k];
					if (DP[i][j - 1][k - 1] > max) max = DP[i][j - 1][k - 1];
					if (DP[i - 1][j][k - 1] > max) max = DP[i - 1][j][k - 1];

					if (DP[i - 1][j][k] > max) max = DP[i - 1][j][k];
					if (DP[i][j - 1][k] > max) max = DP[i][j - 1][k];
					if (DP[i][j][k - 1] > max) max = DP[i][j][k - 1];
					DP[i][j][k] = max;
					
				}
			}
		}
	}

	cout << DP[s1.length() - 1][s2.length() - 1][s3.length() - 1];	

	return 0;
}