#![allow(unused)]

use std::collections::VecDeque;
use std::mem;

fn main() {

    let mut valid_word = VecDeque::from([97, 98, 99]);
    // abc
    let mut word = "abc";

    let mut cnt = 0;
    for w in word.as_bytes() {

        while valid_word.len() > 0 {

            if valid_word.pop_front().unwrap() == *w { continue }
            else {
                cnt += 1;
            }
            println!("{:?}", valid_word);
        }

        valid_word = VecDeque::from([97, 98, 99]);

    }

    println!("{cnt}", );
    // let mut i = 0;
    // let mut valid_ptr = 0;
    // while i < word.len() {
    //
    //
    //
    //     i += 1;
    // }


}