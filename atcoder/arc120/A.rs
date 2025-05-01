// use std::io;
use proconio::input;

fn main() {
    let mut lines = io::stdin().lines();
    let n : usize = lines.next()
        .expect("no such line")
        .expect("stdin error")
        .parse().expect("parse int failure");
    let arr: Vec<i64> = lines.next()
        .expect("no such line")
        .expect("stdin error")
        .split_whitespace()
        .map(|x| x.parse().expect("parse int failure"))
        .collect();
    solve(n, arr);
}

fn solve(n: usize, arr: Vec<i64>) {
    let mut acc: i64 = 0;
    let mut sum: i64 = 0;
    let mut pref_mx: i64 = 0;
    for i in 0..n {
        acc += arr[i];
        sum += acc;
        pref_mx = pref_mx.max(arr[i]);
        let ans = sum + ((i + 1) as i64) * pref_mx;
        println!("{ans}");
    }
}
