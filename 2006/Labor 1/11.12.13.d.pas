program zad_11_5;
   uses Crt;


      {funkcje pomocnicze}


function Welcome(s : string) : string;
var w : integer;
begin
   ClrScr;
   Writeln;
   w := 0; Write(' ',chr(201)); repeat Write(chr(205)); w:=w+1; until w=27; Writeln(chr(187));
   Writeln(' ',chr(186),'                           ',chr(186));
   Writeln(' ',chr(186),'  Realizacja zadania ', s ,'  ',chr(186));
   Writeln(' ',chr(186),'                           ',chr(186));
   w := 0; Write(' ',chr(200)); repeat Write(chr(205)); w:=w+1; until w=6;
   Write(' Daniel Kuruc ');
   w := 0; repeat Write(chr(205)); w:=w+1; until w=7; Writeln(chr(188));
   Writeln;
   Writeln;
end;

function PL(s : string) : string;
   var i : integer;
       c : char;
begin
   for i := 1 to length(s) do
   begin
      case s[i] of
         '�' : c := #165;
         '�' : c := #134;
         '�' : c := #169;
         '�' : c := #136;
         '�' : c := #228;
         '�' : c := #162;
         '�' : c := #152;
         '�' : c := #190;
         '�' : c := #171;
         '�' : c := #164;
         '�' : c := #143;
         '�' : c := #168;
         '�' : c := #157;
         '�' : c := #227;
         '�' : c := #224;
         '�' : c := #151;
         '�' : c := #189;
         '�' : c := #141;
      else
         c := s[i];
   end;
   s[i] := c;
end;
Result := s;
end;


      {g��wna cz�� programu}


   var i, liczba: longint;
       pierwsza: boolean;

begin

     Welcome('123d');

REPEAT
      Write(PL('   Podaj dowoln� liczb� naturanl� wi�ksz� od 1: ')); Readln(liczba);
      if (liczba <= 1) then
      begin
           Writeln(PL('    B��D: Liczba ma by� ca�kowita i wi�ksza od 1, bez wyjatku!'));
           Writeln
      end;
UNTIL (liczba > 1);

pierwsza := true;
for i:=2 to liczba-1 do
begin
    if (liczba mod i) = 0 then {reszta z dzielenia ca�kowitego}
       pierwsza := false;
end;

Write('Podana liczba');
if not pierwsza then write(' nie');
Writeln(PL(' jest liczb� pierwsz�'));


Readln;
end.
