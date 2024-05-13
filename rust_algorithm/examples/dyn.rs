#![allow(unused)]
use async_std::{
    prelude::*, //prelude re-exports some traits required to work with futures and streams
    task, // The task module roughly corresponds to the std::thread module, but tasks are much lighter weight.
    // but tasks are much lighter weight. A single thread can run many tasks.

    net::{TcpListener, ToSocketAddrs},
    // For the socket type, we use TcpListener from async_std, which is just like std:net::TcpListener, but
    // is non-blocking and uses async Api.
    // We will skip implementing comprehensive error handling in this example
};

type Result<T> = std::result::Result<T, Box<dyn std::error::Error + Send + Sync>>;


/// dyn is a prefix of a trait object's type
/// The dyn keyword is used to highlight that calls to methods on the associated Trait
/// are dynamically dispatched. To use the trait this way, it must be object safe
/// Unlike generic parameters or impl Trait, the compiler does not know the concrete type that
/// is being passed. That is, the type has been erased. As such, a dyn Trait
/// reference contains two pointers. One pointer goes to the data .
/// Another pointer goes to a map of method call names to function pointers
///

type Meters = u32;
type Kilograms = u32;

trait Car {
    fn drive(&self);
}

// sedan structure that has car type
#[derive(Debug)]
struct Sedan;

impl Car for Sedan{
    fn drive(&self) {
        println!("Sedan can drive", );
    }
}

// suv structure that has car type
struct Suv;

impl Car for Suv{
    fn drive(&self) {
        println!("Suv can drive", );
    }
}

fn drive_car(car: impl Car){

    car.drive();
}

// 반환 타입의 impl Car를 구현하는 유일한 타입 하나를 리턴하겠다는 것을 의미합니다.
// 하지만 우리는 지금 Car를 구현하는 Sedan 타입 혹은 Car를 구현하는 Suv 둘 중 하나를
// 리턴하겠다고 선언했다.

/// 즉 현재 Rust 컴파일러가 컴파일 타임에 반환 타입을 결정할 수 없기 때문에 에러를 발생시키고
/// 아래와 같이 Box<dyn Car>를 사용하라는 도움말이 출력되는 것을 볼 수 있습니다.
fn get_car(is_sedan: bool) -> Box<dyn Car> {

    if is_sedan {
        Box::new(Sedan)
    }
    else {
        Box::new(Suv)
    }
}

// Trait object must include dyn keyword
// 정적 다형성을 구현한 것이다.
/// compile time에 Rust compiler는 drive car 함수의 인자로
/// sedan과 suv를 넘기는 것을 확인하고, sedan과 suv가 Car Trait을 구현했는지 검사함.
/// 결과적으로, 명확한 타입을 갖는 함수들이 추가되었고, 컴파일 타임에 어떤 함수를 호출할지가 결정되는
/// 정적 디스패치가 구현된 것입니다.
/// 함수의 parameter로 generic Trait을 받는다는 것은
/// 특정 struct or enum을 받는 게 아니라 그 상위의 (super) 값을 받음으로
/// abstract class 어떤 것이든지 받을 수 있는 확장성을 가지게 한다.
fn drive_trait<T: Car>(car: T){

    car.drive();

}


fn main() {
    let sedan = Sedan{};
    println!("{:?}", sedan);
    drive_car(sedan);

}


// type does not create a new type:
// type Meters = u32;
// type Kilograms = u32;
//
// let m: Meters = 3;
// let k: Kilograms = 3;
//
// assert_eq!(m, k);
//
// A type can be generic:
// type ArcMutex<T> = Arc<Mutex<T>>;
//
// In traits, type is used to declare an associated type:
// trait Iterator {
//     // associated type declaration
//     type Item;
//     fn next(&mut self) -> Option<Self::Item>;
// }
//
// struct Once<T>(Option<T>);
//
// impl<T> Iterator for Once<T> {
//     // associated type definition
//     type Item = T;
//     fn next(&mut self) -> Option<Self::Item> {
//         self.0.take()
//     }
// }