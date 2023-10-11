========================================================================
Autor: Bartosz Ludera,                               Krakow, 8.06.2022
========================================================================

* Zawartosc:
============

Katalog Zestaw9 zawiera 3 kody źródłowe do 9 ćwiczenai, 
orazplik Makefile.
--------------------------------------------------------------------

I.  Program sklada sie z: 
       Biblioteka z funkcjami potrzebnymi do obsługi watków.

    1) watki.c
    2) watki.h

II. Porgram główny:
       Uruchamia podaną ilość wątków o podanej ilości sekcji krytycznych.   
       Każdy wątek uzyskuje dostęp do zmiennej globalnej i zwiększa jej wartość o 1.

    Program sklada sie z:
    1) cwiczenie9.c

    
------------------------------------------------------------------------

* Jak uruchomic programy:
=========================

Katalog zawiera program Makefile do kompilacji, linkowania
i uruchamiania powyzszych programow, a takze czyszczenia katalogu 
i jego archiwizacji.

-> Aby uruchomic programy należy wpisać:
	make run9

---> Dla pewnosci, ze wykonywane sa polecenia zdefiniowane w Makefile,
     a nie wbudowane polecenia make'a, uzyc opcji -r, tzn.
       make -r run9

-> Aby wyczyscic zawartosc katalogu (usunac zbedne pliki), nalezy wykonac:
       make clean

-> W celu archiwizacji oraz kompresji katalogu nalezy wykonac:
       make tar

========================================================================
