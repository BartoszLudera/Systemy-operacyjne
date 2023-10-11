========================================================================
Autor: Bartosz Ludera,                               Krakow, 4.05.2022
========================================================================

* Zawartosc:
============

Katalog Zestaw6 zawiera 4 kody źródłowe do 6 ćwiczenai, plik Makefile.
--------------------------------------------------------------------

I.  Własna biblioteka prostych funkcji do tworzenia, otwierania, uzyskiwania wartości, 
    operowania, zamykania i usuwania semafora.

    Program sklada sie z: 
    1) semafory.c  - program glowny. 
    2) semafory.h

II. Program powielacz.c tworzy podaną ilość kopii programu inkrementator.c, który implementuje 
    problem korzystania z zasobu współdzielonego.
    Program sklada sie z: 

    1) powielacz.c  - program glowny. 

III. Program inkrementator.c odczytuje plik numer.txt, inkrementuje zawartą
     w nim liczbę i zapisuje ją z powrotem do pliku
     Program sklada sie z: 

    1) inkrementator.c  - program glowny. 
------------------------------------------------------------------------

* Jak uruchomic programy:
=========================

Katalog zawiera program Makefile do kompilacji, linkowania
i uruchamiania powyzszych programow, a takze czyszczenia katalogu 
i jego archiwizacji.

-> Aby uruchomic programy należy wpisać:
	make run6

---> Dla pewnosci, ze wykonywane sa polecenia zdefiniowane w Makefile,
     a nie wbudowane polecenia make'a, uzyc opcji -r, tzn.
       make -r run6

-> Aby wyczyscic zawartosc katalogu (usunac zbedne pliki), nalezy wykonac:
       make clean

-> W celu archiwizacji oraz kompresji katalogu nalezy wykonac:
       make tar

========================================================================
