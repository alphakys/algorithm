#![allow(unused)]
#![allow(non_snake_case)]

use std::cmp::PartialEq;
use std::collections::LinkedList;
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

type Node = Box<ListNode>;

fn main() {
    let arr1 = [2,4,3];
    let arr2 = [5,6,4];

    let mut l1 = Some(Box::new(ListNode::new(arr1[0])));
    let mut l2 = Some(Box::new(ListNode::new(arr2[0])));

    let mut node1 = &mut l1;
    let mut node2 = &mut l2;

    for &n in &arr1[1..] {
        if let Some(t) = node1 {
            t.next = Some(Box::new(ListNode::new(n)));
            node1 = &mut t.next;
        }
    }

    for &n in &arr2[1..] {
        if let Some(t) = node2 {
            t.next = Some(Box::new(ListNode::new(n)));
            node2 = &mut t.next;
        }
    }

    let mut answer = Box::new(ListNode::new(0));
    let mut tail = &mut answer;
    let mut carry = 0;
    let mut result = 0;
    while l1.is_some() || l2.is_some() || carry != 0 {
        // ref keyword의 중요성!!!
        result =
            match l1 {
                Some(l) => { l1 = l.next; l.val },
                None => { 0 },
        } +
            match l2 {
                Some(l) => { l2 = l.next; l.val },
                None => 0,
        } + carry;

        carry = result / 10;
        println!("{} {}", result%10, carry);

        tail.next = Some(Box::new(ListNode::new(result%10)));
        tail = tail.next.as_mut().unwrap();

    }

    println!("{:?}", answer.next);

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
