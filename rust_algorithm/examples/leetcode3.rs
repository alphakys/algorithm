#![allow(unused)]


use std::cell::RefCell;
use std::collections::HashSet;

fn main() {

    let s = String::from("pwwkew");
    let bytes = s.as_bytes();

    let mut pivot = 0;
    // not mutable and just reading variable
    let mut set = HashSet::new();
    let mut answer = 0;
    while pivot < bytes.len() {

        set.insert(bytes[pivot]);
        let mut left: i32 = pivot as i32 - 1;
        let mut right = pivot + 1;

        loop {
            match (bytes.get(left as usize), bytes.get(right)) {
                (Some(&l), Some(&r))=> {
                    if set.insert(l) && set.insert(r) == false{
                        break
                    }
                },
                (Some(&l), None)=> {
                    if set.insert(l) == false { break };
                },
                (None, Some(&r))=> {
                    if set.insert(r) == false { break };
                },
                _ => { break },

            }
            left -= 1;
            right += 1;
        }
        left = if left < 0 {0} else {left};
        println!("{left} {right}", );
        pivot += 1;
    }











    // let inner = if data.borrow().is_none() {
    //     let d = 1337;
    //     *data.borrow_mut() = Some(d);
    //     d
    // } else {
    //     data.borrow().unwrap()
    // };
    //
    // let s: String = String::from("abcbbcbb");
    //
    // let mut str_slice = s.as_bytes();
    //
    // let mut max_length = 0;
    // // left pointer
    // let mut left = 0;
    // // right pointer
    // let mut right = 0;
    //
    // let mut set: HashSet<u8> = HashSet::new();
    // while right < str_slice.len() {
    //     // get이 immutable borrow인 부분에 대해서는 너무 이해가 간다.
    //     // get을 통해서 element를 return 받았는데 만약에 그 사이에 mut borrow를 통해서
    //     // 값이 바뀌었다면 어떻게 할 것인가에 대해서 생각할 필요가 있다.
    //     let result = set.get(&str_slice[right]);
    //
    //     if result.is_some(){
    //         if max_length < set.len() { max_length = set.len(); }
    //
    //         while str_slice[left] != *result.unwrap() {
    //             // remove all elements e for which f(&e) Imp` returns false
    //             set = { set.remove(&str_slice[left]); set };
    //             left += 1;
    //         }
    //     }
    //     else{
    //         set.insert(str_slice[right]);
    //     }
    //
    //     right += 1;
    // }



    // let mut answer = vec![];
    //
    // let mut i = 0;
    // let mut max_length = 0;
    // for &c in str_slice {
    //     match answer.iter().position(|x| *x == c) {
    //
    //         Some(t) => {
    //             if max_length < answer.len() { max_length = answer.len(); }
    //             answer.drain(..=t);
    //             answer.push(c);
    //
    //         },
    //         None => {
    //             answer.push(c);
    //
    //         }
    //     }
    //     i += 1;
    // }
    //
    // if answer.len() > max_length { max_length = answer.len(); }
    // println!("{max_length}", );

}