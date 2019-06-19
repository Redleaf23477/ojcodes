//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

struct Node
{
    ll sum;
    Node *ch[2];
    Node():sum(0)
    {
        ch[0] = ch[1] = NULL;
    }
};

Node *trie;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    trie = new Node;

}

void process()
{
}

