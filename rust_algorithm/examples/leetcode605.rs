#![allow(unused)]

use std::process::exit;

fn main()  {
    let mut flowerbed: Vec<i32> = vec![1,1,1,0,0,1,0,0];
    let mut n: i32 = 1;

    flowerbed.push(0);
    flowerbed.insert(0,0);

    println!("{:?}", flowerbed);

    println!("{:?}", flowerbed.split(|&c| c == 1).collect::<Vec<_>>());
    let mut split = flowerbed.split(|&c| c == 1).
                        map(|v| (v.len() - 1) / 2);

    println!("{:?}", split.next());
    println!("{:?}", split.next());

    // match flowerbed.len() {
    //     1 if flowerbed[0] == 0 => { println!("{}", true); exit(1)},
    //     _ => ()
    // }
    //
    // let len = flowerbed.len() - 1;
    //
    // let mut idx: usize = 0;
    //
    // while idx < flowerbed.len() {
    //
    //     if flowerbed[idx] == 1 {
    //         idx += 1;
    //         continue;
    //     }
    //
    //     if idx == 0 {
    //         if flowerbed[idx + 1] == 0 { n -= 1; flowerbed[idx] = 1; }
    //
    //     } else if idx == len {
    //         if flowerbed[idx - 1] == 0 { n -= 1; flowerbed[idx] = 1;}
    //     } else {
    //         if flowerbed[idx - 1] == 0 && flowerbed[idx + 1] == 0 {
    //             n -= 1;
    //             flowerbed[idx] = 1;
    //         }
    //     }
    //     println!("{:?}", flowerbed);
    //     if n == 0 { break; }
    //     idx += 1;
    // }
    //
    //
    // println!("{}", n == 0);
}