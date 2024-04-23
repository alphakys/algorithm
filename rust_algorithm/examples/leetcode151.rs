#![allow(unused)]
fn main() {

    let s = String::from("  hello world  ");

    let mut answer: Vec<_> = s.split(" ").filter(|&w| w != "").collect();
    answer.reverse();

    println!("{:?}", answer.join(" "));

    //
    // let mut v: Vec<_> = s.split_whitespace().
    //     collect();
    //
    // let mut left = 0;
    // let mut right: i32 = v.len() as i32 - 1;
    //
    // let mut stop = 1;
    // loop {
    //     if left > right { break }
    //
    //     v.swap(left as usize ,right as usize);
    //     left += 1;
    //     right -= 1;
    //
    //     if stop ==5 { break }
    //     stop += 1;
    // }
    //
    // let answer = v.join(" ");
    // // v.iter().for_each(|&str_literal| {
    // //                                     answer.push_str(str_literal);
    // //                                     answer.push_str(" ");
    // //                                 });
    //
    // println!("{}", answer);


}
