#include<stdio.h>
#define C 4
#define T 3
void cerear(int tabla[][T]);
void cargar(int tabla[][T]);
int Menu1(int tabla[][T]);
int Menu2(int tabla[][T]);
void total_alumnos(int tabla[][T]);
int acum_alum(int tabla[T]);
void Max_curso_inscriptos(int tabla[][T]);
int curso_inscriptos();
void Max_turno_inscriptos(int tabla[][T]);
int turno_inscriptos();
void curso_total_inscriptos(int tabla[][T],int total_curso[C]);
int acumula_curso(int fila[T]);
void turnos_total_inscriptos(int tabla[][T],int total_turno[T]);
int acumula_turno(int columna[][T],int turno);

int main(){
    int tabla[C][T],total_curso[C],total_turno[T];

    cerear(tabla);
    cargar(tabla);
    total_alumnos(tabla);
    Max_curso_inscriptos(tabla);
    Max_turno_inscriptos(tabla);
    curso_total_inscriptos(tabla,total_curso);
    turnos_total_inscriptos(tabla,total_turno);
    

    return 0;
}

void cerear(int tabla[][T]){
    int i,j;
    for(i=0;i< C;i++){
        for(j=0;j< T;j++){
            tabla[i][j]=0;
        }
    }

}

void cargar(int tabla[][T]){
    int cursos,turnos,cant_inscriptos;

    cursos=Menu1(tabla);

    while(cursos != 0){
        turnos=Menu2(tabla);

        while(turnos != 4){
            printf("Ingrese cantidad de inscriptos: ");
            scanf("%i", &cant_inscriptos);
            tabla[cursos-1][turnos-1]+=cant_inscriptos;

            turnos=Menu2(tabla);
        }
        cursos=Menu1(tabla);
    }

}

int Menu1(int tabla[][T]){
    int cursos;
    printf("CURSOS\n1_IA Generativa\n2_Administracion de Base de Datos\n3_Cableado de Datos\n4_Gestion Inteligente de APs\n0_Salir\n");
    printf("Ingrese opcion: ");
    scanf("%i", &cursos);

    while(cursos < 0 || cursos > 4){

        printf("\nOPCION INCORRECTA\n");

        printf("CURSOS\n1_IA Generativa\n2_Administracion de Base de Datos\n3_Cableado de Datos\n4_Gestion Inteligente de APs\n0_Salir\n");
        printf("Reingrese opcion: ");
        scanf("%i", &cursos);
    }
    return cursos;
}

int Menu2(int tabla[][T]){
    int turnos;
    printf("TURNOS\n1_Manana\n2_Tarde\n3_Vespertino\n4_Salir\nIngrese opcion: ");
    scanf("%i", &turnos);

    while(turnos < 1 || turnos > 4){

        printf("\nOPCION INCORRECTA\n");

        printf("TURNOS\n1_Manana\n2_Tarde\n3_Vespertino\n4_Salir\n");
        printf("Reingrese opcion: ");
        scanf("%i", &turnos);
    }

    return turnos;
}

void total_alumnos(int tabla[][T]){
    int i,acum=0;

    for(i=0;i< C;i++){
        acum+=acum_alum(tabla[i]);
    }

    printf("El total de alumnos inscriptos es: %i\n", acum);
}

int acum_alum(int tabla[T]){
    int i,acum=0;

    for(i=0;i< T;i++){
        acum+=tabla[i];
    }

    return acum;
}
void Max_curso_inscriptos(int tabla[][T]){
    int i,curso,max=0,total=0,turno_max=0;

    curso = curso_inscriptos();
    for(i=0;i < T;i++){
        total+=tabla[curso-1][i];

        if(tabla[curso-1][i] > max){
            max=tabla[curso-1][i];
            turno_max=i+1;
        }
    }

    if(turno_max == 1){
        printf("\nEl turno con mayor cantidad de inscriptos es Mañana con un total de %i inscriptos\n", max);
    }else if(turno_max == 2){
        printf("\nEl turno con mayor cantidad de inscriptos es Tarde con un total de %i inscriptos\n", max);
    }else if(turno_max == 3){
        printf("\nEl turno con mayor cantidad de inscriptos es Vespertino con un total de %i inscriptos\n", max);
    }
    printf("\nEl total de inscriptos en el curso %i es: %i", curso, total);

    
}

