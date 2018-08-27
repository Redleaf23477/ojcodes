// best cow line
// greedy
#include <cstdio>

using namespace std;
typedef long long int ll;

const int N = 2020;

int n; 
char arr[N], ans[N];

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
        char str[10]; scanf("%s", str);
        arr[i] = str[0];
    }
}

bool cmp(int l, int r) // true -> left, false -> right
{
    while(l < r)
    {
        if(arr[l] == arr[r]) l++, r--;
        else if(arr[l] < arr[r]) return true;
        else return false;
    }
    return true;
}

void process()
{
    int l = 0, r = n-1;
    for(int i = 0; i < n; i++)
    {
        if(cmp(l, r)) ans[i] = arr[l++];
        else ans[i] = arr[r--];
    }
    for(int i = 0; i < n; )
    {
        for(int j = 0; i < n && j < 80; i++, j++)
            printf("%c", ans[i]);
        printf("\n");
    }
}

