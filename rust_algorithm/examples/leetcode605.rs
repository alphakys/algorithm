fn main() {

    let len = flowerbed.len();

    let mut idx: usize = 0;

    while idx < len {

        if flowerbed[idx] == 1 { idx += 1; continue }

        match idx {
            0 if flowerbed[idx + 1] == 0  => { n -=1; flowerbed[idx] = 1; },
            len if flowerbed[idx - 1] == 0 => { n -= 1; flowerbed[idx] = 1; },
            _ if (flowerbed[idx - 1] == 0 && flowerbed[idx + 1] == 0) => { n -= 1; flowerbed[idx] = 1; },
            _ => {}
        }
        if n == 0 { break }
        idx += 1;
    }


    n == 0
}