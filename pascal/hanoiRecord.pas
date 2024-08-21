unit hanoiRecord;

interface

uses stack;

type
    THanoi = record
        size: integer;
        towers: array[0..2] of TStack;
    end;

    PHanoi = ^THanoi;

implementation

end.