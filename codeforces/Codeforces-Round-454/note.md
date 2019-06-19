# Codeforces Round #454 (Div. 2, based on Technocup 2018 Elimination Round 4)
- [Standing:266](http://codeforces.com/contest/907/standings/page/2)
- Solved:3
- 我升級**藍人**了
## [A. Masha and Bears](http://codeforces.com/contest/907/problem/A)
implementation, brute force: 測資夠小，暴力會AC
## [B. Tic-Tac-Toe](http://codeforces.com/contest/907/problem/b)
implementation: 照做就AC
## [C. Shockers](http://codeforces.com/contest/907/problem/c)
implementation: 從26個字母中篩出題目要的字母，用bitwise存每個字母可不可能是題目所求會比用陣列還要優
------------
賽後ac：
## [D. Seating of Students](http://codeforces.com/contest/907/problem/D)
重新排一個n\*m的陣列，滿足原本相鄰的數字不相鄰。分(n,m)的case討論：
- case (1, 1): 顯然解
- case (1, 2 or 3),(2 or 3, 1)：顯然沒解
- case (1, m >= 4),(n >= 4, 1)：先排偶數再排奇數（顛倒的話在奇偶交界處會出事）
- case (2, 2 or 3),(2 or 3, 2)：沒解
- case (3, 3)：有解
- case 剩下的(n > m)：奇數column下移兩格，偶數row右移一格
- case 剩下的(m > n)：基數row右移兩格，偶數column下移一格
