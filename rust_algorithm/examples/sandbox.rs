
#![allow(unused)]

// Converts a &str into a String
// The result is allocated on the heap
pub fn from(s: &str) -> String {
    to_own(s)
}


#[inline]
pub fn to_own(selff: &str) -> String {
    println!("{:p}", selff);

    let cl = selff.as_bytes().to_owned();

    println!("{:p}", *cl);
    String::new()
}


fn main() {

    let s = from("sfd");


}