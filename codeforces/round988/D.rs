use std::io;
use std::collections::{BTreeMap, BinaryHeap};

enum Event {
    Coin(usize),
    Hurdle(usize),
}

fn main() {
    let mut lines = io::stdin().lines();
    let t: usize = lines.next()
        .expect("no such line")  // unwrap Option<T>
        .expect("stdin error")   // unwrap Result<T, E>
        .parse()
        .expect("parst t failure");
    for _ in 0..t {
        let (n, m, len) = {
            let line: String = lines.next()
                .expect("no such line")  // unwrap Option<T>
                .expect("stdin error");  // unwrap Result<T, E>
            let mut split_ws = line.split_whitespace();
            let n: usize = split_ws.next().expect("no such token").parse().expect("parse fail");
            let m: usize = split_ws.next().expect("no such token").parse().expect("parse fail");
            let len: usize = split_ws.next().expect("no such token").parse().expect("parse fail");
            (n, m, len)
        };
        let mut path = BTreeMap::new();
        for _ in 0..n {
            let line: String = lines.next()
                .expect("no such line")  // unwrap Option<T>
                .expect("stdin error");  // unwrap Result<T, E>
            let mut split_ws = line.split_whitespace();
            let l: usize = split_ws.next().expect("no such token").parse().expect("parse fail");
            let r: usize = split_ws.next().expect("no such token").parse().expect("parse fail");
            path.entry(l).or_insert(Vec::<Event>::new()).push(Event::Hurdle(r - l + 2));
        }
        for _ in 0..m {
            let line: String = lines.next()
                .expect("no such line")  // unwrap Option<T>
                .expect("stdin error");  // unwrap Result<T, E>
            let mut split_ws = line.split_whitespace();
            let x: usize = split_ws.next().expect("no such token").parse().expect("parse fail");
            let v: usize = split_ws.next().expect("no such token").parse().expect("parse fail");
            path.entry(x).or_insert(Vec::<Event>::new()).push(Event::Coin(v));
        }
        solve(path, len);
    }
}

fn solve(path: BTreeMap<usize, Vec<Event>>, _len: usize) {
    let mut ans: usize = 0;
    let mut jmp: usize = 1;
    let mut max_heap = BinaryHeap::new();
    for (_x, events) in path {
        for e in events {
            match e {
                Event::Coin(v) => max_heap.push(v),
                Event::Hurdle(h_len) => {
                    if jmp >= h_len {
                        continue;
                    }
                    while let Some(power) = max_heap.pop() {
                        jmp += power;
                        ans += 1;
                        if jmp >= h_len {
                            break;
                        }
                    }
                    if jmp < h_len {
                        println!("-1");
                        return;
                    }
                },
            }
        }
    }
    println!("{ans}");
}

