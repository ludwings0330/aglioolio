#include <iostream>
#include <string>

using namespace std;

// ���� 1958 - LCS 3
// DP, LCS
// ��� 3
// (ù��°, �ι�°), (�ι�°, ����°) LCS ���� ��
// �ٽ� �� �ΰ��� LCS ���Ѵ�. -> X Ʋ��

// LCS�� ��Ȯ�� �Ѱ��� �ƴ�, ������ �ѹ��� ���ϴ� ���� ���� ��Ȯ
// -> 3���� DP�� ������.
// 2���� DP�� ������.

int DP[101][101][101];

int main()
{
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	s1 = "." + s1;
	s2 = "/" + s2; // �ε��� DP �迭�� ���߱� ����
	s3 = "@" + s3;

	for (int i = 1; i < s1.length(); i++)
	{
		for (int j = 1; j < s2.length(); j++)
		{
			for (int k = 1; k < s3.length(); k++)
			{
				if (s1[i] == s2[j] && s2[j] == s3[k])
				{
					// ���� ���� ��
					DP[i][j][k] = DP[i - 1][j - 1][k - 1] + 1;
				}
				else
				{					
					// ���� ���� ������ -> ��� ������ �� �ִ� �ֱ�
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