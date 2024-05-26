#![allow(unused)]

use std::cmp::Ordering;

fn main() {
    let nums: &mut Vec<i32> = &mut vec![98, 99, 99, 100, 100, 100, 100, 101];

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
}