
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s, t; cin>>s>>t;

    bool ok = false;
    for (int i = 0; i < s.length(); i++)
        if (s[i] < t[i])
        {
            if (s[i] < t[i]-1)
                s[i] = t[i] - 1, ok = true;
            else
                for (int t = i+1; t < s.length() && !ok; t++)
                    if (s[t] < 'z')
                        s[t] ++, ok = true;
        }
    if (ok)
        cout << s << endl;
    else
        cout << "No such string" << endl;

    return 0;
}
