#![allow(unused)]

fn main() {
    let mut digits = vec![1];

    let mut i: i32 = digits.len() as i32 - 1;
    let mut carry = 0;

    let mut sum = carry + digits[i as usize] + 1;
    carry = i32::from(sum == 10);
    digits[i as usize] = sum % 10;

    while i >= 0 && carry == 1 {
        if i ==0 {
            digits.insert(0, 1);
            break
        }
        i -=1;
        sum = carry + digits[i as usize];
        digits[i as usize] = sum % 10;
        carry = i32::from(sum == 10);
    }

    println!("{:?}", digits);
    // let itr = digits.iter().rev().take_while(|&&n| {
    //     if (n + 1) / 10 == 1 {
    //         println!("{}", n + 1);
    //         true
    //     } else {
    //         false
    //     }
    // });
    //
    // for d in itr {
    //     println!("{d}", );
    // }
}