use std::io;

fn main() {
    let mut lines = io::stdin().lines();
    let (r_size, c_size) = {
        let data: Vec<usize> = lines
            .next()
            .expect("no such line")
            .expect("stdin error")
            .split_whitespace()
            .map(|x| x.parse().expect("parse int failure"))
            .collect();
        (data[0], data[1])
    };
    let arr: Vec<Vec<char>> = lines
        .map(|x| x.expect("stdin error").chars().collect())
        .collect();
    solve(r_size, c_size, arr);
}

fn solve(r_size: usize, c_size: usize, arr: Vec<Vec<char>>) {
    const MOD: i64 = 998244353;
    let mut ans: i64 = 1;
    // from upper-left
    for r in 0..r_size {
        let mut has_red = false;
        let mut has_blue = false;
        for c in 0..=r {
            if c >= c_size { break; }
            // eprint!("arr[{}][{}]({})", r - c, c, arr[r - c][c]);
            if arr[r - c][c] == 'R' {
                has_red = true;
            }
            if arr[r - c][c] == 'B' {
                has_blue = true;
            }
        }
        // eprintln!("");
        if has_red && has_blue {
            ans = 0;
        } else if !has_red && !has_blue {
            ans = ans * 2 % MOD;
        }
    }
    // from lower-right
    for c in 0..c_size - 1 {
        let mut has_red = false;
        let mut has_blue = false;
        for r in 0..=c {
            if r_size < 1 + r { break; }
            // eprint!("arr[{}][{}]({})", r_size - 1 - r, c_size - 1 - c + r, arr[r_size - 1 - r][c_size - 1 - c + r]);
            if arr[r_size - 1 - r][c_size - 1 - c + r] == 'R' {
                has_red = true;
            }
            if arr[r_size - 1 - r][c_size - 1 - c + r] == 'B' {
                has_blue = true;
            }
        }
        // eprintln!("");
        if has_red && has_blue {
            ans = 0;
        } else if !has_red && !has_blue {
            ans = ans * 2 % MOD;
        }
    }
    println!("{ans}");
}
