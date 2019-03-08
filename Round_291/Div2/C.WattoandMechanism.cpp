
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>

#define MAXC 3

using namespace std;

struct Trie_node
{
    bool exist;
    Trie_node* next[MAXC];
    Trie_node() : exist(false) { memset(next, 0, sizeof(next)); }
};

void insert(Trie_node *root, const char *word)
{
    Trie_node *tmp = root;
    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        int idx = word[i] - 'a';
        if (tmp->next[idx] == NULL)
            tmp->next[idx] = new Trie_node();
        tmp = tmp->next[idx];
    }
    tmp->exist = true;
}

bool dfs(Trie_node *node, const char *word, int diff, int pos)
{
    int len = strlen(word);
    if (diff > 1)
        return false;
    if (pos == len)
        return (diff == 1 && node->exist) ? true : false;
    for (int i = 0; i < MAXC; i++)
        if (node->next[i] != NULL)
            if (dfs(node->next[i], word, diff+(i!=word[pos]-'a'), pos+1))
                return true;
    return false;
}

int main()
{
    int n, m; cin>>n>>m;
    Trie_node* root = new Trie_node();
    for (int i = 0; i < n; i++)
    {
        string word; cin>>word;
        insert(root, word.c_str());
    }
    for (int i = 0; i < m; i++)
    {
        string word; cin>>word;
        if (dfs(root, word.c_str(), 0, 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
