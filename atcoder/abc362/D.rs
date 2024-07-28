use proconio::input;
use std::collections::BinaryHeap;
use std::cmp::Ordering;

#[derive(Debug, Clone)]
struct Edge {
    v: usize,
    w: i64,
}

#[derive(Eq, PartialEq)]
struct SsspState {
    v: usize,
    len: i64,
}

impl Ord for SsspState {
    fn cmp(&self, other: &Self) -> Ordering {
        if self.len != other.len {
            return other.len.cmp(&self.len);
        } else {
            return other.len.cmp(&self.len);
        }
    }
}

impl PartialOrd for SsspState {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

fn main() {
    let (n, graph) = run_prob_input();
    // dbg!(&graph);

    let sssp = run_sssp(graph);
    for i in 1 .. n {
        print!("{} ", sssp[i + n]);
    }
    println!("");

}

fn run_sssp(graph: Vec<Vec<Edge>>) -> Vec<i64> {
    let v_num = graph.len();

    let mut sssp = vec![std::i64::MAX; v_num];
    let mut pq = BinaryHeap::new();

    sssp[0] = 0;
    pq.push(SsspState {v: 0, len: 0});

    while let Some(SsspState {v: u, len}) = pq.pop() {
        if len > sssp[u] { continue; }

        // dbg!((u, len));

        for edge in &graph[u] {
            let new_len = len + edge.w;
            if new_len < sssp[edge.v] {
                sssp[edge.v] = new_len;
                pq.push(SsspState {v: edge.v, len: new_len});
            }
        }
    }

    // dbg!(&sssp);
    return sssp;
}

fn run_prob_input() -> (usize, Vec<Vec<Edge>>) {
    input! {
        n: usize,
        m: usize,
        v_weight: [i64; n],
    };

    let v_num = 2 * n;
    let mut g = vec![vec![]; v_num];

    // v_start to v_end
    for i in 0 .. n {
        let u = i;
        let v = n + i;
        g[u].push(Edge {v, w: v_weight[i]});
    }

    // edges in original graph
    for _ in 0 .. m {
        input! {
            u: usize,
            v: usize,
            w: i64,
        };
        let (u_start, u_end) = (u - 1, u - 1 + n);
        let (v_start, v_end) = (v - 1, v - 1 + n);
        g[u_end].push(Edge {v: v_start, w});
        g[v_end].push(Edge {v: u_start, w});
    }

    return (n, g);
}
