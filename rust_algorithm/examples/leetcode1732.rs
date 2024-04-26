#![allow(unused)]
fn main() {
    let mut gain: Vec<i32> = vec![1];

    let mut max_gain = 0;
    let r = gain.iter().fold(0, |acc, g| {
        if acc + g > max_gain { max_gain = acc + g }
        acc + g
    });

    println!("{r} {}", max_gain);

}