#![allow(unused)]
fn main() {
    let n = 4;

    let mut answer = -1;
    for i in 1..=n {
        // 초항은 left sum에서 1
        let left_sum = |i| i * (1 + i) / 2;
        // right sum에서 초항은 i 자신
        let right_sum = |i| (n - i + 1) * (i + n) / 2;

        // 1 2 3 4
        println!("{} {}", left_sum(i), right_sum(i));
        if left_sum(i) == right_sum(i) { answer = i; break; }
    }

    println!("{answer}", );
}