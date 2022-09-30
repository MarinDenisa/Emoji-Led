#include <mega164a.h>
#include <delay.h>
char smile[8] = {0xFF, 0x99, 0x99, 0xFF, 0x81, 0xBD, 0x81, 0xFF};
char face[8] = {0xc3, 0xbd, 0x5a, 0x7e, 0x5a, 0x66, 0xbd, 0xc3};
char heart[8] = {0xff, 0x99, 0x0, 0x0, 0x81, 0xc3, 0xe7, 0xff};
char pacman[8] = {0xc7, 0x83, 0x31, 0x33, 0x7, 0x3, 0x81, 0xc3};
char surprised[8] = {0xff, 0x99, 0x99, 0xff, 0xe7, 0xdb, 0xdb, 0xe7};
char umbrella[8] = {0xe7, 0xc3, 0x81, 0x0, 0xf7, 0xf7, 0xd7, 0xef};
char house[8] = {0xe7, 0xc3, 0x81, 0x0, 0x99, 0x99, 0x81, 0x81};
char etti[8] = {0xff, 0xfe, 0x31, 0x7a, 0x2a, 0x6a, 0x2e, 0xc7};
char skull[8] = {0xc3, 0xa5, 0xa5, 0x81, 0xc3, 0xc3, 0xff, 0xff};
char sad[8] = {0xff, 0x99, 0x99, 0xff, 0xff, 0xc3, 0xbd, 0x7e};
void main(void) {
 int i;
 // DDRA - linii matrice LED - setarea tutuor pinilor ca output
 DDRA = 0xFF;
 // DDRC - coloane matrice LED - setarea tutuor pinilor ca output
 DDRC = 0xFF;
 // DDRD - butoane - setarea tutuor pinilor ca input
 DDRD = 0x0;
 while (1) {
 // Pornirea LED-urilor se face pe o singura linie la
 // un moment de timp dat, insa, datorita vitezei,
 // ochiul uman va vedea intreaga imagine
 // PORTA - linii matrice LED-uri (active pe 1)
 // PORTC - coloane matrice LED-uri (active pe 0)
 // Parcurge matricea de LED-uri rand cu rand
 for (i = 0; i < 8; i++) {
 // Citire stare butoane (buton1 - dreapta, buton3 - stanga)
 char button1 = PIND & (1 << 0);
 char button2 = PIND & (1 << 1);
 char button3 = PIND & (1 << 2);

 // 111 - Toate butoanele apasate
 if (button1 && button2 && button3)
 PORTC = etti[i];
 else if (button1 && button2 && !button3)
 PORTC = house[i];
 else if (button1 && !button2 && button3)
 PORTC = umbrella[i];
 else if (button1 && !button2 && !button3)
 PORTC = surprised[i];
 else if (!button1 && button2 && button3)
 PORTC = skull[i];
 else if (!button1 && button2 && !button3)
 PORTC = face[i];
 else if (!button1 && !button2 && button3)
 PORTC = heart[i];
 // 000 - Niciun buton apasat
 else if (!button1 && !button2 && !button3)
 PORTC = sad[i];
 // PORTA - se shifteaza cu 1 (se inmulteste cu 2) pentru
 // a prelucra urmatoarea linie
 PORTA = (1 << i);
 delay_ms(10);
 }
 }
}
