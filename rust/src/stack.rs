struct Node {
    element: i32,
    next: Option<Box<Node>>
}

pub struct Stack {
    pub size: i32,
    top: Option<Box<Node>>
}

impl Stack {
    pub fn new() -> Self {
        Stack {
            size: 0,
            top: None
        }
    }

    pub fn push(&mut self, element: i32) {
        let new_node = Box::new(Node{
            element: element,
            next: self.top.take()
        });

        self.top = Some(new_node);
        self.size += 1;
    }

    pub fn pop(&mut self) -> i32 {
        match self.top.take() {
            None => {
                return 0;
            }
            
            Some(node) => {
                self.top = node.next;
                self.size -= 1;
                
                return node.element;
            }
        }
    }

    pub fn peek(&self) -> i32 {
        match &self.top {
            None => {
                return 0;
            }

            Some(n) => {
                return n.element;
            }
        }
    }
}

#[cfg(test)]
mod test {
    #[test]
    fn basics() {
        use crate::stack::Stack;

        let mut list = Stack::new();

        // Check empty list behaves right
        assert_eq!(list.pop(), 0);

        // Populate list
        list.push(1);
        list.push(2);
        list.push(3);

        // Check normal removal
        assert_eq!(list.pop(), 3);
        assert_eq!(list.pop(), 2);

        // Push some more just to make sure nothing's corrupted
        list.push(4);
        list.push(5);

        // Check normal removal
        assert_eq!(list.pop(), 5);
        assert_eq!(list.pop(), 4);

        // Check exhaustion
        assert_eq!(list.pop(), 1);
        assert_eq!(list.pop(), 0);
    }
}
