#![allow(unused)]

use std::collections::{HashMap, HashSet};

fn main() {
    let arr = vec![1,2];

    let mut map: HashMap<i32, i32> = HashMap::new();
    let mut push_flag = false;
    for n in arr {

        match map.get_mut(&n){
            Some(v) => *v += 1,
            _ => { push_flag = true; },
        }

        if push_flag { map.insert(n, 1); push_flag = false; }

    }
    let mut set: HashSet<i32> = HashSet::new();

    let mut answer = true;
    for v in map.values() {
        if !set.insert(*v) {
            answer = false;
            break
        }
    }


    println!("{:?}", answer);
}