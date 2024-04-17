#![allow(unused)]
fn main() {

    let mut flowerbed: Vec<i32> = vec![0,0,0,0,0];
    let mut n: i32 = 2;

    let len = flowerbed.len() - 1;

    let mut idx: usize = 0;

    while idx < len + 1 {

        if flowerbed[idx] == 1 { idx += 1; continue }

        match idx {
            0 if flowerbed[idx + 1] == 0  => {  println!("check1", ); n -=1; flowerbed[idx] = 1; },
            len if flowerbed[idx - 1] == 0 => { println!("check2", ); n -= 1; flowerbed[idx] = 1; },
            _ => {
                if flowerbed[idx - 1] == 0 && flowerbed[idx + 1] == 0 { println!("check3", ); n -= 1; flowerbed[idx] = 1; }
            },
        }

        println!("{:? } {}", flowerbed, idx);

        if n == 0 { break }
        idx += 1;
    }


    println!("{}", n == 0);
}