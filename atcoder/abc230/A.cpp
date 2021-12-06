#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n; cin >> n;
    cout << "AGC" << setw(3) << setfill('0') << (n < 42? n : n+1) << endl;
}
