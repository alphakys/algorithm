#![allow(unused)]

use log::debug;

fn main() {
    let nums: Vec<i32> = vec![1,5,0,4,5,1];

    let mut small = i32::MAX;
    let mut big = i32::MAX;

    let mut answer = false;
    nums.iter().for_each(|&n| {
        // small이 먼저 조건문에 걸림으로 인해 더 작은 값이 small에 assign 된다.
        if n <= small { small = n; }
        // 두 번째 조건문에 if가 걸림으로 두번째로 작은 값이 big에 할당된다.
        else if n <= big { big = n; }
        else {
            answer  = true;
        }
    });

    println!("{}", answer);
        //
    // if result {
    //     println!("{:?}", answer.map(|opt| nums[opt.unwrap()]));
    //     println!("{:?}", dp);
    //
    // }

}