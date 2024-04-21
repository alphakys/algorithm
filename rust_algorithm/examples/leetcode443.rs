#![allow(unused)]

use std::ffi::c_char;

fn main() {
    let mut chars: Vec<char> = vec!['a','a','b','b','c','c','c', 'a', 'a', 'a'];
    let mut ascii = [-1; 128];

    let mut left: i32 = 0;
    let mut right: i32 = (chars.len() - 1) as i32;

    let mut lidx = 0;
    let mut ridx = 0;

    let mut cnt = 1;
    let mut i = 0;
    while left <= right {
        lidx = chars[left as usize] as usize;
        ridx = chars[right as usize] as usize;

        if ascii[lidx] == -1 { cnt = 1; }
        else { cnt += 1; }
        ascii[lidx] = i;

        if left == right { ascii[lidx] += 1; break }

        // ascii[lidx] += 1;
        //
        // ascii[ridx] += 1;

        left += 1;
        right -= 1;
        i += 1;
    }

    chars.clear();
    let mut answer = 0;
    ascii.iter().enumerate().for_each(| (idx, &n) | {
        match n {
            0 => { },
            1=> {
                chars.push((idx as u8) as char);
                answer += 1;
            }
            _ => {

                chars.push((idx as u8) as char);
                n.to_string().chars().for_each(|c| { chars.push(c); answer += 1; });

            },
        }

    });

    println!("{} {:?}", chars.len(), chars);

}