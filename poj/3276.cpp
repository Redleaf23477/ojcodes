//
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long int ll;

const int N = 5050;

int n;
int arr[N];

void init();
void process();

int main()
{
    init();
    process();
    return 0;
}

void init()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        char ch;
        scanf(" %c", &ch);
        arr[i+1] = (ch == 'F');
    }
}

void process()
{
    int mnk = N, mn = N;
    for(int k = 1; k <= n; k++)
    {
        bool ok = true;
        int flip[N] = {0};
        for(int i = 1; i+k-1 <= n; i++)
        {
            int flipped = (flip[i-1]-flip[max(0, i-k)])%2;
            int face = arr[i] ^ flipped;
            flip[i] = flip[i-1]+1-face;
        }
        for(int i = n-k+2; i <= n; i++)
        {
            int flipped = (flip[i-1]-flip[max(0, i-k)])%2;
            int face = arr[i] ^ flipped;
            flip[i] = flip[i-1];
            ok &= face;
        }
        if(ok && flip[n] < mn) mn = flip[n], mnk = k;
    }
    printf("%d %d\n", mnk, mn);
}

