program Zad_8_1;
   uses Crt;


      {funkcje pomocnicze}


function Welcome(s : string) : string;
var w : integer;
begin
   ClrScr;
   Writeln;
   w := 0; Write(' ',chr(201)); repeat Write(chr(205)); w:=w+1; until w=26; Writeln(chr(187));
   Writeln(' ',chr(186),'                          ',chr(186));
   Writeln(' ',chr(186),'  Realizacja zadania ', s ,'  ',chr(186));
   Writeln(' ',chr(186),'                          ',chr(186));
   w := 0; Write(' ',chr(200)); repeat Write(chr(205)); w:=w+1; until w=6;
   Write(' Daniel Kuruc ');
   w := 0; repeat Write(chr(205)); w:=w+1; until w=6; Writeln(chr(188));
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


   var podzielne, liczba : string;
       i, podzielnych, x : longint;

begin

   Welcome('8.2');

   podzielne := '';
   i := 1;

   Writeln(PL('(Wpisanie zera ko�czy dzia�anie programu)')); Writeln;

   REPEAT
      Write(PL('Podaj liczb� x'), i ,': '); Readln(x);

      if (x mod 3 = 0) and (x <> 0) then
      begin
         podzielnych := podzielnych + 1;
         str(x,liczba);
         if podzielne = '' then podzielne := liczba
         else podzielne := podzielne + ', ' + liczba;
      end;
      if x = 0 then
      begin
         Writeln;
         Writeln('---------------------------------------------------');
         Writeln(PL(' ��cznie sprawdzono liczb: '), i-1);
         Writeln(PL(' W tym podzielnych przez 3: '), podzielnych);
         if podzielne <> '' then Writeln(' Liczby: ', podzielne);
         Writeln('---------------------------------------------------');
      end;
      i := i + 1;
   UNTIL x = 0;

   Readln;
end.
