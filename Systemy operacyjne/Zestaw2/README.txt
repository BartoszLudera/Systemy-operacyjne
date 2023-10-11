========================================================================
Autor: Bartosz Ludera,                               Krakow, 6.04.2022
========================================================================

* Zawartosc:
============

Katalog Zestaw2 zawiera 4 kody źródłowe do 3 ćwiczenai, plik Makefile.
--------------------------------------------------------------------

I.  Program słuzy do obsługi sygnałów z możliwością:
    -wykonania operacji domyślnej
    -ignorowania sygnału
    -własniej obsługi sygnału

    Program sklada sie z: 
    1) zad1.c  - program glowny. 

II. Program poprzez funkcję exec w procesie potomnym innego procesu wysyła 
    do niego sygnał poprzez funkcję systemową kill.
    Program sklada sie z: 

    1) zad2.c  - program glowny. 

III. Program uruchamia w procesie macierzysytm proces potomny i sprawdza czy 
    stał się liderem nowej grupy procesów (poprzez funkcje stpgid).

    1) zad3.c  - program glowny. 

IV. Program ośredni który tworzy 3 procesy potomne poprzez funckje exec 
    uruchamiając program z zad1.
    1) zad3a.c  - program glowny (pośredni do zad3). 
------------------------------------------------------------------------

* Jak uruchomic programy:
=========================

Katalog zawiera program Makefile do kompilacji, linkowania
i uruchamiania powyzszych programow, a takze czyszczenia katalogu 
i jego archiwizacji.

-> Aby uruchomic 1-szy program, nalezy wykonac komende:
       make runzad1 o=(nazwa operacji[d,i,w]) s=(nr_syganlu)

-> Aby uruchomic 2-gi program, nalezy wykonac komende:
       make runzad2 o=[d,i,w] s=[nr_sygnalu] ./(nazwa zadania z podpunktu a))

-> Aby uruchomic 3-ci program, nalezy wykonac komende:
       make runzad3 o=[d,i,w] s=[nr_sygnalu] ./zad3a ./(nazwa zad z podp. a))

-> Aby uruchomic 4-ci program, 
        należy uruchomić program 3-ci (jest to prgram główny)

---> Dla pewnosci, ze wykonywane sa polecenia zdefiniowane w Makefile,
     a nie wbudowane polecenia make'a, uzyc opcji -r, tzn.
       make -r runzad1 itd

-> Aby wyczyscic zawartosc katalogu (usunac zbedne pliki), nalezy wykonac:
       make clean

-> W celu archiwizacji oraz kompresji katalogu nalezy wykonac:
       make tar

========================================================================
