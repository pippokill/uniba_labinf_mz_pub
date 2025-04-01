#include "labirinto_p.c"

#ifndef LABIRINTO_P_H
#define LABIRINTO_P_H

labirinto creaLabirinto();

int muovi(labirinto* l, char comando);

void stampaLabirinto(labirinto l, int hide);

#endif