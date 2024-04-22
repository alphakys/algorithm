#![allow(unused)]

use std::process::exit;

fn main() {
    let binding1 = String::from("ABABAB");
    let mut str1 = binding1.as_str();
    let binding2 = String::from("c");
    let mut str2 = binding2.as_str();

    let mut answer = "";

    // str1 = nGCD str2 = mGCD
    // str1 + str2 = (n+m)GCD
    // str2 + str1 = (n+m)GCD;

    loop {

        if str1.len() > str2.len() {

            match str1.starts_with(str2) {
                true => {
                    str1 = &str1[str2.len()..];
                    if str1 == "" { answer = str2; break }
                },
                false => {
                    break
                }
            }
        }
        else {

            match &str2.starts_with(&*str1) {
                true => {
                    str2 = &&str2[str1.len()..];
                    if str2 == "" { answer = str1; break }
                },
                false => {
                    break
                }
            }
        }
    }

    println!("{}", answer.to_string());

}