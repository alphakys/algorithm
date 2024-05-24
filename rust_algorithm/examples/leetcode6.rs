#![allow(unused)]
fn main() {

    let s: String = String::from("PAYPALISHIRING");
    let num_rows: i32 = 1;

    let mut arr: Vec<Vec<&str>> = vec![];
    for _ in 0..num_rows{
        arr.push(vec![]);
    }

    let mut stopper = 0;
    let mut i = 0;

    while stopper < s.len(){

        while i < num_rows && stopper < s.len() {
            arr[i as usize].push(&s[stopper..=stopper]);
            i += 1;
            stopper += 1;
        }
        if stopper == s.len() { break }
        i -= 2;
        while 0 <= i && stopper < s.len() {
            arr[i as usize].push(&s[stopper..=stopper]);
            i -= 1;
            stopper += 1;
        }
        println!("{:?}", arr);
        if stopper == s.len() { break }
        i = 1;
        // 13
        println!("{stopper}", );
    }

    println!("{:?}", arr);

}
