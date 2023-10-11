#ifndef WATKI_H
#define WATKI_H

#include <pthread.h>

pthread_t utworz_watek (void *funkcja(void *), void *argument);// utwórz nowy wątek, który rozpocznie wykonywać "funkcja" i przyjmie "argument"

void polacz_watek (pthread_t watek);// czekaj na zakończenie i połącz wątek

void inicjalizuj_mutex (pthread_mutex_t *mutex);// inicjalizuj mutex

void zamknij_mutex (pthread_mutex_t *mutex);// zamknij mutex (wejdź do sekcji krytycznej)

void otworz_mutex (pthread_mutex_t *mutex);// otwórz mutex (wyjdź z sekcji krytycznej)

void usun_mutex (pthread_mutex_t *mutex);// usuń mutex

#endif