%Instrukcja 1

% ZADANIE 1
% Utw�rz m-funkcje, kt�re dla macierzy A i B (wymiaru 2�2, 4�4, 8�8, 16�16,
% 32�32, 64�64, 128�128) o losowych warto�ciach element�w pozwol� okre�li� czas
% wykonania operacji:
% a) mno�enia macierzy A i B;
% b) mno�enia macierzy A przez wektor kolumnowy b o odpowiedniej liczbie
%    sk�adowych (tj. wymiaru 2�1, 4�1, 8�1, 16�1, 32�1, 64�1, 128�1);
% c) obliczenia wyznacznika macierzy A (polecenie det(A));
% d) obliczenia �ladu macierzy A (polecenie trace(A));
% e) rozk�adu tr�jk�tnego macierzy A (polecenie lu(A)).
%
% Wskaz�wki: Macierze oraz wektory losowe wygeneruj za pomoc� wbudowanego
% polecenia Matlaba randn(A). Do pomiaru czasu realizacji poszczeg�lnych operacji
% zastosuj stopwatch timer (polecenia tic, toc). W razie potrzeby (gdy czas mierzony dla
% pojedynczej operacji jest zbyt kr�tki) rejestruj czas 100-krotnego wykonania danej
% operacji (za pomoc� p�tli for i =1:100 � end).
% Aby uzyska� wiarygodny wynik, ka�d� funkcj� wywo�aj 5-krotnie i w analizie
% por�wnawczej operacji z punkt�w (a) - (e) uwzgl�dnij �redni� arytmetyczn�
% otrzymanych warto�ci czas�w.
lOperacji = 100;

A1 = randn(2);
A2 = randn(4);
A3 = randn(8);
A4 = randn(16);
A5 = randn(32);
A6 = randn(64);
A7 = randn(128);

B1 = randn(2);
B2 = randn(4);
B3 = randn(8);
B4 = randn(16);
B5 = randn(32);
B6 = randn(64);
B7 = randn(128);

b1 = randn(2, 1);
b2 = randn(4, 1);
b3 = randn(8, 1);
b4 = randn(16, 1);
b5 = randn(32, 1);
b6 = randn(64, 1);
b7 = randn(128, 1);

clc;
disp(['Czasy ', num2str(lOperacji), ' operacji: '])

czas = 0;
for i=1:lOperacji 
    czas = czas + ZADANIE1_mnozenieMacierzy(A7, B7);
end;
disp([' - Mnozenia macierzy:              ', num2str(czas)])

czas = 0;
for i=1:lOperacji
    czas = czas + ZADANIE1_mnozenieMacierzyPrzezWektor(A7, b7);
end;
disp([' - Mnozenia macierzy przez wektor: ', num2str(czas)])

czas = 0;
for i=1:lOperacji
    czas = czas + ZADANIE1_wyznacznikMacierzy(A7);
end;
disp([' - Wyznacznika macierzy:           ', num2str(czas)])

czas = 0;
for i=1:lOperacji
    czas = czas + ZADANIE1_sladMacierzy(A7);
end;
disp([' - Sladu macierzy:                 ', num2str(czas)])
