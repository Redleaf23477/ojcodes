use proconio::input;
const MOD: i64 = 998244353;

fn main() {
    input! {
        n: usize,
        k: usize,
        s: String,
    };
    let s: Vec<char> = s.chars().collect();

    let mut dp: Vec<Vec<i64>> = vec![vec![0; 1 << k]; n];

    // s[0]
    dp[0][0] = if s[0] == 'A' || s[0] == '?' { 1 } else { 0 };
    dp[0][1] = if s[0] == 'B' || s[0] == '?' { 1 } else { 0 };

    // s[1..k-1]
    for i in 1..k-1 {
        let max_mask = 1 << (i + 1);
        for m in 0..max_mask {
            if s[i] == 'A' && m & 1 == 0 {
                dp[i][m] += dp[i - 1][m >> 1];
            }
            if s[i] == 'B' && m & 1 == 1 {
                dp[i][m] += dp[i - 1][m >> 1];
            }
            if s[i] == '?' {
                dp[i][m] += dp[i - 1][m >> 1];
            }

            dp[i][m] %= MOD;
        }
    }

    // s[k-1..]
    for i in k-1..n {
        let max_mask = 1 << k;
        let high_bit = 1 << (k - 1);
        for m in 0..max_mask {
            if is_palin(m, k) { 
                continue; 
            }
            if s[i] == 'A' && m & 1 == 0 {
                dp[i][m] += dp[i - 1][m >> 1] + dp[i - 1][high_bit + (m >> 1)];
            }
            if s[i] == 'B' && m & 1 == 1 {
                dp[i][m] += dp[i - 1][m >> 1] + dp[i - 1][high_bit + (m >> 1)];
            }
            if s[i] == '?' {
                dp[i][m] += dp[i - 1][m >> 1] + dp[i - 1][high_bit + (m >> 1)];
            }

            dp[i][m] %= MOD;
        }
    }

    println!("{}", dp[n - 1].iter().sum::<i64>() % MOD);
}

fn is_palin(m: usize, k: usize) -> bool {
    let mut l = 0; 
    let mut r = k - 1;
    while l < r {
        let l_bit = (m >> l) & 1;
        let r_bit = (m >> r) & 1;
        if l_bit != r_bit {
            return false;
        }
        l += 1;
        r -= 1;
    }
    return true;
}
