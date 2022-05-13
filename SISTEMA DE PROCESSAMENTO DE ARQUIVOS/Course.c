#include "Course.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct course{
  char course_name[100];
  char course_number[30];
  int credit_hours;
  char departament[30];
};

typedef struct course Course;

//CREAD
int Create_New_Course(){
  Course* new = malloc(sizeof(Course));
  FILE* Course_File = fopen("Course.dat","ab");
  if(new && Course_File){
    printf("\n\t\t ** ATENCAO **\n--- PREENCHA TODOS OS CAMPOS COM LETRA MAIUSCULA ---\n");
    printf("Course Name: ");
    scanf("%s%*c",new->course_name);
    setbuf(stdin,NULL);
    printf("Course Number: ");
    scanf("%s%*c",new->course_number);
    setbuf(stdin,NULL);
    printf("Credit Hours:");
    scanf("%d%*c",&new->credit_hours);
    setbuf(stdin,NULL);
    printf("Departament: ");
    scanf("%s%*c",new->departament);
    setbuf(stdin,NULL);
    fseek(Course_File,0,SEEK_END);
    if((fwrite(new,sizeof(Course),1,Course_File)) == 1){
      fclose(Course_File);
      return 0;
    }
  }
  return 1;
}

//READ
int Print_Course(){
    FILE* Course_File = fopen("Course.dat","rb");
    if(!Course_File)  return 1;
    int op, op1, op2, op3, op4, IsValid = 1;
    while(IsValid){
        printf("\nDESEJA:\n| <1> IMPRIMIR TODOS OS ATRIBUTOS DOS REGISTROS | <2> IMPRIMIR SOMENTE ALGUNS | -> ");
        scanf("%d%*c",&op);
        if(op >= 1 && op <= 2)
            IsValid = 0;
        else  
            printf("OPCAO INVALIDA! DIGITE NOVAMENTE.\n");
    }
    if(op != 1){
        printf("\nQUAIS ATRIBUTOS DESEJA IMPRIMIR:\n");
        printf("-> Course name <1> Sim ou <0> Nao? -> ");
        scanf("%d",&op1);
        printf("-> Course number <1> Sim ou <0> Nao? -> ");
        scanf("%d",&op2);
        printf("-> Credit hours <1> Sim ou <0> Nao? -> ");
        scanf("%d",&op3);
        printf("-> Departament <1> Sim ou <0> Nao? -> ");
        scanf("%d",&op4);
    }else{
        op1 = 1;
        op2 = 1;
        op3 = 1;
        op4 = 1;
    }
    fseek(Course_File,0,SEEK_SET);
    struct course aux;
    puts("\n\t\tREGISTROS ATUAIS");
    while(1){
        fread(&aux,sizeof(Course),1,Course_File);
        if(feof(Course_File)){
            break;
        }
        puts("-----------------------------------------------");
        if(op1 == 1)
            printf("Course Name: %s\n",aux.course_name);
        if(op2 == 1)
            printf("Course Number: %s\n",aux.course_number);
        if(op3 == 1)
            printf("Credit Hours: %d\n",aux.credit_hours);
        if(op4 == 1)
            printf("Departament: %s\n",aux.departament);
        puts("-----------------------------------------------");
    }
    fclose(Course_File);
    return 0;
}

