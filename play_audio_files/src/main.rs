use soloud::*;
use std::env;
use std::process;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut args = env::args();
    let program_name = args.next().unwrap();

    let filename = match (args.next(), args.next()) {
        (Some(filename), None) => filename,
        _ => {
            eprintln!("Usage: {} path/to/filename.rs", program_name);
            process::exit(1);
        }
    };

    let sl = Soloud::default()?;

    let mut wav = audio::Wav::default();

    wav.load(&std::path::Path::new(&filename))?;

    sl.play(&wav);
    while sl.voice_count() > 0 {
        std::thread::sleep(std::time::Duration::from_millis(100));
    }

    Ok(())
}
