/*
 * Matrix2D derived from vector<vector<ll>>
 *
 * Tested : https://atcoder.jp/contests/dp/tasks/dp_r
 *
*/


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



