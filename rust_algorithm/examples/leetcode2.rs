#![allow(unused)]
#![allow(non_snake_case)]

use std::cmp::PartialEq;
use std::collections::LinkedList;
use std::fmt::Pointer;
use std::future::pending;
use std::ops::DerefMut;
use std::rc::Rc;

#[derive(Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode {
            next: None,
            val,
        }
    }
}


fn main() {
    let arr1 = [2, 4, 3];
    let arr2 = [5, 6, 4];

    let mut l1: Option<Box<ListNode>> = Some(Box::new(ListNode::new(arr1[0])));
    let mut tmp = &mut l1;
    for &n in &arr1[1..] {
        // Converts from &mut Option<T> to Option<&mut T>
        // Converts from &mut Option<T> to Option<&mut T>
        // Converts from &mut Option<T> to Option<&mut T>
        tmp.as_mut().unwrap().next = Some(Box::new(ListNode::new(n)));
        tmp = &mut tmp.as_mut().unwrap().next;
    }

    println!("{:?}", l1);
    for n in arr2 {
        println!("{n}", );
    }




}
