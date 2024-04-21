#![allow(unused)]
fn main() {
    let word1: String = String::from("abc");
    let word2: String = String::from("word2");

    let words1 = word1.as_bytes();
    let words2 = word2.as_bytes();

    let mut i = 0;

    let limit = words1.len().max(words2.len());

    let mut answer: Vec<u8> = Vec::new();

    while i < limit {

        if words1.get(i).is_some() { answer.push(words1[i]); }
        if words2.get(i).is_some() { answer.push(words2[i]); }
        i+= 1;

    }
    println!("{:?}", String::from_utf8(answer).unwrap());
    // while litr.next() {
    //
    //     // break 조건문 추가
    //     // i += 1;
    //
    // }

}