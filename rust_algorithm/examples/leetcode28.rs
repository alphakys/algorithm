fn main() {

    let haystack: String = String::from("leetcode");
    let needle: String = String::from("leeto");

    let result: i32 = match haystack.find(&needle){
        Some(idx) => idx as i32,
        _ => -1,
    };

    println!("{:?}", result);

}