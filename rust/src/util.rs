//use std::io::Write;

pub fn read_i32() -> i32 {
    let number: i32;
    let mut buffer = String::new();

    std::io::stdin()
        .read_line(&mut buffer)
        .expect("Failed to read input!");

    number = buffer.trim_end().parse::<i32>()
        .expect("Input is not an integer!");

    return number;
}

#[macro_export]
macro_rules! myprint {
    //($text:ident) => {
    //    print!("{}", $text);
    //    std::io::stdout().flush().unwrap();    
    //};
    //($text:ty) => {
    //    print!("{}", $text);
    //    std::io::stdout().flush().unwrap();    
    //};
    ($arg1:tt) => {
        use std::io::Write;
        print!($arg1);
        std::io::stdout().flush().unwrap();    
    };
    ($arg1:tt, $arg2:expr) => {
        use std::io::Write;
        print!($arg1, $arg2);
        std::io::stdout().flush().unwrap();    
    };
    //($text:expr) => {
    //    print!("{}", $text);
    //    std::io::stdout().flush().unwrap();    
    //};
}