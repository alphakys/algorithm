#![allow(unused)]

fn combination(v: &[i32], vis: &mut Vec<bool>, target: i32, container: &mut Vec<i32>, depth: usize, idx: usize, mut answer: i32) -> i32 {

    if idx == container.len() {
        if target == container.iter().sum::<i32>() {
            answer += 1;
            println!("gotcha {target} {:?}", container);
        }
        return answer
    }

    for n in depth..v.len(){
        if !vis[n] {
            vis[n] = true;
            container[idx] = v[n];
            answer = combination(v, vis, target, container, n, idx + 1, answer);
            vis[n] = false;
        }

    }

    answer
}
fn main() {

    let nums: Vec<i32> = vec![1,1,1,3,5];

    let mut j = nums.len() - 1;

    let mut vis: Vec<bool> = vec![false;nums.len()];
    let mut container: Vec<i32> = vec![0;3];

    // combination(&nums[0..(j-1)], &mut vis, nums[j], &mut container, 0, 0);
    let mut cnt: i32 = 0;
    while 2 < j{

        let mut answer: i32 = combination(&nums[0..=(j-1)], &mut vis, nums[j], &mut container, 0, 0, 0);
        cnt = cnt + answer;
        j -= 1;
    }

    println!("{cnt}", );

}