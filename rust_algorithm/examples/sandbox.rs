#![allow(unused)]

// Converts a &str into a String
// The result is allocated on the heap
// pub fn from(s: &str) -> String {
//     to_own(s)
// }
//
//
// #[inline]
// pub fn to_own(selff: &str) -> String {
//     println!('{:p}', selff);
//
//     let cl = selff.as_bytes().to_owned();
//
//     println!('{:p}', *cl);
//     String::new()
// }


use std::mem::size_of_val;
use std::ops::{Range, Sub};

#[derive(Debug, Clone, Copy)]
struct Foo;



fn main() {

    let s = String::from("pwwkewvnqqdczor[e");
    let z = s.as_bytes().get(1);
    println!("{:?}", z);

    let aa: usize = 1;
    aa.sub(3);

    // git push

    // What Copy trait??
    // It is bicopy trait of value!

    // What Clone trait?
    // I think it is associated with object copy so clone is different with
    // copy trait that is copy of variable's value!

    // let r = 1..4;
    // for i in r.into_iter() {
    //     println!('{}', i);
    // }
}