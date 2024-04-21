#![allow(unused)]

use std::ops::Index;

fn main() {
    let s = String::from("abczx");
    let t = String::from("qwwcahbgdczxx");

    for (i, c) in s.bytes().enumerate(){
        println!("{}", &t.contains(c as char));


    }


}