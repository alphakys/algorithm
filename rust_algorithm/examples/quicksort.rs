#![allow(unused)]

use std::mem::swap;

fn quick_sort(v: &mut Vec<i32>, start: i32, end: i32) {
    if start + 1 > end { return; }

    let mut left = start + 1;
    let mut right = end;
    let pivot = v[start as usize];

    loop {
        while left <= right && pivot >= v[left as usize] { left += 1; }
        while left <= right && pivot <= v[right as usize] { right -= 1; }

        if left > right {
            v.swap(start as usize, right as usize);
            break;
        }

        v.swap(left as usize, right as usize);

    }

    quick_sort(v, start, right - 1);
    quick_sort(v, right + 1, end);

}

fn main() {
    let mut v = vec![43, 23, 33];

    let len = (v.len() - 1) as i32;
    quick_sort(&mut v, 0 as i32, len);

    println!("{:?}", v);
}