#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// saves the input chars in in_string
char in_string[0x1000][4];
// saves the output chars in out_string
char out_string[0x1000][5];
// bin saves the binaray codes before execution.
int bin[0x1000][16];      
int bin_reverse[0x1000][16];      
FILE *fp;    

int PC = 0x3000;
int reg[8][16];
int MAR = 0x3000;
int IR[16];
int N, Z, P;


// transfers hex to bin and saves bins in bin
int hex_to_bin(char hex, int i, int j){
    if((hex & 0x8) == 0x8)
        bin[i][4*j] = 1;
    else
        bin[i][4*j] = 0;
    if((hex & 0x4) == 0x4)
        bin[i][4*j+1] = 1;
    else
        bin[i][4*j+1] = 0;
    if((hex & 0x2) == 0x2)
        bin[i][4*j+2] = 1;
    else
        bin[i][4*j+2] = 0;
    if((hex & 0x1) == 0x1)
        bin[i][4*j+3] = 1;
    else
        bin[i][4*j+3] = 0;
    return 0;
}
//load from bin
int load(int *to, int *from){
    for(int i = 0; i < 16; i++){
        to[i] = from[i];
    }
    return 0;
}

//SEXT function : n refers to IR[n : 0]
int SEXT(int n){
    int sum = 0;
    if(IR[n] == 0){
        for(int i = 0; i <= n; i++){
            sum += (IR[i] << i);
        }
    }
    else{
        for(int i = 0; i <= n; i++){
            sum += (((~IR[i])&1) << i);
        }
        sum += 1;
        sum = -sum;
    }
    return sum;
}

// transfers the chars to 0,1 and saves them in bin
int in_to_bin(){
    char hex = 0;
    for(int i = 0; i < 0x1000; i++){
        for(int j = 0; j < 4; j++){
            hex = in_string[i][j];
                // printf("%c", hex);
            if(hex >= '0' && hex <= '9')
                hex -= '0';
            else if(hex >= 'A' && hex <= 'F')
                hex -= ('A' - 10);
            else if(hex >= 'a' && hex <= 'f')
                hex -= ('a' - 10);
            else {
                // printf("%c\n", hex);
                printf("wrong in in_to_bin:\n");
                exit(1);
            }
                // printf(" %x\n", hex);
            hex_to_bin(hex, i, j);
        }
        // printf("\n");
    }
    reverse(0);
    return 0;
}

// gets input and saves in in_string
int input(){
    if((fp = fopen("lab06inpu", "r")) == NULL){
        puts("wrong in fopen_r!\n");
        exit(1);
    }
    for(long i = 0; i < 4096; i++){
        if(fgets(in_string[i], 6, fp) == NULL && i < 4095){
            puts("wrong in input!\n");
            // printf(" i = %d\n", i);
            exit(1);
        }
            // printf("%ld  ", i);
        // printf("%s\n", in_string[i]);
    }
    fclose(fp);
    in_to_bin();
    return 0;
}

// saves the outcomes in out_string
int output(){
    reverse(1);
    if((fp = fopen("lab06output", "w")) == NULL){
        puts("wrong in fopen_w!\n");
        exit(1);
    }
    for(int i = 0; i < 0x1000; i++){
        for(int j = 0; j < 4; j++){
            out_string[i][j] = 
                bin[i][j*4]*8 + bin[i][j*4+1]*4 
                + bin[i][j*4+2]*2 + bin[i][j*4+3];
            switch(out_string[i][j]){
                case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:
                    out_string[i][j] += '0';break;
                case 10:case 11:case 12:case 13:case 14:case 15:
                    out_string[i][j] += 'a'-10;break;
                default:printf("wrong here!\n");
            }
        }
        out_string[i][4] = '\n';
        fwrite(out_string[i], 1, 5,fp);
    }    
    return 0;
}

