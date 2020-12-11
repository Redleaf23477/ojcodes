// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);

using namespace std;
using LL = long long int;

void init();
void process();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int R, C;
char arr[102][102];
vector<tuple<tuple<int,int>,tuple<int,int>,tuple<int,int>>> ans;

void init() {
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) 
            cin >> arr[i][j];
    ans.clear();
}

void gather(int r, int c, int dr, int dc, vector<tuple<int,int>> &z, vector<tuple<int,int>> &o) {
    for (int i = 0; i < dr; i++) for (int j = 0; j < dc; j++) {
        int a = r+i, b = c+j;
        if (arr[a][b] == '0') z.emplace_back(a, b);
        else o.emplace_back(a, b);
        arr[a][b] = '0';
    }
}

void rev(char &ch) { ch = '0' + '1' - ch; }

void case2x2(int r, int c) {
    vector<tuple<int,int>> z, o; gather(r, c, 2, 2, z, o);
    if (z.size() == 4) return;
    else if (z.size() == 3) {
        auto a = z[0], b = z[1], c = z[2];
        auto d = o[0];
        ans.emplace_back(a, b, d);
        ans.emplace_back(b, c, d);
        ans.emplace_back(a, c, d);
    } else if (z.size() == 2) {
        auto a = z[0], b = z[1];
        auto c = o[0], d = o[1];
        ans.emplace_back(a, b, c);
        ans.emplace_back(a, b, d);
    } else if (z.size() == 1) {
        ans.emplace_back(o[0], o[1], o[2]);
    } else {
        auto a = o[0], b = o[1], c = o[2], d = o[3];
        ans.emplace_back(a, b, c);
        ans.emplace_back(a, b, d);
        ans.emplace_back(b, c, d);
        ans.emplace_back(a, c, d);
    }
}

void case2x3(int r, int c) {
    if (arr[r][c] == '0' && arr[r+1][c] == '0') {
        case2x2(r, c+1);
    } else if (arr[r][c+2] == '0' && arr[r+1][c+2] == '0') {
        case2x2(r, c);
    } else {
        vector<tuple<int,int>> buf;
        if (arr[r][c] == '1') buf.emplace_back(r, c), arr[r][c] = '0';
        if (arr[r+1][c] == '1') buf.emplace_back(r+1, c), arr[r+1][c] = '0';
        if (buf.size() != 3) buf.emplace_back(r, c+1), rev(arr[r][c+1]);
        if (buf.size() != 3) buf.emplace_back(r+1, c+1), rev(arr[r+1][c+1]);
        ans.emplace_back(buf[0], buf[1], buf[2]);
        case2x2(r, c+1);
    }
}

void case3x2(int r, int c) {
    if (arr[r][c] == '0' && arr[r][c+1] == '0') {
        case2x2(r+1, c);
    } else if (arr[r+2][c] == '0' && arr[r+2][c+1] == '0') {
        case2x2(r, c);
    } else {
        vector<tuple<int,int>> buf;
        if (arr[r][c] == '1') buf.emplace_back(r, c), arr[r][c] = '0';
        if (arr[r][c+1] == '1') buf.emplace_back(r, c+1), arr[r][c+1] = '0';
        if (buf.size() != 3) buf.emplace_back(r+1, c), rev(arr[r+1][c]);
        if (buf.size() != 3) buf.emplace_back(r+1, c+1), rev(arr[r+1][c+1]);
        ans.emplace_back(buf[0], buf[1], buf[2]);
        case2x2(r+1, c);
    }
}

void case3x3(int r, int c) {
    if (arr[r][c] == '0' && arr[r][c+1] == '0' && arr[r][c+2] == '0') {
        case2x3(r+1, c);
    } else if (arr[r][c] == '0' && arr[r+1][c] == '0' && arr[r+2][c] == '0') {
        case3x2(r, c+1);
    } else {
        // r, c
        vector<tuple<int,int>> buf;
        if (arr[r][c] == '1' || arr[r+1][c] == '1') {
            if (arr[r][c] == '1') buf.emplace_back(r, c), arr[r][c] = '0';
            if (arr[r+1][c] == '1') buf.emplace_back(r+1, c), arr[r+1][c] = '0';
            if (buf.size() != 3) buf.emplace_back(r, c+1), rev(arr[r][c+1]);
            if (buf.size() != 3) buf.emplace_back(r+1, c+1), rev(arr[r+1][c+1]);
            ans.emplace_back(buf[0], buf[1], buf[2]);
        }

        // r+1, c
        buf.clear();
        if (arr[r+1][c] == '1' || arr[r+2][c] == '1') {
            if (arr[r+1][c] == '1') buf.emplace_back(r+1, c), arr[r+1][c] = '0';
            if (arr[r+2][c] == '1') buf.emplace_back(r+2, c), arr[r+2][c] = '0';
            if (buf.size() != 3) buf.emplace_back(r+1, c+1), rev(arr[r+1][c+1]);
            if (buf.size() != 3) buf.emplace_back(r+2, c+1), rev(arr[r+2][c+1]);
            ans.emplace_back(buf[0], buf[1], buf[2]);
        }

        case3x2(r, c+1);
    }
}

void process() {
    for (int r = 0; r+1 < R; r += 2) for (int c = 0; c+1 < C; c += 2) {
        if (r+2 == R-1 && c+2 == C-1) {
            case3x3(r, c);
        } else if (r+2 == R-1) {
            case3x2(r, c);
        } else if (c+2 == C-1) {
            case2x3(r, c);
        } else {
            case2x2(r, c);
        }
    }
    cout << ans.size() << endl;
    for (auto [t1, t2, t3] : ans) {
        cout << get<0>(t1)+1 << " " << get<1>(t1)+1 << " ";
        cout << get<0>(t2)+1 << " " << get<1>(t2)+1 << " ";
        cout << get<0>(t3)+1 << " " << get<1>(t3)+1 << endl;
    }
}

