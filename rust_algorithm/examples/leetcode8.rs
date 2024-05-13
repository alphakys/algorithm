#![allow(unused)]

fn main() {

    let s = String::from("-2147483648");
    let s = s.trim_start();

    let (s, sign) = match s.strip_prefix('-'){
        Some(t)=> {
            (t , 1)
        },
        None => {
            (&s[..], -1)
        },
    };

    println!("{s} {sign}", );


    //
    // if trim_str.len() == 0 { println!("return {}", 0); }
    //
    // let mut i = 0;
    // let mut is_signed= 1;
    // let mut start = 0;
    // match &trim_str[0..=0].as_bytes()[0] {
    //     45 => { is_signed = -1; start = 1; },
    //     43 => { start = 1; },
    //     48..= 57 => {},
    //     _ => { println!("end : {}", 0);},
    // }
    //
    // let mut answer: i32 = 0;
    // for &c in trim_str[start..].as_bytes(){
    //
    //     match c {
    //        48..= 57 => {
    //            // 2147483647
    //            // println!("{}",);
    //            if ((i32::MAX / 10) - answer + i32::MAX%10 - (c as i32 -48)) < 0{
    //
    //                if is_signed > 0 {
    //
    //                    answer = i32::MAX;
    //                }
    //                else {
    //                    answer = i32::MIN;
    //                    is_signed = 1;
    //                }
    //
    //                break
    //            }
    //
    //            // 1의 자릿수를 빼고 비교를 해볼까?
    //            answer *= 10;
    //            answer += c as i32 - 48;
    //        }
    //        _ => {
    //
    //            break
    //        }
    //     }
    //
    // }
    //
    // println!("{}", answer * is_signed);


}