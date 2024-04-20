#![allow(unused)]
fn main() {

    let mut nums = [-1,1,0,-3,3];

    let mut dp: Vec<i32> = vec![0; nums.len()];
    dp[0] = 1;

    for (i, &n) in nums[1..].iter().enumerate() {
        println!("{} {}", n * dp[i], i);
        dp[i] = dp[i] * n;
    }

    println!("{:?}", dp);

    //
    // let mut product = nums.iter().fold(1, |acc, &n| {
    //     if n != 0 { acc * n } else { acc }
    // });
    //
    // let tmp_product = product;
    // // println!("{product}", );
    // // let mut product: i32 = nums.iter().product();
    // let mut answer: Vec<i32> = vec![0; nums.len()];
    // let mut left_product = 1;
    // for i in 0..nums.len() {
    //
    //     if nums[i] == 0 {
    //         answer[i] = tmp_product;
    //         continue
    //     }
    //
    //     product /= nums[i];
    //
    //     answer[i] = left_product * product;
    //     left_product *= nums[i];
    //
    // }
    //
    // println!("{:?}", answer);
}