
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#define MAXN 52

using namespace std;

inline int char2idx(char c)
{
    if (c >= 'a' && c <= 'z')
        return c-'a';
    if (c >= 'A' && c <= 'Z')
        return c-'A'+26;
    return -1;
}
inline char convertCase(char c)
{
    if (c >= 'a' && c <= 'z')
        return c-'a'+'A';
    if (c >= 'A' && c <= 'Z')
        return c-'A'+'a';
    return '\0';
}

int main()
{
    string s, t; cin>>s>>t;
    int alphabet[MAXN]; memset(alphabet, 0, sizeof(alphabet));
    for (int i = 0; i < t.length(); i++)
        alphabet[char2idx(t[i])] ++;

    int a = 0, b = 0;
    bool vis[s.length()]; memset(vis, 0, sizeof(vis));
    for (int i = 0; i < s.length(); i++)
        if (alphabet[char2idx(s[i])] > 0)
            a ++, alphabet[char2idx(s[i])]--, vis[i] = true;
    for (int i = 0; i < s.length(); i++)
        if (!vis[i])
        {
            int x = char2idx(convertCase(s[i]));
            if (alphabet[x] > 0)
                b ++, alphabet[x]--, vis[i] = true;
        }
    cout << a << ' ' << b << endl;
    return 0;
}
