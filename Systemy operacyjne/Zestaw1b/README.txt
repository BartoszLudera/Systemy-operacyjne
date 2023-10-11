========================================================================
Autor: Bartosz Ludera,                               Krakow, 22.03.2022
========================================================================

* Zawartosc:
============

Katalog Zestaw1b zawiera 2 kody źródłowe do 1 zadania z ćw2 i 1 plik
zawierający funkcję używaną przez resztę zadań,
1 pliki txt zawiera odpowiedzi na pytanie z zadania a), plik Makefile
--------------------------------------------------------------------

I.  Program wypisujacy w identyfikatory UID, GID, PID, PPID i PGID dla 
    danego procesu używając fukcji exec.
    Program sklada sie z: 
    1) zad2_1.c  - program glowny. 
    2) processes.c, processes.h - funkcja wypusująca procesy

II. Program wypisujacy identyfikatory UID, GID, PID, PPID i PGID dla 
    danych procesów z zadania 1 ćw a).
    Program sklada sie z: 
    1) zad1.c  - program glowny. 
    2) processes.c, processes.h - funkcja wypusująca procesy

VI. Plik zad2_1pytanie.txt zawiera odpowiedz na pytanie do ćw a)
------------------------------------------------------------------------

* Jak uruchomic programy:
=========================

Katalog zawiera program Makefile do kompilacji, linkowania
i uruchamiania powyzszych programow, a takze czyszczenia katalogu 
i jego archiwizacji.

-> Aby uruchomic 1-szy program, nalezy wykonac komende:
       make
       następnie komende
       make runzad1
       i na końcu komende
       make runzad2_1 argument=./zad1.x

---> Dla pewnosci, ze wykonywane sa polecenia zdefiniowane w Makefile,
     a nie wbudowane polecenia make'a, uzyc opcji -r, tzn.
       make -r runzad1 itd


-> Aby wyczyscic zawartosc katalogu (usunac zbedne pliki), nalezy wykonac:
       make clean

-> W celu archiwizacji oraz kompresji katalogu nalezy wykonac:
       make tar

========================================================================
