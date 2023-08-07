#include "StringCase.h"

string JadenCase(string s)
{
	queue<char> q;
	string answer = "";

	for (int i = 0; i < s.length(); ++i)
	{
		char c = s[i];

		if (('0' <= c && c <= '9') || c == ' ')
		{
			q.push(c);
			continue;
		}

		// ó���� ���
		if (q.empty())
		{
			// ����
			if ('a' <= c && c <= 'z')
			{
				c -= 32;
			}
			q.push(c);
		}

		else
		{
			char prevC = q.back();
			// ������ ���
			if (prevC == ' ')
			{
				if ('a' <= c && c <= 'z')
				{
					c -= 32;
				}
			}
			else
			{
				if ('A' <= c && c <= 'Z')
				{
					c += 32;
				}
			}
			q.push(c);
		}
	}

	while (!q.empty())
	{
		answer += q.front();
		q.pop();
	}

	return answer;

}
