#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

#define ENTER 13
#define TAB 9
#define BKSP 8

//DEKLARASI FUNGSI
//konvresi biner
int binary_decimal(int);
int binary_octal(int);
int binary_hexadecimal(int);

//konversi desimal
int decimal_binary(int);
int decimal_octal(int);
int decimal_hexadecimal(int);

//konversi oktal
int octal_binary(int);
int octal_decimal(int);
int octal_hexadecimal(int);

// konversi hexadesimal
int hexadecimal_binary(char []);
int hexadecimal_octal(char []);
int hexadecimal_decimal(char []);

void welcome();
void list();
void clean();
void tryAgain(int);
void userInput(int);

//main function
int main(){
    int pilihan;

    welcome();
    list();

    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan);

    switch (pilihan){
    case 1:
        userInput(1);
        break;
    case 2:
        userInput(2);
        break;
    case 3:
        userInput(3);
        break;
    case 4:
        userInput(4);
        break;
    case 0:
        exit(0);
    default:
        printf("Masukkan pilihan yang benar!. (1-4)");
        getch();
        clean();
        return main();
        break;
    }

}


//FUNGSIIIIII
void welcome(){
    printf("========== APLIKASI KONVERSI ANGKA ==========\n");
    printf("Nama:\tMoh Fatkhur Rahman\n");
    printf("NIM:\t4.33.22.1.15\n");
    printf("Kelas:\tTI-1B\n");
    printf("=============================================\n");
    printf("\n");
}

void list(){
    printf("Pilih tipe konversi: \n");
    printf("1. Konversi Desimal\n");
    printf("2. Konversi Biner\n");
    printf("3. Konversi Octal\n");
    printf("4. Konversi Hexadecimal\n");
    printf("0. Keluar program\n");
}

void userInput(int pilihan){
    if(pilihan == 1){
        long int deci;
        int validation = 0;

        printf("\n========KONVERSI DECIMAL========\n");
        printf("Masukkan nilai decimal: ");
        scanf("%ld", &deci);

        if(deci > 0)
            validation = digitChecker(deci, pilihan);

        if(validation == 1){
            printf("\nError: Digit Decimal antara 0..9. \n");
            getch();
            clean();
            return main();
        }
        else{
            decimal_binary(deci);
            decimal_octal(deci);
            decimal_hexadecimal(deci);
            tryAgain(pilihan);
        }
    }
    else if(pilihan == 2){  // Decimal
        long int nilai_binary;
        int validation = 0;

        printf("\n========KONVERSI NILAI BINER========\n");
        printf("Masukkan nilai biner: ");
        scanf("%ld", &nilai_binary);

        validation = digitChecker(nilai_binary, pilihan);

        if(validation == 1){
            printf("\nError: Digit Biner hanya 0 dan 1. \n");
            getch();
            clean();
            return main();
        }
        else{
            binary_decimal(nilai_binary);
            binary_octal(nilai_binary);
            binary_hexadecimal(nilai_binary);
            tryAgain(pilihan);
        }
    }
    else if(pilihan == 3){ //Octal
        long int octal;
        int validation = 0;

        printf("\n========KONVERSI OCTAL========\n");
        printf("Masukkan niai octal: ");
        scanf("%ld", &octal);

        validation = digitChecker(octal, pilihan);

        if(validation == 1){
            printf("\nError: Digit octal antara 0..7. \n");
            getch();
            clean();
            return main();
        }
        else{
            octal_binary(octal);
            octal_decimal(octal);
            octal_hexadecimal(octal);
            tryAgain(pilihan);
        }
    }
    else if(pilihan == 4){ //Hexadecimal
        char hexa[50];
        char ch;
        int i=0, j=0, k=0, validation=0;

        printf("\n========KONVERSI HEXADECIMAL========\n");
        printf("Masukkan nilai Hexadecimal: ");

        //validasi karakter untuk hexadecimal
        while(1){
            ch = getch();
            if(ch == ENTER || ch == TAB){
                hexa[i] = '\0';
                break;
            }
            else if(ch == BKSP){
                if(i > 0)
                {
                    i--;
                    printf("\b \b"); // for backspace
                }
            }
            else{
                hexa[i++] = ch;
                printf("%c", ch);
            }
        }


        for(j=0; j<i; j++){
            if((hexa[j] >= 'A' && hexa[j] <= 'F') || (hexa[j] >= 'a' && hexa[j] <= 'f') || isdigit(hexa[j])){
                k++;
            }
            else{
                validation = 1;
                break;
            }
        }

        if(validation == 1){
            printf("\n\nError: Digit hexadecimal antara 0..9 dan A..F. \n");
            getch();
            clean();
            return main();
        }
        else{
            printf("\n");

            hexadecimal_binary(hexa);
            hexadecimal_octal(hexa);
            hexadecimal_decimal(hexa);
            tryAgain(pilihan);
        }
    }
    else
        printf("\n!! Unexpected Error occured. Report to program Administrator !! \n");
}

