use proconio::input;

fn main() {
    input! {
        mut sx: i64,
        mut sy: i64,
        mut tx: i64,
        mut ty: i64,
    };
    if sx % 2 != sy % 2 {
        sx -= 1;
    }
    if tx % 2 != ty % 2 {
        tx -= 1;
    }

    tx = (tx - sx).abs();
    ty = (ty - sy).abs();
    let ans = ty + if ty < tx { (tx - ty) / 2 } else { 0 };
    println!("{ans}");
}

