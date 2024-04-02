#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reverseString(vector<char> &s)
{
    for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
    {
        swap(s[i], s[j]);
    }
}

void reverseString(string &s)
{
    for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
    {
        swap(s[i], s[j]);
    }
}

int main()
{
    vector<char> s;
    s.push_back('a');
    s.push_back('b');
    s.push_back('e');
    s.push_back('d');
    s.push_back('c');
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << *i << " ";
    }
    reverseString(s);
    cout << endl;
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    string s1 = "asdasddas";
    for (auto i = s1.begin(); i != s1.end(); i++)
    {
        cout << *i << " ";
    }
    reverseString(s1);
    cout << endl;
    for (auto i = s1.begin(); i != s1.end(); i++)
    {
        cout << *i << " ";
    }
}