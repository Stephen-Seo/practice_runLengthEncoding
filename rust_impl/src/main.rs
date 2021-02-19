use structopt::StructOpt;
use std::collections::HashMap;

#[derive(StructOpt, Debug)]
#[structopt(name = "RunLengthEncoding")]
struct Opts {
    input: String,
}

fn main() {
    let opts = Opts::from_args();

    let mut map: HashMap<char, u32> = HashMap::new();

    for c in opts.input.chars() {
        map.get_mut(&c).map(|v| *v += 1).or_else(|| {map.insert(c, 1); Some(())});
    }

    for (c, value) in map {
        println!("{} with value {}", c, value);
    }
}
