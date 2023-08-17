#include "StringCase.h"

int MakeBtoA(string before, string after)
{
    int answer = 1;
    unordered_map<char, int> beforeTable;
    unordered_map<char, int> afterTable;

    // 단어를 등록
    for (int i = 0; i < before.length(); ++i)
    {
        // table에 없을 경우
        if (beforeTable.find(before[i]) == beforeTable.end())
            beforeTable[before[i]] = 1;
        else
            ++beforeTable[before[i]];

        if (afterTable.find(after[i]) == afterTable.end())
            afterTable[after[i]] = 1;
        else
            ++afterTable[after[i]];
    }


    //문자열의 글자가 같은지, 글자 갯수가 같은지 확인
    auto iter = afterTable.begin();
    auto iterEnd = afterTable.end();

    for (; iter != iterEnd; ++iter)
    {
        // 알파벳이 존재하지 않을 경우
        if (beforeTable.find(iter->first) == beforeTable.end())
            return 0;

        // 알파벳이 존재하는 경우 철자 수까지 확인함
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

    // Map을 만들어서 table제작
    map<string, char> morseTable;
    string morseSign = "";
    for (int i = 0; i < morse.length(); ++i)
    {
        if (morse[i] == '.' || morse[i] == '-')
        {
            morseSign += morse[i];
        }

        // 문자 일 경우
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

    // 마지막 철자는 저장
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

		// 처음일 경우
		if (q.empty())
		{
			// 숫자
			if ('a' <= c && c <= 'z')
			{
				c -= 32;
			}
			q.push(c);
		}

		else
		{
			char prevC = q.back();
			// 공백일 경우
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
