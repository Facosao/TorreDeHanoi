unit stack;

interface

type
    TNode = record
        element: integer;
        next: ^TNode;
    end;

    TStack = record
        size: integer;
        top: ^TNode;
    end;

    PStack = ^TStack;

function new(): TStack;
procedure push(stack: PStack; element: integer);
function pop(stack: PStack): integer;
function peek(stack: PStack): integer;

implementation

function new(): TStack;
begin
    new.size := 0;
    new.top := nil;
end;

procedure push(stack: PStack; element: integer);

var
    newNode: ^TNode;

begin
    newNode := GetMem(sizeOf(TNode));

    newNode^.element := element;
    newNode^.next := stack^.top;

    stack^.top := newNode;
    stack^.size += 1;
end;

function pop(stack: PStack): integer;

var
    auxElem: integer;
    auxPtr: ^TNode;

begin
    if stack^.top = nil then
        exit(0)
    else
    begin
        auxElem := stack^.top^.element;
        auxPtr := stack^.top^.next;

        freeMem(stack^.top);

        stack^.top := auxPtr;
        stack^.size -= 1;

        pop := auxElem;
    end;
end;    

function peek(stack: PStack): integer;
begin
    if stack^.top = nil then
        exit(0)
    else
        exit(stack^.top^.element);
end;

procedure print(s: PStack);

var
    auxPtr: ^TNode;

begin
    auxPtr := s^.top;

    while auxPtr <> nil do
    begin
        writeLn(auxPtr^.element);
        auxPtr := auxPtr^.next;
    end;
    writeLn('-----');
end;

end.