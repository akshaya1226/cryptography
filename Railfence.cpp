#include<stdio.h>
#include<string.h>

int main()
{
    int i, j, k, l;
    char a[20], c[20], d[20];

    printf("\n\t\t RAIL FENCE TECHNIQUE\n\n");
    printf("Enter the input string : ");
    gets(a);
    l = strlen(a);

    /*Ciphering*/
    j = 0;
    for(i = 0; i < l; i += 2)
    {
        c[j++] = a[i];
    }
    for(i = 1; i < l; i += 2)
    {
        c[j++] = a[i];
    }
    c[j] = '\0';
    printf("\nCipher text after applying rail fence :");
    printf("\n%s", c);

    /*Deciphering*/
    k = (l + 1) / 2;
    j = 0;
    for(i = 0; i < k; i++)
    {
        d[j] = c[i];
        j += 2;
    }
    j = 1;
    for(i = k; i < l; i++)
    {
        d[j] = c[i];
        j += 2;
    }
    d[l] = '\0';
    printf("\nText after decryption : ");
    printf("%s\n", d);

    return 0;
}

