use proconio::input;

struct Point {
    x: i32,
    y: i32
}

fn main() {
    input! {
        xa: i32,
        ya: i32,
        xb: i32,
        yb: i32,
        xc: i32,
        yc: i32,
    };
    let a = Point {x: xa, y: ya};
    let b = Point {x: xb, y: yb};
    let c = Point {x: xc, y: yc};
    let len2_arr = { let mut v = vec![len2(&a, &b), len2(&a, &c), len2(&b, &c)]; v.sort(); v};

    if len2_arr[0] + len2_arr[1] == len2_arr[2] {
        println!("Yes");
    } else {
        println!("No");
    }
}

fn len2(a: &Point, b: &Point) -> i32 {
    let dx = a.x - b.x;
    let dy = a.y - b.y;
    return dx * dx + dy * dy;
}

