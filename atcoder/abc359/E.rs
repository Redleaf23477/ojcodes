use proconio::input;

fn main() {
    input! {
        n: usize,
        h: [i64; n],
    };
    let h = { let mut v = vec![i64::MAX; 1]; v.extend(h); v};
    let mut ans = vec![0; n];
    let mut stk = Vec::<usize>::new();
    let mut stk_sum = Vec::<i64>::new();

    stk.push(0);
    stk_sum.push(0);

    for i in 1..n + 1 {
        while let Some(&tp) = stk.last() {
            if h[tp] <= h[i] {
                stk.pop();
                stk_sum.pop();
            } else {
                break;
            }
        }
        let tp = stk.last().unwrap();
        stk_sum.push(stk_sum.last().unwrap() + (i - tp) as i64 * h[i]);
        stk.push(i);
        ans[i - 1] = stk_sum.last().unwrap() + 1;
    }

    for i in 0..n {
        print!("{} ", ans[i]);
    }
    println!("");
}
