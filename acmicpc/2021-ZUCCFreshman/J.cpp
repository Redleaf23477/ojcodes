#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

string get_name(int r) {
    if (r < 1200) return "Newbie";
    else if (r < 1400) return "Pupil";
    else if (r < 1600) return "Specialist";
    else if (r < 1900) return "Expert";
    else if (r < 2100) return "Candidate master";
    else if (r < 2300) return "Master";
    else if (r < 2400) return "International master";
    else if (r < 2600) return "Grandmaster";
    else if (r < 3000) return "International grandmaster";
    else return "Legendary grandmaster";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n, rating; cin >> n >> rating;
        string name = get_name(rating);
        for (int i = 0; i < n; i++) {
            int d; cin >> d;
            rating += d;
            string new_name = get_name(rating);
            if (name != new_name) {
                cout << name << " -> " << new_name << "\n";
                name = new_name;
            }
        }
        cout << name << "\n";
    }
}

