pub mod graphics;
pub mod stack;
pub mod hanoi;
pub mod util;

use util::*;
use graphics::clear_screen;

fn main() {
    //for i in 1..11 {
    //    graphics::print_disc(i, 10);
    //    //println!("");
    //    myprint!("\n");
    //}

    loop {
        clear_screen();
        println!("Tower of Hanoi - Rust Edition");
        println!("Enter a number between 3 and 10 to start the game with that many discs.");
        //println!("Number of discs: ");
        //print("Number of discs: ".to_owned());
        //myprint!(format!("one: {}\n", 1));
        //myprint!("Number of discs: ");
        myprint!("Number of discs: ");
        
        let input: i32 = read_i32();
        //format!("");
        //let input = 3;
        //println!("input:|{input}|");

        match input {
            3..10 => {
                //println!("Got a number!");
                hanoi::new_game(input);
            }

            _ => {
                //println!("No number!");
                continue;
            }
        }
    }
}
