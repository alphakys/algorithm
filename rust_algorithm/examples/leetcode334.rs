#![allow(unused)]

use log::debug;

fn main() {
    let nums: Vec<i32> = vec![0, 11, 5, 1, 4, 5, 1];

    let a = [0, 11];

    let re = a.binary_search(&5);

    println!("{:?}", re);

    let mut answer: Vec<i32> = vec![];
    for n in &nums[1..] {

        if *n > *answer.last().unwrap() {
            /// If the current number is greater than the last element
            /// of the answer vector, it means we have found a longer increasing
            /// subsequence. Hence, we append the current number to the answer vector
            answer.push(*n);
        }
        else {

        }
    }

    println!("{:?}", answer);

    // let mut first = i32::MAX;
    // let mut second = i32::MAX;
    //
    // let mut answer = false;
    // for n in nums {
    //     if n <= first { first = n; }
    //     else if n <= second { second = n; }
    //     else { answer = true; }
    // }
    //
    // println!("{}", answer);
}