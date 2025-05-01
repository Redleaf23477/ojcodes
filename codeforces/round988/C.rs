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
        solve(n);
    }
}

fn solve(n: usize) {
    if n < 5 {
        println!("-1");
    } else {
        // odd ... 5 4 ... even
        for i in (1..=n).step_by(2) {
            if i != 5 {
                print!("{i} ");
            }
        }
        print!("5 4");
        for i in (2..=n).step_by(2) {
            if i != 4 {
                print!(" {i}");
            }
        }
        println!("");
    }
}
