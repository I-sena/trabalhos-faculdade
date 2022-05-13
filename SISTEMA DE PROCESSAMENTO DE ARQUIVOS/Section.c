#include "Section.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct section{
  int section_identifier;
  char course_number[30];
  char semester[10];
  int year;
  char instructor[100];
};

typedef struct section Section;

//CREAD
int Create_New_Section(){
    Section* new = malloc(sizeof(Section));
    FILE* Section_File = fopen("Section.dat","ab");
    if(new && Section_File){
        printf("\n\t\t** ATENCAO **\n--- PREENCHA OS CAMPOS COM LETRA MAIUSCULAS ---\n");  
        printf("Section Identifier: ");
        scanf("%d%*c",&new->section_identifier);
        setbuf(stdin,NULL);
        printf("Course Number: ");
        scanf("%s%*c",new->course_number);
        setbuf(stdin,NULL);        
        printf("Semester: ");
        scanf("%s%*c",new->semester);
        setbuf(stdin,NULL);        
        printf("Year: ");
        scanf("%d%*c",&new->year);
        setbuf(stdin,NULL);       
        printf("Instructor: ");
        scanf("%s%*c",new->instructor);
        setbuf(stdin,NULL);
        fseek(Section_File,0,SEEK_END);
        if(fwrite(new,sizeof(Section),1,Section_File) == 1){
            fclose(Section_File);
            return 0;
        }
    }
    return 1;
}

//READ
int Print_Section(){
    FILE* Section_File = fopen("Section.dat","rb");
    if (!Section_File)   return 1;
    struct section aux;
    int op, op1, op2, op3, op4, op5, IsValid = 1;
    while(IsValid){
        printf("\nDESEJA:\n<1> IMPRIMIR TODOS OS ATRIBUTOS DOS REGISTROS | <2> IMPRIMIR SOMENTE ALGUNS\n");
        scanf("%d",&op);
        if(op >= 1 && op <= 2)
            IsValid = 0;
        else  
            printf("OPCAO INVALIDA! DIGITE NOVAMENTE.\n");
    }
    if(op != 1){
        printf("\nQUAIS ATRIBUDOS DESEJA IMPRIMIR:\n");
        printf("-> Section Identifier: <1> sim ou <0> nao?-> ");
        scanf("%d",&op1);
        printf("-> Course number: <1> sim ou <0> nao?-> ");
        scanf("%d",&op2);
        printf("-> Semester: <1> sim ou <0> nao?-> ");
        scanf("%d",&op3);
        printf("->  Year: <1> sim ou <0> nao?-> ");
        scanf("%d",&op4);
        printf("-> Instructor: <1> sim ou <0> nao?-> ");
        scanf("%d",&op5);
    }else{
        op1 = 1;
        op2 = 1;
        op3 = 1;
        op4 = 1;
        op5 = 1;
    }
    fseek(Section_File,0,SEEK_SET);
    puts("\n\t\tREGISTROS ATUAIS");
    while(1){
        fread( &aux, sizeof(Section), 1, Section_File);
        if(feof(Section_File))
            break;
        puts("-----------------------------------------");
        if(op1 == 1)
            printf("Section Identifier: %d\n",aux.section_identifier);
        if(op2 == 1)
            printf("Course_number: %s\n",aux.course_number);
        if(op3 == 1)
            printf("semester: %s\n",aux.semester);
        if(op4 == 1)
            printf("year: %d\n",aux.year);
        if(op5 == 1)        
            printf("Instructor: %s\n",aux.instructor);
        puts("-----------------------------------------");
    } 
    fclose(Section_File);
    return 0;
}

