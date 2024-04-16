#![allow(unused)]
#![allow(non_snake_case)]

use std::collections::VecDeque;

fn main() {

    let s = String::from("abbazezalphaduethoohbookkoob");
    // let s = String::from("babad");

    let s = String::from("baaaaaaaab");
    let s = s.as_bytes();

    let mut q: VecDeque<char> = VecDeque::new();

    let mut mid: usize = 0;
    q.push_back(s[mid] as char);
    let mut left: i32 = mid as i32;
    let mut right: usize = mid;

    let mut stopper = 1;

    let mut answer = String::new();

    let mut pivot = 0;
    let mut advancer = 0;

    fn palidrome() {

    }

    while mid < s.len() {

        while advancer < s.len() && s[pivot] == s[advancer] { advancer += 1; }

        while  s[advancer] == s[pivot - 1] {

            advancer += 1;
            pivot -= 1;
        }


        if stopper == 12 { break; }
        stopper += 1;
    }

    println!("{answer}", );
}