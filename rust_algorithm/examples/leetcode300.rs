#![allow(unused)]

fn main() {
    let nums = vec![0,1,0,3,2,3];
    let mut buckets: Vec<Vec<i32>> = vec![vec![nums[0]]];

    for &n in &nums[1..] {

        for mut b in &mut buckets {

            // If the current number is greater than the last element of the answer
            // vector, it means we have found a longer increasing subsequence.
            // Hence, we append the current number to the answer vector.
            if *b.last().unwrap() < n { b.push(n); }
            else{
                // If the current number is not greater than the last element of the answer vector.
                // we perform a binary search to find the smallest element in the answer vector that
                // is greater than or equal to the current number.
            }

        }

    }


    // for x in nums {
    //
    //     for y in lis.iter_mut() {
    //         if *y >= x {
    //             *y = x;
    //             break
    //         }
    //     }
    // }
    //
    // let mut answer: i32 = 0;
    //
    // lis.iter().for_each(|&n|{
    //     if n != i32::MAX { answer += 1; }
    // });
    //
    // println!("{answer}", );
}