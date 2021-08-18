use structopt::StructOpt;

#[derive(StructOpt, Debug)]
#[structopt(name = "RunLengthEncoding")]
struct Opts {
    input: String,
}

fn main() {
    let opts = Opts::from_args();

    let mut current: Option<char> = None;
    let mut current_count: u32 = 0;
    let mut list: Vec<(char, u32)> = Vec::new();
    for c in opts.input.chars() {
        if c.is_ascii_whitespace() {
            continue;
        } else {
            if current.is_none() || current.unwrap() != c {
                if current_count > 0 {
                    list.push((current.unwrap(), current_count));
                }
                current_count = 1;
                current = Some(c);
            } else {
                current_count += 1;
            }
        }
    }
    if current_count > 0 && current.is_some() { 
        list.push((current.unwrap(), current_count));
    }

    for (c, count) in list {
        println!("{}: has count of {}", c, count);
    }
}
