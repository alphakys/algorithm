#![allow(unused)]
fn main() {
    let mut nums = vec![3,3];

    nums.sort();

    let mut min = nums[0];
    let mut max = nums[nums.len() - 1];

    let mut answer: i32 = 0;
    loop {

        if max % min == 0 {
            answer = min;
            break
        }
        else {
            let tmp = min;
            min = max % min;
            max = tmp;
        }
    }

    println!("{answer}", );


}