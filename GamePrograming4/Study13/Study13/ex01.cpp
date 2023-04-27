#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    map<char, int> m;

    for (int i = 0; i < s.size(); i++)
    {
        char temp = s[i];

        if (m.count(temp))
        {
            answer.push_back(m[temp] - i);
            m[temp] = i;
        }
        else
        {
            m.insert(make_pair(temp, i));
            answer.push_back(-1);
        }
    }
    
    return answer;
}