int digitChecker(int num, int pilihan){
    long int rem, temp=0, validation=0;
    temp = num;

        while(temp != 0){
            rem = temp % 10;

            if((rem >= 0 && rem <= 9) && pilihan == 1){ // desimal, pilihan = 1
                temp = temp / 10;
            }
            else if(rem == 0 || rem == 1 && pilihan == 2){ // biner, pilihan = 2
                temp = temp / 10;
            }
            else if(rem >= 0 && rem <=7 && pilihan == 3){ // octal, pilihan = 3
                temp = temp / 10;
            }
            else{
                validation = 1;
                break;
            }
        }
    return validation;
}

void tryAgain(int pilihan){
    char pilih;

    printf("\n\nIngin mengulangi lagi? [Y/N]: ");
    scanf(" %c", &pilih);

    switch(pilih){
        case 'Y':
        case 'y':
            userInput(pilihan);
            clean();
            break;
        case 'N':
        case 'n':
            clean();
            return main();
            break;
        default:
            printf("\nError: invalid input. \n");
            printf("Press any key to continue... \n");
            clean();
            return main();
    }
}

void clean(){
    system("cls");
    fflush(stdin);
}


//FUNGSI KONVERSI
int decimal_binary(int dec){
    long bin = 0;
    int rem_binary;
    int mult = 1;

    while(dec !=0){
        rem_binary = dec % 2;
        bin = bin + rem_binary * mult;
        mult = mult * 10;
        dec = dec / 2;
    }

    printf("\nNilai biner: %d", bin);

}

int decimal_octal(int dec){
    int octal = 0;
    int rem_octal;
    int i = 1;

    while(dec != 0){
        rem_octal = dec % 8;
        octal = octal + rem_octal * i;
        i = i * 10;
        dec = dec / 8;
    }
    printf("\nNilai Octal: %d", octal);
    /*
    printf("Nilai octal: %o", dec);
    */
}

int decimal_hexadecimal(int dec){
    int count, i;
    char hex[32];

    count = 0;
    while (dec > 0) {
        switch (dec % 16) {
        case 10:
            hex[count] = 'A';
            break;
        case 11:
            hex[count] = 'B';
            break;
        case 12:
            hex[count] = 'C';
            break;
        case 13:
            hex[count] = 'D';
            break;
        case 14:
            hex[count] = 'E';
            break;
        case 15:
            hex[count] = 'F';
            break;
        default:
            hex[count] = (dec % 16) + 0x30; /*konversi ke char value*/
        }
        dec = dec / 16;
        count++;
    }

    printf("\nNilai Hexadesimal: ");
    for (i = (count - 1); i >= 0; i--){
        printf("%c", hex[i]);
    }
    printf("\n");

    /*
    printf("Nilai hexadecimal : %x",  dec);
    */
}

int binary_decimal(int bin){
    int rem,sum=0,i=0;

    while(bin!=0){
        rem = bin % 10;
        bin = bin / 10;
        sum = sum + rem*pow(2,i);
        i++;
    }
    printf("\nNilai decimal : %d", sum);
}

int binary_octal(int bin){
    int i=0;
    int rem;
    int sum=0;
    int remain_octal[100];
    int len=0;

    while(bin!=0){
        rem = bin % 10;
        bin = bin / 10;
        sum = sum + rem * pow(2,i);
        i++;
    }

    i=0;
    while(sum!=0){
        remain_octal[i]=sum%8;
        sum = sum/8;
        i++;
        len++;
    }

    printf("\nNilai Octal: ");
    for(i=len-1;i>=0;i--){
        printf("%d",remain_octal[i]);
    }

    /*
     while (binaryNumber != 0) {
        rem = binaryNumber % 10;
        octalNumber = octalNumber + rem * i;

        i = i * 2;
        binaryNumber = binaryNumber / 10;
    }

    printf("Octal Number: %o", octalNumber);
    */

    /*
    printf("Nilai octal: %o", sum);
    */
}

int binary_hexadecimal(int bin){
    int rem, i=0, sum=0, remain_hexa[100], len=0;

    while(bin!=0){
        rem = bin % 10;
        bin = bin / 10;
        sum = sum + rem * pow(2,i);
        i++;
    }
    i=0;
    while(sum!=0){
        remain_hexa[i]=sum%16;
        sum = sum/16;
        i++;
        len++;
    }

    printf("\nNilai Hexadesimal: ");
    for(i=len-1;i>=0;i--){
        switch(remain_hexa[i]){
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%d",remain_hexa[i]);
        }
    }
    /*
    printf("Nilai hexadecimal: %x", sum);
    */
    printf("\n");
}

