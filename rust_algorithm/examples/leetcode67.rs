#![allow(unused)]

fn main() {
    let mut a = String::from("1010");
    let mut b = String::from("1011");

    let mut ia = a.pop();
    let mut ib = b.pop();

    let mut sum = 0;
    let mut carry = 0;
    let mut answer = vec![];
    while ia.is_some() || ib.is_some() || carry == 1{
        match (ia, ib) {
            (Some(t1), Some(t2)) => {
                sum = t1 as u8 - 48 + t2 as u8 - 48 + carry;
            }
            (Some(t1), None) => {
                sum = t1 as u8 - 48 + carry;
            }
            (None, Some(t2)) => {
                sum = t2 as u8 - 48 + carry;
            }
            _ => {
                answer.push(49); break
            }
        }
        carry = sum / 2;
        answer.push((sum % 2) + 48);

        ia = a.pop();
        ib = b.pop()

    }
    answer.reverse();
    println!("{:?}", String::from_utf8(answer));

    // let mut inta = a.parse::<i32>().unwrap();
    // let mut intb = b.parse::<i32>().unwrap();
    //
    // let mut carry = 0;
    // let mut sum = 0;
    // let mut answer: Vec<u8> = vec![];
    // while inta != 0 || intb != 0 || carry == 1 {
    //     sum = carry + inta % 10 + intb % 10;
    //     carry = sum / 2;
    //     answer.push((sum % 2 + 48) as u8);
    //
    //     inta /= 10;
    //     intb /= 10;
    // }
    // answer.reverse();
    // String::from_utf8(answer);
}