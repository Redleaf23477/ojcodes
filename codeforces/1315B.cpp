// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

using namespace std;
using ll = long long int;

ll a, b, p;
string str;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> a >> b >> p;
    cin >> str;
}

void process()
{
    vector<int> money, idx;
    char ch = str.back();
    money.push_back(0);
    idx.push_back(str.size()-1);
    for(int i = str.size()-1; i >= 0; i--)
    {
        if(ch != str[i])
        {
            if(i != str.size()-2)
            {
                money.push_back(money.back()+(ch == 'A'? a : b));
                idx.push_back(i+1);
            }
            ch = str[i];
        }
    }
    money.push_back(money.back()+(ch == 'A'? a : b));
    idx.push_back(0);

    /*
    cout << "debug" << endl;
    for(int i = 0; i < money.size(); i++) cout << i << " : " << money[i] << " " << idx[i] << endl;
    */

    int i = upper_bound(money.begin(), money.end(), p)-money.begin()-1;
    cout << idx[i]+1 << endl;
}

