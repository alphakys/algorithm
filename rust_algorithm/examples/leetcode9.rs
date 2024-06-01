#![allow(unused)]

use std::future::pending;

fn main() {
    let mut x: i32 = 1221;
    let mut ori = x;
    if x < 0 { println!("{}", false); }
    let mut ri = 0;
    while x > ri {
        ri = (ri * 10) + x % 10;

        x /= 10;
    }
    // We can compare half and half
    println!("{} {} {} {}", (ori - ri) == 0, x== ri/10 ,  x, ri);


    //
    // while x != 0 {
    //     reverse_num *= 10;
    //     reverse_num += x%10;
    //     x /= 10;
    // }
    //
    // if reverse_num < 0 {
    //     println!("{}", true);
    // }
    // else {
    //     println!("{} {}", reverse_num, answer - reverse_num == 0);
    // }
}