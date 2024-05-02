#![allow(unused)]

use log::debug;

fn main() {
    let nums: Vec<i32> = vec![0, 11, 5, 1, 4, 5, 1];

    let mut answer: Vec<&mut Vec<i32>> = vec![];
    for n in &nums {

        for v in &mut answer {
            println!("{:?}", v);
            if v[v.len()] < *n {
                v.push(*n);
            }

        }

        match &nums.binary_search(n){
            Ok(t) => {

            },
            Err(e) => {}
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