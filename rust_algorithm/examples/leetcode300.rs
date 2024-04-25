#![allow(unused)]
fn main() {
    let nums = vec![10,9,2,5,3,7,101,18];
    let mut lis = vec![i32::MAX; nums.len()];

    for x in nums {

        for y in lis.iter_mut() {
            if *y >= x {
                *y = x;
                break
            }
        }
    }

    let mut answer: i32 = 0;

    lis.iter().for_each(|&n|{
        if n != i32::MAX { answer += 1; }
    });

    println!("{answer}", );
}