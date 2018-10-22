//
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long int ll;

const int N = 10005;
const double PI = acos(-1.0); //3.14159265359; // 3.14 will WA  // 3.14159 will WA

struct Node
{
    double x, y, rot;
};

int n, q;
int len[N];
Node st[4*N];
double angle[N];    // angle between i and i+1

void init();
void process();

int main()
{
    bool firstCase = true;
    while(~scanf("%d %d", &n, &q))
    {
        if(!firstCase) printf("\n");
        firstCase = false;
        init();
        process();
    }
    return 0;
}

void printNode(int idx)
{
    printf("st[%d]=(%f, %f, %f)\n", idx, st[idx].x, st[idx].y, st[idx].rot);
}

void rotate(int idx, double rot)
{
    double cosTheta = cos(rot), sinTheta = sin(rot);
    double newx = cosTheta*st[idx].x - sinTheta*st[idx].y;
    double newy = sinTheta*st[idx].x + cosTheta*st[idx].y;
    st[idx].x = newx, st[idx].y = newy;
}

void up(int l, int r, int idx)
{
    if(l < r)
    {
        int lson = idx*2, rson = idx*2+1;
        st[idx].x = st[lson].x + st[rson].x;
        st[idx].y = st[lson].y + st[rson].y;
    }
}

void down(int l, int r, int idx)
{
    if(l < r) // not leaf
    {
        int lson = idx*2, rson = idx*2+1;
        st[lson].rot += st[idx].rot, st[rson].rot += st[idx].rot;
        rotate(lson, st[idx].rot);
        rotate(rson, st[idx].rot);
    }
    st[idx].rot = 0;
}

void buildst(int l, int r, int idx)
{
    if(l == r)
    {
        //st[idx] = (Node){0, (double)len[l], 0};
        st[idx].x = 0, st[idx].y = len[l], st[idx].rot = 0;
        return;
    }
    int mid = (l+r)/2;
    buildst(l, mid, idx*2);
    buildst(mid+1, r, idx*2+1);
    up(l, r, idx);
}

void modify(int L, int R, double rot, int l, int r, int idx)
{
    if(r < L || R < l) return;
    down(l, r, idx);
    if(L <= l && r <= R)
    {
        st[idx].rot = rot;
        rotate(idx, rot);
        return;
    }
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
    modify(L, R, rot, l, mid, lson);
    modify(L, R, rot, mid+1, r, rson);
    up(l, r, idx);
}

void init()
{
    for(int i = 0; i < 4*n; i++) st[i].x = st[i].y = st[i].rot = 0;
    for(int i = 0; i < n; i++) scanf("%d", &len[i]);
    buildst(0, n-1, 1);
    for(int i = 0; i < n; i++) angle[i] = PI;
}

void process()
{
    while(q--)
    {
        int pos, ang; scanf("%d %d", &pos, &ang); 
        double rad = ang*PI/180.0;
        double rot = rad-angle[pos];
        modify(pos, n-1, rot, 0, n-1, 1);
        angle[pos] = rad;
        down(0, n-1, 1);
        printf("%.2f %.2f\n", st[1].x, st[1].y);
    }
}

