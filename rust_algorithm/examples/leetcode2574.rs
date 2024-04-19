#![allow(unused)]

use std::collections::VecDeque;

fn main() {


    let mut nums = vec![10,4,8,3];

    let mut total_sum = nums.iter().fold(0, |acc, &n| acc + n);

    let mut i = 0;

    let mut sub_sum = 0;
    let mut answer = vec![];

    let mut left_sum: i32 = 0;
    while i < nums.len() {
        total_sum -= nums[i];

        answer.push((total_sum - left_sum).abs());
        left_sum += nums[i];
        i += 1;

    }
    println!("{:?}", answer);

    //
    // // iterator가 reference를 가져오는지 clone을
    //     // if nums.len() == 1 { vec![0]; }
    //     //
    //     // let mut sum = 0;
    //     //
    //     // let mut maps = (&mut nums).iter_mut().map(|n| {
    //     //     sum += *n;
    //     //     sum
    //     // }).collect::<Vec<_>>(); 통해서 메모리 복사가 일어난 배열에 대해서 iterating 하는지 알아보자.
    // let mut itr = (&mut nums).iter_mut();
    // let mut itr_result = itr.next_back();
    //
    // let mut reverse_fold: VecDeque<i32> = VecDeque::new();
    // sum = 0;
    // while itr_result.is_some() {
    //     sum += **itr_result.as_ref().unwrap();
    //     reverse_fold.push_front(sum);
    //     itr_result = itr.next_back();
    // }
    //
    //
    // let mut pivot_idx = 0;
    // let mut answer: Vec<i32> = Vec::new();
    // sum = 0;
    //
    // while pivot_idx < nums.len() {
    //     if pivot_idx == 0 { sum = (0 - reverse_fold[1]).abs() } else if pivot_idx == nums.len() - 1 { sum = (0 - maps[pivot_idx - 1]).abs() } else {
    //         sum = (maps[pivot_idx - 1] - reverse_fold[pivot_idx + 1]).abs()
    //     }
    //     answer.push(sum);
    //     pivot_idx += 1;
    // }
    //
    // println!("{:?}", answer);
}