use std::io;
use std::io::Write;

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).expect("stdin error");   // unwrap Result<T, E>
    let t = s.trim().parse().expect("parst t failure");
    for _ in 0..t {
        let mut s = String::new();
        io::stdin().read_line(&mut s).expect("stdin error");   // unwrap Result<T, E>
        let n = s.trim().parse().expect("parst n failure");
        solve(n);
    }
}

fn solve(n: usize) {
    let mut ans = vec!['x'; n];
    let mut acc = query(0, n - 1);
    if acc == 0 {
        report_no_ans();
        return;
    }
    for i in 0..n - 1 {
        let sub = query(i + 1, n - 1);
        if sub < acc {
            ans[i] = '0';
        } else {
            ans[i] = '1';
        }
        if sub == 0 {
            // 1   ....1  0    ....0
            // i+1 .....  i+acc
            ans[i + 1..i + 1 + acc].fill('1');
            ans[i + 1 + acc..].fill('0');
            break;
        }
        acc = sub;
    }
    report_ans(ans);
}

fn query(l: usize, r: usize) -> usize {
    if l == r {
        return 0;
    }

    println!("? {} {}", l + 1, r + 1);
    io::stdout().flush().expect("stdout flush error");

    let mut s = String::new();
    io::stdin().read_line(&mut s)
        .expect("stdin error");  // unwrap Result<T, E>
    let x: usize = s.trim().parse().expect("parse error");
    return x;
}

fn report_no_ans() {
    println!("! IMPOSSIBLE");
}

fn report_ans(ans: Vec<char>) {
    print!("! ");
    for x in ans {
        print!("{x}");
    }
    println!("");
}

