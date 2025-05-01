use std::io;
use std::collections::BTreeMap;

fn main() {
    let mut lines = io::stdin().lines();
    let t: usize = lines.next()
        .expect("no such line")  // unwrap Option<T>
        .expect("stdin error")   // unwrap Result<T, E>
        .parse()
        .expect("parst t failure");
    for _ in 0..t {
        let n: usize = lines.next()
            .expect("no such line")  // unwrap Option<T>
            .expect("stdin error")   // unwrap Result<T, E>
            .parse()
            .expect("parst n failure");
        let arr: Vec<usize> = lines.next()
            .expect("no such line")
            .expect("stdin error")
            .split_whitespace()
            .map(|x| x.parse().expect("parst a_i failure"))
            .collect();
        solve(n, arr);
    }
}

fn solve(_n: usize, arr: Vec<usize>) {
    let mut elem_cnt = BTreeMap::new();
    for x in arr {
        elem_cnt.entry(x)
            .and_modify(|val| *val += 1)
            .or_insert(1);
    }
    let ans = elem_cnt.values()
        .fold(0, |ans, cnt| ans + cnt / 2);
    println!("{ans}");
}
