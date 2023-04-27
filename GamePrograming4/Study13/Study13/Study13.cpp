#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    for (int i = 0; i < s.size(); i++)
    {
        if (find(s.begin(), s.find(s[i]), s[i]) != s.find(s[i]))
        {
            int begin = find(s.begin(), s.end(), s[i]) - s.begin();
            int cnt = 0;
            while (begin + cnt < i)
            {
                begin = find(s.begin() + begin, s.end(), s[i]) - s.begin();
                cnt++;
            }

            answer.push_back(i - begin);
        }
        else // 존재하지 않는다면
            answer.push_back(1);
    }

    return answer;
}
