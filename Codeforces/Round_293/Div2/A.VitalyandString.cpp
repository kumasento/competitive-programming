
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s, t; cin>>s>>t;
    for (int i = s.length()-1; i >= 0; i--)
    {
        if (s[i] == 'z') s[i] = 'a';
        else { s[i] ++; break; }
    }
    if (s < t)
        cout << s << endl;
    else
        cout << "No such string" << endl;

    return 0;
}
