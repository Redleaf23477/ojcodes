#include <iostream>
#include <string>
using namespace std;

bool good(string &str, int idx) {
    string pat = "oxx";
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] != pat[(idx + i)%3]) return false;
    }
    return true;
}

int main() {
    string str; cin >> str;
    if (good(str, 0) || good(str, 1) || good(str, 2)) cout << "Yes" << endl;
    else cout << "No" << endl;
}