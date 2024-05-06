#![allow(unused)]

fn quick_sort(v: &mut Vec<i32>, start: i32, end: usize) {
    let mut left = start + 1;
    let mut right = end;

    if left > end as i32 { return; }

    let pivot = v[start as usize];

    loop {
        while left <= right as i32 && v[left as usize] <= pivot { left += 1; }
        while left <= right as i32 && v[right] >= pivot { right -= 1; }

        if left > right as i32 {
            v.swap(start as usize, right);
            break;
        }
        v.swap(left as usize, right);
    }

    quick_sort(v, start, right - 1);
    quick_sort(v, (right + 1) as i32, end);
}

fn main() {
    let mut v = vec![43, 23, 333, 5, 78, 45, 3, 4, 78, 9, 5, 3, 1, 11];

    let end = v.len() - 1;
    quick_sort(&mut v, 0, end);

    println!("{:?}", v);
}