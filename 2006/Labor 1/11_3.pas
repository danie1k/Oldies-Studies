program zad_11_3;
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


   var n: integer;
       Wn: real;

begin

     Welcome('11.3');

REPEAT
      Writeln(PL(' Podaj liczb� naturaln� n,'));
      Write(PL(' dla kt�rej ma zosta� policzona warto�� wyra�enia W(n): '));
      Readln(n);
      if  (n <= 0) then
      begin
          Writeln(PL('    B��D: Liczba muszi by� wi�ksza od zera!'));
          Writeln;
      end;

UNTIL n > 0;


if odd(n) then
   begin
     Wn := (n-5)*n;
     Writeln; Writeln;
     Writeln('     Podana liczba jest nieparzysta');
   end
else
   begin
     Wn := (n/2)+n*n;
     Writeln; Writeln;
     Writeln('     Podana liczba jest nieparzysta');
    end;

Writeln;
Writeln(PL('     Warto�� wyra�enia dla podanego n wynosi: W(n) = '),Wn:0:0);


Readln;
end.
