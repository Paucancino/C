#ifndef CALCULADORA_H
#define CALCULADORA_H

// Prototipos
void menu(int& opc);
void pedirOperandos(float& a, float& b);
float suma(float a, float b);
float resta(float a, float b);
float multiplicacion(float a, float b);
bool division(float a, float b, float& resultado);

#endif