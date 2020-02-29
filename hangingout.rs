use std::io::{self, BufRead};

fn main() {
    let input = io::stdin();
    let mut lines_completed = 0;

    let mut input_buffer = String::from("");
    input.read_line(&mut input_buffer).expect("failed to read input test count and room count");

    let numbers: Vec<u32> = input_buffer.split_whitespace().map(|n| n.parse().unwrap()).collect();

    let number_events_limit = numbers[0];
    let total_tests = numbers[1];

    let mut cannot_enter = 0;
    let mut entering = 0;

    for line in input.lock().lines().map(|l| l.unwrap())
    {
        let mut split = line.split_whitespace();

        let party_type = split.next().unwrap();
        let party_amount: u32 = split.next().unwrap().parse().unwrap();

        if party_type == "enter" && entering + party_amount > number_events_limit {
            cannot_enter += 1;
        } else if party_type == "enter" {
            entering += party_amount;
        } else {
            entering -= party_amount;
        }

        lines_completed += 1;
        if lines_completed == total_tests {
            break;
        }
    }

    print!("{}", cannot_enter)
}
















