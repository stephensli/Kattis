use std::io::{self};

fn main() {
    let input = io::stdin();

    let mut input_buffer = String::from("");
    input.read_line(&mut input_buffer).unwrap();

    let number_tests: u32 = input_buffer.trim().parse().unwrap();
    input_buffer.clear();

    for _i in 0..number_tests {
        input.read_line(&mut input_buffer).unwrap();

        let numbers: Vec<u32> = input_buffer.split_whitespace().into_iter()
            .map(|l| l.parse().unwrap()).collect();

        let mut answer: u64 = 0;

        for i in 1..numbers.len() {
            if i == numbers.len() - 1 { continue; }

            if numbers[i - 1] * 2 < numbers[i] {
                answer += (numbers[i] - numbers[i - 1] * 2) as u64
            }
        }

        println!("{:?}", answer);
        input_buffer.clear();
    }
}
