//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

struct Node
{
    int leafIdx;
    int combo;
    Node *parent, *root;
    Node *lchild, *rchild, *mostLson;
    Node(int idx = -1):leafIdx(idx)
    {
        combo = 0;
        parent = root = this;
        lchild = rchild = NULL;
        mostLson = this;
    }
};

const int N = 200005;

int n;
string str;
Node *dp[N];
ll ans[N];

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> str;
    n = str.size();
}

ll res;
Node *build_tree(int lidx, Node *r)
{
    if(lidx < 0 || dp[lidx] == NULL)
    {
        r->root = r; return r;
    }
    Node *l = dp[lidx]->root;
    if(r->leafIdx == -1 && l->leafIdx != -1)
    {
        r->root = r; return r;
    }
    Node *p = new Node();
    res += max(1, l->combo * r->combo);
    p->combo = max(1, l->combo + r->combo);
    p->lchild = l, p->rchild = r;
    p->mostLson = l->mostLson;
    // cout << "lidx = " << lidx << " res++ : " << l->leafIdx << " " << r->leafIdx << endl;
    l->parent = r->parent = p;
    r->root = build_tree(p->mostLson->leafIdx-1, p);
    return r->root;
}

void free_branch(Node *r)
{
    if(r->parent != r) free_branch(r->parent);
    delete r;
}

void process()
{
    stack<int> s;
    vector<int> cur;
    // dp
    for(int i = 0, j = 0, jl = 0; i < n; i++)
    {
        // cout << "j = " << j << ", jl = " << jl << endl;
        if(j == 0)
        {
            jl = i;
            ans[i] = 0;
            if(str[i] == '(')
            {
                s.push(j);
                dp[j] = new Node(0);
            }
            else
            {
                dp[j] = NULL;
            }
            cout << ans[i] << endl;
            j++;
            cur.push_back(i);
            continue;
        }
        if(str[i] == '(')
        {
            ans[i] = ans[cur.back()];
            s.push(j);
            dp[j] = new Node(j);
            j++;
            cur.push_back(i);
        }
        else if(str[i] == ')')
        {
            ans[i] = ans[cur.back()];
            if(s.empty())
            {
                dp[j] = NULL;
            }
            else
            {
                dp[j] = new Node(j);
                int lp = s.top(); s.pop();
                res = 0;
                build_tree(lp, dp[j]);
                // cout << "res = " << res << endl;
                ans[i] += res;
            }
            j++;
            cur.push_back(i);
        }
        else  // -
        {
            j--;
            if(str[cur.back()] == '(')
            {
                s.pop();
                delete dp[j];
                dp[j] = NULL;
            }
            else if(str[cur.back()] == ')')
            {
                if(dp[j] != NULL)
                {
                    int l = dp[j]->parent->mostLson->leafIdx;
                    // free_branch(dp[j]);
                    s.push(l);
                    // cout << "( = " << l << endl;
                }
                dp[j] = NULL;
            }
            cur.pop_back();
            ans[i] = (j == 0? 0 : ans[cur.back()]);
        }
        // cout << cur << endl;
        cout << ans[i] << endl;
    }
}

