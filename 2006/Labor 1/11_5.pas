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


   var liczba_dziesietna, x: integer;
       liczba_binarna: string;



begin

     Welcome('11.5');

Write(PL('   Podaj liczb� ca�kowit� w systemie dziesi�tnym: ')); Readln(liczba_dziesietna);

x := liczba_dziesietna;
liczba_binarna := '';
REPEAT
      if (x mod 2) = 1 then liczba_binarna := '1' + liczba_binarna
      else
          if (x mod 2) = 0 then liczba_binarna := '0' + liczba_binarna;

      x := (x div 2);
UNTIL x = 0;

Writeln;Writeln;
Writeln(PL('      Liczba dzisi�tna: '),liczba_dziesietna,' w systemie bianrnym wynosi: ',liczba_binarna);

Readln;
end.
