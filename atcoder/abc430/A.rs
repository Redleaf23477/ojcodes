/// stdin helper designed for common competitive use case
mod input_helper {
    use std::io::{self, BufRead};
    use std::str::FromStr;
    use std::fmt::Debug;

    /// Define common input errors in competitive programming
    #[derive(Debug)]
    pub enum InputError {
        ReadLine,
        Parse,
        ElementNum,
    }

    /* Parsing helper functions */

    fn parse_line_as_value<T>(s: String) -> Result<T, InputError> 
        where T: FromStr, <T as FromStr>::Err: std::fmt::Display 
    {
        match s.trim().parse() {
            Ok(val) => Ok(val),
            Err(_e) => {
                let type_name = std::any::type_name::<T>();
                eprintln!("err: failed to parse `{s}` as {type_name}");
                Err(InputError::Parse)
            },
        }
    }

    fn parse_line_as_vec<T>(s: String) -> Result<Vec<T>, InputError>
        where T: FromStr, <T as FromStr>::Err: std::fmt::Display,
    {
        s.split_whitespace()
         .map(|x| x.parse().map_err(|err| (x, err)))
         .collect::<Result<Vec<T>, _>>()
         .map_err(|(x, _e)| {
            let type_name = std::any::type_name::<T>();
            eprintln!("err: failed to parse `{x}` as {type_name} vec");
            InputError::Parse})
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
        let mut line_buff= String::new();
        match io::stdin().lock().read_line(&mut line_buff) {
            Ok(_bytes_read) => Ok(line_buff),
            Err(e) => {
                eprintln!("err: stdin read_line err: {e}");
                Err(InputError::ReadLine)
            },
        }
    }

    /// general scan line entry function
    ///   will consume a line based on input source
    ///   currently hard code to stdin
    /// 
    /// TODO: support multiple input source, e.g. file input
    pub fn scan_line() -> Result<String, InputError> {
        scan_line_from_stdin()
    }


    /// Generic impl of comsume line and parse a single value
    /// ```
    /// let x: i32 = scan_line_as_value()?;
    /// let s: String = scan_line_as_value()?;
    /// ```
    #[allow(unused)]
    pub fn scan_line_as_value<T>() -> Result<T, InputError> 
        where T: FromStr, <T as FromStr>::Err: std::fmt::Display
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
        where T: FromStr, <T as FromStr>::Err: std::fmt::Display
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
        where T: ParseTupleFromLine,
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

fn main() {
    let (a, b, c, d): (i32, i32, i32, i32) = input_helper::scan_line_as_tuple().unwrap();

    if c >= a && d < b {
        println!("Yes");
    } else {
        println!("No");
    }
}