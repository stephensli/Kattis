use std::io::{self, BufRead};
use std::cmp::max;

fn main() {
    let input = io::stdin();

    let mut line: String = String::from("");

    input.lock().read_line(&mut line).unwrap();
    let numbers: Vec<u32> = line.split_whitespace().map(|l| l.parse().unwrap()).collect();

    let a = numbers[0];
    let b = numbers[1];

    if a == 0 && b == 0 {
        println!("Not a moose")
    } else if a == b {
        println!("Even {}", a + b)
    } else {
        println!("Odd {}", max(a, b) * 2)
    }
}