int curso_inscriptos(){
    int curso;
    printf("Ingrese el curso que desea consultar: ");
    scanf("%i", &curso);

    while(curso < 1 || curso > 4){

        printf("\nOPCION INCORRECTA\n");

        printf("Reingrese el curso que desea consultar: ");
        scanf("%i", &curso);
    }
    return curso;
}

void Max_turno_inscriptos(int tabla[][T]){
    int i,turno,max=0,total=0,curso_max=0;

    turno=turno_inscriptos();

    for(i=0;i < C;i++){
        total+=tabla[i][turno-1];

        if(tabla[i][turno-1] > max){
            max=tabla[i][turno-1];
            curso_max=i+1;
        }
    }

    if(curso_max==1){
        printf("El curso mas demandado es IA Generativa con un total de %i alumnos inscriptos\n",max);
    }else if(curso_max==2){
        printf("El curso mas demandado es Administracion de Base de Datos con un total de %i alumnos inscriptos\n",max);
    }else if(curso_max==3){
        printf("El curso mas demandado es Cableado de Datos con un total de %i alumnos inscriptos\n",max);
    }else if(curso_max==4){
        printf("El curso mas demandado es Gestion Inteligente de APs con un total de %i alumnos inscriptos\n",max);
    }

    printf("La cantidad de alumnos inscriptos en total de ese turno es: %i\n",total);

}

int turno_inscriptos(){
    int turno;

    printf("Ingrese turno a consultar: ");
    scanf("%i", &turno);

    while(turno < 1 || turno > 3){

        printf("\nOPCION INCORRECTA\n");

        printf("Reingrese turno a consultar: ");
        scanf("%i", &turno);
    }
    return turno;
}

void curso_total_inscriptos(int tabla[][T],int total_curso[C]){
    int i,max=0,curso=0;

    for(i=0;i < C;i++){
        total_curso[i]=acumula_curso(tabla[i]);
    }

    for(i=0;i<C;i++){
        if(total_curso[i] > max){
            max=total_curso[i];
            curso=i + 1;
        }
    }

    if(curso==1){
        printf("El curso con mayor cantidad de inscriptos es IA Generativa\n");
    }else if(curso==2){
        printf("El curso con mayor cantidad de inscriptos es Administracion de Base de Datos\n");
    }else if(curso==3){
        printf("El curso con mayor cantidad de inscriptos es Cableado de Datos\n");
    }else if(curso==4){
        printf("El curso con mayor cantidad de inscriptos es Gestion Inteligente de APs\n");
    }
}
int acumula_curso(int fila[T]){
    int i,acum=0;

    for(i=0;i<T;i++){
        acum+=fila[i];
    }

    return acum;
}

void turnos_total_inscriptos(int tabla[][T],int total_turno[T]){
    int i,max=0,turno=0;

    for(i=0;i<T;i++){
        total_turno[i]=acumula_turno(tabla,i);
    }

    for(i=0;i<T;i++){
        if(total_turno[i] > max){
            max=total_turno[i];
            turno=i + 1;
        }
    }
    if(turno==1){
        printf("El turno con mayor cantidad de inscriptos es Manana\n");
    }else if(turno==2){
        printf("El turno con mayor cantidad de inscriptoses Tarde\n");
    }else if(turno==3){
        printf("El turno con mayor cantidad de inscriptos es Vespertino\n");
    }

}

int acumula_turno(int tabla[][T],int turno){
    int i,acum=0;

    for(i=0;i<C;i++){
        acum+=tabla[i][turno];
    }
    return acum;
}