//UPDATE
int Update_Course(){
    FILE* backup = fopen("backup.dat","wb");
    FILE* Course_File = fopen("Course.dat","rb");
    if( !Course_File || !backup )     return 1;
    int options[4], all;
    char actual_name[30], actual_number[30];
    printf("\nDIGITE OS DADOS ATUAIS DO REGISTRO PARA REALIZAR A BUSCA!\n");   
    printf("\n\t\t** ATENCAO **\n--- PREENCHA COM LETRA MAIUSCULA ---\n");
    printf("- VALOR ATUAL DE \"COURSE NAME\": ");
    scanf("%s%*c",actual_name);
    printf("- VALOR ATUAL DE \"COURSE NUMBER\": ");
    scanf("%s%*c",actual_number);
    printf("\n-> ALTERAR TODOS OS CAMPOS DO REGISTRO? <1> Sim ou <0> Nao: ");
    scanf("%d",&all);
    if(all != 1){        
        printf("\nQUAIS CAMPOS DESEJA ALTERAR:\n");
        printf("-> Course Name <1> sim ou <0> nao?-> ");
        scanf("%d",&options[0]);
        printf("-> Course Number <1> sim ou <0> nao?-> ");
        scanf("%d",&options[1]);
        printf("-> Credit Hours <1> sim ou <0> nao?-> ");
        scanf("%d",&options[2]);
        printf("-> Departament <1> sim ou <0> nao?-> ");
        scanf("%d",&options[3]);
    }else{
        options[0] = 1;
        options[1] = 1;
        options[2] = 1;
        options[3] = 1;
    }
    fseek(Course_File, 0,SEEK_SET);
    fseek(backup,0,SEEK_END);
    struct course current;
    Course* new = malloc(sizeof(Course));
    int find_r[] = {0,0};
    while(1){
        fread(&current,sizeof(Course),1,Course_File); 
        if(feof(Course_File)){  
            if(find_r[0] == 0 && find_r[1] == 0)
                printf(" | REGISTRO NAO ENCONTRADO! |\n"); 
            break;
        }
        if(find_r[0] == 0 && find_r[1] == 0){
            if(!strncmp(current.course_name,actual_name,strlen(actual_name))){
                find_r[0] = 1;
            }
            if(!strncmp(current.course_number,actual_number,strlen(actual_number))){
                find_r[1] = 1;
            }
        }
        if(find_r[0] == 1 && find_r[1] == 1){
            printf("\n\t\t** ATENCAO **\n--- PREENCHA OS CAMPOS COM LETRA MAIUSCULA ---\n");
            if(options[0] == 1){
                printf("Novo \"Course Name\": ");
                scanf("%s%*c",new->course_name);
                setbuf(stdin,NULL);
            }else{
                strcpy(new->course_name,"");
                strcpy(new->course_name,current.course_name);
            }
            if(options[1] == 1){
                printf("Novo \"Course Number\": ");
                scanf("%s%*c",new->course_number);
                setbuf(stdin,NULL);
            }else{
                strcpy(new->course_number,"");
                strcpy(new->course_number,current.course_number);
            }
            if(options[2] == 1){
                printf("Novo \"Credit Hours\": ");
                scanf("%d%*c",&new->credit_hours);
                setbuf(stdin,NULL);
            }else
                new->credit_hours = current.credit_hours;
            if(options[3] == 1){
                printf("Novo \"Departament\": ");
                scanf("%s%*c",new->departament);
                setbuf(stdin,NULL);
            }else{
                strcpy(new->departament,"");
                strcpy(new->departament,current.departament);
            }
            fwrite(new,sizeof(Course),1,backup);
            find_r[0] = 2;
            find_r[1] = 2;
        }          
        else
            fwrite(&current,sizeof(Course),1,backup);
    }
    fclose(Course_File);
    fclose(backup);
    if(!remove("Course.dat") && !rename("backup.dat","Course.dat")) return 0;
    else  return 1;
}

//DELETE
int Delete_Course(){
    FILE* Course_File = fopen("Course.dat","rb");
    FILE* backup = fopen("backup.dat","wb");
    if(!Course_File || !backup)  return 1;
    char actual_name[30],actual_number[20];
    printf("\nDIGITE DADOS ATUAIS DO REGISTRO PARA EFEITUAR A BUSCA!\n");
    printf("\n\t\t** ATENCAO **\n--- PREENCHA O CAMPO COM LETRA MAIUSCULA ---\n");
    printf("- VALOR ATUAL DE \"COURSE NAME\": ");
    scanf("%s%*c",actual_name);
    printf("- VALOR ATUAL DE \"COURSE NUMBER\": ");
    scanf("%s%*c",actual_number);
    fseek(Course_File, 0, SEEK_SET);
    fseek(backup,0,SEEK_END);
    struct course current;
    while(1){
        int find_r[] = {0,0};
        fread(&current, sizeof(Course), 1, Course_File); 
        if(feof(Course_File)){    
            break;
        }
        if(!strncmp(current.course_name, actual_name, strlen(actual_name)))
            find_r[0] = 1;
        if(!strncmp(current.course_number, actual_number,strlen(actual_number)))
            find_r[1] = 1; 
        if(find_r[0] == 0 && find_r[1] == 0)
            fwrite(&current,sizeof(Course),1,backup);
    }
    fclose(Course_File);
    fclose(backup);
    if(!remove("Course.dat") && !rename("backup.dat","Course.dat")) return 0;
    else  return 1;
}