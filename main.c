#include <stdio.h>
#include<netinet/in.h>
#include<stdlib.h>

uint32_t File_load (char *path){

    uint32_t nbo;
    FILE *fp = fopen(path, "r");
    fread(&nbo,1,sizeof(uint32_t),fp);
    fclose(fp);
    return ntohl(nbo);
}

int main(int argc, char* argv[])
{

    uint32_t n1 = File_load(argv[2]);
    uint32_t n2 = File_load(argv[3]);


    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",n1,n1,n2,n2,n1+n2,n1+n2);

    return 0;
}



