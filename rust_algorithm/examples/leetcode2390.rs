#![allow(unused)]

use std::collections::VecDeque;

fn main() {
    let s = String::from("erase*******");

    let mut answer = String::new();
    for c in s.chars() {

        if c == '*' {
            answer.pop();
        }
        else {
            answer.push(c);
        }
    }
    println!("{:?}", answer);

}
