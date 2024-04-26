#![allow(unused)]
fn main() {
    let mut nums: Vec<i32> = vec![1,2,3,4];
    let k = 6;
    nums.sort();

    // [3,1,3,4,3]
    // [3,5,3,2,3]

    // [1, 3, 3, 3, 4]
    let mut i = 0;
    let mut cnt = 0;
    while i < nums.len() {
        match &nums.binary_search(&(k - nums[i])){
            Ok(t) => {
                // println!("{} {}", nums[i], k - nums[i]);
                nums.remove(i);
                println!("{t}", );
                nums.remove(*t);
                cnt += 1;
            },
            _ => (),
        }
        i += 1;
        
    }

    println!("{cnt}", );
}