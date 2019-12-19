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

char dump(int *arr)
{
    for(int i = 0; i < 3; i++) if(arr[i] == 0) return 'a'+i;
}

void process()
{
    int n = str.size();
    for(int i = 0; i < n; i++)
    {
        int arr[3] = {0};
        if(i-1 >= 0 && str[i-1] != '?') arr[str[i-1]-'a'] = 1;
        if(i+1 < n && str[i+1] != '?') arr[str[i+1]-'a'] = 1;
        if(str[i] == '?') str[i] = dump(arr);
    }
    bool good = true;
    for(int i = 1; i < n; i++)
        if(str[i] == str[i-1]) good = false;
    if(good) cout << str << endl;
    else cout << -1 << endl;
}

