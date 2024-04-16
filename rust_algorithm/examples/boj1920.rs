// #[allow(unused_imports)]
use std::{io, mem};
use std::io::{Stdin, StdinLock};
use std::mem::size_of;
#[allow(unused)]

// &'a str
fn read_line() -> String {
    let mut input: String = String::new();
    // Result 반환 몇 byte 읽었는지 return
    let _ = io::stdin().read_line(&mut input);

    let input_str = input.strip_suffix('\n').unwrap().to_string();

    input_str
}

fn binary_search(arr: &Vec<isize>, target: isize) -> u8 {
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

    let N = read_line().parse::<usize>().unwrap();

    let binding = read_line();
    let splitted = &mut binding.split(' ');

    let arr = splitted.map(|x| x.parse::<isize>().unwrap());

    let mut arr: Vec<isize> = arr.collect();
    arr.sort();
    let M = read_line().parse::<isize>().unwrap();

    let binding = read_line();
    let splitted = &mut binding.split(' ');

    let target_nums = splitted.map(|x| x.parse::<isize>().unwrap());

    let mut target_nums: Vec<isize> = target_nums.collect();

    let mut answer = String::new();
    for t in target_nums {
        // let mut s = &binary_search(&arr, t).to_string()
        answer.push_str(&binary_search(&arr, t).to_string());
        answer.push_str("\n");
    }

    print!("{}", answer);
}
