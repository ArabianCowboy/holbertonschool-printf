#include "main.h"
int main(void){
    int r1 = _printf("A:%c S:%s %%:%%\n", X, "Hi");
    int r2 = _printf("%");
    (void)r1; (void)r2;
    return 0;
}
