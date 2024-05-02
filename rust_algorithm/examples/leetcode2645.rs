#![allow(unused)]

use std::collections::VecDeque;
use std::mem;

fn main() {

    let mut valid_word = [97, 98, 99];

    let mut word = "abc";
    let mut st: Vec<u8> = word.chars().map(|c| c as u8).collect();

    let mut cnt = 0;
    let mut i = 0;
    let mut j = 0;

    let mut stop = 0;
    let mut target = st[j];

    loop {
        if stop == 20 { break }
        stop += 1;

        while i < 3 {

            if *(&valid_word[i]) == target {
                i += 1;
                j += 1;
                target = match st.get(j){
                    Some(t) => *t,
                    None => { target },
                };
                continue
            }
            else {
                cnt += 1;
                i += 1;
            }
        }
        if j >= st.len()  { break }
        i = 0;

    }

    println!("{cnt}", );


}