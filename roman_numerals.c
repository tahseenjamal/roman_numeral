#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DECIMAL 10

char initial[] = {'I', 'X', 'C', 'M'};
char middle[] = {'V', 'L', 'D'};
char last[] =  {'X', 'C', 'M'};


char* roman(char *dest, int number, unsigned char pos) {

    int digit =  number % 10  ;

    number /= 10;

    if(number != 0 )

        dest = roman(dest, number, pos + 1);

    switch (digit) {

        case 1 ... 3:

            while(digit) {

                (*dest++) = initial[pos];

                digit--;
            
            }

            break;

        case 4 ... 8:

            if(digit == 4) {

                if(pos < 3)
                {
                    (*dest++) = initial[pos];
                    (*dest++) = middle[pos];

                }

                else {

                    while(digit) {
                        (*dest++) = initial[pos];
                        digit--;

                    }


                }


            } 
            else {

                (*dest++) = middle[pos];
                digit -= 5;

                while(digit) {
                    (*dest++) = initial[pos];
                    digit--;

                }

            }

            break;


        case 9:

            (*dest++) = initial[pos];
            (*dest++) = last[pos];

            break;


    }

    if(pos == 0)

        *dest = '\0';

    return dest;


}

char* solution(int n) {

    char* final;

    final = (char*)malloc(16 * sizeof(char));

    roman(final, n, 0);

    return final;

}


int main(int argc, char* argv[]){

    char *garbage;

    int number = atoi(argv[1]);

    char *result = solution(number);

    printf("Roman Numeral: %s\n", result);

    free(result);

    return 0;
}
