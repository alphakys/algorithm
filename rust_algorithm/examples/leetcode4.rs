#![allow(unused)]
#![allow(non_snake_case)]

use std::io;
use std::path::Component::ParentDir;


fn find_lengest1(nums1: &mut Vec<i32> , nums2: &mut Vec<i32>){
    nums1.sort();
    nums2.sort();
    let cnt = nums1.len() + nums2.len();
    let mut tmp_arr = vec![];

    let mut i = 0;
    let mut j = 0;
    let mut idx = 0;
    let mut answer:f64 = 0.0;
    loop {

        if i == nums1.len() && j == nums2.len() { break }

        if i == nums1.len() { tmp_arr.push(nums2[j]); j += 1; }
        else if j == nums2.len() { tmp_arr.push(nums1[i]); i += 1; }
        else if nums1[i] > nums2[j] { tmp_arr.push(nums2[j]); j += 1;}
        else{ tmp_arr.push(nums1[i]); i += 1;}

        if idx == cnt / 2{

            if cnt %2==0{ answer = (tmp_arr[idx] as f64 + tmp_arr[idx-1] as f64) / 2 as f64; }
            else { answer = tmp_arr[idx] as f64}

            break
        }
        idx += 1;
    }

    println!("{answer}", );
}
fn main() {

    let mut nums1: Vec<i32> = vec![1,2,4,5,23,6,7,8,102];
    let mut nums2: Vec<i32> = vec![3,4,113,4,23,12,23,3,2313,5,43];
    ///                             [1,2,3,4,4,5,11,23]

    nums1.sort();
    nums2.sort();

    println!("{:?}", nums1);
    println!("{:?}", nums2);

    let mut left = 0;
    let mut right = nums1.len();
    let mut mid = (left + right) / 2;


    find_lengest1(&mut nums1, &mut nums2);


    // nums1.sort();
    // nums2.sort();
    // let cnt = nums1.len() + nums2.len();
    // let mut tmp_arr = vec![];
    //
    // let mut i = 0;
    // let mut j = 0;
    // let mut idx = 0;
    // let mut answer:f64 = 0.0;
    // loop {
    //
    //     if i == nums1.len() && j == nums2.len() { break }
    //
    //     if i == nums1.len() { tmp_arr.push(nums2[j]); j += 1; }
    //     else if j == nums2.len() { tmp_arr.push(nums1[i]); i += 1; }
    //     else if nums1[i] > nums2[j] { tmp_arr.push(nums2[j]); j += 1;}
    //     else{ tmp_arr.push(nums1[i]); i += 1;}
    //
    //     if idx == cnt / 2{
    //
    //         if cnt %2==0{ answer = (tmp_arr[idx] as f64 + tmp_arr[idx-1] as f64) / 2 as f64; }
    //         else { answer = tmp_arr[idx] as f64}
    //
    //         break
    //     }
    //     idx += 1;
    // }
    //
    // println!("{answer}", );

    // println!("{:?}", v.iter().map(|x| x.to_string()).collect::<Vec<_>>().join("\n"));

    // let mut nums1: Vec<i32> = vec![2,4, 6];
    // let mut nums2: Vec<i32> = vec![1,3, 5];
    //
    // let mut i = 0;
    // let mut j = 0;
    //
    // let mut stopper = nums1.len() + nums2.len();
    //
    // let target = stopper / 2;
    // let mut v  = vec![];
    // let mut itr = 0;
    //
    // let mut median_num = 0;
    // let mut second_median_num = 0;
    //
    // while  itr <= target {
    //     second_median_num = median_num;
    //
    //     if i == nums1.len() {
    //         median_num = nums2[j];
    //         j += 1;
    //         itr += 1;
    //     }
    //     else if j == nums2.len() {
    //         median_num = nums1[i];
    //         i += 1;
    //         itr += 1;
    //     }
    //     else if nums1[i] > nums2[j] {
    //         v.push(nums2[j]);
    //         median_num = nums2[j];
    //         j += 1;
    //     }
    //     else {
    //         v.push(nums1[i]);
    //         median_num = nums1[i];
    //         i += 1;
    //     }
    //
    //     itr += 1;
    //
    // }
    //
    // let mut answer = 0f64;
    //
    // if stopper % 2 == 1 {
    //     answer = median_num as f64;
    //
    // }
    // else {
    //     answer = (median_num as f64 + second_median_num as f64) / 2 as f64;
    // }
}