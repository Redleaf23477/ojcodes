#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define endl '\n'
const ll INF = 1ll<<60;

struct Treap {
    int pri, sz;
    ll data, tag, mn;
    Treap *l, *r;
    Treap(ll d):pri(rand()), sz(1), data(d), tag(0), mn(d), l(NULL), r(NULL) {}
    inline void up();
    inline void down();
}; 

int size(Treap *t) { return t? t->sz:0; }
ll get_data(Treap *t) { return t? t->data:INF; }
ll get_min(Treap *t) { return t? t->mn:INF; }

void Treap::up() {
    if(l) l->down();
    if(r) r->down();
    sz = 1+size(l)+size(r);
    mn = min({ data+tag, get_min(l), get_min(r) });
}
void Treap::down() {
    data += tag;
    mn += tag;
    if(l) l->tag += tag;
    if(r) r->tag += tag;
    tag = 0;
}
void freeTreap(Treap *t) {
    if(!t) return;
    if(t->l) freeTreap(t->l);
    if(t->r) freeTreap(t->r);
    delete t;
}
Treap *merge(Treap *a, Treap *b) {
    if(!a || !b) return (a? a:b);
    if(a->pri < b->pri) {
        a->down();
        a->r = merge(a->r, b);
        a->up();
        return a;
    } else {
        b->down();
        b->l = merge(a, b->l);
        b->up();
        return b;
    }
}
void split(Treap *o, Treap *&a, Treap *&b, int k) {
    if(!o) a = b = NULL;
    else {
        o->down();
        if(k >= size(o->l)+1) {
            a = o;
            split(o->r, a->r, b, k-size(o->l)-1);
        } else {
            b = o;
            split(o->l, a, b->l, k);
        }
        o->up();
    }
}

Treap* buildTreap(vector<ll> &arr) {
    srand(7122+time(NULL));
    Treap *tp = NULL;
    for(auto x : arr)
        tp = merge(tp, new Treap(x));
    return tp;
}
void addTag(Treap *tp, int l, int r, ll val) {
    Treap *a, *b, *c;
    split(tp, a, b, l-1);
    split(b, b, c, r-l+1);
    b->tag += val;
    tp = merge(a, merge(b, c));
}
ll query(Treap *tp, int l, int r) {
    Treap *a, *b, *c;
    split(tp, a, b, l-1);
    split(b, b, c, r-l+1);
    ll ans = b->mn;
    tp = merge(a, merge(b, c));
    return ans;
}

int n, q;
Treap *tp = NULL;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
}

void init()
{
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    tp = buildTreap(arr);
    cin >> q >> ws;
}

void process()
{
    while(q--)
    {
        string str; getline(cin, str);
        stringstream ss(str);
        vector<ll> arg;
        ll x;
        while(ss >> x) arg.push_back(x);
        arg[0]++, arg[1]++;
        if(arg.size() == 3)
        {
            if(arg[0] <= arg[1]) addTag(tp, arg[0], arg[1], arg[2]);
            else 
            {
                addTag(tp, arg[0], n, arg[2]);
                addTag(tp, 1, arg[1], arg[2]);
            }
        }
        else
        {
            if(arg[0] <= arg[1]) cout << query(tp, arg[0], arg[1]) << endl;
            else cout << min(query(tp, arg[0], n), query(tp, 1, arg[1])) << endl;
        }
    }
}

