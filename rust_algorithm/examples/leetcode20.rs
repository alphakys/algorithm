#![allow(unused)]

use std::collections::{HashMap, VecDeque};
use std::ffi::{c_char, FromVecWithNulError};

fn main() {
    let mut s: String = String::from("()]");

    let mut stack: VecDeque<u8> = VecDeque::new();

    let mut map = HashMap::new();
    map.insert(b'}', b'{');
    map.insert(b']', b'[');
    map.insert(b')', b'(');
    let mut answer = true;

    let mut c1: u8 = 0;
    let mut c2: u8 = 0;
    for &c in s.as_bytes() {
        match c {
            b'}' | b')' | b']' => {
                c1 = *(map.get(&c).unwrap());
                c2 = stack.pop_back().unwrap_or(0);
                if c1 != c2 {
                    answer = false;
                }
            }
            _ => {
                stack.push_back(c);
            }
        }
    }

    println!("{:?}", answer && stack.is_empty());
}