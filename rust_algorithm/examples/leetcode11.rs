#![allow(unused)]
fn main() {
    let mut height: Vec<i32> = vec![1,8,6,2,5,4,8,3,7];

    let mut st = 0;
    let mut end: i32 = height.len() as i32 - 1;

    let mut base = end - st;
    let mut v = 0;

    let mut max = 0;

    if height[st] > height[end] {
        v = height[end];
    }
    else {
        v = height[st];
    }

    let area = base * v;

    if max < area {
        max = area;
    }

}