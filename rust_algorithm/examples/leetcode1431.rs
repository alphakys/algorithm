#![allow(unused)]
#![allow(non_snake_case)]

use std::cmp::max;
use std::collections::BinaryHeap;

fn main() {
    let candies: Vec<i32> = vec![2, 3, 5, 1, 3];
    let extra_candies = 3;

    let mut heap = BinaryHeap::from(candies.clone());

    let max_val = heap.pop().unwrap();

    // let mut answer: Vec<bool> = vec![false; candies.len()];

    let mut answer: Vec<bool> = candies.iter().map(|&n| {
        (extra_candies + n).ge(&max_val)
    }).collect();
    println!("{:?}", answer);
}