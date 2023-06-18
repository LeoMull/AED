/*
*Fac¸a uma funcao que receba uma temperatura 
*em graus Celsius e retorne-a convertida em 
*graus Fahrenheit. A formula de conversao e:
* F = C ∗ (9.0/5.0) + 32.0, sendo F a
*temperatura em Fahrenhit e C a temperatura em Celsius.
*/

#include <stdio.h>

float converte(float temp);

int main(){
	float tempC, tempF;
	printf("Digite a tempertatura em Celsius: ");
	scanf("%f", &tempC);
	tempF = converte(tempC);
	printf("Temperatura em Fahrenheit = %f", tempF);
}
float converte(float temp){
	return temp*(9.0/5.0)+32.0;
}
