unit stack;

interface

type
    TNode = record
        element: integer;
        next: ^TNode;
    end;

    TStack = record
        size: cardinal;
        top: ^TNode;
    end;

function newStack(): TStack;
procedure push(stack: TStack; element: integer);
function pop(stack: TStack): integer;
function peek(stack: TStack): integer;

implementation

function newStack(): TStack;
begin
    newStack.size := 0;
    newStack.top := nil;
end;

procedure push(stack: TStack; element: integer);

var
    newNode: ^TNode;

begin
    newNode := GetMem(sizeOf(TNode));

    newNode^.element := element;
    newNode^.next := stack.top;

    stack.top := newNode;
    stack.size += 1;
end;

function pop(stack: TStack): integer;

var
    auxElem: integer;
    auxPtr: ^TNode;

begin
    if stack.top = nil then
        exit(0)
    else
    begin
        auxElem := stack.top^.element;
        auxPtr := stack.top^.next;

        freeMem(stack.top);

        stack.top := auxPtr;
        stack.size -= 1;

        pop := auxElem;
    end;
end;    

function peek(stack: TStack): integer;
begin
    if stack.top = nil then
        exit(0)
    else
        exit(stack.top^.element)
end;

end.