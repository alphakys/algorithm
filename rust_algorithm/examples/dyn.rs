#![allow(unused)]

use std::option::IterMut;

trait Car {
    fn drive(car: impl Car){
        println!("This is Car", );
    }

    fn drive_car<T: Car>(car: T);
}

#[derive(Debug)]
struct Sedan;

impl Car for Sedan {
    fn drive(car: impl Car) {
        println!("This is Sedan", );
    }

    fn drive_car<T: Car>(car: T) {

    }
}
#[derive(Debug)]
struct Suv{}


impl Car for Suv {
    fn drive_car<T: Car>(car: T) {

    }
}

fn drive_car<T: Car>(car: T){
    println!("{:?}", car);
}

fn get_car(is_sedan: bool) -> Box<dyn Car>{

    if is_sedan{
        Box::new(Sedan)
    }
    else{
        Box::new(Suv{})
    }
}

/// Compile time에 Compiler가 get_car가 반환하는 type에 대해서 알고 싶어도
/// trait을 반환하기 때문에 어떤 Trait Car의 어떤 specific한 타입이 반환되는 지를 알 수가 없다.
/// 따라서 Box<dyn {struct}> 를 사용하여 동적으로 타입을 정하겠다고 compiler에게 알리도록 한다.
fn get_car1(is_sedan: bool) -> Box<dyn Car>{

    if is_sedan{
       Box::new(Sedan)
    }
    else{
       Box::new(Suv{})
    }
}
fn main() {

    let suv = Suv{};
    let sedan = Sedan;

    let is_sedan = true;

    let result = get_car1(is_sedan);

    println!("{result}", );
    println!("{:?}", suv);

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