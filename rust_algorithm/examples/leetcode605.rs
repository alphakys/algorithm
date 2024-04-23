#![allow(unused)]

use std::process::exit;

fn main() {
    let mut flowerbed: Vec<i32> = vec![1,0,0,0,1,0,0,0,1,1,0,0,1,1];

    // [1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1]
    // [[], [], [], [0, 0, 0, 0], [0, 0], []]

    let mut n: i32 = 2;

    let col: Vec<_> = flowerbed.split(|&n| n == 1).collect();
    println!("{:?}", col);

    // if flowerbed.len() == 1 && flowerbed[0] == 0 { println!("1");}
    // [1,0,0,0,0,0,0,0,0,0,1]
    // 2 4 6 8
    // an = a + (n-1)*d
    // an - a = (n -1)*d
    // (an - a)/d = n - 1
    // (an - a)/d + 1 = n;

    // 1 0 0 0 0 0 1 => 2
    // 0 0 0 0 0 0 1 => 3
    // 0 0 0 0 0 0 0 => 4

    // let mut pivot = 0;
    // let mut fold = 0;
    // while pivot < flowerbed.len() {
    //     fold += flowerbed[pivot];
    //     if flowerbed[pivot] == 0 {
    //         let mut ptr = pivot;
    //         let mut cnt = 0;
    //
    //         while ptr < flowerbed.len() && flowerbed[ptr] == 0 {
    //             cnt += 1;
    //             ptr += 1;
    //         }
    //
    //         if flowerbed[ptr] == 0 {
    //
    //         }
    //         else {
    //
    //         }
    //         // println!("{pivot} {cnt } {ptr}", );
    //         pivot = ptr;
    //         if cnt == 1 { continue; }
    //         if fold >0 {}
    //         n -= (cnt - 2) / 2 + 1;
    //         // println!("{}", (cnt - 2)/2 + 1);
    //         // println!("{}", -1/2);
    //     }
    //     pivot += 1;
    // }
    //
    // println!("{}", n <= 0);

    // flowerbed.push(0);
    // flowerbed.insert(0,0);
    //
    // println!("{:?}", flowerbed);
    //
    // println!("{:?}", flowerbed.split(|&c| c == 1).collect::<Vec<_>>());
    // let mut split = flowerbed.split(|&c| c == 1).
    //                     map(|v| (v.len() - 1) / 2);
    //
    // println!("{:?}", split.next());
    // println!("{:?}", split.next());

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