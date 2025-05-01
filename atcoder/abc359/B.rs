use proconio::input;

fn main() {
    input! {
        n: usize,
        arr: [usize; n + n],
    };
    let m = n + n;
    let mut left = vec![usize::MAX; n + 1];
    let mut ans = 0;
    for i in 0..m {
        if left[arr[i]] == usize::MAX {
            left[arr[i]] = i;
        } else if i - left[arr[i]] == 2 {
            ans += 1;
        }
    }
    println!("{ans}");
}


