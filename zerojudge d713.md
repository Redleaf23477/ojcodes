# [zerojudge d713 中位数](https://zerojudge.tw/ShowProblem?problemid=d713)
動態求中位數
## 作法
維護兩個優先佇列，一個有小到大，另外一個由大到小。讓這兩個PQ的大小相同(或差1)，把中位數夾在兩個PQ的top。
```c++
int main()
{
    priority_queue<ll, vector<ll>, greater<ll>> gpq;
    priority_queue<ll, vector<ll>, less<ll>> lpq;
    // less mid greater
    ll x;
    while(cin >> x)
    {
        if(lpq.empty() || x > lpq.top()) gpq.push(x);
        else lpq.push(x);
        if(gpq.size() > lpq.size()) lpq.push(gpq.top()), gpq.pop();
        if(lpq.size() > gpq.size()) gpq.push(lpq.top()), lpq.pop();
        if(gpq.size() == lpq.size()) cout << (gpq.top()+lpq.top())/2 << endl;
        else if(gpq.size() > lpq.size()) cout << gpq.top() << endl;
        else cout << lpq.top() << endl;
    }
}
```


> Written with [StackEdit](https://stackedit.io/).
> <priority_queue>
