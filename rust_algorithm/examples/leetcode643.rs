#![allow(unused)]

use std::ops::Div;

fn main() {

    let nums: Vec<i32> = vec![1,12,-5,-6,50,3];
    let k: i32 = 4;

    let mut st =0;
    let mut end: i32 = k;

    let mut pre_sum: f64 = nums.iter().take(k as usize).map(|&n| n as f64 ).sum();

    let mut answer = (pre_sum /k as f64);

    while end < nums.len() as i32 {

        pre_sum = pre_sum + nums[end as usize] as f64 - nums[st as usize] as f64;

        let avg = pre_sum.div(k as f64);
        if answer < avg {
            answer = avg;
        }
        st += 1;
        end += 1;
    }

    println!("{answer}", );

}