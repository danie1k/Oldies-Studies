program zad_10_1;
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
         '¹' : c := #165;
         'æ' : c := #134;
         'ê' : c := #169;
         '³' : c := #136;
         'ñ' : c := #228;
         'ó' : c := #162;
         'œ' : c := #152;
         '¿' : c := #190;
         'Ÿ' : c := #171;
         '¥' : c := #164;
         'Æ' : c := #143;
         'Ê' : c := #168;
         '£' : c := #157;
         'Ñ' : c := #227;
         'Ó' : c := #224;
         'Œ' : c := #151;
         '¯' : c := #189;
         '' : c := #141;
      else
         c := s[i];
   end;
   s[i] := c;
end;
Result := s;
end;


      {g³ówna czêœæ programu}


   var imie: array[1..10] of string;
       nazwisko: array[1..10] of string;
       adres: array[1..10] of string;
       ilosc, i: integer;

begin

     Welcome('10.1');
     Writeln('   Program tworzy baze danych maksymalnie 10 studentow'); Writeln;

REPEAT
     Write(PL('Podaj iloœæ studentów: ')); Readln(ilosc);
     if ilosc > 10 then Writeln(PL(' Mo¿e byæ maksymalnie 10 studentów!'));
     Writeln;
UNTIL ilosc <= 10;

for i := 1 to ilosc do
begin
     Writeln; Writeln(' Student ', i, ': ');
     Write('  Podaj imie: '); Readln(imie[i]);
     Write('  Podaj nazwisko: '); Readln(nazwisko[i]);
     Write('  Podaj miejsce zamieszkania: '); Readln(adres[i]);
end;

ClrScr;

Writeln; Writeln;
Writeln('   ',chr(218),'----',chr(194),'----------------',chr(194),'----------------',chr(194),'--------------------------------',chr(191));
Writeln('   ',chr(179),' ID ',chr(179),PL('           Imiê '),chr(179),'       Nazwisko ',chr(179),'                          Adres ',chr(179));
Writeln('   ',chr(195),'----',chr(197),'----------------',chr(197),'----------------',chr(197),'--------------------------------',chr(180));

for i := 1 to ilosc do
begin
    Writeln('   ',chr(179),' ',i:2,' ',chr(179),' ',imie[i]:14,' ',chr(179),' ',nazwisko[i]:14,' ',chr(179),' ',adres[i]:30,' ',chr(179))
end;

Writeln('   ',chr(192),'----',chr(193),'----------------',chr(193),'----------------',chr(193),'--------------------------------',chr(217));

Readln;
end.
