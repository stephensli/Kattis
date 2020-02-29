use std::io::{self, BufRead};

fn print_matrix(a: &Vec<Vec<char>>) {
    for i in 0..a.len() {
        for j in 0..a.len() {
            print!("{} ", a[i][j]);
        }
        println!();
    }
}

fn main() {
    let input = io::stdin();
    let mut lines_completed = 0;

    let mut input_buffer = String::from("");
    input.read_line(&mut input_buffer).expect("failed to read input test count");

    let total_tests: u32 = input_buffer.trim().parse().unwrap();

    for line in input.lock().lines().map(|l| l.unwrap())
    {
        let square_size = (line.len() as f32).sqrt() as usize;
        let line_chars: Vec<char> = line.chars().collect();

        let mut matrix: Vec<Vec<char>> = Vec::with_capacity(square_size);

        for i in 0..square_size {
            matrix.push(vec![])
        }

        for i in 0..line.len() {
            matrix[i % square_size].push(line_chars[i]);
        }

        matrix.reverse();

        let mut buffer = String::from("");

        for line in matrix {
            let joined: String = line.into_iter().collect();
            buffer.push_str(joined.as_str());
        }

        println!("{}", buffer);

        lines_completed += 1;
        if lines_completed == total_tests {
            break;
        }
    }
}











