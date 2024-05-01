#![allow(unused)]
fn main() {
    let n: i32 = 1;

    let mut answer: i32 = 0;
    let mut max = n;
    let mut min = 2;

    if n > 2 {

        loop {
            if max % min == 0 {
                answer = min;
                break
            } else {
                let tmp = min;
                min = max % min;
                max = tmp;
            }
        }
    }
    else {
        answer = n;
    }

    println!("{}", answer * (n/answer) * (2/answer));
}