//UPDATE
int Update_Section(){
    FILE* Section_File = fopen("Section.dat","rb");
    FILE* backup = fopen("backup.dat","wb");
    if ( !Section_File || !backup)    return 1;
    int options[5], all;
    int ID;
    printf("\nDIGITE DADO ATUAL DE \"SECTION IDENTIFIER\" PARA REALIZAR A BUSCA: ");   
    scanf("%d",&ID);
    printf("ALTERAR TODOS OS CAMPOS DO REGISTRO? <1> Sim ou <0> Nao: ");
    scanf("%d",&all);
    if(all != 1){         
        printf("\nQUAIS CAMPOS DESEJA ALTERAR:\n");
        printf("-> Section Identifier <1> sim ou <0> nao? -> ");
        scanf("%d",&options[0]);
        printf("-> Course number <1> sim ou <0> nao? -> ");
        scanf("%d",&options[1]);
        printf("-> Semester <1> sim ou <0> nao? -> ");
        scanf("%d",&options[2]);
        printf("-> Year <1> sim ou <0> nao? -> ");
        scanf("%d",&options[3]);
        printf("-> Instructor <1> sim ou <0> nao? -> ");
        scanf("%d",&options[4]);
    }else{
        options[0] = 1;
        options[1] = 1;
        options[2] = 1;
        options[3] = 1;
        options[4] = 1;
    }
    struct section current;
    Section* new = malloc(sizeof(Section));
    fseek(Section_File, 0, SEEK_SET);
    fseek(backup,0,SEEK_END);
    int find_r = 0;
    while(1){
        fread(&current,sizeof(Section),1,Section_File); 
        if(feof(Section_File)){
            if(find_r == 0)
                printf("| REGISTRO NAO ENCONTRADO! |\n");  
            break;
        }
        if(find_r == 0){
            if( current.section_identifier == ID)
                find_r = 1;
        }
        if(find_r == 1){
            printf("\n\t\t** ATENCAO **\n--- PREENCHA OS CAMPOS COM LETRA MAIUSCULAS ---\n");
            if(options[0] == 1){
                printf("Novo \"Section Identifier\": ");
                scanf("%d%*c",&new->section_identifier);
                setbuf(stdin,NULL);
            }else
                new->section_identifier = current.section_identifier;
            if(options[1] == 1){
                printf("Novo \"Course Number\": ");
                scanf("%s%*c",new->course_number);
                setbuf(stdin,NULL);
            }else{
                strcpy(new->course_number,"");
                strcpy(new->course_number,current.course_number);
            }
            if(options[2] == 1){
                printf("Novo \"Semester\":");
                scanf("%s%*c",&new->semester);
                setbuf(stdin,NULL);
            }else{
                strcpy(new->semester,"");
                strcpy(new->semester,current.semester);
            }
            if(options[3] == 1){
                printf("Novo \"Year\": ");
                scanf("%d%*c",&new->year);
                setbuf(stdin,NULL);
            }else
                new->year = current.year;
            if(options[4] == 1){
                printf("Novo \"Instructor\": ");
                scanf("%s%*c",new->instructor);
                setbuf(stdin,NULL);      
            }else{
                strcpy(new->instructor,"");
                strcpy(new->instructor,current.instructor);
            }
            fwrite(new,sizeof(Section),1,backup);
            find_r = 2;
        }
        else{
            fwrite(&current,sizeof(Section),1,backup);
        }
    }
    fclose(Section_File);
    fclose(backup); 
    if(!remove("Section.dat") && !rename("backup.dat","Section.dat")) return 0;
    else  return 1;
}

//DELETE
int Delete_Section(){
    FILE* Section_File = fopen("Section.dat","rb");
    FILE* backup = fopen("backup.dat","wb");
    if(!Section_File || !backup)  return 1;
    int id;  
    printf("\nDIGITE DADO ATUAL DE \"SECTION IDENTIFIER\" PARA REALIZAR A BUSCA: ");   
    scanf("%d",&id);
    fseek(Section_File, 0, SEEK_SET);
    fseek(backup,0,SEEK_END);
    struct section current;
    while(1){
        int find_r = 0;
        fread(&current,sizeof(Section),1,Section_File); 
        if(feof(Section_File)){
            break;
        }
        if(current.section_identifier == id)
            find_r = 1;
        if(find_r == 0)
            fwrite(&current,sizeof(Section),1,backup);
    }
    fclose(Section_File);
    fclose(backup);
    if(!remove("Section.dat") && !rename("backup.dat","Section.dat")) return 0;
    else  return 1;
}