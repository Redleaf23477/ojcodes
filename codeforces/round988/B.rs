use std::io;

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

fn solve(n: usize, mut arr: Vec<usize>) {
    let m = n - 2;
    arr.sort();
    for i in 1..n {
        if m % arr[i] == 0 && arr[..i].binary_search(&(m / arr[i])).is_ok() {
            println!("{} {}", arr[i], m / arr[i]);
            break;
        }
    }
}
