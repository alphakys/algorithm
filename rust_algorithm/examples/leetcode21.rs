#![allow(unused)]

use std::ptr::copy_nonoverlapping;

#[derive(PartialEq, Eq, Clone, Debug)]
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
    let arr1 = [11, 21];
    let arr2 = [1, 3, 4];
    let mut list1: Option<Box<ListNode>> = Some(Box::new(ListNode::new(arr1[0])));
    let mut list2: Option<Box<ListNode>> = Some(Box::new(ListNode::new(arr2[0])));

    let mut head1 = &mut list1;
    for v in &arr1[1..] {
        head1.as_mut().unwrap().next = Some(Box::new(ListNode::new(*v)));
        head1 = &mut head1.as_mut().unwrap().next;
    }

    let mut head2 = &mut list2;
    for v in &arr2[1..] {
        head2.as_mut().unwrap().next = Some(Box::new(ListNode::new(*v)));
        head2 = &mut head2.as_mut().unwrap().next;
    }


    let mut r = &mut list1;
    while list2.is_some() {
        if r.is_some() || list2.as_ref()?.val < r.as_ref()?.val {
            std::mem::swap(r, &mut list2);
        }
        r = &mut r.as_mut()?.next;
    }

    // let mut head1 = &mut list1;
    // let mut head2 = &mut list2;
    // let mut answer: Option<Box<ListNode>> = Some(Box::new(ListNode::new(0)));
    // let mut current = &mut answer;
    //
    // while let (Some(next_node), which) = match (&head1, &head2) {
    //     (Some(t1), Some(t2)) => {
    //         if t1.val > t2.val {
    //             // current.as_mut().unwrap().next =
    //             (Some(Box::new(ListNode::new(t2.val))), 2)
    //             // current = &mut current.as_mut().unwrap().next;
    //             // head2 = &mut t2.next;
    //         } else {
    //             // current.as_mut().unwrap().next =
    //             (Some(Box::new(ListNode::new(t1.val))), 1)
    //             // current = &mut current.as_mut().unwrap().next;
    //             // head1 = &mut t1.as_mut().next;
    //         }
    //     }
    //     (Some(t1), None) => {
    //         // current.as_mut().unwrap().next =
    //         (Some(Box::new(ListNode::new(t1.val))), 1)
    //         // current = &mut current.as_mut().unwrap().next;
    //         // head1 = &mut t1.as_mut().next;
    //     }
    //     (None, Some(t2)) => {
    //         // current.as_mut().unwrap().next =
    //         (Some(Box::new(ListNode::new(t2.val))), 2)
    //         // current = &mut current.as_mut().unwrap().next;
    //         // head2 = &mut t2.as_mut().next;
    //     }
    //     (None, None) => (None, 0),
    // }
    // {
    //     current.as_mut().unwrap().next = Some(next_node);
    //     current = &mut current.as_mut().unwrap().next;
    //     // println!("{:?}", next_node);
    //     if which == 1 {
    //         head1 = &mut head1.as_mut().unwrap().next;
    //     }
    //     else {
    //         head2 = &mut head2.as_mut().unwrap().next;
    //     }
    //
    // }


}




