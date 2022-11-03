use std::env;
use std::fs::File;
use std::io::Read;
use std::process;

fn main() {
    let mut args = env::args();
    let program_name = args.next().unwrap();

    let filename = match (args.next(), args.next()) {
        (Some(filename), None) => filename,
        _ => {
            eprintln!("Usage: {} path/to/filename.rs", program_name);
            process::exit(1);
        }
    };

    let mut file = File::open(&filename).expect("Unable to open file");

    let mut src = String::new();
    file.read_to_string(&mut src).expect("Unable to read file");

    let syntax: syn::File = syn::parse_file(&src).expect("Unable to parse file");

    let items = syntax.items;
    println!("{:#?}", items.len());
    for item in items {
        println!("{:?}\n\n", item);
    }
}
