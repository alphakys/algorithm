#![allow(unused)]

use std::cell::RefCell;
use std::ops::Deref;
use std::rc::Rc;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

type Node = Option<Rc<RefCell<TreeNode>>>;

pub fn leaf_similar(root: Node, v: &mut Vec<i32>) {
    if root.is_none() {
        return;
    }

    let mut head = root.unwrap();

    match &head.borrow().left {
        Some(l) => {
            println!("{:?}", l);
            let ln = l;
            leaf_similar(*l);
        }
        None => {
            println!("break : {:?}", &tmp);
        }
    }

    match &tmp.right {
        Some(r) => {
            println!("{:?}", r);
        }
        None => {
            println!("break : {:?}", &tmp);
        }
    }

    println!("{:?}", tmp);

    // drop(tmp);
    // drop(head);
    // let r = Rc::strong_count(root.as_ref().unwrap());

    println!("{r}", );


}


fn main() {
    let root1: Node = Some(Rc::new(RefCell::new(TreeNode::new(3))));
    let root2: Node = Some(Rc::new(RefCell::new(TreeNode::new(3))));

    // let t =root1.as_ref().unwrap().borrow_mut().left;
    root1.as_ref().unwrap().borrow_mut().left = Some(Rc::new(RefCell::new(TreeNode::new(5))));

    let mut v: Vec<i32> = Vec::new();
    leaf_similar(root1, &mut v);


}



















