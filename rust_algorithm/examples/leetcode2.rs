#![allow(unused)]
#![allow(non_snake_case)]

use std::cmp::PartialEq;
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

type Node = Box<ListNode>;

fn main() {
    let arr1 = [2,3,4];
    let arr2 = [5,6,4];

    for n in arr1 {
        println!("{n}", );
    }

    // let mut head = Some(Box::new(ListNode::new(2)));
    // let head = head.as_mut().unwrap().next;
    // head = Some(Box::new(ListNode::new(4)));
    // let head = head.as_mut().unwrap().next;
    // head = Some(Box::new(ListNode::new(3)));

    // println!("{:?}", head);
    // let l1: Option<Box<ListNode>> = ;
    // let l2: Option<Box<ListNode>> = ;



    // let mut l1 = Some(Box::new(ListNode::new(arr1[0])));
    // let mut l2 = Some(Box::new(ListNode::new(arr2[0])));
    //
    // let mut h = l1.as_mut().unwrap();
    // let mut h2 = l2.as_mut().unwrap();
    //
    // for n in &arr1[1..] {
    //     h.next = Some(Box::new(ListNode::new(*n)));
    //     h = h.next.as_mut().unwrap();
    // }
    //
    // for n in &arr2[1..] {
    //     h2.next = Some(Box::new(ListNode::new(*n)));
    //     h2 = h2.next.as_mut().unwrap();
    // }
    //
    // let mut lt = &l1;
    // let mut lt2 = &l2;
    //
    // let mut answer = Box::new(ListNode::new(0));
    // let mut node = &mut answer;
    //
    // let mut carry: i32 = 0;
    // loop {
    //     let mut sum = 0;
    //
    //     match (lt, lt2) {
    //         (Some(x), Some(y)) => {
    //             sum = carry + (x.val + y.val);
    //             lt = &lt.as_ref().unwrap().next;
    //             lt2 = &lt2.as_ref().unwrap().next;
    //         }
    //         (Some(x), None) => {
    //             sum = carry + x.val;
    //             lt = &lt.as_ref().unwrap().next;
    //         }
    //         (None, Some(y)) => {
    //             sum = carry + y.val;
    //             lt2 = &lt2.as_ref().unwrap().next;
    //         }
    //         _ => {
    //             if carry == 1 {
    //                 node.next = Some(Box::new(ListNode::new(1)));
    //             }
    //             break;
    //         }
    //     }
    //
    //     carry = sum / 10;
    //     println!("{}", sum % 10);
    //     node.next = Some(Box::new(ListNode::new(sum % 10)));
    //     node = node.next.as_mut().unwrap();
    // }
    //
    //
    // println!("{:?} ", Some(answer.next));
}
