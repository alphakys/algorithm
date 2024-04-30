#![allow(unused)]
fn main() {
    let word1: String = String::from("abc");
    let word2: String = String::from("word2");

    let mut answer = String::new();

    let mut zip = word1.chars().zip(word2.chars());

    for z in zip {
        println!("{:?}", z);
    }
    // let mut itr1 = word1.chars();
    // let mut itr2 = word2.chars();
    // let mut i = 0;
    // loop {
    //
    //     match (itr1.next(), itr2.next()) {
    //         (Some(c1), Some(c2)) => {
    //             answer.push(c1);
    //             answer.push(c2);
    //         },
    //         (Some(c1), None) => {
    //             answer.push(c1);
    //         },
    //         (None, Some(c2)) => {
    //             answer.push(c2);
    //         },
    //         _ => {
    //             break
    //         }
    //     }
    // }

    println!("{answer}", );


}