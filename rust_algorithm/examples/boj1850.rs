#![allow(unused)]

use std::io;

fn main() {
    let mut buff = String::new();
    io::stdin().read_line(&mut buff);

    let nums = buff.trim_end().split(' ').collect::<Vec<&str>>();

    let ori_a: u32 = nums[0].parse::<u32>().unwrap();
    let ori_b: u32 = nums[1].parse::<u32>().unwrap();

    let mut a: u32 = ori_a;
    let mut b: u32 = ori_b;

    let mut gd = 0;
    loop {

        if a > b {
            if a % b == 0 { gd = b; break }
            a = a % b;
        }
        else {
            if b % a == 0 { gd = a; break }
            b = b % a;
        }
    }

    println!("{}\n{}", gd, (ori_a/gd)*(ori_b/gd)*(gd));
}