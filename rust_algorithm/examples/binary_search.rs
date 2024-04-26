#![allow(unused)]

fn binary_search(v: &Vec<i32>, target: i32) -> Result<usize, usize> {
    let mut left: i32 = 0;
    let mut right: i32 = v.len() as i32;
    let mut mid = (left + right) / 2;

    let mut result = Err(0);
    while left < right {
        if v[mid as usize] == target {
            result = Ok(mid as usize);
            break;
        } else if v[mid as usize] > target {
            right = mid;
        } else {
            left = mid + 1;
        }

        mid = (left + right) / 2;
    }

    match result {
        Ok(t) => result,
        Err(e) => Err(mid as usize),
    }
}

fn lower_bound(v: &Vec<i32>, target: i32) -> usize {
    // lower bound 란?
    // 같은 element가 반복될 때, 반복되는 element 중에서 처음 시작하는 index를 lower bound라 한다.
    // idx -1 < target <= idx
    let mut left: i32 = 0;
    let mut right: i32 = v.len() as i32;
    let mut mid = (left + right) / 2;

    // [2, 3, 3, 3, 3, 5, 7, 9, 10, 18, 101]
    //  0  1  2  3  4  5  6  7  8   9   10
    let mut i = 0;
    while left < right {
        if v[mid as usize] == target {
            right = mid;
        } else if v[mid as usize] > target {
            right = mid;
        } else {
            left = mid + 1;
        }

        mid = (left + right) / 2;
    }

    mid as usize
}

fn upper_bound(v: &Vec<i32>, target: i32) -> usize {
    // lower bound 란?
    // 같은 element가 반복될 때, 반복되는 element 중에서 처음 시작하는 index를 lower bound라 한다.
    // idx -1 < target <= idx
    let mut left: i32 = 0;
    let mut right: i32 = v.len() as i32;
    let mut mid = (left + right) / 2;

    // [2, 3, 3, 3, 3, 5, 7, 9, 10, 18, 101]
    //  0  1  2  3  4  5  6  7  8   9   10
    let mut i = 0;
    while left < right {
        if v[mid as usize] == target {
            left = mid + 1;
        } else if v[mid as usize] > target {
            right = mid;
        } else {
            left = mid + 1;
        }

        mid = (left + right) / 2;
    }

    mid as usize
}


fn main() {
    let mut v: Vec<i32> = vec![2, 2, 2, 3, 3, 3, 3, 5, 7, 7, 7, 7, 9, 10, 18, 18, 101];

    let result = upper_bound(&v, 3);

    let r = v.binary_search_by(|probe| probe.cmp(&3));

    println!("{:?}", result);
    println!("{:?}", r);
}


