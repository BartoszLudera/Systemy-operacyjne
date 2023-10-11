========================================================================
Autor: Bartosz Ludera,                                        16.06.2022
========================================================================

* Zawartosc:
============

Katalog Zestaw2a zawiera 1 kod źródłowy do 1 zadania z Ćwiczenia A2, 
plik Makefile
--------------------------------------------------------------------

I.  Program wypisujacy identyfikatory UID, GID, PID, PPID i PGID dla 
    danego procesu używając fukcji clone.
    
    Różnica pomiędzy funckją exec i fork a clone:
    
    funkcja clon tak jak fork, tworzy nowy proces. W przeciwieństwie 
    do forka, wywołania te umożliwiają procesowi potomnemu współdzielenie 
    części kontekstu wykonania z procesem wywołującym, 
    takich jak przestrzeń pamięci, tablica deskryptorów plików 
    i tablica obsługi sygnałów.
    
    Program sklada sie z: 
    1) cwiczenie2a.c  - program glowny. 
------------------------------------------------------------------------

* Jak uruchomic programy:
=========================

Katalog zawiera program Makefile do kompilacji, linkowania
i uruchamiania powyzszych programow, a takze czyszczenia katalogu 
i jego archiwizacji.

-> Aby uruchomic 1-szy program, nalezy wykonac komende:
       make run2

---> Dla pewnosci, ze wykonywane sa polecenia zdefiniowane w Makefile,
     a nie wbudowane polecenia make'a, uzyc opcji -r, tzn.
       make -r run2

-> Aby wyczyscic zawartosc katalogu (usunac zbedne pliki), nalezy wykonac:
       make clean

-> W celu archiwizacji oraz kompresji katalogu nalezy wykonac:
       make tar

========================================================================

