/// stdin helper designed for common competitive use case
mod input_helper {
    use std::fmt::Debug;
    use std::io::{self, BufRead};
    use std::str::FromStr;

    /// Define common input errors in competitive programming
    #[derive(Debug)]
    pub enum InputError {
        ReadLine,
        Parse,
        ElementNum,
    }

    /* Parsing helper functions */

    fn parse_line_as_value<T>(s: String) -> Result<T, InputError>
    where
        T: FromStr,
        <T as FromStr>::Err: std::fmt::Display,
    {
        match s.trim().parse() {
            Ok(val) => Ok(val),
            Err(_e) => {
                let type_name = std::any::type_name::<T>();
                eprintln!("err: failed to parse `{s}` as {type_name}");
                Err(InputError::Parse)
            }
        }
    }

    fn parse_line_as_vec<T>(s: String) -> Result<Vec<T>, InputError>
    where
        T: FromStr,
        <T as FromStr>::Err: std::fmt::Display,
    {
        s.split_whitespace()
            .map(|x| x.parse().map_err(|err| (x, err)))
            .collect::<Result<Vec<T>, _>>()
            .map_err(|(x, _e)| {
                let type_name = std::any::type_name::<T>();
                eprintln!("err: failed to parse `{x}` as {type_name} vec");
                InputError::Parse
            })
    }

    pub trait ParseTupleFromLine: Sized {
        fn parse_line_as_tuple(s: String) -> Result<Self, InputError>;
    }

    macro_rules! impl_parse_line_as_tuple {
        ( $( $T:ident ),+ ) => {
            impl <$( $T ),+> ParseTupleFromLine for ($( $T ),+)
            where
                $( $T: FromStr, <$T as FromStr>::Err: std::fmt::Display, )+
            {
                fn parse_line_as_tuple(s: String) -> Result<Self, InputError> {
                    let mut it = s.split_whitespace();
                    let result_tuple = (
                        $(
                            {
                                let elem = it.next().ok_or(InputError::ElementNum)?;
                                elem.parse::<$T>().map_err(|_e| {
                                    let type_name = std::any::type_name::<$T>();
                                    eprintln!("err: failed to parse `{elem}` as {type_name}");
                                    InputError::Parse
                                })?
                            }
                        ),+
                    );
                    if it.next().is_some() {
                        eprintln!("err: too many items!");
                        Err(InputError::ElementNum)
                    } else {
                        Ok(result_tuple)
                    }
                }
            }
        }
    }
    impl_parse_line_as_tuple!(A, B);
    impl_parse_line_as_tuple!(A, B, C);
    impl_parse_line_as_tuple!(A, B, C, D);
    impl_parse_line_as_tuple!(A, B, C, D, E);

    /* Scanning helper functions */

    /// consume a line from stdin
    fn scan_line_from_stdin() -> Result<String, InputError> {
        let mut line_buff = String::new();
        match io::stdin().lock().read_line(&mut line_buff) {
            Ok(_bytes_read) => Ok(line_buff),
            Err(e) => {
                eprintln!("err: stdin read_line err: {e}");
                Err(InputError::ReadLine)
            }
        }
    }

    /// general scan line entry function
    ///   will consume a line based on input source
    ///   currently hard code to stdin
    ///
    /// TODO: support multiple input source, e.g. file input
    pub fn scan_line() -> Result<String, InputError> {
        let s = scan_line_from_stdin()?.trim().to_string();
        Ok(s)
    }

    /// Generic impl of comsume line and parse a single value
    /// ```
    /// let x: i32 = scan_line_as_value()?;
    /// let s: String = scan_line_as_value()?;
    /// ```
    #[allow(unused)]
    pub fn scan_line_as_value<T>() -> Result<T, InputError>
    where
        T: FromStr,
        <T as FromStr>::Err: std::fmt::Display,
    {
        let s = scan_line()?;
        parse_line_as_value(s)
    }

    /// Generic impl of comsume line and parse same-type value
    /// into a Vec<T>
    /// ```
    /// let v: Vec<u32> = scan_line_as_vec()?;
    /// ```
    #[allow(unused)]
    pub fn scan_line_as_vec<T>() -> Result<Vec<T>, InputError>
    where
        T: FromStr,
        <T as FromStr>::Err: std::fmt::Display,
    {
        let s = scan_line()?;
        parse_line_as_vec(s)
    }