// reverse:
int reverse(int t){
    if(t == 0)
        for(int i = 0; i < 0x1000; i++){
            for (int j = 0; j < 16;j++){
                bin_reverse[i][j] = bin[i][15-j];
            }
        }
    else 
        for(int i = 0; i < 0x1000; i++){
            for (int j = 0; j < 16;j++){
                bin[i][j] = bin_reverse[i][15-j];
            }
        }
    return 0;
}

// go!: executes 2/6 phases of the instruction
int go(){
    int opcode; //saves IR[15:12]
//1.fetch:
    MAR = PC++;
    load(IR, bin_reverse[MAR-0x3000]);
        
//2.decode:
    opcode = IR[15]*8 + IR[14]*4 + IR[13]*2 + IR[12];
    switch(opcode){
        case 0x0:   return BR();       
        case 0x1:   return ADD();      
        case 0x2:   return LD();       
        case 0x3:   return ST();   
        case 0x4:   return JSR();  
        case 0x5:   return AND();  
        case 0x6:   return LDR();  
        case 0x7:   return STR();  
        case 0x9:   return NOT();  
        case 0xa:   return LDI();  
        case 0xb:   return STI();  
        case 0xc:   return JMP_RET();  
        case 0xe:   return LEA();  
        case 0xf:   return TRAP(); 
        default:printf("wrong in go!!\n");
                exit(1);
    }
}

//setcc
int setcc(int a[16]){
    int i;
    if(a[15] == 1){
        N = 1; Z = P = 0;
    }
    else{
        for(i = 0; i < 15; i++)
            if(a[i] == 1)
                break;
        if(i == 15){
            Z = 1; N = P = 0;
        }
        else{
            P = 1; Z = N = 0;
        }
    }
    return 1;
}

//ADD part
int ADD(){
    int DSR = IR[11]*4 + IR[10]*2 + IR[9];
    int SR1 = IR[8]*4 + IR[7]*2 + IR[6];
    int sr1 = 0;
    for(int i = 0; i < 16; i++){
        sr1 += ((reg[SR1][i] & 1) << i);
    }
    if(IR[5] == 0){
        int SR2 = IR[2]*4 + IR[1]*2 + IR[0];
        int sr2 = 0;
        for(int i = 0; i < 16; i++){
            sr2 +=( (reg[SR2][i] & 1) << i);
        }
        for(int i = 0; i < 16; i++){
            reg[DSR][i] = ((sr1 + sr2) & (1 << i)) >> i;
        }
    }
    else{
        for(int i = 0; i < 16; i++){
            reg[DSR][i] = ((sr1 + SEXT(4)) & (1 << i)) >> i;
        }
    }
    setcc(reg[DSR]);
    return 1;
}

//AND part
int AND(){
    int DSR = IR[11]*4 + IR[10]*2 + IR[9];
    int SR1 = IR[8]*4 + IR[7]*2 + IR[6];
    int sr1 = 0;
    for(int i = 0; i < 16; i++){
        sr1 += ((reg[SR1][i] & 1) << i);
    }
    if(IR[5] == 0){
        int SR2 = IR[2]*4 + IR[1]*2 + IR[0];
        int sr2 = 0;
        for(int i = 0; i < 16; i++){
            sr2 += ((reg[SR2][i] & 1) << i);
        }
        for(int i = 0; i < 16; i++){
            reg[DSR][i] = ((sr1 & sr2) & (1 << i)) >> i;
        }
    }
    else{
        for(int i = 0; i < 16; i++){
            reg[DSR][i] = ((sr1 & SEXT(4)) & (1 << i)) >> i;
        }
    }
    setcc(reg[DSR]);
    return 1;
}

//BR part
int BR(){
    if((IR[11]&N) || (IR[10]&Z) || (IR[9]&P))
        PC = PC + SEXT(8);
    return 1;
}

//JMP_RET part
int JMP_RET(){
    int BaseR = IR[8] * 4 + IR[7] * 2 + IR[6];
    PC = 0;
    for(int i = 0; i < 16; i++){
        PC += (reg[BaseR][i] << i); 
    }
    return 1;
}

