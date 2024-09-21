#include <stdio.h>

int main() {
    int code;
    for(;;){
		printf("Show me your code,please.");
        scanf("%d",&code);
        if(code >= 100000 && code <= 999999)
        {
            printf("I am super hacker!");
            break;
        }
        else printf("Fake code!");
    }
    return 0;
}
