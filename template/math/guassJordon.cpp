/*
 * Guass Jordon solve equation set
 *
 * Tested : 
 *
*/

#include <bits/stdc++.h>

using namespace std;

class Matrix2D : public vector<vector<double>>
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

int main()
{
    Matrix2D mat(3, 4);
    // ax + by + cz + d = 0 => {a, b, c, d}
    mat[0] = {1, -2, 3, -6};
    mat[1] = {4, -5, 6, -12};
    mat[2] = {7, -8, 10, -21};
    mat.print(cout); cout << endl;
    GuassJordon gj(3, mat);
    if(gj.haveSol())
    {
        cout << "Has solution" << endl;
        auto res = gj.getSol();
        for(auto x : res) cout << x << endl;
    }
    else if(gj.infSol())
    {
        cout << "Inf solution" << endl;
    }
    else
    {
        cout << "No solution" << endl;
    }
}
