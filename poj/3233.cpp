//
#include <cstdio>
#include <vector>

using namespace std;
typedef long long int ll;
typedef vector< vector<ll> > Matrix;

ll n, m, k;
Matrix A;

Matrix mul(Matrix lhs, Matrix rhs)
{
    Matrix res;
    int I = lhs.size(), J = lhs[0].size(), K = rhs[0].size();
    res.resize(I); for(int i = 0; i < I; i++) res[i].resize(K, 0);
    for(int i = 0; i < I; i++)
        for(int k = 0; k < K; k++)
            for(int j = 0; j < J; j++)
                res[i][k] = (res[i][k] + lhs[i][j]*rhs[j][k])%m;
    return res;
}

Matrix fpw(Matrix m, int p)
{
    if(p == 0)
    {
        Matrix res;
        res.resize(m.size());
        for(size_t i = 0; i < res.size(); i++) res[i].resize(m[i].size(), 0);
        for(size_t i = 0; i < m.size(); i++) res[i][i] = 1;
        return res;
    }
    if(p%2 == 0) return fpw(mul(m, m), p/2);
    else return mul(fpw(mul(m, m), p/2), m);
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
    scanf("%lld %lld %lld", &n, &k, &m);
    A.resize(n); for(int i = 0; i < n; i++) A[i].resize(n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%lld", &A[i][j]);
}

void process()
{
    Matrix m;
    m.resize(A.size()*2);
    for(size_t i = 0; i < m.size(); i++) m[i].resize(A.size()*2, 0);
    for(size_t i = 0; i < A.size(); i++)
    {
        m[i][i] = 1;
        m[i+A.size()][i] = 1;
    }
    for(size_t i = 0; i < A.size(); i++)
        for(size_t j = 0; j < A.size(); j++)
            m[i+A.size()][j+A.size()] = A[i][j];
    
    Matrix b;
    b.resize(A.size()*2);
    for(size_t i = 0; i < b.size(); i++) b[i].resize(A.size());
    for(size_t i = 0; i < A.size(); i++)
        for(size_t j = 0; j < A.size(); j++)
        {
            b[i][j] = A[i][j];
            b[i+A.size()][j] = A[i][j];
        }

    Matrix res;
    m = fpw(m, k-1);
    res = mul(m, b);
    for(size_t i = 0; i < A.size(); i++)
    {
        printf("%lld", res[i+A.size()][0]);
        for(size_t j = 1; j < A.size(); j++)
            printf(" %lld", res[i+A.size()][j]);
        printf("\n");
    }
}

