#include <stdio.h>

#define INPUTS 2
#define HIDDEN 4  /* Número de neuronas en la capa oculta */
#define OUTPUTS 1
#define SAMPLES 4
#define EPOCHS 50000  /* Más entrenamiento para sobrecargar la CPU */
#define LEARNING_RATE 1

/* Datos de entrenamiento (x1, x2, bias) -> Etiqueta */
int train_data[SAMPLES][INPUTS + 1] = {
    {0, 0, 1}, {0, 1, 1}, {1, 0, 1}, {1, 1, 1}
};
int labels[SAMPLES] = {0, 1, 1, 0};  /* XOR */

/* Pesos de la capa oculta */
int weights_hidden[HIDDEN][INPUTS + 1];
/* Pesos de la capa de salida */
int weights_output[OUTPUTS][HIDDEN + 1];

int activation(int sum) {
    return sum >= 0 ? 1 : 0;
}

/* Inicializar pesos */
void initialize_weights() {
    int i, j;
    for (i = 0; i < HIDDEN; i++)
        for (j = 0; j < INPUTS + 1; j++)
            weights_hidden[i][j] = (i + j) % 2 ? 1 : -1;

    for (i = 0; i < OUTPUTS; i++)
        for (j = 0; j < HIDDEN + 1; j++)
            weights_output[i][j] = (i + j) % 2 ? -1 : 1;
}

void train_network() {
    int i, j, k, l, sum_hidden[HIDDEN], sum_output[OUTPUTS], error, output;
    
    for (i = 0; i < EPOCHS; i++) {
        for (j = 0; j < SAMPLES; j++) {
            /* Forward Pass */
            for (k = 0; k < HIDDEN; k++) {
                sum_hidden[k] = 0;
                for (l = 0; l < INPUTS + 1; l++)
                    sum_hidden[k] += train_data[j][l] * weights_hidden[k][l];
                sum_hidden[k] = activation(sum_hidden[k]);
            }

            for (k = 0; k < OUTPUTS; k++) {
                sum_output[k] = 0;
                for (l = 0; l < HIDDEN + 1; l++)
                    sum_output[k] += sum_hidden[l] * weights_output[k][l];
                output = activation(sum_output[k]);
            }

            /* Backpropagation (Corrección de pesos) */
            error = labels[j] - output;
            for (k = 0; k < OUTPUTS; k++)
                for (l = 0; l < HIDDEN + 1; l++)
                    weights_output[k][l] += LEARNING_RATE * error * sum_hidden[l];

            for (k = 0; k < HIDDEN; k++)
                for (l = 0; l < INPUTS + 1; l++)
                    weights_hidden[k][l] += LEARNING_RATE * error * train_data[j][l];
        }
    }
}

void test_network() {
    int i, j, k, sum_hidden[HIDDEN], sum_output[OUTPUTS], output;
    
    printf("\nPruebas de Red Neuronal XOR:\n");
    for (i = 0; i < SAMPLES; i++) {
        for (j = 0; j < HIDDEN; j++) {
            sum_hidden[j] = 0;
            for (k = 0; k < INPUTS + 1; k++)
                sum_hidden[j] += train_data[i][k] * weights_hidden[j][k];
            sum_hidden[j] = activation(sum_hidden[j]);
        }

        for (j = 0; j < OUTPUTS; j++) {
            sum_output[j] = 0;
            for (k = 0; k < HIDDEN + 1; k++)
                sum_output[j] += sum_hidden[k] * weights_output[j][k];
            output = activation(sum_output[j]);
        }

        printf("Entrada: [%d, %d] -> Salida: %d\n", train_data[i][0], train_data[i][1], output);
    }
}

int main() {
    initialize_weights();
    train_network();
    test_network();
    return 0;
}
