# F - XOR Matching

from atcoder - [abc126-F](https://atcoder.jp/contests/abc126/tasks/abc126_f)

## Observe

For xor sum from **0** to **2^m** where **m > 1**, the result must be **0**.

e.g. xor sum from **0** to **3**

| number | bit1 | bit0 |
| ------ | ---- | ---- |
| 0      | 0    | 0    |
| 1      | 0    | 1    |
| 2      | 1    | 0    |
| 3      | 1    | 1    |

Consider bit **i** of every number, there must be exactly **2^(m-1) 1s**.  And since **2^(m-1)** must be even when **m > 1**, the xor sum must be **0**.  Therefore the xor sum for all numbers from **0** to **2^(m-1)** is always **0**.

## Solution

Break the problem into cases:

- **M = K = 0** : Obviously, "0 0" is a solution.
- **K <= 2^(M-1)** and **M > 1** : There exist a solution in this form : "0 1 ... 2^(M-1) K 2^(M-1) ... 0 K", where "0 1 ... 2^(M-1)" is a sequence without **K**, and "2^(M-1) ... 1 0" is its reverse sequence.
- **K = 1** and **M = 1** : no solution