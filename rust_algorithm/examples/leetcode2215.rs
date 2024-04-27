#![allow(unused)]

use std::collections::HashSet;

fn main() {
    let mut nums1: Vec<i32> = vec![1,2,3,3];
    let mut nums2: Vec<i32> = vec![1,1,2,2];

    let mut set1: HashSet<i32> = HashSet::from_iter(nums1);
    let mut set2: HashSet<i32>  = HashSet::from_iter(nums2);

    // let symetric1 = set1.difference(&set2).to_owned();

    let symetric1: Vec<i32> = set1.difference(&set2).into_iter().map(|&n| n).collect();

    let symetric2: Vec<i32> = set2.difference(&set1).into_iter().map(|&n| n).collect();

    let answer: Vec<Vec<i32>> = Vec::from([symetric1, symetric2]);

    println!("{:?}",answer );
    // println!("{:?}\n{:?}", nums1, nums2);

}