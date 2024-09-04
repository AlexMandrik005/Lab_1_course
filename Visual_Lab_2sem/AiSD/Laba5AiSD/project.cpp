#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    stack <char> st;
    string s, answer = "������ ����������� �����";
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        }

        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (st.top() == '(' && s[i] == ')' ||
                st.top() == '[' && s[i] == ']' ||
                st.top() == '{' && s[i] == '}')
            {
                st.pop();
            }
        }

    }
    if (!st.empty())
        answer = "������ ����������� �� �����";
    std::cout << answer;

    return 0;
}