//pE
//TLE
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
#define r first
#define c second

const int N = 5050;
const int BLK = 1;
const int PASS = 2;
int R, C, q;
int arr[N][N];

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
   cin >> R >> C >> q;
   R *= 2, C *= 2;
   for(int r = 1; r <= R; r++) for(int c = 1; c <= C; c++) arr[r][c] = 0;
}

void print()
{
   for(int r = 1; r <= R; r++)
   {
      for(int c = 1; c <= C; c++) cout << arr[r][c];
      cout << endl;
   }
}

void block(int r1, int c1, int r2, int c2)
{
   if(r1 > r2) r1^=r2^=r1^=r2;
   if(c1 > c2) c1^=c2^=c1^=c2;
   r1 = 2*r1-1, c1 = 2*c1-1, r2 = 2*r2+1, c2 = 2*c2+1;
   for(int r = r1; r <= r2; r++) arr[r][c1] = arr[r][c2] = BLK;
   for(int c = c1; c <= c2; c++) arr[r1][c] = arr[r2][c] = BLK;
//   print();
}

void rm(int r1, int c1, int r2, int c2)
{
   if(r1 > r2) r1^=r2^=r1^=r2;
   if(c1 > c2) c1^=c2^=c1^=c2;
   r1 = 2*r1-1, c1 = 2*c1-1, r2 = 2*r2+1, c2 = 2*c2+1;
   for(int r = r1; r <= r2; r++) arr[r][c1] = arr[r][c2] = 0;
   for(int c = c1; c <= c2; c++) arr[r1][c] = arr[r2][c] = 0;
//   print();
}

bool legal(int r, int c)
{
   if(1 <= r && r <= R && 1 <= c && c <= C) return true;
   return false;
}

void bfs(int sr, int sc, int fr, int fc)
{
   sr *= 2, sc *= 2, fr *= 2, fc *= 2;
   if(!legal(sr, sc) || !legal(fr, fc))
   {
      cout << "No" << endl;
      return;
   }
   queue<P> que;
   stack<P> went;
   if(arr[sr][sc] != BLK) que.push(P(sr, sc));
   int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
   bool found = false;
   while(!que.empty() && !found)
   {
      P tp = que.front(); que.pop();
      for(int i = 0; i < 4; i++)
      {
         int rr = tp.r+dr[i], cc = tp.c+dc[i];
         if(legal(rr, cc) && arr[rr][cc] != BLK)
         {
            if(rr == fr && cc == fc)
            {
               found = true;
               break;
            }
            if(arr[rr][cc] == 0) 
            {
               arr[rr][cc] = PASS;
               went.push(P(rr, cc));
               que.push(P(rr, cc));
            }
         }
      }
   }
   if(!found) cout << "No" << endl;
   else cout << "Yes" << endl;
   while(!went.empty()) 
   {
      arr[went.top().r][went.top().c] = 0;
      went.pop();
   }
}

void process()
{
   int cmd, r1, c1, r2, c2;
   while(q--)
   {
      cin >> cmd >> r1 >> c1 >> r2 >> c2;
      if(cmd == 1) block(r1, c1, r2, c2);
      else if(cmd == 2) rm(r1, c1, r2, c2);
      else bfs(r1, c1, r2, c2);
   }
}
