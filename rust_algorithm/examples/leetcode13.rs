#![allow(unused)]
use std::collections::HashMap;

fn main() {

    let s: String = String::from("MDCXCV");
    let s_replaced = s.replace("IV", "IIII")
        .replace("IX", "VIIII")
        .replace("XL", "XXXX")
        .replace("XC", "LXXXX")
        .replace("CD", "CCCC")
        .replace("CM", "DCCCC");

    let answer = s_replaced.as_bytes().iter().fold(0, |acc, &u|{
        (match u {
            b'I' => 1,
            b'V' => 5,
            b'X' => 10,
            b'L' => 50,
            b'C' => 100,
            b'D' => 500,
            b'M' => 1000,
            _ => 0,
        }) + acc
    });

    println!("{answer}", );


    // let bytes = s.as_bytes();
    // let mut map = HashMap::new();
    //
    // map.insert(b'I',1);
    // map.insert(b'V',5);
    // map.insert(b'X',10);
    // map.insert(b'L',50);
    // map.insert(b'C',100);
    // map.insert(b'D',500);
    // map.insert(b'M',1000);
    //
    // // slicing 할 경우, u8로 변환됨
    // let mut answer = 0;
    // let mut curr = 0;
    // let mut next = 0;
    // let mut i = 0;
    // while i < bytes.len(){
    //
    //     curr = *map.get(&bytes[i]).unwrap();
    //     if let Some(c) = bytes.get(i + 1) {
    //         next = *map.get(c).unwrap();
    //     }else {
    //         next = 0;
    //     }
    //
    //     if curr < next {
    //         answer += next - curr;
    //         i +=1;
    //     }
    //     else {
    //         answer += curr;
    //     }
    //     i += 1;
    // }
    //
    // println!("{answer}", );



}