#![allow(unused)]
fn main() {


    let mut nums = [1,2,3,4];
    // 22 12                1 2 6 24 48

    let length = nums.len();

    let mut dp:Vec<i32> = vec![0; length];



    let mut i = 1;
    dp[0] = nums[0];
    while i < length {
        dp[i] = dp[i - 1] * nums[i];
        i += 1;
    }

    let mut i = 1;
    while i < length -1 {
        println!("{}", dp[i - 1] * nums[i + 1]);
        i += 1;
    }

    // [1,2,6,24]
    // [24,6,2,1]

    println!("{:?}", dp);
    // let sum = nums.iter().fold(1, |acc , &n|
    //     {
    //         match n {
    //             0 => { acc * 1 },
    //             _ => {acc * n}
    //         }
    //     }
    // );
    //
    // let mut_ptr = nums.as_mut_ptr();
    //
    // for i in 0.. nums.len() {
    //     unsafe {
    //         match *mut_ptr.add(i) {
    //             0 => { *mut_ptr.add(i) = sum }
    //             _ => { *mut_ptr.add(i) = 0 }
    //         }
    //     }
    // }

    // println!("{:?}", nums);
}