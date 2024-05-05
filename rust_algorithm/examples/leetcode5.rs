#![allow(unused)]
#![allow(non_snake_case)]

use std::collections::VecDeque;

fn main() {
    // Imp` substring is a contiguous sequence of characters within a larger string.
    let s = String::from("abbazezalphaduethoohbookkoob");
    // abbazezalphaduethoohbookkoob

    let mut left = 0;
    let mut right = s.len() - 1;

    let mut answer = String::new();
    while left < right {
        println!("left! : {} {}", &s[left..left + 1], left);

        while left < right {
            println!("{} {}", &s[right - 1..right], s.starts_with(&s[right - 1..right]));
            println!("right : {}", right);

            if s[left..].starts_with(&s[right - 1..right]) {

                println!("gotcha! : {:?}", &s[left..right]);
                if *&s[left..right].ends_with(&s[left..right]) {
                    if answer.len() < *&s[left..right].len(){
                        answer.clear();
                        answer.push_str(&s[left..right]);
                    }
                }

            }
            right -= 1;
        }
        right = s.len() - 1;
        left += 1;
        println!("\n", );
    }

    println!("{answer}", );
}