//JSR part
int JSR(){
    for(int i = 0; i < 16; i++){
        reg[7][i] = ((PC&(1<<i))>>i)&1; 
    }
    if(IR[11] == 0){
        PC = 0;
        int BaseR = IR[8] * 4 + IR[7] * 2 + IR[6];
        for(int i = 0; i < 16; i++){
            PC += (reg[BaseR][i] << i);
        }
    }
    else{
        PC += SEXT(10);
    }
    return 1;
}

//LD part
int LD(){
    int i;
    int DR = IR[11]*4 + IR[10]*2 + IR[9];
    for(i = 0; i < 16; i++){
        reg[DR][i] = bin_reverse[PC + SEXT(8)-0X3000][i];
    }
    setcc(reg[DR]);
    return 1;
}

//LDI part
int LDI(){
    int i;
    int place = 0;
    int DR = IR[11]*4 + IR[10]*2 + IR[9];
    for(i = 0; i < 16; i++){
        place += bin_reverse[PC + SEXT(8)-0X3000][i] << i;
    }
    for(i = 0; i < 16; i ++){
        reg[DR][i] = bin_reverse[place-0x3000][i];
    }
    setcc(reg[DR]);
    return 1;
}

//LDR part
int LDR(){
    int i;
    int place = 0;
    int DR = IR[11]*4 + IR[10]*2 + IR[9];
    int BaseR = IR[8]*4 + IR[7]*2 + IR[6];
    for(i = 0; i < 16; i++){
        place += reg[BaseR][i] << i;
    }
    place += SEXT(5);
    for(i = 0; i < 16; i ++){
        reg[DR][i] = bin_reverse[place-0x3000][i];
    }
    setcc(reg[DR]);
    return 1;
}

//LEA part
int LEA(){
    int i;
    int place = 0;
    int DR = IR[11]*4 + IR[10]*2 + IR[9];
    place = PC + SEXT(8);
    for(i = 0; i < 16; i ++){
        reg[DR][i] = ((place&(1<<i))>>i)&1;
    }
    setcc(reg[DR]);
    return 1;
}

//NOT part
int NOT(){
    int i;
    int DR = IR[11]*4 + IR[10]*2 + IR[9];
    int SR = IR[8]*4 + IR[7]*2 + IR[6];
    for(i = 0; i < 16; i++){
        reg[DR][i] = ((~reg[SR][i])&1);
    }
    setcc(reg[DR]);
    return 1;
}

//ST part
int ST(){
    int SR = IR[11]*4 + IR[10]*2 + IR[9];
    int place = PC + SEXT(8);
    for(int i = 0; i < 16; i++){
        bin_reverse[place-0x3000][i] = reg[SR][i];
    }
    return 1;
}

//STI part
int STI(){
    int SR = IR[11]*4 + IR[10]*2 + IR[9];
    int tmp_place = PC + SEXT(8);
    int place = 0;
    for(int i = 0; i < 16; i++){
        place += bin_reverse[tmp_place-0x3000][i] << i;
    }
    for(int i = 0; i < 16; i++){
        bin_reverse[place-0x3000][i] = reg[SR][i];
    }
    return 1;    
}

//STR part
int STR(){
    int SR = IR[11]*4 + IR[10]*2 + IR[9];
    int BaseR = IR[8]*4 + IR[7]*2 + IR[6];
    int place = 0;
    for(int i = 0; i < 16; i++){
        place += reg[BaseR][i] << i;
    }
    place += SEXT(5);
    for(int i = 0; i < 16; i++){
        bin_reverse[place-0x3000][i] = reg[SR][i];
    }
    return 1;
}

//TRAP part
int TRAP(){
    return 0;
}

int main(){
    input();
    while(go() && PC < 0x4000 && PC >= 0x3000)
        ;
    //test
    // for(int i = 0; i < 0x1000; i++){
    //     for(int j = 0; j < 16; j++){
    //         printf("%2d", bin[i][j]);
    //     }
    //     putchar('\n');
    // }
    output();
    return 0;
}


