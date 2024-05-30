#![allow(unused)]

use std::cmp::Ordering;
use std::ffi::c_char;
use std::mem::size_of_val;
use std::ops::{Range, Sub};

#[derive(Debug, Clone, Copy)]
struct Foo;


fn main() {

    let c = '1';
    // 48 0
    // 49 1
    println!("{}", b'0');
    println!("{}", (48 + 49) / 50);

}