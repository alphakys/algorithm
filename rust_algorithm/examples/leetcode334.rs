#![allow(unused)]

use log::debug;

fn main() {
    let nums: Vec<i32> = vec![1,5,0,4,1,3];

    let mut pivot_idx = 0;
    let mut left = pivot_idx + 1;
    let end = (nums.len() as i32 - 2) as i32;
    let mut right = end + 1;

    let mut answer = false;
    'main_loop: while pivot_idx < end {
        let mut stop = 1;
        left = pivot_idx + 1;
        right = end + 1;

        loop {
            if stop == 10 { break; }
            stop += 1;

            while left <= right && nums[pivot_idx as usize] >= nums[left as usize] {
                left += 1;
            }

            while left <= right && nums[left as usize] >= nums[right as usize] {
                right -= 1;
            }

            println!("p : {pivot_idx} l : {left} r : {right}\n", );
            if left >= right { break; }

            // println!("got cha {} {} {}", nums[pivot_idx ], nums[left], nums[right]);
            println!("got cha {} {} {}", pivot_idx, left, right);
            answer = true;
            break 'main_loop
        }
        pivot_idx += 1;
    }

    println!("{answer}", );
}