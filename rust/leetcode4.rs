#![allow(unused)]
#![allow(non_snake_case)]

use std::io;
use rand::{random, Rng, thread_rng};

fn quick_sort(mut v: &mut Vec<i32>, start: usize, end: usize) {

    if start + 1 > end { return; }

    let mut pivot = v[start];

    let mut left = start + 1;
    let mut right = end;

    let mut stopper = 1;
    loop {
        println!("{start} {end} {left} {right}", );
        if stopper == 10 { break; }

        stopper += 1;
        while left <= right && v[left] < pivot { left += 1; }
        while left <= right && v[right] > pivot { right -= 1; }

        if left > right { v.swap(right, start); break; }

        v.swap(left, right);
        println!("swap : {:?}", v);
    }
    println!("{:?}", v);
    println!("{right}", );
    quick_sort(&mut v, start, right - 1);
    quick_sort(&mut v, left, end);
}

fn main() {

    // let mut buf = String::new();
    //
    // io::stdin().read_line(&mut buf);
    //
    // let N: usize = buf.trim().parse().unwrap();
    // let mut v = vec![0;N];
    //
    // buf.clear();
    //
    // let lines = io::stdin().lines();
    //
    // for (idx, line) in lines.enumerate() {
    //     // print!("{}", line.unwrap().parse::<i32>().unwrap());
    //     v[idx] = line.unwrap().parse::<i32>().unwrap();
    // }

    let mut v = [0; 5];

    let r = thread_rng().gen_range(0..100);

    let mut v = v.iter().map(|x| *x + thread_rng().gen_range(0..100)).collect::<Vec<_>>();

    let mut v = vec![53, 93, 21, 52, 73];

    let cnt = v.len();
    println!("original v : {:?}", v);
    quick_sort(&mut v, 0, cnt - 1);

    println!("v1 \n{:?}", v);

    v.sort();
    println!("v2 \n{:?}", v);
    // let cnt = v.len();
    // quick_sort(&mut v, 0, cnt);


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