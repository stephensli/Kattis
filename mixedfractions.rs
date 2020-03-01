use std::io::{self};
use std::collections::HashMap;

fn main() {
    let input = io::stdin();

    let mut input_buffer = String::from("");

    loop {
        input.read_line(&mut input_buffer).unwrap();

        let numbers: Vec<i32> = input_buffer.split_whitespace()
            .map(|l| l.parse().unwrap()).collect();

        let first = numbers[0];
        let second = numbers[1];

        if first == 0 && second == 0 { break; }

        println!("{} {} / {}", (first / second), first % second, second);

        input_buffer.clear();
    }
}
