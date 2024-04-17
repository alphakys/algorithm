#![allow(unused)]

use std::any::type_name;
use std::collections::{HashSet, VecDeque};
use std::process::exit;


fn main() {
    let mut s = String::from("aA");
    let mut s = unsafe { s.as_bytes_mut() };

    let mut left = 0;
    let mut right: i32 = s.len() as i32 - 1;

    let mut stop = 1;
    loop {

        if stop ==10 { break }
        stop += 1;
        while left <= right {
            match s[left as usize] {
                b'a' | b'e' | b'i' | b'o' | b'u'|
                b'A' | b'E' | b'I' | b'O' | b'U' => {
                    break;
                }
                _ => { left += 1; }
            }
        }

        while left <= right {
            match s[right as usize] {
                b'a' | b'e' | b'i' | b'o' | b'u'|
                b'A' | b'E' | b'I' | b'O' | b'U' => {
                    break;
                }
                _ => { right -= 1; }
            }
        }

        if left > right {
            // s.swap(left as usize, right as usize);
            break;
        }
        println!("{left} {right} {:?}", s);
        s.swap(left as usize, right as usize);
        left += 1; right -= 1;
    }

    println!("{:?}", String::from_utf8_lossy(s).to_string());
}