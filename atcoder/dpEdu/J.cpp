//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const int N = 303;
int n, cnt[5];
double prob[N][N][N];
double exp[N][N][N];

/* Probability :
 *
 * prob[#1][#2][#3] = probability when there are #1 dishes with one sushi, #2 with two, #3 with three
 * prob[cnt1][cnt2][cnt3] = 1, starting from this state
 * prob[0][0][0] = 1, eventually finish at this state
 *
 * transfering to another state :
 * p(pick dish with one sushi) = p(pick one | pick 0 times zero) + p(pick one | pick 1 time zero) + ...
 *     = #1/(#1+#2+#3) ... need proof
 */

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
        int x; cin >> x;
        cnt[x]++;
    }
}

void process()
{
    prob[cnt[1]][cnt[2]][cnt[3]] = 1;
    exp[cnt[1]][cnt[2]][cnt[3]] = 0;
    for(int c = n; c >= 0; c--)
    {
        for(int b = n; b >= 0; b--)
        {
            for(int a = n; a >= 0; a--)
            {
                exp[a][b][c] += (double)(n-a-b-c)/n;
                if(a > 0) 
                {
                    prob[a-1][b][c] += prob[a][b][c] * a / (a+b+c);
                }
                if(b > 0) 
                {
                    prob[a+1][b-1][c] += prob[a][b][c] * b / (a+b+c);
                }
                if(c > 0) 
                {
                    prob[a][b+1][c-1] += prob[a][b][c] * c / (a+b+c);
                }
            }
        }
    }
    cout << exp[0][0][0]+cnt[1]+cnt[2]+cnt[3] << endl;
}

