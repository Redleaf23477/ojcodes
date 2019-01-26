//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 300005;
int n;
char arr[N];
int cnt[3];

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
        cin >> arr[i];
        cnt[arr[i]-'0']++;
    }
    for(int i = 0; i < 3; i++)
    {
        cnt[i] = cnt[i]-n/3;
    }
}

void process()
{
    // mask 0
    for(int i = n-1, c = 0; i >= 0 && c < cnt[0]; i--)
    {
        if(arr[i] == '0') arr[i] = 'x', c++;
    }
    // mask 1
    if(cnt[1] > 0)
    {
        if(cnt[0] < 0 && cnt[2] < 0)
        {
            for(int i = 0, c = 0; i < n && c < -cnt[0]; i++)
                if(arr[i] == '1') arr[i] = 'x', c++;
            for(int i = n-1, c = 0; i >= 0 && c < -cnt[2]; i--)
                if(arr[i] == '1') arr[i] = 'x', c++;
        }
        else if(cnt[0] < 0)
        {
            for(int i = 0, c = 0; i < n && c < cnt[1]; i++)
                if(arr[i] == '1') arr[i] = 'x', c++;
        }
        else if(cnt[2] < 0)
        {
            for(int i = n-1, c = 0; i >= 0 && c < cnt[1]; i--)
                if(arr[i] == '1') arr[i] = 'x', c++;
        }
    }
    // mask 2
    for(int i = 0, c = 0; i < n && c < cnt[2]; i++)
    {
        if(arr[i] == '2') arr[i] = 'x', c++;
    }
    // put
    int i = 0;
    for(int j = 0; j < 3; j++)
    {
        while(cnt[j] < 0)
        {
            if(arr[i] == 'x') arr[i] = '0'+j, cnt[j]++;
            i++;
        }
    }
    for(int i = 0; i < n; i++)
        cout << arr[i];
    cout << endl;
}

