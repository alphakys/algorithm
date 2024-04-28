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

pub fn leaf_similar(root: Option<Rc<RefCell<TreeNode>>>) {

    if root.is_none() {
        return
    }
    let mut head = Rc::clone(&root.unwrap());


    // match root.unwrap() {
    //     Some(r) => { r. },
    //     None =>,
    // }
}

fn main() {


    let root1: Option<Rc<RefCell<TreeNode>>> = Some(Rc::new(RefCell::new(TreeNode::new(3))));
    let root2: Option<Rc<RefCell<TreeNode>>> = Some(Rc::new(RefCell::new(TreeNode::new(3))));

    // let t =root1.as_ref().unwrap().borrow_mut().left;
    root1.as_ref().unwrap().borrow_mut().left = Some(Rc::new(RefCell::new(TreeNode::new(5))));

    // println!("{:?}", root1);

    let mut head = Rc::clone(&root1.as_ref().unwrap());

    println!("up head pointer : {:p}", &head);
    let r = Rc::strong_count(&root1.unwrap());

    let mut i = 0;
    loop {

        // let t = Rc::clone(&head);
        // let tt = *head.borrow();
        // let tt = &head.borrow().left;
        let tmp = head.borrow().left.to_owned();
        match &tmp {
            Some(t) => {
                println!("{:?}", &t);
                head = Rc::clone(t);
            },
            None => { println!("break : {:?}", &tmp); break },
        }


        if i ==5 { break }
        i += 1;
    }



}



















