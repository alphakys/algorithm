#![allow(unused)]

fn split_func(){
    // while window < str1.len() {
    //
    //     let mut pivot: i32 = window as i32;
    //     println!("pivot : {pivot}", );
    //     while pivot > -1 {
    //
    //         if str1_bytes[pivot as usize] == str2_bytes[pivot as usize] { pivot -= 1; }
    //         else { break }
    //
    //     }
    //
    //     if pivot == 0 {
    //         println!("contain", );
    //     }
    //     window += 1;
    // }

}
fn main() {
    let mut str1 = String::from("ABABAB");
    let mut str2 = String::from("l");

    let mut stop = 1;
    loop {
        let mut greater_str = &str1;
        if str1.len() < str2.len() {
            greater_str = &str2;

            let split_str = greater_str.split(&str1).fold(String::from(""), |acc, s| {
                match s {
                    "" => { format!("") },
                    _ => { format!("{}{}", acc, s) }
                }
            });

            str2 = split_str;

        }
        else {
            greater_str = &str1;

            let split_str = greater_str.split(&str2).fold(String::from(""), |acc, s| {
                match s {
                    "" => { format!("") },
                    _ => { format!("{}{}", acc, s) }
                }
            });
            str1 = split_str;
        }

        println!("str1 : {} str2 : {}", str1, str2);
        if str1 == "" || str2 == "" { break }

        if stop == 4 { break }
        stop +=1;

    }





}