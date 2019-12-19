//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

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
    cin >> str;
}

void process()
{
    string ans;
    queue<size_t> idx[10];
    int comboParity = -1;
    size_t i,j;
    for(i = 0, j = 0; i < str.size(); i++)
    {
        int d = (str[i]-'0')%2;
        if(comboParity == -1)
        {
            idx[d].push(i);
            comboParity = d%2;
        }
        else if(comboParity == d%2) // same parity
        {
            idx[d].push(i);
        }
        else // different parity
        {
            int posToIns = -1;
            for(int k = d+1; k < 10; k++)
            {
                if(!idx[k].empty()) posToIns = idx[k].front();
            }
            if(posToIns == -1)
            {
                // dump queue to ans
                while(j != i)
                {
                    if(idx[str[j]-'0'].empty()) 
                    {
                        j++; continue;
                    }
                    assert(idx[str[j]-'0'].front() == j);
                    ans.push_back(str[j]);
                    idx[str[j]-'0'].pop();
                    j++;
                }
                for(int i = 0; i < 10; i++) assert(idx[i].empty());
                // change comboParity
                comboParity = d%2;
                idx[d].push(i);
            }
            else
            {
                while(j != posToIns)
                {
                    if(idx[str[j]-'0'].empty()) 
                    {
                        j++; continue;
                    }
                    assert(idx[str[j]-'0'].front() == j);
                    ans.push_back(str[j]);
                    idx[str[j]-'0'].pop();
                    j++;
                }
                ans.push_back(str[i]);
            }
        }
    }
    while(j != str.size())
    {
        if(idx[str[j]-'0'].empty()) 
        {
            j++; continue;
        }
        assert(idx[str[j]-'0'].front() == j);
        ans.push_back(str[j]);
        idx[str[j]-'0'].pop();
        j++;
    }
    cout << ans << endl;
}

