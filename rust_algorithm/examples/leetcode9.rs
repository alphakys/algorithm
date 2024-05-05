#![allow(unused)]

fn main() {
    let mut x: i32 = 1221;
    let mut answer = x;
    let mut reverse_num = 0;

    while x != 0 {
        reverse_num *= 10;
        reverse_num += x%10;
        x /= 10;
    }

    if reverse_num < 0 {
        println!("{}", true);
    }
    else {
        println!("{} {}", reverse_num, answer - reverse_num == 0);
    }

}