use proconio::input;
use std::cmp::min;

fn main() {
    input! {
        n: usize,
        arr: [(i64, i64); n]
    };

    let mut lsum = 0;
    let mut rsum = 0;
    for (l, r) in &arr {
        lsum += l;
        rsum += r;
    }
    if lsum > 0 || rsum < 0 {
        println!("No");
        return;
    }

    let ans = {
        let mut sum = lsum;
        let mut ans: Vec<i64> = vec![0; n];
        for i in 0..n {
            let diff = min(-sum, arr[i].1 - arr[i].0);
            sum += diff;
            ans[i] = arr[i].0 + diff;
        }
        ans
    };
    println!("Yes");
    for x in &ans {
        print!("{x} ");
    }
    println!("");
}
