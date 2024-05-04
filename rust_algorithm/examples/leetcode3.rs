#![allow(unused)]


fn main() {

    let s: String = String::from("abcabcbb");

    let mut str_slice = s.as_bytes();
    let mut hashmap = [-1; 128];

    for (i, &c) in str_slice.iter().enumerate() {
        if hashmap[c] > -1 {

        }
        else {
            hashmap[c] = i;
        }

    }


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