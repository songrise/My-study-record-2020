/* do_ while. c -- 出口 条件 循环 */ 
#include <stdio.h> 
int main(void) 
{ 
    const int secret_code = 13; 
    int code_entered; 
    do //below is loop body, when while condition is true, loop it
    { 
        printf("To enter the triskaidekaphobia therapy club,\n");  // triskaidekaphobia 13恐惧症
        printf("please enter the secret code number: "); 
        scanf("%d", &code_entered); 
    } while (code_entered != secret_code); 
    printf("Congratulations! You are cured!\n"); 
    
    return 0; 
}

