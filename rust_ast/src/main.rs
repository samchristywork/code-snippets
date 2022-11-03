use std::fs::File;
use std::io::Read;

fn main() {
    let mut file = File::open("src/main.rs").expect("Unable to open file");

    let mut src = String::new();
    file.read_to_string(&mut src).expect("Unable to read file");

    let syntax: syn::File = syn::parse_file(&src).expect("Unable to parse file");

    let items = syntax.items;
    println!("{:#?}", items.len());
    println!("{:#?}", items[0]);
    println!("{:#?}", items);
}
