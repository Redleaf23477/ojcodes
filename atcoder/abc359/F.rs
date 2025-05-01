use proconio::input;
use std::cmp::Ordering;
use std::collections::BinaryHeap;

#[derive(Eq, PartialEq)]
struct SubTree {
    idx: usize,
    deg: i64,
    cost: i64,
}

impl Ord for SubTree {
    fn cmp(&self, other: &Self) -> Ordering {
        if self.cost != other.cost {
            other.cost.cmp(&self.cost)
        } else {
            other.idx.cmp(&self.idx)
        }
    }
}

impl PartialOrd for SubTree {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

fn main() {
    input!{
        n: usize,
        a: [i64; n],
    };
    let mut heap: BinaryHeap<SubTree> = BinaryHeap::new();
    for i in 0..n {
        heap.push(SubTree {idx: i, deg: 1, cost: 3 * a[i]});
    }

    let remain_deg = 2 * (n - 1) - n;  // n - 2
    let mut total_cost: i64 = a.iter().sum();
    for _ in 0..remain_deg {
        let small = heap.pop().unwrap();

        total_cost += small.cost;

        heap.push(SubTree {
            idx: small.idx,
            deg: small.deg + 1,
            cost: a[small.idx] * (sq(small.deg + 2) - sq(small.deg + 1)),
        });

        //eprintln!("ITER: give {}, cost += {} = {total_cost}", small.idx, small.cost);
    }

    println!("{total_cost}");
}

fn sq(x: i64) -> i64 { x * x }
