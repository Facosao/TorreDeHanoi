use crate::stack::Stack;
use crate::util::read_i32;
use crate::graphics::print_game;

pub struct Hanoi {
    pub size: i32,
    pub towers: [Stack; 3]
}

const TOWER_A: usize = 0;
// const TOWER_B: usize = 1;
const TOWER_C: usize = 2;

const AB: i32 = 12;
const AC: i32 = 13;
const BA: i32 = 21;
const BC: i32 = 23;
const CA: i32 = 31;
const CB: i32 = 32;

const QUIT: i32 = 0;

pub fn new_game(difficulty: i32) {
    let mut game = Hanoi {
        size: difficulty,
        towers: [
            Stack::new(),
            Stack::new(),
            Stack::new()
        ]
    };

    for i in difficulty..0 {
        game.towers[TOWER_A].push(i);
    }

    game_loop(game);
}

fn source_tower(value: i32) -> usize {
    ((value / 10) -1) as usize
}

fn destination_tower(value: i32) -> usize {
    ((value % 10) - 1) as usize
}

fn game_loop(mut game: Hanoi) {
    let mut game_running: bool = true;
    print_game(&mut game);
    read_i32();
    while game_running {
        let input = read_i32();
        match input {
            AB | AC | BA | BC | CA | CB => {
                let src_tower = source_tower(input);
                let dest_tower = destination_tower(input);

                let current_src = game.towers[src_tower].peek();
                let current_dest = game.towers[dest_tower].peek();

                if (current_src < current_dest) || (current_dest == 0) {
                    let temp = game.towers[src_tower].pop();
                    game.towers[dest_tower].push(temp);
                }
            }

            QUIT => {
                game_running = false;
            }

            _ => {}
        }

        // ----- Graphics -----
        print_game(&mut game);

        if game.towers[TOWER_C].size == game.size {
            print!("\nCongratulations! Type any number to return to the main menu. ");
            read_i32();
            game_running = false;
        }
    }

}