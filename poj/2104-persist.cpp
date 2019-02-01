// 2104 - kth number using persistance segment tree
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int ll;

const int N = 100005;

struct Node
{
    int sum;
    Node *lchild, *rchild;
    Node()
    {
        sum = 0;
        lchild = rchild = NULL;
    }
    void up()
    {
        sum = 0;
        if(lchild) sum += lchild->sum;
        if(rchild) sum += rchild->sum;
    }
};

int n, q, newSz;
int arr[N];
int rank2data[N];
Node buf[N*(2+20)];
Node *bufptr;
Node *root[N];

Node *buildTree(int l, int r)
{
    Node *nd = new (bufptr++)  Node();
    if(l == r)
    {
        nd->sum = 0;
        return nd;
    }
    int mid = (l+r)/2;
    nd->lchild = buildTree(l, mid);
    nd->rchild = buildTree(mid+1, r);
    nd->up();
    return nd;
}

Node *modify(int l, int r, Node *copyFrom, int pos, int val)
{
    if(pos < l || r < pos) return copyFrom;
    Node *nd = new (bufptr++) Node(*copyFrom);
    if(l == pos && r == pos)
    {
        nd->sum += val;
        return nd;
    }
    int mid = (l+r)/2;
    nd->lchild = modify(l, mid, copyFrom->lchild, pos, val);
    nd->rchild = modify(mid+1, r, copyFrom->rchild, pos, val);
    nd->up();
    return nd;
}

int query(int l, int r, Node *ltree, Node *rtree, int k)
{
    if(l == r)
    {
        return l;
    }
    int mid = (l+r)/2, leftSum = rtree->lchild->sum - ltree->lchild->sum;
    if(leftSum < k)
    {
        return query(mid+1, r, ltree->rchild, rtree->rchild, k-leftSum);
    }
    else 
    {
        return query(l, mid, ltree->lchild, rtree->lchild, k);
    }
}

void init();
void process();

int main()
{
    init();
    process();
    return 0;
}

void init()
{
    bufptr = &buf[0];
    scanf("%d %d", &n, &q);
    vector<int> tmp(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        tmp[i] = arr[i];
    }
    // data to rank
    sort(tmp.begin(), tmp.end());
    newSz = unique(tmp.begin(), tmp.end()) - tmp.begin();
    tmp.resize(newSz);
    for(int i = 0; i < n; i++)
    {
        int rk = lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();
        rank2data[rk] = arr[i];
        arr[i] = rk;
    }
    // build st
    root[0] = buildTree(0, newSz-1);
    for(int i = 0; i < n; i++)
    {
        root[i+1] = modify(0, newSz-1, root[i], arr[i], 1);
    }
}

void process()
{
    int l, r, k;
    while(q--)
    {
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", rank2data[query(0, newSz-1, root[l-1], root[r], k)]);
    }
}

