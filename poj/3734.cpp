//
#include <cstdio>
#include <vector>

using namespace std;
typedef long long int ll;
typedef vector< vector<ll> > Matrix;

const ll MOD = 10007;

int n;

Matrix mul(Matrix lhs, Matrix rhs)
{
    Matrix res;
    int I = lhs.size(), J = lhs[0].size(), K = rhs.size();
    res.resize(I);
    for(int i = 0; i < I; i++) res[i].resize(K, 0);

    for(int i = 0; i < I; i++)
        for(int k = 0; k < K; k++)
            for(int j = 0; j < J; j++)
                res[i][k] = (res[i][k] + lhs[i][j]*rhs[j][k])%MOD;

    return res;
}

Matrix fpw(Matrix m, int p)
{
    if(p == 0)
    {
        Matrix res;
        res.resize(4); for(int i = 0; i < 4; i++) res[i].resize(4, 0);
        for(int i = 0; i < 4; i++) res[i][i] = 1;
        return res;
    }
    if(p%2 == 0) return fpw(mul(m, m), p/2);
    else return mul(m, fpw(mul(m, m), p/2));
}

void init();
void process();

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        init();
        process();
    }
    return 0;
}

void init()
{
    scanf("%d", &n);
}

void process()
{
    Matrix t;
    t.resize(4); for(int i = 0; i < 4; i++) t[i].resize(4);
    t[0][0] = 2, t[0][1] = 1, t[0][2] = 1, t[0][3] = 0;
    t[1][0] = 1, t[1][1] = 2, t[1][2] = 0, t[1][3] = 1;
    t[2][0] = 1, t[2][1] = 0, t[2][2] = 2, t[2][3] = 1;
    t[3][0] = 0, t[3][1] = 1, t[3][2] = 1, t[3][3] = 2;
    printf("%lld\n", fpw(t, n)[0][0]);

}

