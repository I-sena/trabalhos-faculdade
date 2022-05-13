#include "Grade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct grade_report{
  int student_number;
  int section_identifier;
  char grade[2];
};

typedef struct grade_report Grade_Report;

//CREAD
int Create_New_Grade(){
    Grade_Report* new = malloc(sizeof(Grade_Report));
    FILE* Grade_File = fopen("Grade.dat","ab");
    if(new && Grade_File){
        printf("\n\t\t** ATENCAO **\n--- PREENCHA OS CAMPOS COM LETRA MAIUSCULA ---\n");
        printf("Student Number: ");
        scanf("%d%*c",&new->student_number);
        setbuf(stdin,NULL);
        printf("Section Identifier: ");
        scanf("%d%*c",&new->section_identifier);
        setbuf(stdin,NULL);
        printf("Grade: ");
        scanf("%s%*c",new->grade);
        setbuf(stdin,NULL);
        fseek(Grade_File, 0, SEEK_END);
        if(fwrite(new, sizeof(Grade_Report), 1, Grade_File) == 1){
            fclose(Grade_File);
            return 0;
        }
    }
    return 1;
}

//READ
int Print_Grade(){
    FILE* Grade_File = fopen("Grade.dat","rb");
    if (!Grade_File) return 1;
    int op, op1 ,op2, op3, IsValid = 1;
    while(IsValid){
        printf("\nDESEJA:\n<1> IMPRIMIR TODOS OS ATRIBUDOS DOS REGISTROS | <2> IMPRIMIR SOMENTE ALGUNS |-> ");
        scanf("%d",&op);
        if(op >= 1 && op <= 2)
            IsValid = 0;
        else  
            printf("OPCAO INVALIDA! DIGITE NOVAMENTE.\n");
    }
    if(op != 1){
        printf("QUAIS ATRIBUDOS DESEJA IMPRIMIR:\n");
        printf("-> Student Number: <1> sim ou <0> nao?-> ");
        scanf("%d",&op1);
        printf("-> Section Identifier: <1> sim ou <0> nao?-> ");
        scanf("%d",&op2);
        printf("-> Grade: <1> sim ou <0> nao?-> ");
        scanf("%d",&op3);
    }else{
        op1 = 1;
        op2 = 1;
        op3 = 1;
    }
    struct grade_report aux;
    fseek(Grade_File,0,SEEK_SET);
    puts("\n\tREGISTROS ATUAIS");
    while(1){
        fread(&aux,sizeof(Grade_Report),1,Grade_File);
        if(feof(Grade_File))
            break;
        puts("--------------------------------");
        if(op1 == 1)
            printf("Student Number: %d\n",aux.student_number);
        if(op2 == 1)
            printf("Section Identifier: %d\n",aux.section_identifier);
        if(op3 == 1)
            printf("Grade: %s\n",aux.grade);
        puts("--------------------------------");
    }   
    fclose(Grade_File);
    return 0;
}

//UPDATE
int Update_Grade(){
    FILE* backup = fopen("backup.dat","wb");
    FILE* Grade_File = fopen("Grade.dat","rb");
    if (!backup || !Grade_File)     return 1;
    int type, options[3], all;
    int id, Snumber;
    printf("\nDIGITE DADOS ATUAIS DO REGISTRO PARA EFEITUAR A BUSCA:\n");
    printf("- DADO ATUAL DE \"STUDENT NUMBER\": ");
    scanf("%d%*c",&Snumber);
    printf("- DADO ATUAL DE \"SECTION IDENTIFIER\": ");
    scanf("%d%*c",&id);
    printf("\nALTERAR TODOS OS CAMPOS DO REGISTRO? <1> Sim ou <0> Nao: ");
    scanf("%d",&all);
    if(all != 1){         
        printf("QUAIS CAMPOS DESEJA ALTERAR:\n");
        printf("-> Student Number <1> sim ou <0> nao?->  ");
        scanf("%d%*c",&options[0]);
        printf("-> Section Identifier <1> sim ou <0> nao?->  ");
        scanf("%d%*c",&options[1]);
        printf("-> Grade <1> sim ou <0> nao?-> ");
        scanf("%d%*c",&options[2]);
    }else{
        options[0] = 1;
        options[1] = 1;
        options[2] = 1;
    }
    int sizeGrade = sizeof(Grade_Report);
    fseek(Grade_File, 0, SEEK_SET);
    fseek(backup, 0, SEEK_END);
    struct grade_report current;
    Grade_Report* new = malloc(sizeof(Grade_Report));
    int find_r[]= {0,0};
    while(1){
        fread(&current, sizeof(Grade_Report), 1, Grade_File);
        if(feof(Grade_File)){
            if(find_r[0] == 0 && find_r[1] == 0)
                printf("| REGISTRO NAO ENCONTRADO! | \n");
            break;
        }
        if(find_r[0] == 0 && find_r[1] == 0){
            if(Snumber == current.student_number)
                find_r[0] = 1;         
            if(id == current.section_identifier){
                find_r[1] = 1;
            }
        }
        if(find_r[0] == 1 && find_r[1] == 1){
            printf("\n\t** ATENCAO **\n--- PREENCHA OS CAMPOS COM LETRA MAIUSCULA ---\n");
            if(options[0] == 1){
                printf("Novo \"Student Number\": ");
                scanf("%d%*c",&new->student_number);
                setbuf(stdin,NULL);
            }else
                new->student_number = current.student_number;
            if(options[1] == 1){
                printf("Novo \"Section Identifier\": ");
                scanf("%d%*c",&new->section_identifier);
                setbuf(stdin,NULL);
            }else{
                new->section_identifier = current.section_identifier;
            }
            if(options[2] == 1){
                printf("Novo \"Grade\": ");
                scanf("%s%*c",new->grade);
                setbuf(stdin,NULL);
            }else{
                strcpy(new->grade,current.grade);
            }
            fwrite(new,sizeof(Grade_Report),1,backup);
            find_r[0] = 2;
            find_r[1] = 2;
        }                
        else{
            fwrite(&current,sizeof(Grade_Report),1,backup);
        }
    }
    fclose(Grade_File);
    fclose(backup);
    if(!remove("Grade.dat") && !rename("backup.dat","Grade.dat")) return 0;
    else  return 1;
}

//DELETE
int Delete_Grade(){
    FILE* Grade_File = fopen("Grade.dat","rb");
    FILE* backup = fopen("backup.dat","wb");
    if(!Grade_File || !backup)  return 1;
    int type, Snumber, id, IsValid = 1;  
    printf("\nDIGITE DADOS ATUAIS DO REGISTRO PARA REALIZAR A BUSCA!\n");   
    printf("- DADO ATUAL DE \"STUDENT NUMBER\": ");
    scanf("%d%*c",&Snumber);
    printf("- DADO ATUAL DE \"SECTION IDENTIFIER\": ");
    scanf("%d%*c",&id);
    struct grade_report current;
    fseek(Grade_File, 0, SEEK_SET);
    fseek(backup,0,SEEK_END);
    while(1){
        int find_r[] = {0,0};
        fread(&current, sizeof(Grade_Report), 1, Grade_File);
        if(feof(Grade_File)){  
            break;
        }
        if(Snumber == current.student_number)
            find_r[0] = 1;
        else if(id == current.section_identifier)
            find_r[1] = 1; 
        if(find_r[0] == 0 && find_r[1] == 0)
            fwrite(&current,sizeof(Grade_Report),1,backup);
    }
    fclose(Grade_File);
    fclose(backup);
    if(!remove("Grade.dat") && !rename("backup.dat","Grade.dat")) return 0;
    else  return 1;
}