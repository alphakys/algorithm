#![allow(unused)]
#![allow(non_snake_case)]

use std::io;


fn heap_push(v: &mut Vec<isize>, val: isize) -> &mut Vec<isize> {

    v.push(val);

    let mut curr = v.len() - 1;
    let mut parent = curr / 2;
    while parent >= 1  {

        if v[parent] < v[curr] {
            v.swap(parent, curr);
            curr = parent;
        }
        else{
            break
        }

        parent = curr / 2;
    }
    return v
}

fn heap_pop(v: &mut Vec<isize>) -> Option<isize> {

    if v.len() == 1 {
        return None;
    }
    else if v.len() == 2 { return v.pop(); }

    let ret = Some(v[1]);

    v[1] = v.pop().unwrap();

    let mut curr_idx: usize = 1;

    let mut left_child_idx: usize = curr_idx * 2;
    let mut right_child_idx: usize = curr_idx * 2 + 1;

    let length = v.len() - 1;

    while left_child_idx <= length {

        if left_child_idx == length {

            if v[left_child_idx] > v[curr_idx] {
                v.swap(curr_idx, left_child_idx);
                curr_idx = left_child_idx;
            }
            else {
                break;
            }

        }
        else {
            if v[left_child_idx] > v[right_child_idx] {

                if v[left_child_idx] > v[curr_idx] { v.swap(left_child_idx, curr_idx); curr_idx = left_child_idx; }
                else { break; }
            }
            else{
                if v[right_child_idx] > v[curr_idx] { v.swap(right_child_idx, curr_idx); curr_idx = right_child_idx; }
                else { break; }
            }

        }

        left_child_idx = curr_idx * 2;
        right_child_idx = curr_idx * 2 + 1;

    }

    return ret
}

fn main() {

    let mut buff = String::new();
    io::stdin().read_line(&mut buff);

    let N: usize = buff.trim().parse().unwrap();
    buff.clear();

    let mut answer = String::new();

    for _ in 0..N {
        io::stdin().read_line(&mut buff);
    }

    let lines: Vec<&str> = buff.trim_end().split("\n").collect();

    let mut h: Vec<isize> = Vec::from(vec![0]);

    for opcode in lines {
        if opcode == "0" {
            match heap_pop(&mut h) {
                Some(T) => answer.push_str(&format!("{}\n", T)),
                None => answer.push_str(&format!("0\n"))
            }
        }
        else {
            heap_push(&mut h, opcode.parse::<isize>().unwrap());
        }
    }

    println!("{}", answer);

}