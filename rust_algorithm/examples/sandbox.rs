#![allow(unused)]

use std::cmp::Ordering;
use std::collections::VecDeque;
use std::ffi::c_char;
use std::mem::size_of_val;
use std::ops::{Range, Sub};

#[derive(Debug, Clone, Copy)]
struct Foo;


fn main() {

    // string interning
    // 취지: string type은 프로그래밍 언어에서 가장 많이 쓰이는 type이라고 해도 과언이 아니다.
    /// 하지만 많이 쓰이는 만큼 문자열에서 심각한 performance overhead가 발생할 가능성이 높다고 할 수 있다.
    /// 이를 방지하기 위해 string interning 이라는 방식을 통해서 string의 최적화를 도모한다.
    /// string interning 이란 문자열의 원본 하나를 저장하고 똑같은 문자열의 생성 요청이 있더라도 같은 문자열이라면 기존에
    /// 저장되어 있는 문자열을 사용한다는 것을 말한다ㅏ.
    ///
    /// 이 방식을 통해서 똑같은 문자열의 copy 본을 여러개 만드는 비효율을 줄일 수 있다.
    ///
    /// 그렇다면 string interning은 single instance를 가지고 반복 사용한다는 것인데 이를 위해서는 검색 기능이 필수일 것이다.
    /// 검색은 어떻게 이뤄질 것인가? dictionary의 key - value 방식을 통해서 검색이 이뤄진다.
    /// hashing 된 키를 사용하여 검색하기 때문에 time-complexity는 O(1)이다. 아주 효율적으로 검색할 수 있다.
    /// 대신 hashing을 사용하기 때문에 무작위적으로 string interning 을 사용할 수는 없다.

    /// String literals are string slices
    /// let hello = "Hello World";
    /// Here we have declared a string slice initialized with a string literal.
    /// String literals have a static lifetime, which means the string hello_wrold is guarateed
    /// to be vaild for the duration of the entire program. We can explicitly specify hello_world
    /// lifetime as well.
    ///
    /// let hello: '&static str = "Hello world";
    ///
    /// 왜 as_bytes를 쓰라고 하는지 이제 이해가 된다.
    /// 그 이유는 string literal(string interning)의 str은 string literal의 slice object이기 때문에
    /// 즉 ptr와 len으로 이루어진 object이기 때문에 str index 사이의 비교라는 것은 결국 memory address의
    /// 비교이기 때문에 그 본질적인 값의 비교가 될 수 없다. 따라서 as_bytes를 통해서 byte 값으로 비교를
    /// 해라고 compiler가 말해주는 것이다.

    let mut s = VecDeque::new();

    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    println!("{:?}", s);

    println!("{}", s.pop_front().unwrap());

}