int octal_decimal(int oct){
    int num, rem;
    int decimal=0;
    int i=0;

    while(oct!=0){
        rem = oct % 10;
        decimal = decimal + rem * pow(8,i);
        i++;
        oct = oct/10;
    }
    printf("\nNilai Desimal: %d",decimal);
}

int octal_binary(int oct){
    int rem;
    int rem_binary[20];
    int len=0;
    int decimal=0;
    int i=0;
    int num,ans;

    while(oct!=0){
        rem = oct % 10;
        decimal = decimal + rem * pow(8,i);
        i++;
        oct = oct/10;
    }

    i=0;
    while(decimal != 0){
        rem_binary[i]=decimal%2;
        decimal=decimal/2;
        i++;
        len++;
    }
    printf("\nNilai Biner: ");
    for(i=len-1;i>=0;i--){
        printf("%d",rem_binary[i]);
    }

}

int octal_hexadecimal(int oct){
    int rem[50],len=0,decimal=0,i=0,num,ans=0;
    while(oct!=0){
        ans=oct % 10;
        decimal = decimal + ans * pow(8,i);
        i++;
        oct = oct/10;
    }

    i=0;
    while(decimal!=0){
        rem[i]=decimal%16;
        decimal=decimal/16;
        i++;
        len++;
    }

    printf("\nNilai Hexadesimal: ");

    for(i=len-1;i>=0;i--){
        switch(rem[i]){
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%d",rem[i]);
        }
    }
    printf("\n");
}

int hexadecimal_decimal(char hexa[]){
    int num=0;
    int pangkat=0;
    int decimal=0;

    int i;

    for(i=strlen(hexa)-1;i>=0;i--){
        if(hexa[i]=='A'||hexa[i]=='a')
            num=10;
        else if(hexa[i]=='B'||hexa[i]=='b')
            num=11;
        else if(hexa[i]=='C'||hexa[i]=='c')
            num=12;
        else if(hexa[i]=='D'||hexa[i]=='d')
            num=13;
        else if(hexa[i]=='E'||hexa[i]=='e')
            num=14;
        else if(hexa[i]=='F'||hexa[i]=='f')
            num=15;
        else
            num=hexa[i]-48;

        decimal=decimal + num * pow(16,pangkat);
        pangkat++;
    }
    printf("\nNilai decimal: %d",decimal);
}

int hexadecimal_binary(char hexa[]){
    int i=0;

    printf("\nNilai biner: ");

    for(i=0;i<strlen(hexa);i++){
        switch (hexa[i]){
            case '0':
                printf("0000");
                break;
            case '1':
                printf("0001");
                break;
            case '2':
                printf("0010");
                break;
            case '3':
                printf("0011");
                break;
            case '4':
                printf("0100");
                break;
            case '5':
                printf("0101");
                break;
            case '6':
                printf("0110");
                break;
            case '7':
                printf("0111");
                break;
            case '8':
                printf("1000");
                break;
            case '9':
                printf("1001");
                break;
            case 'A':
            case 'a':
                printf("1010");
                break;
            case 'B':
            case 'b':
                printf("1011");
                break;
            case 'C':
            case 'c':
                printf("1100");
                break;
            case 'D':
            case 'd':
                printf("1101");
                break;
            case 'E':
            case 'e':
                printf("1110");
                break;
            case 'F':
            case 'f':
                printf("1111");
                break;
            default:
                printf("\nDigit hexadesimal salah. %c ", hexa[i]);
        }
    }
}

int hexadecimal_octal(char hexa[]){
    int len;
    int num=0;
    int power=0;
    int decimal=0;
    int rem[100];

    int i;

    for(i=strlen(hexa)-1;i>=0;i--){
        if(hexa[i]=='A'||hexa[i]=='a')
            num=10;
        else if(hexa[i]=='B'||hexa[i]=='b')
            num=11;
        else if(hexa[i]=='C'||hexa[i]=='c')
            num=12;
        else if(hexa[i]=='D'||hexa[i]=='d')
            num=13;
        else if(hexa[i]=='E'||hexa[i]=='e')
            num=14;
        else if(hexa[i]=='F'||hexa[i]=='f')
            num=15;
        else
            num=hexa[i]-48;

        decimal=decimal+num*pow(16,power);
        power++;
    }

    i=0,len=0;
    while(decimal!=0){
        rem[i]=decimal%8;
        decimal=decimal/8;
        i++;
        len++;
    }

    printf("\nNilai Oktal: ");
    for(i=len-1;i>=0;i--){
        printf("%d",rem[i]);
    }
}


