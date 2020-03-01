use std::io::{self};
use std::collections::HashMap;

fn main() {
    let input = io::stdin();

    let mut input_buffer = String::from("");
    input.read_line(&mut input_buffer).unwrap();

    let number_cases: i32 = input_buffer.trim().parse().unwrap();
    input_buffer.clear();

    for i in 0..number_cases {
        input.read_line(&mut input_buffer).unwrap();
        input_buffer.clear();
        input.read_line(&mut input_buffer).unwrap();

        let invite_codes: Vec<i32> = input_buffer.split_whitespace()
            .map(|l| l.parse().unwrap()).collect();

        let mut hash = HashMap::new();

        for code in invite_codes {
            *hash.entry(code).or_insert(0) += 1;
        }

        let singletons: Vec<(i32, i32)> = hash.into_iter()
            .filter(|&(_k, v)| v == 1).collect();

        println!("Case #{}: {}", i + 1, singletons[0].0);
        input_buffer.clear();
    }
}
