
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>


#define clear() printf("\033[H\033[J")
#define c 4
#define t 19
#define max_width 15


void FlushStdin(void) {
  int ch;
  while(((ch = getchar()) !='\n') && (ch != EOF));
}


struct transaccion{
	char id[7];
	char fecha[8];
	char numero_cuenta[8];
	long long valor;
	char tipo_trans;
};

struct cuentas{
	char numero_cuenta[50];
	char estado[50]; // activa inactiva cancelada
	char fecha_creada[50];
	char fecha_cancelada[50];
	char cedula[50];
	char nombre[50];
	char direccion[50];
	char telefono[50];
	char e_mail[50];

	long long saldo;
};
void trans_consignar(){
	printf("%s\n", "Digite el numero de cedula");
	char cc[50];
	scanf("%s", cc);
	FlushStdin();
	printf("%s\n", "Cuanto dinero desea consignar?");
	long long valor;
	long long valortemp;
	scanf("%lld", &valor);
	FlushStdin();

	FILE *archdisco;
	archdisco = fopen("cuentas.txt","r+");
	struct cuentas cuenta_a_modificar;

	while(fread(&cuenta_a_modificar, sizeof(struct cuentas),1,archdisco) != 0){
		if (strcmp(cc, cuenta_a_modificar.cedula) == 0){
				printf("%s\n", "Por favor confirme el calor a consignar:");
				scanf("%lld", &valortemp);
				if(valor == valortemp){
					cuenta_a_modificar.saldo += valor;
					fseek(archdisco, -sizeof(cuenta_a_modificar), SEEK_CUR); //places the pointer at the struct I want
					fwrite(&cuenta_a_modificar, sizeof(cuenta_a_modificar), 1, archdisco); //adds the new structP
					printf("%s\n", "Consignacion exitosa !\n");
					sleep(0.6);
					exit(0);
					break;
				}else{
					clear();
					printf("%s\n", "Los valores no coinciden.");
					sleep(1);
					exit(0);
				}
		}
	}
	fclose(archdisco);
};
void trans_retirar(){
	printf("%s\n", "Digite el numero de cedula");
	char cc[50];
	scanf("%s", cc);
	FlushStdin();
	printf("%s\n", "Cuanto dinero desea retirar?");
	long long valor;
	long long valortemp;
	scanf("%lld", &valor);
	FlushStdin();

	FILE *archdisco;
	archdisco = fopen("cuentas.txt","r+");
	struct cuentas cuenta_a_modificar;

	while(fread(&cuenta_a_modificar, sizeof(struct cuentas),1,archdisco) != 0){
		if (strcmp(cc, cuenta_a_modificar.cedula) == 0){
				printf("%s\n", "Por favor confirme el calor a retirar:");
				scanf("%lld", &valortemp);
				if(valor == valortemp){
					if((cuenta_a_modificar.saldo - valor)<= 0){
						printf("%s\n", "Usted no posee fondos suficientes para relaizar la transaccion");
						exit(0);
					}else{
						cuenta_a_modificar.saldo = cuenta_a_modificar.saldo - valor;
					}
					fseek(archdisco, -sizeof(cuenta_a_modificar), SEEK_CUR); //places the pointer at the struct I want
					fwrite(&cuenta_a_modificar, sizeof(cuenta_a_modificar), 1, archdisco); //adds the new structP
					printf("%s\n", "Consignacion exitosa !\n");
					sleep(0.6);
					exit(0);
					break;
				}else{
					clear();
					printf("%s\n", "Los valores no coinciden.");
					sleep(1);
					exit(0);
				}
		}
	}
	fclose(archdisco);

};
struct transaccion vector_transacciones[t];



struct cuentas vector_cuentas[c];

