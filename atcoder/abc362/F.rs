use proconio::input;

struct Tree {
    n: usize,
    edges: Vec<Vec<usize>>,
}

fn main() {
    let tree = read_tree();
    let c = find_centroid(&tree);

    let mut ans = Vec::<usize>::with_capacity(tree.n);
    post_ord(c, c, &tree, &mut ans);
    for i in 0..tree.n / 2 {
        println!("{} {}", ans[i] + 1, ans[i + tree.n / 2] + 1);
    }
}

fn post_ord(u: usize, pa: usize, tree: &Tree, ans: &mut Vec<usize>) {
    for v in &tree.edges[u] {
        if *v == pa {
            continue;
        }
        post_ord(*v, u, tree, ans);
    }
    ans.push(u);
}

fn find_centroid(tree: &Tree) -> usize {
    let leaf = get_leaf(tree);
    return dfs(leaf, leaf, tree).0;
}

// (centroid, subtree size)
fn dfs(u: usize, pa: usize, tree: &Tree) -> (usize, usize) {
    let mut my_size: usize = 1;
    let mut am_i_centroid = true;
    let mut centroid = tree.n;
    for v in &tree.edges[u] {
        if *v == pa {
            continue;
        }
        let (c, sz) = dfs(*v, u, tree);
        if c != tree.n {
            centroid = c;
        }
        if c != tree.n || sz > tree.n / 2 {
            am_i_centroid = false;
        }
        my_size += sz;
    }
    if tree.n - my_size > tree.n / 2 {
        am_i_centroid = false;
    }
    if am_i_centroid == true {
        centroid = u;
    }
    return (centroid, my_size);
}

fn get_leaf(tree: &Tree) -> usize {
    for u in 0..tree.n {
        if tree.edges[u].len() == 1 {
            return u;
        }
    }
    unreachable!("trees always have leaf");
}

fn read_tree() -> Tree {
    input! {
        n: usize,
        e: [(usize, usize); n - 1],
    };
    let mut tree = Tree{n, edges: vec![vec![]; n]};
    for (u, v) in e {
        tree.edges[u - 1].push(v - 1);
        tree.edges[v - 1].push(u - 1);
    }
    return tree;
}

