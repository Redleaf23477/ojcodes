//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

struct Node
{
    char ch;
    ll leafcnt;
    Node *nxt[26];
    Node(char ch):ch(ch), leafcnt(0)
    {
        for(int i = 0; i < 26; i++) nxt[i] = NULL;
    }
};

int n, len;
vector<set<char>> charset;
vector<string> arr;
Node *trie;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, caseN = 0; cin >> T;
    while(T--)
    {
        cout << "Case #" << ++caseN << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void build(Node *ptr, string &str, int idx)
{
    if(idx == len) return;
    int nxtidx = str[idx]-'A';
    if(ptr->nxt[nxtidx] == NULL) ptr->nxt[nxtidx] = new Node(str[idx]);
    ptr->leafcnt++;
    build(ptr->nxt[nxtidx], str, idx+1);
}

char stk[100];
void print(Node *ptr, int depth)
{
    if(depth == len)
    {
        for(int i = 0; i < len; i++) cout << stk[i];
        cout << endl;
        return;
    }
    for(int i = 0; i < 26; i++)
    {
        if(ptr->nxt[i] != NULL)
        {
            stk[depth] = 'A'+i;
            print(ptr->nxt[i], depth+1);
        }
    }
}

void freeTrie(Node *ptr)
{
    for(int i = 0; i < 26; i++)
    {
        if(ptr->nxt[i] != NULL) freeTrie(ptr->nxt[i]);
        delete ptr->nxt[i];
    }
}

void init()
{
    cin >> n >> len;
    trie = new Node('X');
    charset.resize(len);
    for(int i = 0; i < len; i++) charset[i].clear();
    arr.resize(n);
    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i];
        for(int j = 0; j < len; j++) charset[j].insert(arr[i][j]);
    }
    for(int i = 0; i < n; i++)
    {
        build(trie, arr[i], 0);
    }
//    print(trie, 0);
}

string ans;
void dfs(Node *ptr, int depth)
{
    if(ans.size() == len) return;
    ll mn = (1ll<<60), mnidx = -1;
    for(auto c:charset[depth])
    {
        int i = c-'A';
        if(ptr->nxt[i] == NULL)
        {
            ans.push_back('A'+i);
            for(size_t j = ans.size(); j < len; j++) 
            {
                ans.push_back(*charset[j].begin());
            }
            return;
        }
        else if(ptr->nxt[i]->leafcnt < mn)
        {
            mn = ptr->nxt[i]->leafcnt;
            mnidx = i;
        }
    }
    ans.push_back('A'+mnidx);
    dfs(ptr->nxt[mnidx], depth+1);
}

void process()
{
    if(len == 1)
    {
        cout << "-" << endl;
    }
    else
    {
        ll maxNum = 1;
        for(int i = 0; i < len; i++) maxNum *= charset[i].size();
        if(trie->leafcnt == maxNum) cout << "-" << endl;
        else 
        {
            ans.clear();
            dfs(trie, 0);
            cout << ans << endl;
        }
    }
    freeTrie(trie);
    delete trie;
    trie = NULL;
}