void crear_cuenta(){

	struct cuentas cuenta_a_crear;

		int temp = rand() % (999999999 - 100000000) + 100000000;            //numero aleatorio de cuenta

		sprintf(cuenta_a_crear.numero_cuenta, "%d", temp); 				// Estamos trabajando con direcciones que apuntan a donde esta la estructura.
		FlushStdin();
		strcpy(cuenta_a_crear.estado, "1"); // Estado

		time_t rawtime;
	   	struct tm *info;
	   	time( &rawtime );													// FECHA CREADA
	   	info = localtime( &rawtime );
	   	strftime(cuenta_a_crear.fecha_creada,80,"%x - %I:%M%p", info);

	   	strcpy(cuenta_a_crear.fecha_cancelada, "No cancelada");



	   	printf("%s\n", "Digite el numero de su cedula");    					//CEDULA
	   	fgets(cuenta_a_crear.cedula, 50, stdin);
	   	strtok(cuenta_a_crear.cedula, "\n");

	   	printf("%s\n", "Digite su nombre");									//NOMBRE
		fgets(cuenta_a_crear.nombre, 50, stdin);
		strtok(cuenta_a_crear.nombre, "\n");

	 	printf("%s\n", "Digite su direccion");								//DIRECCION
		fgets(cuenta_a_crear.direccion, 50, stdin);
		strtok(cuenta_a_crear.direccion, "\n");

	   	printf("%s\n", "Digite su telefono");									//TELEFONO
		fgets(cuenta_a_crear.telefono, 50, stdin);
		strtok(cuenta_a_crear.telefono, "\n");

	   	printf("%s\n", "Digite su e_mail");									//E_MAIL
		fgets(cuenta_a_crear.e_mail, 50, stdin);
		strtok(cuenta_a_crear.e_mail, "\n");

		cuenta_a_crear.saldo = 100000;

		FILE *fp;
		fp = fopen("cuentas.txt", "a+");

		// fprintf(fp, "\n %s %s %s %s %s %s %s %s %s", "Nro de cuenta", "Estado", "Fecha creada", "Fecha cancelada", "Cedula", "Nombre", "Direccion", "Telefono", "email");

		// fprintf(fp, "\n %s %s %s %s %s %s %s %s %s", cuenta_a_crear.numero_cuenta, cuenta_a_crear.estado, cuenta_a_crear.fecha_creada, cuenta_a_crear.fecha_cancelada, cuenta_a_crear.cedula, cuenta_a_crear.nombre, cuenta_a_crear.direccion, cuenta_a_crear.telefono, cuenta_a_crear.e_mail);

		fwrite(&cuenta_a_crear, sizeof(cuenta_a_crear), 1, fp);

		fclose(fp);

		printf("%s\n", "Cuenta creada con satisfaccion, saldo actual = $100.000");
	};

void leerCuentaDisco(){
	// printf("%s\n", "Buscar por cedula");
	// char cedula[50];
	// fgets(cedula, 50, stdin);
	// strtok(cedula, "\n");

	FILE *archdisco;
	archdisco = fopen("cuentas.txt","a+");
	struct cuentas cuenta_a_buscar;
	printf("%s\n", "CC?");
	char cc[50];
	scanf("%s", cc);

	while(fread(&cuenta_a_buscar, sizeof(struct cuentas),1,archdisco) != 0){
		if (strcmp(cc, cuenta_a_buscar.cedula) == 0){
			clear();
			printf("%s\n", "Cuenta encontrada !");
			sleep(0.9);
			printf("\n Nro de cuenta = %s ", cuenta_a_buscar.numero_cuenta);
			printf("\n Estado = %s ", cuenta_a_buscar.estado);
			printf("\n Fecha creada = %s ", cuenta_a_buscar.fecha_creada);
			printf("\n Fecha cancelada = %s ", cuenta_a_buscar.fecha_cancelada);
			printf("\n Cedula =%s ",cuenta_a_buscar.cedula);
			printf("\n nombre =%s ",cuenta_a_buscar.nombre);
			printf("\n Direccion=%s ",cuenta_a_buscar.direccion);
			printf("\n Telefono=%s ",cuenta_a_buscar.telefono);
			printf("\n e_mail= %s",cuenta_a_buscar.e_mail);
			printf("\n saldo= $%'lld",cuenta_a_buscar.saldo);
		}
	}
	fclose(archdisco);
}


