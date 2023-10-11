========================================================================
Autor: Bartosz Ludera,                               Krakow, 13.04.2022
========================================================================

* Zawartosc:
============

Katalog Zestaw3 zawiera 1 kod źródłowy do 4 ćwiczenai, plik Makefile.
--------------------------------------------------------------------

I.  Przesyłam poprzez potoki tekt pobrany od producenta który wysyła
    konsumentowi.

    Program sklada sie z: 
    1) zad1.c  - program glowny. 

* Jak uruchomic programy:
=========================

Katalog zawiera program Makefile do kompilacji, linkowania
i uruchamiania powyzszych programow, a takze czyszczenia katalogu 
i jego archiwizacji.

-> Aby uruchomic 1-szy program, nalezy wykonac komende:
       make runzad1 zad1in.txt zad1out.txt

---> Dla pewnosci, ze wykonywane sa polecenia zdefiniowane w Makefile,
     a nie wbudowane polecenia make'a, uzyc opcji -r, tzn.
       make -r runzad1 itd

-> Aby wyczyscic zawartosc katalogu (usunac zbedne pliki), nalezy wykonac:
       make clean

-> W celu archiwizacji oraz kompresji katalogu nalezy wykonac:
       make tar

========================================================================
