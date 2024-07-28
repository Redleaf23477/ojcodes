use proconio::input;
use std::cmp::min;

fn main() {
    input! {
        r: i32,
        g: i32,
        b: i32,
        c: String
    };
    let ans = match c.as_str() {
        "Red" => min(g, b),
        "Green" => min(r, b),
        "Blue" => min(r, g),
        _ => { println!("WTF"); 87}
    };
    println!("{ans}");
}
