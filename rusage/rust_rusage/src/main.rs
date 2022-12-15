#[link(name = "rusage")]
extern "C" {
    fn print_rusage();
}

fn main() {
    unsafe {
        print_rusage();
    }
}
