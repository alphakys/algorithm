#![allow(unused)]

use log::debug;

fn main() {
    let nums: Vec<i32> = vec![1,5,0,4,1,3];

    let mut pivot = 0;
    let mut left = 1;
    let mut dp = nums[0];

    let mut answer = [None::<usize>; 3];
    answer[0] = Some(pivot);
    let mut result = false;

    while pivot < nums.len() {
        if nums[left] > dp {
            dp = nums[left];
            match answer[1] {
                Some(n) => {
                    answer[2] = Some(left);
                    result = true;
                    break;
                }
                None => { answer[1] = Some(left); }
            }
        }

        left += 1;
        if left == nums.len() {
            match answer[1] {
                Some(n) => {
                    println!("{pivot}", );
                    println!("{:?} n : {} left : {} dp : {}", answer.map(|opt| match opt {
                                Some(t) => {nums[t]},
                        None => {100},
                    } ), n, nums[left - 1], dp);
                    pivot = n + 1;
                    answer[0] = Some(pivot);
                    left = pivot + 1;
                    dp = nums[pivot];
                    answer[1] = None;
                }
                None => { break; }
            }
        }
    }
    //
    // if result {
    //     println!("{:?}", answer.map(|opt| nums[opt.unwrap()]));
    //     println!("{:?}", dp);
    //
    // }

    println!("{result}", );
}