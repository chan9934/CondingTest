#include <iostream>

using namespace std;

int N, M, ret;
char board[51][51];
int main()
{
	ret = 2500;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N - 8 + 1; ++i)
	{
		for (int j = 0; j < M - 8 + 1; ++j)
		{
			int count = 0;

			for (int y = i; y < i + 8; ++y)
			{
				for (int x = j; x < j + 8; ++x)
				{
					if ((y & 1) == (x & 1))
					{
						if (board[y][x] == 'B')
						{
							++count;
						}
					}
					else
					{
						if (board[y][x] == 'W')
						{
							++count;
						}
					}
				}
			}


			count = min(count, 64 - count);
			ret = min(count, ret);
		}
	}
	cout << ret << "\n";

	return 0;
}