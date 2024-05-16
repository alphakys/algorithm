#![allow(unused)]

use std::collections::{BTreeMap, HashMap};

fn main() {
    let nums = vec![2,7,11,15];
    let target = 9;


    // let mut tu: Vec::<(usize, i32)> = vec![];
    // for (idx, &j) in nums.iter().enumerate() {
    //     tu.push((idx, j));
    // }
    //
    // tu.sort_by(|a, b| a.1.cmp(&b.1));
    // let values = tu.iter().map(|t| t.1).collect::<Vec<_>>();
    //
    // let mut complement = 0;
    // let mut answer = vec![];
    // for (i, &n) in nums.iter().enumerate() {
    //     complement = target - n;
    //     match values.binary_search(&complement){
    //         Ok(t) => {
    //             if tu[t].0 != i { answer.push(i as i32); answer.push( tu[t].0 as i32); break }
    //         },
    //         Err(e) => ()
    //     }
    //
    // }
    // println!("{:?}", answer);
}