#![allow(unused)]
#![allow(non_snake_case)]

use std::cmp::PartialEq;
use std::collections::LinkedList;
use std::fmt::Pointer;
use std::future::pending;
use std::ops::{Deref, DerefMut};
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
    let arr1 = [9,9,9,9,9,9,9];
    let arr2 = [9,9,9,9];

    let mut l1: Option<Box<ListNode>> = Some(Box::new(ListNode::new(arr1[0])));
    let mut tmp1 = &mut l1;
    for &n in &arr1[1..] {
        // Converts from &mut Option<T> to Option<&mut T>
        // Converts from &mut Option<T> to Option<&mut T>
        // Converts from &mut Option<T> to Option<&mut T>
        tmp1.as_mut().unwrap().next = Some(Box::new(ListNode::new(n)));
        tmp1 = &mut tmp1.as_mut().unwrap().next;
    }

    let mut l2: Option<Box<ListNode>> = Some(Box::new(ListNode::new(arr2[0])));
    let mut tmp2 = &mut l2;
    for &n in &arr2[1..] {
        // Converts from &mut Option<T> to Option<&mut T>
        // Converts from &mut Option<T> to Option<&mut T>
        // Converts from &mut Option<T> to Option<&mut T>
        tmp2.as_mut().unwrap().next = Some(Box::new(ListNode::new(n)));
        tmp2 = &mut tmp2.as_mut().unwrap().next;
    }

    let mut tmp1 = l1;
    let mut tmp2 = l2;

    let mut result = 0;
    let mut carry = 0;
    let mut answer = Some(Box::new(ListNode::new(0)));
    let mut tail = &mut answer;

    while tmp1.is_some() || tmp2.is_some() || carry !=0{

        result = match tmp1 {
            Some(t) => {
                tmp1 = t.next;
                t.val
            },
            None => 0,
        }
        +
        match tmp2{
            Some(t) => {
                tmp2 = t.next;
                t.val
            },
            None => 0
        } + carry;

        carry = result/10;
        tail.as_mut().unwrap().next = Some(Box::new(ListNode::new(result % 10)));
        tail = &mut tail.as_mut().unwrap().next;

    }

    println!("{:?}", answer.unwrap().next);


}
