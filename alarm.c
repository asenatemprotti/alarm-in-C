#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

int main() {
    int hr_atual, min_atual, sec_atual;
    int hr_despertador, min_despertador, sec_despertador;
    int a, b, i;
    char ch;
    
    // Obter horário atual
    printf("\nDigite a hora atual: ");
    scanf("%d", &hr_atual);
    printf("\nDigite os minutos atuais: ");
    scanf("%d", &min_atual);
    printf("\nDigite os segundos atuais: ");
    scanf("%d", &sec_atual);
    
    // Obter horário do despertador
    printf("\nDigite a hora do despertador: ");
    scanf("%d", &hr_despertador);
    printf("\nDigite os minutos do despertador: ");
    scanf("%d", &min_despertador);
    printf("\nDigite os segundos do despertador: ");
    scanf("%d", &sec_despertador);
    
    if (hr_atual > 23 || hr_atual < 0 || min_atual > 59 || min_atual < 0 || sec_atual > 59 || sec_atual < 0 ||
        hr_despertador > 23 || hr_despertador < 0 || min_despertador > 59 || min_despertador < 0 || sec_despertador > 59 || sec_despertador < 0) {
        printf("\nValor invalido");
    } else {
        while (1) {
            for (i = hr_atual; i <= 23; i++) { // horas
                for (a = (i == hr_atual) ? min_atual : 0; a <= 59; a++) { // minutos
                    for (b = (i == hr_atual && a == min_atual) ? sec_atual : 0; b <= 59; b++) { // segundos
                        printf("\r%02d:%02d:%02d", i, a, b); // o display do relogio 
                        Sleep(1);  // delay de 1 segundo
                        if (i == hr_despertador && a == min_despertador && b == sec_despertador) { // comparando a hora do despertador
                            printf("\nPara desligar o alarme, digite 0: ");
                            do {
                                printf ("\a");
                                if (kbhit()) {
                                	ch = getch();
                                	if (ch=='0')
     									exit(0);
     							}
     							Sleep(1000);
                            } while (1);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
