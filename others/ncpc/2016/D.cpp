// stable marriage -> school to student
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 100005;
const int M = 1003;

int studentNum, schoolNum;
vector<int> school[M];
map<int, int> student[N];
int accept[N];
int quota[M];

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
    cin >> studentNum >> schoolNum;
    for(int i = 0; i < studentNum; i++)
    {
        accept[i] = -1;
        student[i].clear();
        student[i][-1] = N;
        for(int rk = 0, s; ; rk++)
        {
            cin >> s; 
            if(s == 0) break;
            student[i][s-1] = rk;
        }
    }
    for(int i = 0, s; i < schoolNum; i++)
    {
        school[i].clear();
        cin >> quota[i];
        while(cin >> s && s) school[i].push_back(s-1);
        reverse(school[i].begin(), school[i].end());
    }
}

void process()
{
    while(true)
    {
        bool update = false;
        for(int sch = 0; sch < schoolNum; sch++)
        {
            if(quota[sch] == 0 || school[sch].empty()) continue;
            int wantStudent = school[sch].back();
            if(student[wantStudent].count(sch) != 0)
            {
                if(student[wantStudent][sch] < student[wantStudent][accept[wantStudent]])
                {
                    update = true;
                    if(accept[wantStudent] >= 0) quota[accept[wantStudent]]++;
                    accept[wantStudent] = sch;
                    quota[sch]--;
                }
            }
            school[sch].pop_back();
            update = true;
        }
        if(!update) break;
    }
    int hasSchool = 0, leftQuota = 0;
    for(int i = 0; i < studentNum; i++)
        hasSchool += (accept[i] != -1);
    for(int i = 0; i < schoolNum; i++)
        leftQuota += quota[i];
    cout << hasSchool << " " << leftQuota << endl;
}

