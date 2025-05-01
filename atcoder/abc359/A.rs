use proconio::input;

fn main() {
    input! {
        n: usize,
        s: [String; n],
    };
    let ans = s.iter().filter(|x| *x == "Takahashi").count();
    println!("{ans}");
}

#[allow(dead_code)]
fn old(n: usize, s: Vec<String>) {
    let takahashi = "Takahashi";
    let mut cnt = 0;
    for name in &s {
        if name == takahashi {
            cnt += 1;
        }
    }
    println!("{cnt}");
}
