#![allow(unused)]
#![allow(non_snake_case)]

use std::io;

struct MaxHeap {
    heap: Vec<u32>,
}

impl MaxHeap {
    pub fn new() -> Self {
        Self {
            heap: vec![0]
        }
    }
    pub fn insert(&mut self, val: u32) {
        // Bottom Up!
        let mut idx = self.heap.len();
        let mut parent_idx = idx / 2;

        self.heap.push(val);

        while self.heap[parent_idx] < val && parent_idx > 0 {
            let tmp = self.heap[parent_idx];
            self.heap[parent_idx] = val;
            self.heap[idx] = tmp;

            idx = parent_idx;
            parent_idx = idx / 2;
        }
    }

    pub fn swap_element(&mut self, idx1: usize, idx2: usize) {
        let tmp = self.heap[idx1];
        self.heap[idx1] = self.heap[idx2];
        self.heap[idx2] = tmp;
    }

    pub fn delete(&mut self) -> Option<u32> {
        // Top Down!
        let mut length: usize = self.heap.len() - 1;
        let mut return_val = None;

        if length == 1 {
            return Some(self.heap.pop().unwrap());
        } else if length == 0 {
            return return_val;
        }

        return_val = Some(self.heap[1]);
        self.heap[1] = self.heap.pop().unwrap();

        length -= 1;

        let mut curr_idx: usize = 1;
        let mut curr: u32 = self.heap[curr_idx];

        let mut left = 0;
        let mut right = 0;

        let mut stopper = 0;

        while curr_idx * 2 <= length {
            if length == curr_idx * 2 {
                if self.heap[curr_idx * 2] > curr { self.swap_element(curr_idx, curr_idx * 2) }
                break;
            }

            left = self.heap[curr_idx * 2];
            right = self.heap[curr_idx * 2 + 1];

            if (left > right && left > curr) {
                self.swap_element(curr_idx, curr_idx * 2);

                curr_idx = curr_idx * 2;
                curr = self.heap[curr_idx];
            } else if (right >= left && right > curr) {
                self.swap_element(curr_idx, curr_idx * 2 + 1);

                curr_idx = curr_idx * 2 + 1;
                curr = self.heap[curr_idx];
            } else {
                break;
            }
        }
        return_val
    }
}


fn main() {
    let mut buff = String::new();
    io::stdin().read_line(&mut buff);

    let mut h = MaxHeap::new();

    let N: usize = buff.trim().parse().unwrap();
    buff.clear();

    let mut answer = String::new();

    for _ in 0..N {
        io::stdin().read_line(&mut buff);
    }

    let lines: Vec<&str> = buff.trim_end().split("\n").collect();

    for opcode in lines {
        if opcode == "0" {
            match &h.delete() {
                Some(T) => answer.push_str(&format!("{}\n", T)),
                None => answer.push_str(&format!("0\n"))
            }
        } else {
            &h.insert(opcode.parse::<u32>().unwrap());
        }
    }

    println!("{}", answer);
}