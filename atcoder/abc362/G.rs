use proconio::input;

type SA = Vec<usize>;

fn main() {
    input! { s: String };
    let s: Vec<char> = (s + "$").chars().collect();

    let sa = build_suffix_array(&s);

    input! { q: i32 };
    for _ in 0..q {
        input! { t: String };
        println!("{}", solve(t, &sa, &s));
    }
}

fn build_suffix_array(s: &Vec<char>) -> SA {
    let alpha_size = 256;
    let n = s.len();

    /*
     * base case: sort substring of len 2^0
     */
    let mut perm: Vec<usize> = vec![0; n];
    let mut rank: Vec<usize> = vec![0; n];

    // counting sort of len 1
    let mut cnt: Vec<usize> = vec![0; alpha_size];
    for &ch in s {
        cnt[ch as usize] += 1;
    }
    for i in 1..cnt.len() {
        cnt[i] += cnt[i - 1];
    }
    for i in 0..n {
        // put s[i] in perm
        perm[cnt[s[i] as usize] - 1] = i;
        cnt[s[i] as usize] -= 1;
    }
    for i in 1..n {
        if s[perm[i]] == s[perm[i - 1]] {
            rank[perm[i]] = rank[perm[i - 1]];
        } else {
            rank[perm[i]] = i;
        }
    }

    /*
     * inductive case: sort substring of |2*len|
     */
    let mut len = 1;
    let mut cnt: Vec<usize> = vec![0; n];
    while len < n {
        let pref = |i: usize| -> usize {
            if i < len {
                i + n - len
            } else {
                i - len
            }
        };
        let suff = |i: usize| -> usize {
            if i + len > n {
                i + len - n
            } else {
                i + len
            }
        };

        cnt.fill(0);
        for i in 0..n {
            let j = pref(i);
            cnt[rank[j]] += 1;
        }
        for i in 1..cnt.len() {
            cnt[i] += cnt[i - 1];
        }
        let mut new_p: Vec<usize> = vec![0; n];
        for i in (0..n).rev() {
            // put perm[i] in new_p
            new_p[cnt[rank[pref(perm[i])]] - 1] = pref(perm[i]);
            cnt[rank[pref(perm[i])]] -= 1;
        }
        let mut new_r: Vec<usize> = vec![0; n];
        for i in 1..n {
            if rank[new_p[i]] == rank[new_p[i - 1]]
                && rank[suff(new_p[i])] == rank[suff(new_p[i - 1])]
            {
                new_r[new_p[i]] = new_r[new_p[i - 1]];
            } else {
                new_r[new_p[i]] = i;
            }
        }

        perm = new_p;
        rank = new_r;
        len *= 2;
    }

    return perm;
}

fn solve(t: String, sa: &SA, s: &Vec<char>) -> usize {
    let t: Vec<char> = t.chars().collect();

    let mut search_range = &sa[..];

    for i in 0..t.len() {
        if search_range.len() == 0 { return 0; }

        let l = search_range.partition_point(|&x| x + i >= s.len() || s[x + i] < t[i]);
        let r = search_range.partition_point(|&x| x + i >= s.len() || s[x + i] <= t[i]);

        search_range = &search_range[l..r];
    }

    return search_range.len();
}

/*
fn my_lower_bound(sa: &[usize], i: usize, key: char, s: &Vec<char>) -> usize {
    let mut low: usize = 0;
    let mut high: usize = sa.len();

    while low < high {
        let mid = (low + high) / 2;
        let ch = if sa[mid] + i < s.len() { s[sa[mid] + i] } else { '$' };
        match ch.cmp(&key) {
            Ordering::Less => { low = mid + 1; },
            Ordering::Equal => { high = mid; },
            Ordering::Greater => { high = mid; },
        };
    }

    return low;
}

fn my_upper_bound(sa: &[usize], i: usize, key: char, s: &Vec<char>) -> usize {
    let mut low: usize = 0;
    let mut high: usize = sa.len();

    while low < high {
        let mid = (low + high) / 2;
        let ch = if sa[mid] + i < s.len() { s[sa[mid] + i] } else { '$' };
        match ch.cmp(&key) {
            Ordering::Less => { low = mid + 1; },
            Ordering::Equal => { low = mid + 1; },
            Ordering::Greater => { high = mid; },
        };
    }

    return low;
}
*/

/*
 *   abcd$, len = 5
 *  _: ['a', 'b', 'c', 'd', '$']
 *  0: ['ab', 'bc', 'cd', 'd$', '$a']
 *  1: ['abcd', 'bcd$', 'cd$a', 'd$ab', '$abc']
 *  2: ['abcd$abc', 'bcd$abcd' ... ]
 */
