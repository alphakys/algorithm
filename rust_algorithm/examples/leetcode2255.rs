#![allow(unused)]

use std::collections::{HashSet};

fn main() {
    let words: Vec<String> = vec![String::from("a"), String::from("b"), String::from("c"), String::from("ab")
                                  , String::from("bc"), String::from("abc")];

    let s = String::from("abc");
    let mut cnt = 0;
    words.iter().for_each(|word| if s.starts_with(&*word) { cnt += 1; });
    println!("{:?}", cnt);
    dbg!(s.starts_with("abd"));
    // println!("{}", words.starts_with(&["a".to_string(), "c".to_string()]));


    // let mut hs = HashSet::new();
    //
    // let mut v: Vec<&str> = Vec::new();
    // for i in 1..=s.len() {
    //     v.push(&s[0..i]);
    //     hs.insert(&s[0..i]);
    // }
    //
    // let mut cnt = 0;
    // for w in words {
    //     match hs.get(&*w).is_some() {
    //         true => { cnt += 1; }
    //         false => {}
    //     }
    // }
    //
    // println!("{cnt}");
}