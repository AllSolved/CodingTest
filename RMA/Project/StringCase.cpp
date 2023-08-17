#include "StringCase.h"

int MakeBtoA(string before, string after)
{
    int answer = 1;
    unordered_map<char, int> beforeTable;
    unordered_map<char, int> afterTable;

    // �ܾ ���
    for (int i = 0; i < before.length(); ++i)
    {
        // table�� ���� ���
        if (beforeTable.find(before[i]) == beforeTable.end())
            beforeTable[before[i]] = 1;
        else
            ++beforeTable[before[i]];

        if (afterTable.find(after[i]) == afterTable.end())
            afterTable[after[i]] = 1;
        else
            ++afterTable[after[i]];
    }


    //���ڿ��� ���ڰ� ������, ���� ������ ������ Ȯ��
    auto iter = afterTable.begin();
    auto iterEnd = afterTable.end();

    for (; iter != iterEnd; ++iter)
    {
        // ���ĺ��� �������� ���� ���
        if (beforeTable.find(iter->first) == beforeTable.end())
            return 0;

        // ���ĺ��� �����ϴ� ��� ö�� ������ Ȯ����
        else
        {
            if (beforeTable[iter->first] != iter->second)
                return 0;
        }
    }

    return answer;
}

string MorseSign(string letter)
{
    string answer = "";
    string morse = "'.-':'a','-...':'b','-.-.':'c','-..':'d','.':'e','..-.':'f','--.':'g','....':'h','..':'i','.---':'j','-.-':'k','.-..':'l','--':'m','-.':'n','---':'o','.--.':'p','--.-':'q','.-.':'r','...':'s','-':'t','..-':'u','...-':'v','.--':'w','-..-':'x','-.--':'y','--..':'z'";

    // Map�� ���� table����
    map<string, char> morseTable;
    string morseSign = "";
    for (int i = 0; i < morse.length(); ++i)
    {
        if (morse[i] == '.' || morse[i] == '-')
        {
            morseSign += morse[i];
        }

        // ���� �� ���
        else if (morse[i] >= 'a' && morse[i] <= 'z')
        {
            morseTable[morseSign] = morse[i];
            morseSign.clear();
        }
    }

    string morseLetter = "";
    for (int i = 0; i < letter.length(); ++i)
    {
        if (letter[i] != ' ')
        {
            morseLetter += letter[i];
        }

        else
        {
            answer += morseTable[morseLetter];
            morseLetter.clear();
        }
    }

    // ������ ö�ڴ� ����
    answer += morseTable[morseLetter];

    return answer;
}


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
