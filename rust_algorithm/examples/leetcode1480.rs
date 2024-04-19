#![allow(unused)]
fn main() {

    let mut v = vec![1];

    let mut sum = 0;

    for n in v.iter_mut() {
        sum += *n;
        *n = sum;
    }

    println!("{:?}", v);
}