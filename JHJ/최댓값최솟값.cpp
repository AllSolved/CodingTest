#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> vec;
    string str;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!= ' ')
        {
            str += s[i];
        }
        else
        {
            vec.push_back(stoi(str));
            str.clear();
        }
    }
    vec.push_back(stoi(str));
    sort(vec.begin(),vec.end());
    answer += to_string(vec.front())+" "+ to_string(vec.back());
    return answer;
}