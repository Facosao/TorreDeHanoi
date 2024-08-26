pub mod graphics;
pub mod stack;
pub mod hanoi;
pub mod util;

use util::*;
use graphics::clear_screen;

fn main() {
    loop {
        clear_screen();
        println!("Tower of Hanoi - Rust Edition");
        println!("\nInsert a number between 3 and 10 to start the game with that many discs.");
        println!("Insert 0 to quit the game.\n");
        myprint!("Select an option: ");
        
        let input: i32 = read_i32();
        match input {
            3..=10 => hanoi::new_game(input),
            0 => break,
            _ => continue
        }
    }
}