void modificar_cuenta(){

	printf("%s\n", "Digite el numero de cedula");
	char cc[50];
	scanf("%s", cc);
	FlushStdin();
	printf("%s\n", "Que opcion desea cambiar?\n[1] Direccion\t[2] Telefono\n[3] email");
	int sel;
	char mod_dir[50];
	char mod_tel[50];
	char mod_email[50];
	scanf("%d", &sel);
	FlushStdin();

	FILE *archdisco;
	archdisco = fopen("cuentas.txt","r+");
	struct cuentas cuenta_a_modificar;

	while(fread(&cuenta_a_modificar, sizeof(struct cuentas),1,archdisco) != 0){
		if (strcmp(cc, cuenta_a_modificar.cedula) == 0){
			if (sel == 1){
				printf("%s\n", "Nueva direccion:");
				scanf("%s", mod_dir);
				strcpy(cuenta_a_modificar.direccion, mod_dir);

				fseek(archdisco, -sizeof(cuenta_a_modificar), SEEK_CUR); //places the pointer at the struct I want

				fwrite(&cuenta_a_modificar, sizeof(cuenta_a_modificar), 1, archdisco); //adds the new structP
				break;
				
				printf("%s\n", "Cambio de direccion exitoso !\n");
			}else if(sel == 2){
				printf("%s\n", "Nuevo telefono:");
				scanf("%s", mod_tel);
				strcpy(cuenta_a_modificar.telefono, mod_tel);

				fseek(archdisco, -sizeof(cuenta_a_modificar), SEEK_CUR); //places the pointer at the struct I want
				fwrite(&cuenta_a_modificar, sizeof(struct cuentas), 1, archdisco); //adds the new struct
				printf("%s\n", "Cambio de telefono exitoso !\n");

			}else if(sel == 3){
				printf("%s\n", "Nuevo e_mail:");
				scanf("%s", mod_email);
				strcpy(cuenta_a_modificar.e_mail, mod_email);
				fseek(archdisco, -sizeof(cuenta_a_modificar), SEEK_CUR); //places the pointer at the struct I want
				fwrite(&cuenta_a_modificar, sizeof(struct cuentas), 1, archdisco); //adds the new struct
				printf("%s\n", "Cambio de e_mail exitoso !\n");
			}
		}
	}
	fclose(archdisco);
};
void cambiar_estado_cuenta(){

};

void ver_movimiento_cuenta(){

};



void menu_cuenta(){

	int choice;
	do
	{
	printf("\n%s\n", "Choose: ");
	printf("%s\n", "[1] Crear cuenta \t[2] Modificar cuenta\n[3] Leer cuenta del disco\t[4] Salir");
	scanf("%d",&choice);
	   
	switch (choice)
	{
	    case 1: crear_cuenta();
	         break;
	    case 2: modificar_cuenta();
	         break;
	    case 3: leerCuentaDisco(); 
	        break;
	    case 4: printf("%s\n", "Hasta luego ");
	    		exit(0);

	    default: printf("Wrong Choice. Enter again\n");
	    break;
	} 
	 
 	} while (choice != 4);
}
void menu_transa(){

	int choice;
	do
	{
	printf("\n%s\n", "Choose: ");
	printf("%s\n", "[1] Consignacion \t[2] Retiro\t[3] Salir");
	scanf("%d",&choice);
	   
	switch (choice)
	{
	    case 1: trans_consignar();
	         break;
	    case 2: trans_retirar();
	         break;
	    case 3: printf("%s\n", "Hasta luego ");
	    		exit(0);

	    default: printf("Wrong Choice. Enter again\n");
	    break;
	} 
	 
 	} while (choice != 3);
}

void menu_ppal(){
	int choice;
	do
	{
	printf("\n%s\n", "Choose: ");
	printf("%s\n", "[1] Cuenta \t[2] Transacciones\n[3] Salir");
	scanf("%d",&choice); 
	switch (choice)
	{
	    case 1: menu_cuenta();
	         break;
	    case 2: menu_transa();
	         break;
	    case 3: printf("%s\n", "Hasta luego ");
	    		exit(0);

	    default: printf("Wrong Choice. Enter again\n");
	    break;
	} 
 	} while (choice != 3);

}
int main(){
	// FlushStdin();
	srand (time(NULL)); // Numerosb aleatorios nuevos, semilla con el tiempo	 
	setlocale(LC_NUMERIC, ""); //money format
	
	menu_ppal();

} 