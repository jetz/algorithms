#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool
is_digit(char c){
    return c >= '0' && c <= '9';
}

int
find(char *seq, char c){
    if (seq == NULL) 
        return -1;
    size_t len = strlen(seq);
    for (int i = 0; i < len; i++) {
        if (seq[i] == c) 
            return i;
    }
    return -1;
}

double
str2double(char *seq){
    assert(seq != NULL);

    double result = 0.0;

    bool is_negtive = false;
    bool has_integer = true;
    bool has_fraction = true;

    int start_pos = 0;
    size_t len = strlen(seq);

    if (seq[0] == '-'){ // negtive
        is_negtive = true;
        start_pos = 1;
    }
    int dot_pos = find(seq,'.');
    if (dot_pos == -1) {
        has_fraction = false;
        dot_pos = len;
    } else if ((is_negtive && dot_pos == 1) || (!is_negtive && dot_pos == 0))
        has_integer = false;
       
    if (has_integer){ 
        for (int i = dot_pos - 1; i >= start_pos; i--) { //handle integer part
            if (!is_digit(seq[i])) {
                printf("Wrong Format Integer\n");
                exit(-1);
            }
            result += (seq[i] - '0') * pow(10, dot_pos -1 - i);
        }
    }
    if (has_fraction) { // handle fraction part
       for (int i = dot_pos + 1; i < len; i++) {
           if (!is_digit(seq[i])) {
               printf("Wrong Format Fraction\n");
               exit(-1);
           }
           result += (seq[i] - '0') * pow(10, dot_pos - i);
       }
    }
    if (is_negtive) {
        result = -result;
    }
    return result;
}


int main(int argc, const char *argv[]) {
    char *str1 = "-.123456";
    char *str2 = "12345.123";
    char *str3 = "-654321.321";
    char *str4 = "-000654321.321";
    char *str5 = "123a4.12";
    printf("%f\n",str2double(str1));
    printf("%f\n",str2double(str2));
    printf("%f\n",str2double(str3));
    printf("%f\n",str2double(str4));
    printf("%f\n",str2double(str5));
    return 0;
}
