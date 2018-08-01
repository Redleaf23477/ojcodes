# [Codeforce 922D](https://codeforces.com/problemset/problem/922/D)

## 解法
觀察兩個字串$s_1, s_2$，我們比較$s_1s_2$和$s_2s_1$兩種排法哪個可以產生比較多"sh"子序列。作法是記錄每個字串的's'和't'數量，如果$s_1s_2$的子序列數量少於$s_2s_1$的話，就讓他們交換，也就是在cmp寫個`return a.s*b.t > b.s*a.t;`。排序後再掃過一次陣列算"sh"子序列數量就好了。時間花最多在排序，整體複雜度$O(n \log n)$

```c++
//codeforce 922D
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

struct Seg
{
    string nstr;
    ll s, h, cnt;
    Seg(string str):nstr(str)
    {
        s = h = cnt = 0;
        for(auto c:str)
        {
            if(c == 's') s++;
            else h++, cnt += s;
        }
    }
    bool operator < (Seg &that)
    {
        return this->s*that.h > this->h*that.s;
    }
};

int n;
vector<Seg> noise;

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
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s; cin >> s; noise.emplace_back(s);
    }
    sort(noise.begin(), noise.end());
}

void process()
{
    ll tot = 0, s = 0;
    for(auto x:noise)
    {
        tot += s*x.h + x.cnt;
        s += x.s;
    }
    cout << tot << endl;
}
```


> Written with [StackEdit](https://stackedit.io/).
