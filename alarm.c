#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

int main() {
    int hr_atual, min_atual, sec_atual;
    int hr_despertador, min_despertador, sec_despertador;
    int a, b, i;
    int alarme_ativo = 1;
    int hr_retomada, min_retomada, sec_retomada; // Variaveis auxiliares para retomar a contagem

    // Obter horario atual
    printf("\nDigite a hora atual: ");
    scanf("%d", &hr_atual);
    printf("\nDigite os minutos atuais: ");
    scanf("%d", &min_atual);
    printf("\nDigite os segundos atuais: ");
    scanf("%d", &sec_atual);

    // Obter horario do despertador
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
            // Loop para retomar a contagem a partir do ponto atual
            for (i = hr_atual; i <= 23; i++) { // horas
                for (a = (i == hr_atual) ? min_atual : 0; a <= 59; a++) { // minutos
                    for (b = (i == hr_atual && a == min_atual) ? sec_atual : 0; b <= 59; b++) { // segundos
                        printf("\r%02d:%02d:%02d", i, a, b); // o display do relogio
                        Sleep(1);  // delay de 1 segundo
                        if (i == hr_despertador && a == min_despertador && b == sec_despertador) { // comparando a hora do despertador
                            while (1) {
                                if (_kbhit()) { // Verificar se alguma tecla foi pressionada
                                    int key = _getch();
                                    if (key == '0') { // Se a tecla pressionada for '0'
                                        hr_retomada = i; // Armazenar os valores atuais nas variaveis auxiliares
                                        min_retomada = a;
                                        sec_retomada = b;
                                        goto continue_counting; // Ir para o label continue_counting para retomar a contagem
                                    }
                                }
                                printf("\a"); // Emitir o bip
                                Sleep(1000); // Aguardar 1 segundo antes de emitir o proximo bip
                            }
                            break; // Sair do loop do despertador
                        }
                    }
                }
            }
        }

        continue_counting:
        // Retomar a contagem do relogio
        printf("\nContagem retomada!\n");
        for (i = hr_retomada; i <= 23; i++) { // horas
            for (a = (i == hr_retomada) ? min_retomada : 0; a <= 59; a++) { // minutos
                for (b = (i == hr_retomada && a == min_retomada) ? sec_retomada : 0; b <= 59; b++) { // segundos
                    printf("\r%02d:%02d:%02d", i, a, b); // o display do relogio
                    Sleep(1);  // delay de 1 segundo
                }
            }
        }
    }

    return 0;
}
