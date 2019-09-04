//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

class Matrix2D : public vector<vector<ll>>
{
private:
public:
    Matrix2D(){}
    Matrix2D(size_t rn, size_t cn, bool standard = true)
    {
        this->resize(rn);
        for(auto &r:(*this)) r.resize(cn, 0);
        if(rn == cn && standard) 
            for(size_t i = 0; i < rn; i++) (*this)[i][i] = 1;
    }
    size_t getRowNum() { return this->size(); }
    size_t getColNum() { return (*this)[0].size(); }
    Matrix2D operator*(Matrix2D that)
    {
        assert(this->getColNum() == that.getRowNum());
        Matrix2D res(this->getRowNum(), that.getColNum(), false);
        for(size_t i = 0; i < res.getRowNum(); i++)
            for(size_t j = 0; j < res.getColNum(); j++)
                for(size_t k = 0; k < this->getColNum(); k++)
                    res[i][j] = (res[i][j] + (*this)[i][k] * that[k][j])%MOD;
        return res;
    }
    Matrix2D powerN(size_t n)
    {
        assert(this->getRowNum() == this->getColNum());
        if(n == 0) return Matrix2D(this->getRowNum(), this->getColNum());
        Matrix2D res = (*this)*(*this);
        if(n%2 == 0) return res.powerN(n/2);
        return (*this) * res.powerN(n/2);
    }
    void print(ostream &out)
    {
        for(auto &r:*this)
        {
            for(auto &c:r)
                out << c << " ";
            out << endl;
        }
    }
};

const int N = 55;
ll n, k;
Matrix2D mat;

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
    cin >> n >> k;
    mat = Matrix2D(n, n, false);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];
}

void process()
{
    mat = mat.powerN(k);
    Matrix2D cnt(n, 1);
    for(int i = 0; i < n; i++) cnt[i][0] = 1;
    cnt = mat * cnt;
    ll ans = 0;
    for(int i = 0; i < n; i++) ans = (ans + cnt[i][0])%MOD;
    cout << ans << endl;
}

