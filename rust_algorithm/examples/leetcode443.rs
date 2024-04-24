#![allow(unused)]

use std::ffi::c_char;

fn main() {
    let mut chars: &mut Vec<char> = &mut vec!['a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                              'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
    ];


    let mut ascii = [0; 128];

    let mut i = 0;
    let mut curr = chars[0];
    let mut answer: Vec<char> = Vec::new();
    while i < chars.len() {
        if curr == chars[i] {
            ascii[curr as usize] += 1;
        } else {
            answer.push(curr);
            let mut c = ascii[curr as usize] as u8;

            // c += 10;
            if c != 1 {
                answer.append(&mut c.to_string().chars().collect::<Vec<char>>());
            }

            curr = chars[i];
            ascii[curr as usize] = 1;
        }

        i += 1;
    }

    answer.push(curr);
    let mut c = ascii[curr as usize] as usize;

    println!("{:?}", c);
    if c != 1 {
        answer.append(&mut c.to_string().chars().collect::<Vec<char>>());
    }

    chars.clear();
    chars.append(&mut answer);

    println!("{:?}", chars);
    println!("{:?}", chars.len());
}