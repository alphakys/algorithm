#![allow(unused)]

use::std::cell::{RefCell,Ref};
fn main() {


    // Rerference Count는 multiple ownership을 위해 존재함.
    let v = RefCell::from(vec![1,2,3,3,4]);

    let vv = &mut v;

    println!("{:?}", vv);
}