#![allow(unused)]
fn main() {

    let s: String = String::from("Hello world");
    let s1: String = String::from("   fly me   to   the moon  ");
    let s2: String = String::from(" ");

    let answer = s.trim_end().bytes().rev().take_while(|&c| c != b' ').count();

    println!("{:?}", answer);



    // let mut i = 0;
    // let mut cnt = 0;
    // let mut answer = 0;
    // while i < s.len() {
    //     if &s[i..=i] == " " {
    //         cnt = 0;
    //         i += 1;
    //         continue
    //     }
    //
    //     cnt +=1;
    //     answer = cnt;
    //     i +=1;
    // }
    //
    // println!("{answer}", );

}