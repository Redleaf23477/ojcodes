//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> Mat;

ll n;

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

void init()
{
    cin >> n;
}

Mat mul(Mat lhs, Mat rhs)
{
    Mat res(lhs.size());
    for(auto &x : res) x.resize(rhs[0].size(), 0);

    for(int i = 0; i < res.size(); i++)
        for(int j = 0; j < res[i].size(); j++)
            for(int k = 0; k < rhs.size(); k++)
                res[i][j] = (res[i][j] + lhs[i][k] * rhs[k][j])%1000;

    return res;
}

Mat fpw(Mat m, ll p)
{
    if(p == 0)
    {
        Mat res = m;
        for(auto &x : res)
            for(auto &y : x) y = 0;
        for(size_t i = 0; i < res.size(); i++) res[i][i] = 1;
        return res;
    }
    else 
    {
        if(p%2 == 1) return mul(m, fpw(mul(m, m), p>>1));
        else return fpw(mul(m, m), p>>1);
    }
}

void process()
{
    Mat a = {{3, 5}, {1, 3}};
    a = fpw(a, n-1);
    Mat x = {{3}, {1}};
    Mat b = mul(a, x);
    cout << setw(3) << setfill('0') << (b[0][0]*2+999)%1000 << endl;
}

