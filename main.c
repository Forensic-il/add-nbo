#include <stdio.h>
#include<netinet/in.h>
#include<stdlib.h>

int Hex_to_Dec(uint32_t h);

int main()
{
    FILE *fp;
    uint32_t nbo1;
    fp = fopen("file1.bin","r");
    fread(&nbo1,1,4,fp);
    uint32_t hbo1 = ntohl(nbo1);

    FILE *fp2;
    uint32_t nbo2;
    fp2 = fopen("file2.bin","r");
    fread(&nbo2,1,4,fp2);
    uint32_t hbo2 = ntohl(nbo2);

    int a = Hex_to_Dec(hbo1);
    int b = Hex_to_Dec(hbo2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",a,hbo1,b,hbo2,a+b,a+b);
    fclose(fp);
    return 0;
}

int Hex_to_Dec(uint32_t h){
    char s[8];
    sprintf(s, "%x", h);
    int dec = strtol(s,NULL,16);
    return dec;
}

