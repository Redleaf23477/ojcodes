//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const ll INF = (1ll << 60);

/////////////////////////////////
// Treap Template              //
/////////////////////////////////

struct Treap
{
    int pri, sz;
    int rev;
    ll data, tag, sum, mxsum, mxpre, mxpost;   // tag: make-same
    Treap *lchild, *rchild;
    Treap(ll d):pri(rand()), sz(1), rev(0), data(d), tag(INF), sum(d), mxsum(d), lchild(NULL), rchild(NULL)
    {
        mxpre = mxpost = max(d, 0ll);
    }
    inline void up();
    inline void down();
}; 

inline int size(Treap *t) { return t? t->sz:0; }
inline ll get_data(Treap *t) { return t? t->data:0; }
inline ll get_sum(Treap *t) { return t? t->sum:0; }
inline ll get_mxsum(Treap *t) { return t? t->mxsum:-INF; }
inline ll get_mxpre(Treap *t) { return t? t->mxpre:0; }
inline ll get_mxpost(Treap *t) { return t? t->mxpost:0; }

inline void Treap::up()
{
    if(lchild) lchild->down();
    if(rchild) rchild->down();
    sz = 1+size(lchild)+size(rchild);
    sum = get_sum(lchild) + data + get_sum(rchild);
    mxpre = max({ 0ll, get_mxpre(lchild), get_sum(lchild)+data, get_sum(lchild)+data+get_mxpre(rchild) });
    mxpost = max({ 0ll, get_mxpost(rchild), data+get_sum(rchild), get_mxpost(lchild)+data+get_sum(rchild) });
    mxsum = max({ get_mxsum(lchild), get_mxsum(rchild), data, get_mxpost(lchild)+data+get_mxpre(rchild) });
}

inline void Treap::down()
{
    if(tag != INF)
    {
        data = tag;
        sum = tag*sz;
        mxpre = mxpost = max(0ll, tag*sz);
        mxsum = max(tag, tag*sz);
        if(lchild) lchild->tag = tag;
        if(rchild) rchild->tag = tag;
        tag = INF;
    }
    if(rev)
    {
        swap(mxpre, mxpost);
        swap(lchild, rchild);
        if(lchild) lchild->rev ^= 1;
        if(rchild) rchild->rev ^= 1;
        rev ^= 1;
    }
}

void freeTreap(Treap *t)
{
    if(!t) return;
    if(t->lchild) freeTreap(t->lchild);
    if(t->rchild) freeTreap(t->rchild);
    delete t;
}

Treap *merge(Treap *a, Treap *b)
{
    if(!a || !b) return (a? a:b);
    if(a->pri < b->pri)
    {
        a->down();
        a->rchild = merge(a->rchild, b);
        a->up();
        return a;
    }
    else
    {
        b->down();
        b->lchild = merge(a, b->lchild);
        b->up();
        return b;
    }
}

void split(Treap *o, Treap *&a, Treap *&b, int k)
{
    if(!o) a = b = NULL;
    else
    {
        o->down();
        if(k >= size(o->lchild)+1)
        {
            a = o;
            split(o->rchild, a->rchild, b, k-size(o->lchild)-1);
        }
        else 
        {
            b = o;
            split(o->lchild, a, b->lchild, k);
        }
        o->up();
    }
}

void printTreap(Treap *t)
{
    if(!t) return;
    printTreap(t->lchild);
  //  cout << "(deb)" << t->data << ": mxpre = " << t->mxpre << ", mxpost = " << t->mxpost << endl;
    cout << t->data << " ";
    printTreap(t->rchild);
}

////////////////////////////////

int n, q;
Treap *tp;

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

inline void print(Treap *t)
{
    printTreap(t); cout << endl;
}

void init()
{
    srand(7122+time(NULL));
    tp = NULL;
    cin >> n >> q;
    while(n--)
    {
        int x; cin >> x;
        tp = merge(tp, new Treap(x));
    }
//    print(tp);
}

inline void ins()
{
    int pos, k; cin >> pos >> k; 
    if(k == 0) return;
    Treap *tmp = NULL;
    while(k--) { int x; cin >> x; tmp = merge(tmp, new Treap(x)); }
    Treap *a, *b;
    split(tp, a, b, pos);
    tp = merge(a, merge(tmp, b));
}

inline void del()
{
    int pos, k; cin >> pos >> k;
    if(k == 0) return;
    Treap *a, *b, *c;
    split(tp, a, b, pos-1);
    split(b, b, c, k);
    freeTreap(b);
    tp = merge(a, c);
}

inline void makeSame()
{
    int pos, k, i; cin >> pos >> k >> i;
    if(k == 0) return;
    Treap *a, *b, *c;
    split(tp, a, b, pos-1);
    split(b, b, c, k);
    b->tag = i;
    tp = merge(a, merge(b, c));
}

inline void rev()
{
    int pos, k; cin >> pos >> k;
    if(k == 0) return;
    Treap *a, *b, *c;
    split(tp, a, b, pos-1);
    split(b, b, c, k);
    b->rev ^= 1;
    tp = merge(a, merge(b, c));
}

inline ll getSum()
{
    int pos, k; cin >> pos >> k;
    if(k == 0) return 0;
    Treap *a, *b, *c;
    split(tp, a, b, pos-1);
    split(b, b, c, k);
    b->down();
    ll sum = get_sum(b);
    tp = merge(a, merge(b, c));
    return sum;
}

inline ll mxSum()
{
    tp->down();
    return get_mxsum(tp);
}

void process()
{
    string str;
    while(q--)
    {
        cin >> str;
        if(str[0] == 'I') ins();
        else if(str[0] == 'D') del();
        else if(str[2] == 'K') makeSame();
        else if(str[0] == 'R') rev();
        else if(str[0] == 'G') cout << getSum() << endl;
        else cout << mxSum() << endl;
//        print(tp); 
    }
}