    /// Generic impl of comsume line and parse tuple
    /// into a Tuple<A, B, ...>
    /// ```
    /// let tp: (i32, String, bool) = scan_line_as_tuple()?;
    /// ```
    #[allow(unused)]
    pub fn scan_line_as_tuple<T>() -> Result<T, InputError>
    where
        T: ParseTupleFromLine,
    {
        let s = scan_line()?;
        T::parse_line_as_tuple(s)
    }

    #[cfg(test)]
    mod tests {
        use super::*;

        #[test]
        fn test_scan_line_from_stdin() {
            match scan_line_from_stdin() {
                Ok(s) => println!("consumed `{s}` from stdin!"),
                Err(e) => println!("hit `{:?}` from stdin!", e),
            }
        }

        #[test]
        fn test_scan_line_as_value() {
            match scan_line_as_value::<i32>() {
                Ok(s) => println!("consumed and parsed `{s}` from stdin!"),
                Err(e) => println!("hit `{:?}` from stdin!", e),
            }
        }

        #[test]
        fn test_scan_line_as_vec() {
            match scan_line_as_vec::<i32>() {
                Ok(s) => println!("consumed and parsed `{:?}` from stdin!", s),
                Err(e) => println!("hit `{:?}` from stdin!", e),
            }
        }

        #[test]
        fn test_scan_line_as_2_tuple() {
            match scan_line_as_tuple::<(i32, String)>() {
                Ok(s) => println!("consumed and parsed `{:?}` from stdin!", s),
                Err(e) => println!("hit `{:?}` from stdin!", e),
            }
        }

        #[test]
        fn test_scan_line_as_3_tuple() {
            match scan_line_as_tuple::<(i32, String, f32)>() {
                Ok(s) => println!("consumed and parsed `{:?}` from stdin!", s),
                Err(e) => println!("hit `{:?}` from stdin!", e),
            }
        }

        #[test]
        fn test_scan_line_as_4_tuple() {
            match scan_line_as_tuple::<(i32, String, f32, bool)>() {
                Ok(s) => println!("consumed and parsed `{:?}` from stdin!", s),
                Err(e) => println!("hit `{:?}` from stdin!", e),
            }
        }

        #[test]
        fn test_scan_line_as_5_tuple() {
            match scan_line_as_tuple::<(i32, String, f32, bool, u32)>() {
                Ok(s) => println!("consumed and parsed `{:?}` from stdin!", s),
                Err(e) => println!("hit `{:?}` from stdin!", e),
            }
        }
    }
}

use std::collections::BTreeSet;

fn main() {
    let _n: u32 = input_helper::scan_line_as_value().unwrap();
    let arr: Vec<i64> = input_helper::scan_line_as_vec().unwrap();

    let mut set: BTreeSet<i64> = BTreeSet::new();
    set.insert(0);

    let mut ans: i64 = 0;
    for x in arr {
        let left = set.range(..x).last();
        let leftleft = left.and_then(|l| set.range(..l).last());
        let right = set.range(x..).next();
        let rightright = right.and_then(|r| set.range(r + 1..).next());

        // deal with left
        if let Some(l) = left {
            let min_diff = [
                leftleft.map(|ll| l - ll),
                right.map(|r| r - l),
            ].into_iter().flatten().min();
            ans += min_diff.map_or(x - l, |m| {
                if x - l < m {
                    (x - l) - m
                } else {
                    0
                }
            });
        }

        // deal with right
        if let Some(r) = right {
            let min_diff = [
                rightright.map(|rr| rr - r),
                left.map(|l| r - l),
            ].into_iter().flatten().min();
            ans += min_diff.map_or(r - x, |m| {
                if r - x < m {
                    (r - x) - m
                } else {
                    0
                }
            })
        }

        // deal with x
        match (left, right) {
            (Some(l), Some(r)) => ans += (x - l).min(r - x),
            (Some(l), None) => ans += x - l,
            (None, Some(r)) => ans += r - x,
            (None, None) => {},
        }

        set.insert(x);

        // output answer
        println!("{ans}");
    }
}
