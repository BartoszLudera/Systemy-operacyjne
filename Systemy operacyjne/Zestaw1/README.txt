========================================================================
Autor: Bartosz Ludera,                               Krakow, 20.03.2022
========================================================================

* Zawartosc:
============

Katalog Zestaw1 zawiera 5 kodów źródłowych do 5 zadań z ćw1 i 1 plik
zawierający funkcję używaną przez resztę zadań,
2 pliki txt zawierające drzewo z zadania d) i odpowiedz na 
pytanie z zadania e), plik Makefile
--------------------------------------------------------------------

I.  Program wypisujacy w identyfikatory UID, GID, PID, PPID i PGID dla 
    danego procesu.
    Program sklada sie z: 
    1) zad1.c  - program glowny. 
    2) processes.c, processes.h - funkcja wypusująca procesy

II. Program wypisujacy w identyfikatory UID, GID, PID, PPID i PGID dla 
    danych procesó przy użyciu funkcji fork.
    Program sklada sie z: 
    1) zad2.c  - program glowny. 
    2) processes.c, processes.h - funkcja wypusująca procesy
    
III. Program wypisujacy w identyfikatory UID, GID, PID, PPID i PGID dla 
    danych procesów przy użyciu funkcji fork który używa funkcji sleep.
    Program sklada sie z: 
    1) zad3.c  - program glowny. 
    2) processes.c, processes.h - funkcja wypusująca procesy
    
VI.  Program wypisujacy w identyfikatory UID, GID, PID, PPID i PGID dla 
    danych procesów przy użyciu funkcji fork który używa funkcji wait.
    Program sklada sie z: 
    1) zad4.c  - program glowny. 
    2) processes.c, processes.h - funkcja wypusująca procesy
   
V.  Program wypisujacy w identyfikatory UID, GID, PID, PPID i PGID dla 
    danych procesów które stały się liderem.
    Program sklada sie z: 
    1) zad5.c  - program glowny. 
    2) processes.c, processes.h - funkcja wypusująca procesy

VI. Plik cwiczenie1_tree.txt zawiera drzewo procesów do zadania d)

VII. Plik zad5pytanie.txt zawiera odpowiedz na pytanei do zadania e)
------------------------------------------------------------------------

* Jak uruchomic programy:
=========================

Katalog zawiera program Makefile do kompilacji, linkowania
i uruchamiania powyzszych programow, a takze czyszczenia katalogu 
i jego archiwizacji.

-> Aby uruchomic 1-szy program, nalezy wykonac komende:
       make runzad1

---> Dla pewnosci, ze wykonywane sa polecenia zdefiniowane w Makefile,
     a nie wbudowane polecenia make'a, uzyc opcji -r, tzn.
       make -r runzad1

(Dokładnie to samo dla programów od 1 do 5, wywołanie poprzez runzad1, 
runzad2, runzad3, runzad4, runzad5

-> Aby wyczyscic zawartosc katalogu (usunac zbedne pliki), nalezy wykonac:
       make clean

-> W celu archiwizacji oraz kompresji katalogu nalezy wykonac:
       make tar

========================================================================
