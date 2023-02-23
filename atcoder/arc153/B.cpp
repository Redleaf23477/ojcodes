#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

mt19937_64 myrand;

struct Treap {
    struct Node {
        int data;
        LL pri;
        int size;
        bool rev;
        Node *lchild, *rchild;
        Node(int _data): data(_data), pri(myrand()), size(1), rev(false), lchild(nullptr), rchild(nullptr) {}
        ~Node() {
            if (lchild) delete lchild;
            if (rchild) delete rchild;
        }
    };
    using NodePtr = Node*;
    int get_size(NodePtr T) {
        return T? T->size : 0;
    }
    void update_size(NodePtr T) {
        if (T) {
            T->size = 1 + get_size(T->lchild) + get_size(T->rchild);
        }
    }
    void push(NodePtr T) {
        if (T->rev) {
            if (T->lchild) T->lchild->rev ^= true;
            if (T->rchild) T->rchild->rev ^= true;
            swap(T->lchild, T->rchild);
            T->rev = false;
        }
    }
    // Function
    NodePtr merge(NodePtr L, NodePtr R) {
        if (!L) {
            update_size(R);
            return R;
        } else if (!R) {
            update_size(L);
            return L;
        } else if (L->pri < R->pri) {
            push(L), push(R);
            L->rchild = merge(L->rchild, R);
            update_size(R), update_size(L);
            return L;
        } else {
            push(L), push(R);
            R->lchild = merge(L, R->lchild);
            update_size(L), update_size(R);
            return R;
        }
    }
    void split(NodePtr T, NodePtr &L, NodePtr &R, int k) {
        if (!T) {
            L = R = nullptr;
        } else {
            push(T);
            if (k <= get_size(T->lchild)) {
                R = T;
                split(T->lchild, L, R->lchild, k);
                update_size(T);
            } else {
                L = T;
                split(T->rchild, L->rchild, R, k - 1 - get_size(T->lchild));
                update_size(T);
            }
        }
    }
    // Interface
    NodePtr root;
    Treap(int n): root(nullptr) {
        // merge from 0 ... n-1
        for (int i = 0; i < n; i++) {
            root = merge(root, new Node(i));
        }
    }
    ~Treap() {
        if (root) delete root;
    }
    vector<int> inorder() {
        vector<int> ans;
        function<void(NodePtr)> dfs = [&](NodePtr t) {
            if (!t) return;
            push(t);
            dfs(t->lchild);
            ans.emplace_back(t->data);
            dfs(t->rchild);
        };
        dfs(root);
        return ans;
    }
    void reverse(int L, int R) {
        NodePtr tmp = nullptr;
        NodePtr a = nullptr, b = nullptr, c = nullptr;
        split(root, a, tmp, L);
        split(tmp, b, c, R - L + 1);
        b->rev ^= true;
        root = merge(a, merge(b, c));
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int R, C; cin >> R >> C;
    vector<string> A(R);
    for (auto &row : A) cin >> row;
    int Q; cin >> Q;
    vector<pair<int,int>> query(Q);
    for (auto &[a, b] : query) cin >> a >> b;

    Treap row(R), col(C);
    for (auto [a, b] : query) {
        row.reverse(0, a-1);
        row.reverse(a, R-1);
        col.reverse(0, b-1);
        col.reverse(b, C-1);
    }

    vector<int> ans_row = row.inorder();
    vector<int> ans_col = col.inorder();
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cout << A[ans_row[r]][ans_col[c]];
        }
        cout << "\n";
    }
}

