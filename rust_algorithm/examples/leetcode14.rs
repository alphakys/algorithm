#![allow(unused)]

fn find_prefix<'a>(s1: &'a str, s2: &str) -> &'a str {
    let b1 = s1.as_bytes();
    let b2 = s2.as_bytes();

    let mut i = 0;
    let mut cnt = if s2.len() > s1.len() { s1.len() } else { s2.len() };
    let mut prefix = "";
    while i < cnt {
        if b1[i] == b2[i] {
            prefix = &s1[..=i];
            i += 1;
        } else {
            break;
        }
    }
    return prefix;
}

fn main() {
    let mut strs = vec![String::from("reflower"), String::from("flow"), String::from("flight")];
    if strs.len() == 1 { println!("{}", strs[0]); }

    let mut i = 1;
    let mut prefix = "";
    while i < strs.len() {
        if i == 1{
            prefix = find_prefix(&strs[i -1], &strs[i]);
        }
        else {
            prefix = find_prefix(prefix, &strs[i]);
        }

        i += 1;
    }

    println!("{}", prefix.to_string());
}