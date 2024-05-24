#![allow(unused)]
#![allow(non_snake_case)]

fn main() {
    // Imp` substring is a contiguous sequence of characters within a larger string.
    // Imp` palindrome에 양 끝단에 새로운 substring을 append 하면 그것은 새로운 palindrome이 된다.

    let s = String::from("ac");

    if s.len() ==1 { println!("{s}", ); }
    let cnt: usize = s.len();

    let mut mid: usize = 1;
    let mut left: i32 = mid as i32 - 1;
    let mut right: usize = mid + 1;

    let mut answer = String::from(&s[0..=0]);
    while mid < cnt {
        let mut left_str = "";
        let mut right_str = "";

        while 0 <= left && right < cnt {
            left_str = &s[left as usize..=left as usize];
            right_str = &s[right..=right];

            if left_str == right_str {
                left -= 1;
                right += 1;
            }
            else {
                if (right as i32 - left) ==2 {
                    if &s[mid..=mid] == left_str { right = mid + 1 ; left -= 1; }
                    else if &s[mid..=mid] == right_str { left = mid as i32 -1; right +=1; }
                }

                if answer.len() < (right as i32 - left) as usize {
                    answer = String::from(&s[(left +1) as usize ..right]);
                }
                break
            }
        }

        mid += 1;
        left = mid as i32 - 1;
        right = mid + 1;
    }

    println!("{answer}", );







    //
    // // if s.len() == 1{ println!(""); }
    // // let s = String::from("mwwmfjysbbkbbsbpdjyabcfkgprtxpwvhglddhmvaprcvrnuxifcrjpdgnktvmggmguiiquibmtviwjsqwtch");
    // // kqgxqwljouunurcdtoeygdqmijdympcamawnlzsxucbpqtuwkjfqnzvvvigifyvymfhtppqamlgjozvebygkxawcbwtouaankxsjrteeijpuzbsfsjwxe\
    // // jtfrancoekxgfyangvzjkdskhssdjvkvdskjtiybqgsmpxmghvvicmjxqtxdowkjhmlnfcpbtwvtmjhnzntxyfxyinmqzivxkwigkondghzmbioelmepgf\
    // // ttczskvqfejfiibxjcuyevvpawybcvvxtxycrfbcnpvkzryrqujqaqhoagdmofgdcbhvlwgwmsmhomknbanvntspvvhvccedzzngdywuccxrnzbtchisdw\
    // // srfdqpcwknwqvalczznilujdrlevncdsyuhnpmheukottewtkuzhookcsvctsqwwdvfjxifpfsqxpmpwospndozcdbfhselfdltmpujlnhfzjcgnbgprvop\
    // // xklmlgrlbldzpnkhvhkybpgtzipzotrgzkdrqntnuaqyaplcybqyvidwcfcuxinchretgvfaepmgilbrtxgqoddzyjmmupkjqcypdpfhpkhitfegickfsze\
    // // rmqhkwmffdizeoprmnlzbjcwfnqyvmhtdekmfhqwaftlyydirjnojbrieutjhymfpflsfemkqsoewbojwluqdckmzixwxufrdpqnwvwpbavosnvjqxqbosc\
    // // tttxvsbmqpnolfmapywtpfaotzmyjwnd");
    //
    // if s.len() == 1 { println!("{}", s); }
    //
    // let mut left = 0;
    // let mut right = 1;
    // let mut answer = "";
    //
    // let mut stop = 1;
    // while right < s.len(){
    //
    //     if &s[left..=left] == &s[right..=right] {
    //         let mut l: i32 = left as i32;
    //         let mut r = right;
    //
    //         let mut tmp_str = "";
    //         while l >= 0 && r < s.len()  {
    //
    //             if &s[(l as usize)..=(l as usize)] == &s[r..=r] {
    //                 tmp_str = &s[l as usize..=r];
    //                 l -= 1;
    //                 r += 1;
    //             }
    //             else {
    //                 break
    //             }
    //         }
    //
    //         if tmp_str.len() > answer.len(){
    //             answer = tmp_str;
    //         }
    //
    //     }
    //
    //     if left < right { left += 1; }
    //     else { right += 1;}
    //
    //
    // }
    // println!("{}", answer.to_string());

    // while left < s.len() {
    //     let mut right = left;
    //     while right < s.len() {
    //         println!("시작 {}", &s[left..=right]);
    //
    //         let target = &s[left..=right];
    //         let mut binding = String::new();
    //         let reverse = target.as_bytes().iter().rfold(&mut binding, |acc: &mut String, u: &u8| {
    //             acc.push(*u as char);
    //             acc
    //         });
    //
    //         if target == reverse {
    //             println!("-----\n gotcha {}\n----\n", target);
    //             if answer.len() < target.len() { answer = target.to_string(); }
    //
    //         }
    //         right += 1;
    //     }
    //     left += 1;
    // }



    // while left < right {
    //     println!("left! : {} {}", &s[left..left + 1], left);
    //
    //     while left < right {
    //         println!("{} {}", &s[right - 1..right], s.starts_with(&s[right - 1..right]));
    //         println!("right : {}", right);
    //
    //         if s[left..].starts_with(&s[right - 1..right]) {
    //
    //             println!("gotcha! : {:?} {:?}", &s[left..], &s[right - 1..right]);
    //             if *&s[left..right].ends_with(&s[left..right]) {
    //
    //                 if answer.len() < *&s[left..right].len() {
    //                     answer.clear();
    //                     answer.push_str(&s[left..right]);
    //                 }
    //             }
    //
    //         }
    //         right -= 1;
    //     }
    //     right = s.len() - 1;
    //     left += 1;
    //     println!("\n", );
    // }

    // println!("{answer}", );
}