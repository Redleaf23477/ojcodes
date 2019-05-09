//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const long double EPS = 1e-7;
const long double PI = acos(-1);

double area;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, caseN = 0; cin >> T;
    while(T--)
    {
        cout << "Case #" << ++caseN << ":" << endl;
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> area;
}

void mul(long double res[3][3], const long double a[3][3], const long double b[3][3])
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                res[i][j] += a[i][k] * b[k][j];
}

void report(long double theta, long double phi)
{
    long double rot_th[3][3] = {
        {1.0, 0.0, 0.0},
        {0.0, cos(theta), -sin(theta)},
        {0.0, sin(theta), cos(theta)}
    };
    long double rot_ph[3][3] = {
        {cos(phi), -sin(phi), 0.0},
        {sin(phi), cos(phi), 0.0},
        {0.0, 0.0, 1.0}
    };
    long double pts[3][3] = {
        {0.5, 0.0, 0.0},
        {0.0, 0.5, 0.0},
        {0.0, 0.0, 0.5}
    };
    long double rot[3][3] = {0};
    long double res[3][3] = {0};

    mul(rot, rot_th, rot_ph);
    mul(res, rot, pts);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            cout << fixed << setprecision(8) << (double)res[j][i] << " \n"[j==2];
    }
}

void process()
{
    // area = cos(theta-phi) + sin(theta+phi)
    long double theta = (area >= sqrt(2)+EPS? PI/4 : 0);
    long double low = 0, high = PI/4, phi;
    // bs for 30 times
    for(int i = 0; i < 30; i++)
    {
        phi = (high+low)/2;
        long double tmp = (sin(theta+phi) + cos(theta-phi));
//        cout << ".." << fixed << setprecision(8) << tmp << endl;
        if(tmp > area) high = phi-EPS;
        else low = phi+EPS;
    }
    report(theta, phi);
}

