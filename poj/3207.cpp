#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000, M = 500;

int remove_dominated(pair<int,int> arr[], int n) {
    sort(arr, arr+n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (m == 0 || arr[i].second > arr[m-1].second) {
            arr[m] = arr[i], m++;
        }
    }
    return m;
}

int main() {
    pair<int,int> arr[N];
    int line[N];
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &arr[i].first, &arr[i].second);
        if (arr[i].first > arr[i].second) swap(arr[i].first, arr[i].second);
    }
    m = remove_dominated(arr, m);
    memset(line, 0, sizeof(line));
    for (int i = 0; i < m; i++) {
        line[arr[i].first] += 1;
        line[arr[i].second+1] -= 1;
    }
    for (int i = 1; i < n; i++) {
        line[i] += line[i-1];
    }
    bool ans = true;
    for (int i = 1; i < n; i++) {
        if (line[i] > 2) ans = false;
    }
    if (ans) printf("panda is telling the truth...\n");
    else printf("the evil panda is lying again\n");
}

