#![allow(unused)]

fn main() {
    let mut digits = vec![9];

    let mut i: i32 = digits.len() as i32 - 1;
    let mut carry = 0;

    let mut sum = carry + digits[i as usize] + 1;
    carry = i32::from(sum == 10);

    while i >= 0 {

        if i == 0 {
            match carry {
                1 => {
                    digits.insert(0,1);
                },
                _ => break
            }
        }

        if carry ==0 {
            break
        }
        else{
            digits[i as usize] = 0;
        }
        i -= 1;

        sum = carry + digits[i as usize];
        carry = i32::from(sum ==10);

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