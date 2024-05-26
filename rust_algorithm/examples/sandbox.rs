#![allow(unused)]

use std::cmp::Ordering;
use std::mem::size_of_val;
use std::ops::{Range, Sub};

#[derive(Debug, Clone, Copy)]
struct Foo;


fn main() {

    let nums: &mut Vec<i32> = &mut vec![0,0,1];

    let mut i = 0;
    let mut upper_bound = 0;
    let mut k = 0;
    while i < nums.len() {

        let upper = nums.binary_search_by(|probe| {
            match probe.cmp(&nums[i]){
                // Since we try to find position of first element
                // we treat all equal values as greater to move left.
                Ordering::Equal => Ordering::Less,
                ord => { ord },
            }
        });

        upper_bound = upper.unwrap_err();
        k += 1;
        if upper_bound >= nums.len() { break }
        nums[i + 1] = nums[upper_bound];
        i +=1;

    }
    println!("{k}", );
    println!("{:?}", nums);
    // What Copy trait??
    // It is bicopy trait of value!

    // What Clone trait?
    // I think it is associated with object copy so clone is different with
    // copy trait that is copy of variable's value!

    // let r = 1..4;
    // for i in r.into_iter() {
    //     println!('{}', i);
    // }
}