
#include <iostream>
#include <string>
#include<stack>
using namespace std;
  
bool areBracketsBalanced(string bracket)
{  
    stack<char> s;
    char x;
  
    for (int i = 0; i < bracket.length(); i++) 
    {
        if (bracket[i] == '(' || bracket[i] == '['
            || bracket[i] == '{') 
        {
            s.push(bracket[i]);
            continue;
        }
  
        if (s.empty())
            return false;
  
        switch (bracket[i]) {
        case ')':
              
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;
  
        case '}':
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;
  
        case ']':
  
            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }
  
    return (s.empty());
}
  
int main()
{
    string brackets = "{()}[]";
  
    if (areBracketsBalanced(brackets))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}