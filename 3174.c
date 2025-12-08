/* Kauan Dias Caisley AED 1 Grupo de Trabalho do Noel */

#include <stdio.h>
#include <string.h>

int main() {
    int N, h;
    int horas_totais[4] = {0}; // 0 = bonecos, 1 = arquitetos, 2 = músicos, 3 = desenhistas
    char nome[100], g[20];

    scanf("%d", &N);

    while (N--) {
        scanf("%s %s %d", nome, g, &h);

        if (strcmp(g, "bonecos") == 0)
            horas_totais[0] += h;
        else if (strcmp(g, "arquitetos") == 0)
            horas_totais[1] += h;
        else if (strcmp(g, "musicos") == 0)
            horas_totais[2] += h;
        else
            horas_totais[3] += h;
    }

    printf("%d\n", horas_totais[0] / 8 + horas_totais[1] / 4 + horas_totais[2] / 6 + horas_totais[3] / 12
    );

    return 0;
}
