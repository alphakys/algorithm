#![allow(unused)]

use std::process::exit;

fn main() {
    let str1 = String::from("ABCABC");
    let str2 = String::from("ABC");


    /// str1과 str2가 교환법칙이 성립한다는 것은 최대공약수가 있다는 것이니
    /// 두 string의 length를 가지고 최대공약수를 구하고 그 값으로 slicing 하면 된다.
    let mut str_slice1 = &str1[..];
    let mut str_slice2 = &str2[..];

    let mut len1 = str_slice1.len();
    let mut len2 = str_slice2.len();

    let mut answer = "";

    loop  {

        if str_slice1 == "" {
            answer = str_slice2;
            break;
        }
        if str_slice2 == "" {
            answer = str_slice1;
            break;
        }

        if len1 > len2 {
            if str_slice1.starts_with(str_slice2) {
                str_slice1 = &str_slice1[len2..];
            }
            else { break }
        } else {

            if str_slice2.starts_with(str_slice1) {
                str_slice2 = &str_slice2[len1..];
            }
            else { break }
        }

        len1 = str_slice1.len();
        len2 = str_slice2.len();

    }

    println!("{}", answer.to_string());

}