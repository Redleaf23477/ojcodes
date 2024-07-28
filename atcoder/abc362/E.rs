use proconio::input;
use std::collections::BTreeMap;

const MOD: i64 = 998244353;

fn main() {
    input! {
        n: usize,
        arr: [i64; n],
    };

    let mut ans: Vec<i64> = vec![0; n];

    // case where d = 0
    let mut choose = vec![vec![1; n + 1]; n + 1];
    for i in 2..n + 1 {
        for j in 1..i {
            choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % MOD;
        }
    }

    let mut map = BTreeMap::new();
    for elem in &arr {
        let count = map.entry(elem).or_insert(0 as usize);
        *count += 1;
    }
    for (_elem, cnt) in &map {
        for c in 0..*cnt as usize {
            ans[c] = (ans[c] + choose[*cnt][c + 1]) % MOD;
        }
    }

    // case where d != 0
    for i in 0..n {
        for j in i + 1..n {
            let mut dp: Vec<i64> = vec![0; n];
            let a0 = arr[i];
            let d = arr[j] - arr[i];

            if d == 0 { continue; }

            dp[1] = 1;

            for k in j + 1..n {
                let diff = arr[k] - a0;
                if diff % d == 0 {
                    let len = (diff / d) as usize;
                    if len > 1 && len < n {
                        dp[len] = (dp[len] + dp[len - 1]) % MOD;
                    }
                }
            }

            for i in 0..n {
                ans[i] = (ans[i] + dp[i]) % MOD;
            }
        }
    }

    for x in ans {
        print!("{x} ");
    }
    println!("");
}
