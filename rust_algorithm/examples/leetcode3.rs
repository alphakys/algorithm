#![allow(unused)]

fn main() {

    let s: String = String::from("dvdf");
    let mut str_slice = s.as_bytes();

    let mut str = "";

    let mut v: Vec<&str> = vec![];
    for c in s.chars() {
        let mut tmp = "";
        let mut tmp_vector: Vec<&str> = Vec::new();
        for &s in &v {
            if s.contains(c){
                // str이 char을 포함하고 있으면 pop

            }
            else{
                let tmp_str = &c.to_string();
                tmp_vector.push(tmp_str);
                tmp_str.push_str(s);
                if s != "" { tmp_vector.push(tmp_str)}
            }
        }

        v.append(&mut tmp_vector);

        println!("{:?}", v);
    }

    // println!("{:?}", max);

}