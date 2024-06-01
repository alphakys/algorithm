#![allow(unused)]

use std::collections::{BTreeMap, HashMap};

fn main() {
    let nums = vec![3,3];
    let target = 6;

    let mut map = HashMap::new();

    let mut remainder = 0;
    let mut answer: Vec<i32> = vec![];
    for (i, &n) in nums.iter().enumerate() {

        remainder = target - n;
        if let Some(&t) = map.get(&remainder) {
            answer.push(i as i32);
            answer.push(t);
            break
        }
        map.insert(n, i as i32);
    }

    println!("{:?}", answer);




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