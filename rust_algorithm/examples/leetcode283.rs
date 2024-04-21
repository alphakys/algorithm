#![allow(unused)]

fn main() {
    let mut nums = vec![0, 1, 0, 3, 0, 4, 0, 0, 0, 5, 3, 12];
    
    // let mut answer = Vec::new();
    // nums.retain(|&n| {
    //     if n != 0 { true } else { answer.push(0); false }
    // });
    //
    // nums.append(&mut answer);
    //
    // println!("{:?}", nums);

    // let length: i32 = nums.len() as i32;
    // let mut pivot: i32 = 0;
    // let mut end: i32 = (length - 1) as i32;
    // while pivot < length {
    //
    //     if nums[pivot as usize] == 0 {
    //         let mut i: i32 = pivot;
    //
    //         while i < end {
    //             nums.swap(i as usize, (i + 1) as usize); i += 1;
    //         }
    //         end -= 1;
    //         if nums[pivot as usize] == 0 { pivot -= 1;}
    //     }
    //
    //     if pivot >= end { break }
    //     pivot += 1;
    // }
    //
    //
    // println!("{:?}", nums);
}