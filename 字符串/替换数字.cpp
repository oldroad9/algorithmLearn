#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string s;
    while (cin >> s)
    {
        int count = 0; // 记录数字大小
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                count++;
            }
        }
        int sOldsize = s.size();
        s.resize(sOldsize + count * 5);
        int sNewSize = s.size();
        string number = "number";
        for (int i = sNewSize - 1, j = sOldsize - 1; i > j; i--, j--)
        {
            if (s[j] > '9' || s[j] < '0')
            {
                s[i] = s[j];
            }
            else
            {
                for (int index = 0; index < 6; index++)
                {
                    s[i] = number[5 - index];
                    i--;
                }
                i++; // 多减了一次
            }
        }
    }
    cout << s << endl;
    return 0;
}
