#![allow(unused)]
#![allow(non_snake_case)]

use std::io;
use std::io::Read;
use std::ptr::{hash, NonNull};

fn custom_read_line<'a>() -> String {
    let mut buf = String::new();

    // expect internal code
    /*
        pub fn expect(self, &str: message) -> {
            match self {
                Ok(t) => t,
                Err(e:E) => unwrap_failed(message, &e),
            }

        }
     */
    io::stdin().read_line(&mut buf).expect("When reading a data from buf");

    buf.trim_end().to_string()
}

fn lower_bound(arr: &Vec<i32>, target: i32) -> usize {
    let mut start = 0;
    let mut end = arr.len();
    let mut mid = (start + end) / 2;

    // let mut result = None;
    while start < end {
        if arr[mid] >= target {
            end = mid
        } else { // arr[mid] < target
            start = mid + 1
        }
        mid = (start + end) / 2;
    }

    start
}

fn upper_bound(arr: &Vec<i32>, target: i32) -> usize {
    let mut start: usize = 0;
    let mut end: usize = arr.len();
    let mut mid: usize = (start + end) / 2;

    // let mut result = None;
    while start < end {
        if arr[mid] <= target {
            start = mid + 1
        } else {
            end = mid
        }
        mid = (start + end) / 2;
    }

    start
}


fn binary_search(arr: &Vec<i32>, target: i32) -> u8 {
    let mut start: usize = 0;
    let mut end: usize = arr.len();
    let mut mid: usize = (start + end) / 2;

    let mut answer: u8 = 0;

    while start < end {
        if arr[mid] == target {
            answer = 1;
            break;
        } else if arr[mid] > target {
            end = mid;
        } else {
            start = mid + 1;
        }

        mid = (start + end) / 2;
    }

    answer
}

fn main() {
    let buf = custom_read_line();
    let N = buf.parse::<u32>().unwrap();

    let buf = custom_read_line();
    let s: Vec<&str> = buf.split(' ').collect();

    let mut itr = s.iter().map(|x| x.parse::<i32>().unwrap());
    let mut arr: Vec<_> = itr.collect();

    let target_vec: Vec<i32> = arr.clone();
    arr.sort();

    let mut i: usize = 0;
    let mut v: Vec<i32> = vec![];
    v.push(arr[i]);
    let mut upper_bound_idx = upper_bound(&arr, arr[i]);

    while upper_bound_idx < arr.len() {
        v.push(arr[upper_bound_idx]);

        upper_bound_idx = upper_bound(&arr, arr[upper_bound_idx]);
    }

    let mut answer = String::new();

    for target in target_vec {

        let idx = lower_bound(&v, target);
        answer.push_str(&format!("{} ", idx));
    }
    println!("{}", answer);
}
