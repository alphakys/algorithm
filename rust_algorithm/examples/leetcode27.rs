#![allow(unused)]

use std::future::pending;

fn main() {
    let nums: &mut Vec<i32> = &mut vec![3,2,2,3]; // 8
    let val: i32 = 0;
    let mut i = 0;
    let mut k = nums.len() - 1;

    let mut cnt = 0;
    while i < nums.len(){
        if i <= k && nums[i] == val {
            while nums[k] == val{ k -= 1; }
            nums.swap(i, k);
        }
        i += 1;
    }

    println!("{:?} {}", nums, k);
}