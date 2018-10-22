//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 110;
int n;
int arr[N];

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
    for(int i = 0; i < n; i++) cin >> arr[i];
}

void process()
{
    map<int, int> mp;
    for(int i = 0; i < n; i++)
    {
        if(mp.count(arr[i]) == 0) mp[arr[i]] = 0;
        mp[arr[i]]++;
    }
    int one = 0, moreThan2 = 0;
    for(auto x:mp)
    {
        if(x.second == 1) one++;
        else if(x.second > 2) moreThan2++;
    }
    if(one%2 == 0)
    {
        cout << "YES" << endl;
        for(int i = 0, flag = 0; i < n; i++)
        {
            if(mp[arr[i]] > 1) cout << "A";
            else if(flag) cout << "A", flag = 1-flag;
            else cout << "B", flag = 1-flag;
        }
        cout << endl;
    }
    else if(moreThan2 >= 1)
    {
        cout << "YES" << endl;
        int first = -1, flgFirst = -1;
        for(int i = 0, flag = 0; i < n; i++)
        {
            if(mp[arr[i]] > 2)
            {
                if(first == -1)
                {
                    first = arr[i];
                    flgFirst = flag;
                    if(flag) cout << "A", flag = 1-flag;
                    else cout << "B", flag = 1-flag;
                }
                else if(first == arr[i])
                {
                    int tmpflg = 1-flgFirst;
                    if(tmpflg) cout << "A";
                    else cout << "B";
                }
                else cout << "A";
            }
            else if(mp[arr[i]] == 2) cout << "A";
            else
            {
                if(flag) cout << "A", flag = 1-flag;
                else cout << "B", flag = 1-flag;
            }
        }
        cout << endl;
    }
    else cout << "NO" << endl;
}

