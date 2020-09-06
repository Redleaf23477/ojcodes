/*
 * Guass Jordon solve equation set
 *
 * Tested : brainbook pg 292
 *
*/

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

class Matrix2D : public vector<vector<double>>
{
private:
public:
    Matrix2D(){}
    Matrix2D(vector<vector<double>> &vec):vector<vector<double>>(vec)
    {
    }
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
                    res[i][j] = (res[i][j] + (*this)[i][k] * that[k][j]);
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


class GuassJordon
{
private:
    enum Verdict { v_sol, v_noSol, v_infSol };
    static constexpr double EPS = 1e-9;
    int n; // num of variables
    Matrix2D A; // A[nx(n+1)]
    Verdict result;
public:
    GuassJordon(int _n, Matrix2D _A):n(_n), A(_A)
    {
        solve();
    }
    void solve()
    {
        bool hasSolFlg = true;
        for(int it = 0; it < n; it++)
        {
            // find the var with the abs largest coef
            int pivot = it;
            for(int i = it; i < n; i++)
                if(abs(A[i][it]) > abs(A[pivot][it])) pivot = i;
            swap(A[it], A[pivot]);
            if(abs(A[pivot][it] ) <= EPS) 
            {
                hasSolFlg = false; continue;
            }
            // cancel
            for(int i = n; i >= it; i--) A[it][i] /= A[it][it];
            for(int i = 0; i < n; i++)
            {
                if(i == it) continue;
                double ratio = A[i][it];
                for(int j = 0; j <= n; j++)
                {
                    A[i][j] -= A[it][j] * ratio;
                }
            }
        }
        if(hasSolFlg == false)
        {
            for(int i = 0; i < n; i++)
            {
                bool allZero = true;
                for(int j = 0; j < n && allZero; j++)
                    allZero = abs(A[i][j]) <= EPS;
                if(allZero)
                {
                    result = (A[i][n] == 0? v_infSol : v_noSol); 
                }
            }
        }
    }
    bool haveSol() { return result == v_sol; }
    bool noSol() { return result == v_noSol; }
    bool infSol() { return result == v_infSol; }
    vector<double> getSol()
    {
        vector<double> ans(n);
        for(int i = 0; i < n; i++) ans[i] = -A[i].back();
        return ans;
    }
};

using P = pair<int,int>;
#define r first
#define c second

const int N = 15;

int R, C;
char arr[N][N];
int idx[N][N];

int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, 1, -1};

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
    cin >> R >> C;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin >> arr[i][j];
}

bool legal(int r, int c)
{
    return 0 <= r && r < R && 0 <= c && c < C;
}

int bfs()
{
    int cnt = 0;
    queue<P> q;
    q.emplace(R-1, C-1);
    arr[R-1][C-1] = 'x';
    while(!q.empty())
    {
        P f = q.front(); q.pop();
        for(int d = 0; d < 4; d++)
        {
            int r = f.r + dr[d], c = f.c + dc[d];
            if(legal(r, c) && arr[r][c] == '.')
            {
                arr[r][c] = 'o';
                idx[r][c] = cnt++;
                q.emplace(r, c);
            }
        }
    }
    return cnt;
}

void process()
{
    int n = bfs();
    vector<vector<double>> tmp(n, vector<double>(n+1, 0));

    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
        {
            if(arr[r][c] != 'o') continue;
            tmp[idx[r][c]][idx[r][c]] = 1;
            tmp[idx[r][c]][n] = -1;
            int cnt = 0;
            for(int d = 0; d < 4; d++)
            {
                if(legal(r+dr[d], c+dc[d]) && arr[r+dr[d]][c+dc[d]] == 'o')
                    cnt++;
            }
            for(int d = 0; d < 4; d++)
            {
                if(legal(r+dr[d], c+dc[d]) && arr[r+dr[d]][c+dc[d]] == 'o')
                    tmp[idx[r][c]][idx[r+dr[d]][c+dc[d]]] = -1.0/cnt;
            }
        }

    Matrix2D mat = tmp;
    GuassJordon gj(n, tmp);

    vector<double> var = gj.getSol();

    double ans = 1;
    int cnt = 0, r = R-1, c = C-1;
    for(int d = 0; d < 4; d++)
    {
        if(legal(r+dr[d], c+dc[d]) && arr[r+dr[d]][c+dc[d]] == 'o')
            cnt++;
    }
    for(int d = 0; d < 4; d++)
    {
        if(legal(r+dr[d], c+dc[d]) && arr[r+dr[d]][c+dc[d]] == 'o')
            ans += 1.0/cnt*var[idx[r+dr[d]][c+dc[d]]];
    }
    cout << ans << endl;
}
