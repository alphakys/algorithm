#![allow(unused)]

use std::ops::Index;

fn main() {
    let s = String::from("abbc");
    let t = String::from("ahbdc");

    let s_bytes = s.as_bytes();
    let t_bytes = t.as_bytes();

    let mut left: i32 = 0;
    let mut right: i32 = (s.len() as i32 - 1);
    let mut cnt: i32 = s.len() as i32;

    let mut piv_st: i32 = 0;
    let mut piv_end: i32 = t.len() as i32 - 1;
    while piv_st <= piv_end {
        if left > right { break; }

        if s_bytes[left as usize] == t_bytes[piv_st as usize] {
            cnt -= 1;
            left += 1;
        }
        piv_st += 1;

        if piv_st <= piv_end && s_bytes[right as usize] == t_bytes[piv_end as usize] {
            cnt -= 1;
            right -= 1;
        }

        piv_end -= 1;
    }

    println!("{}", cnt <=0);
}