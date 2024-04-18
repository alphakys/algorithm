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
//     println!("{:p}", selff);
//
//     let cl = selff.as_bytes().to_owned();
//
//     println!("{:p}", *cl);
//     String::new()
// }


use std::ops::Range;

#[derive(Debug, Clone, Copy)]
struct Foo;

fn movee(x: [u8; 3]) {
    println!("{:?}", x);
}


fn main() {
    let b = Box::new(1);
    let c = Box::new(2);

    let cl = b.clone();
    // 내 생각이 맞았다.
    // 결국 Rc -> Reference Counting memory allocation가 일종의 shallow copy이다.

    assert_eq!(&b, &cl);


    println!("b : {:p}", b);
    println!("cl {:p}", cl);
    println!("b ref : {:p}", &b);
    println!("c : {:p}", c);


    let x = Foo;
    let y = x;

    println!("{:?}", x);
    // What Copy trait??
    // It is bicopy trait of value!

    // What Clone trait?
    // I think it is associated with object copy so clone is different with
    // copy trait that is copy of variable's value!

    // let r = 1..4;
    // for i in r.into_iter() {
    //     println!("{}", i);
    // }
}