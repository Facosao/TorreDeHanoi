use crate::hanoi::Hanoi;
use crate::stack::Stack;
use crate::myprint;

const BLACK: i32 = 40;
const RED: i32 = 41;
const GREEN: i32 = 42;
const ORANGE: i32 = 43;
const BLUE: i32 = 44;
const MAGENTA: i32 = 45;
const CYAN: i32 = 46;
const WHITE: i32 = 46;

fn odd_number(n: i32) -> i32 {
    2 * n + 1
}

fn select_color(mut disc: i32) {
    const COLORS: [i32; 6] = [CYAN, BLUE, GREEN, ORANGE, RED, MAGENTA];

    if disc == BLACK {
        myprint!("\x1b[{}m", BLACK);
        return;
    }

    if disc == WHITE {
        myprint!("\x1b[{}m", WHITE);
        return;
    }

    disc -= 1;
    disc %= 6;

    myprint!("\x1b[{}m", COLORS[disc as usize]);
}

pub fn print_disc(disc: i32, size: i32) {
    if disc == 0 {
        let largest_disc: i32 = odd_number(size);
        let center: i32 = (largest_disc - 1) / 2;

        for i in 0..largest_disc {
            if i == center {
                select_color(WHITE);
            } else {
                select_color(BLACK);
            }

            myprint!(" ");
        }
    } else {
        let disc_size: i32 = odd_number(disc);
        let space_count: i32 = (odd_number(size) - disc_size) / 2;

        select_color(BLACK);

        for _ in 0..space_count {
            myprint!(" ");
        }

        select_color(disc);

        for _ in 0..disc_size {
            myprint!(" ");
        }

        select_color(BLACK);

        for _ in 0..space_count {
            myprint!(" ");
        }
    }
}

pub fn clear_screen() {
    myprint!("\x1b[2J\x1b[H");
}

fn cursor_up(n: i32) {
    myprint!("\x1b[{}A", n);
}

fn cursor_down(n: i32) {
    myprint!("\x1b[{}B", n);
}

fn cursor_right(n: i32) {
    myprint!("\x1b[{}C", n);
}

fn cursor_left(n: i32) {
    myprint!("\x1b[{}D", n);
}

pub fn print_game(game: &mut Hanoi) {
    clear_screen();
    let size = game.size;

    for i in 0..3 {
        let discs = game.towers[i].size;

        // Print blank disc spaces on the tower
        for _ in size..discs {
            print_disc(0, size);
            cursor_down(1);
            cursor_left(odd_number(size));
        }

        // Print discs
        // Pop items into auxiliary stack to traverse through it
        let mut aux_stack = Stack::new();
        let mut aux_value = game.towers[i].pop();

        while aux_value != 0 {
            print_disc(aux_value, size);
            cursor_down(1);
            cursor_left(odd_number(size));
            aux_stack.push(aux_value);
            aux_value = game.towers[i].pop();
        }

        // Give the items back
        aux_value = aux_stack.pop();

        while aux_value != 0 {
            game.towers[i].push(aux_value);
            aux_value = aux_stack.pop();
        }

        // Undo last cursor movement
        cursor_up(1);
        cursor_right(odd_number(size));

        // Prepare for next tower
        cursor_right(1);
        cursor_up(size - 1);
    }

    // Print HUD
    cursor_down(size);
    cursor_left(100);
    print_hud(size);
}

fn print_hud(size: i32) {
    let largest_disc = odd_number(size);
    let center = (largest_disc - 1) / 2;
    let mut tower_counter = 1;

    // Print tower number
    for _ in 0..3 {
        for i in 0..largest_disc {
            if (i % largest_disc) == center {
                myprint!("{}", tower_counter);
                tower_counter += 1;
            } else {
                myprint!(" ");
            }
        }
        myprint!(" "); // Tower space
    }

    println!("\n\n12, 13, 21, 23, 31, 32 - Possible moves");
    println!("0 - Start a new game");
    myprint!("Insert a move: ");
}