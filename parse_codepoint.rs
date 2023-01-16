use std::env;

fn parse_codepoint(input: &str) {
    match u32::from_str_radix(input, 16) {
        Ok(a) => {
            let c = char::from_u32(a).unwrap();
            println!("{}", c);
        }
        Err(_) => {}
    }
}

fn main() {
    for argument in env::args() {
        parse_codepoint(argument.as_str());
    }
}
