use std::cmp::min;
use std::collections::HashMap;
use std::io::{self, BufRead};

fn main() {
    let input = io::stdin();
    let mut total_score = 0;

    let mut input_buffer = String::from("");
    input.read_line(&mut input_buffer).expect("failed to read cards");

    let mut cards = HashMap::new();
    cards.insert("T", 0);
    cards.insert("C", 0);
    cards.insert("G", 0);

    for card in input_buffer.trim().split("") {
        if card == "" { continue; }
        *cards.get_mut(card).unwrap() += 1;
    }

    let t_value: i32 = cards.remove("T").unwrap();
    let c_value: i32 = cards.remove("C").unwrap();
    let g_value: i32 = cards.remove("G").unwrap();

    let set_count = min(t_value, min(c_value, g_value)) as i32;
    total_score += 7 * set_count;

    total_score += i32::pow(t_value, 2);
    total_score += i32::pow(c_value, 2);
    total_score += i32::pow(g_value, 2);

    print!("{}", total_score)
}
















