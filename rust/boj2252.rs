#![allow(unused)]
#![allow(non_snake_case)]

use std::collections::VecDeque;
use std::io;
use std::io::Read;

fn main() {

    let mut buff = String::new();
    io::stdin().read_line(&mut buff);

    let line: Vec<&str> = buff.split_whitespace().collect();

    let N = line[0].parse::<usize>().unwrap();
    let M = line[1].parse::<usize>().unwrap();

    buff.clear();
    io::stdin().read_to_string(&mut buff);

    let mut vis_cnt = vec![0; (N + 1)];
    let mut vis = vec![false; (N + 1)];
    let mut tree = vec![vec![]; (N + 1)];

    let mut u = 0;
    let mut v = 0;

    // let mut split_str = [""; 2];
    let mut split_str: Vec<&str> = vec![];

    for line in buff.trim_end().split("\n"){
        // println!("{:?}", );
        split_str = line.split_whitespace().collect::<Vec<&str>>();
        u = split_str[0].parse().unwrap();
        v = split_str[1].parse().unwrap();

        tree[u].push(v);
        vis_cnt[v] += 1;

    }

    let mut q = VecDeque::new();

    for (idx, v) in vis_cnt[1..].iter().enumerate() {
        if *v == 0 {
            q.push_back(idx + 1);
        }
    }

    let mut v = vec![];
    
    println!("{:?}", tree);
    println!("{:?}", vis_cnt);

    while q.len() > 0 {

        let curr = q.pop_front().unwrap();

        println!("curr {}", curr);
        // if vis[curr] { continue }
        if vis_cnt[curr] == 0{
            v.push(curr);
        }

        vis[curr] = true;

        for node in &tree[curr] {
            if vis[*node]{ continue }
            println!("check : {} {}", curr, *node);
            q.push_back(*node);
            vis_cnt[*node] -= 1;
        }

    }

    print!("{:?}", v);
    for s in v{
        print!("{:?} ", char::from_u32(s as u32 + 96));
    }




    // (1, 2) 3 (6, 7)
    // 2 (4, 5) 7
    // (6, 7) 8

    // A 1
    // B 2
    // C 3
    // D 4
    // E 5
    // F 6
    // G 7

// 7 7
// 1 2
// 3 2
// 3 4
// 4 2
// 4 5
// 5 6
// 7 5



    // println!("{:?}", q);
    // println!("{:?}", tree);
    // println!("{:?}", &vis_cnt);
    // println!("{:?}", &vis_cnt[1..]);

    // let mut tree: Vec<Vec<u32>> = Vec::new();
    //
    // for _ in 0..3 {
    //     tree.push(Vec::new());
    // }
    //
    // println!("{:?}", tree);



    //
    // let mut tree = [[-1i32; 2]; 7];
    // let mut vis = [false; 7];
    // let mut vis_cnt = [0; 7];
    //
    // vis_cnt[][]
    //
    // tree[0][0] = 1; //A
    // tree[2][0] = 1; //C
    // tree[2][1] = 3;
    // tree[3][0] = 1; //D
    // tree[3][1] = 4;
    // tree[4][0] = 5;
    // tree[6][0] = 4;
    //
    // println!("{:?}", tree);
    // println!("{:?}", vis);





}