#![allow(unused)]
fn main() {

    let mut nums = [1,2,3,4];
    let mut suffix_dp: Vec<i32> = Vec::new();

    nums.iter().rfold(1, |acc, n| {
        suffix_dp.push(acc * n);
        acc * n
    });
    suffix_dp.reverse();

    let mut prefix_dp: Vec<i32> = vec![0; nums.len()];
    prefix_dp[0] = nums[0];

    let mut answer: Vec<i32> = Vec::new();

    let mut i = 1;
    answer.push(suffix_dp[1]);
    while i < nums.len() -1 {
        prefix_dp[i] = prefix_dp[i - 1] * nums[i];

        answer.push(prefix_dp[i-1] * suffix_dp[i + 1]);

        i += 1;
    }
    answer.push(prefix_dp[i-1]);

    println!("{:?}", answer);


    // let mut dp: Vec<i32> = vec![0; nums.len()];
    // dp[0] = 1;
    //
    // for (i, &n) in nums[1..].iter().enumerate() {
    //     println!("{} {}", n * dp[i], i);
    //     dp[i] = dp[i] * n;
    // }
    //
    // println!("{:?}", dp);

}