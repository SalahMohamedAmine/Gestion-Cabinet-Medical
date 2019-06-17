#include<stdio.h>
#include <conio.h>
#include<stdlib.h>

 struct patient {
       int id;
       char nom[20],prenom[20],adresse[20],nscDate[20],lieuDate[20],etatCivile[20];
       
       struct Date {
       	
       	int j,m,a,h ;
       	
	   };
       struct Date Date ;
};
struct patient p;

struct medicaments{
		int code ;
		int nom[20];
		int quantite;
	}; 
struct medicaments d;

int rech (int id){
	int i;
	FILE *fpatient ;
	
	fpatient=fopen("GestionnaireDesPatients.txt","r");
	
	
	do{
	
    fscanf(fpatient,"ID=%d\tNom:%s\tPrenom:%s\tAdreese:%s\tDate de naissance:%d/%d/%d\tLieu de Naissance:%s\tEtat Civile:%s",&p.id,&p.nom,&p.prenom,&p.adresse,&p.Date.j,&p.Date.m,&p.Date.a,&p.lieuDate,&p.etatCivile);
    fscanf(fpatient,"\n\n\n");

		if(p.id==id){
		fclose(fpatient);
		return 1;
	}
	

		
	}while(!feof(fpatient));
	
	fclose(fpatient);
    return 0;
	
}

//Condition de saisir une date correcte
void ConditionDeSaisir(struct patient *p,int choixNum){
	
	do{
		printf("\nDonner le jour :\t");
		scanf("%d",&p->Date.j);
		if (p->Date.j<1 || p->Date.j>31)printf("jour invalide ");
	}while(p->Date.j<1 || p->Date.j>31);
	
	
	do {
		printf("\nDonner le mois :\t");
		scanf("%d",&p->Date.m);
		if (p->Date.m <1 || p->Date.m>12)printf("mois invalide ");
	}while(p->Date.m<1 || p->Date.m>12);
	
	
	do {
		printf("\nDonner l annee :\t");
		scanf("%d",&p->Date.a);
		if(p->Date.a <1900 || p->Date.a >2016) printf("annee invalide ");
	}while(p->Date.a <1900 || p->Date.a >2016);
	
	if (choixNum==1){
	do{
		printf("\nDonner l heure :\t");
		scanf("%d",&p->Date.h);
		if(p->Date.h<0 || p->Date.h>23)printf("heure invalide ");
	}while(p->Date.h<0 || p->Date.h>23);}
}

void GestPatient ( int i){
	struct patient p;
	
	 
     FILE *fpatient ;
     fpatient = fopen("GestionnaireDesPatients.txt","a");
     printf("donner l ID du patient num %d:\t",i);
     scanf("%d",&p.id);
     if(rech(p.id)==0) {
	 
     printf("donner le Nom et Prenom du patient num %d:\t",i);
     scanf("%s",&p.nom);
     scanf("%s",&p.prenom);
     printf("donner l adresse du patient num %d:\t",i);
     scanf("%s",&p.adresse);
     printf("donner la date du naissance du patient num %d:\t",i);
     ConditionDeSaisir(&p,0);
     printf("donner le lieu du naissance du patient num %d:\t",i);
     scanf("%s",&p.lieuDate);
     printf("donner l etat civile du patient num %d:\t",i);
     scanf("%s",&p.etatCivile);
     
     
      
      fprintf(fpatient,"ID=%d\tNom:%s\tPrenom:%s\tAdreese:%s\tDate de naissance:%d/%d/%d\tLieu de Naissance:%s\tEtat Civile:%s",p.id,p.nom,p.prenom,p.adresse,p.Date.j,p.Date.m,p.Date.a,p.lieuDate,p.etatCivile);
      fprintf(fpatient,"\n\n\n");
      fclose(fpatient);
      
	  }
	  
	  else printf("L ID existe\n");
	  
      
         
}




void supprime(){
		int ID,i ;
    printf("Donner l ID a rechercher :");
	scanf("%d",&ID);
	FILE *fpatient,*f;
	f=fopen("patient.txt","a");
	fpatient=fopen("GestionnaireDesPatients.txt","r");	
	if(rech(ID)==0) printf("L ID n existe pas\n");
	else {	
	do{
	
    fscanf(fpatient,"ID=%d\tNom:%s\tPrenom:%s\tAdreese:%s\tDate de naissance:%d/%d/%d\tLieu de Naissance:%s\tEtat Civile:%s",&p.id,&p.nom,&p.prenom,&p.adresse,&p.Date.j,&p.Date.m,&p.Date.a,&p.lieuDate,&p.etatCivile);
    fscanf(fpatient,"\n\n\n");
	if(p.id!=ID){
    	fprintf(f,"ID=%d\tNom:%s\tPrenom:%s\tAdreese:%s\tDate de naissance:%d/%d/%d\tLieu de Naissance:%s\tEtat Civile:%s",p.id,p.nom,p.prenom,p.adresse,p.Date.j,p.Date.m,p.Date.a,p.lieuDate,p.etatCivile);
        fprintf(f,"\n\n\n");
	}
	}while(!feof(fpatient));
	fclose(f);
	fclose(fpatient);
	remove("GestionnaireDesPatients.txt");
	rename("patient.txt","GestionnaireDesPatients.txt");
}
}
	
	
	
void AfficheListePatient(){
	
	FILE *f ;
	f=fopen("GestionnaireDesPatients.txt","r");
	printf("\t*************Liste Des Patients******************\n");
	do{
	
    fscanf(f,"ID=%d\tNom:%s\tPrenom:%s\tAdreese:%s\tDate de naissance:%d/%d/%d\tLieu de Naissance:%s\tEtat Civile:%s",&p.id,&p.nom,&p.prenom,&p.adresse,&p.Date.j,&p.Date.m,&p.Date.a,&p.nscDate,&p.lieuDate,&p.etatCivile);
    fscanf(f,"\n\n\n");
    
		
    	printf("ID=%d\tNom:%s\tPrenom:%s\tAdreese:%s\tDate de naissance:%d/%d/%d\tLieu de Naissance:%s\tEtat Civile:%s",p.id,p.nom,p.prenom,p.adresse,p.Date.j,p.Date.m,p.Date.a,p.nscDate,p.lieuDate,p.etatCivile);
        printf("\n\n\n");
	
	}while(!feof(f));
	
}	
	
void rechPatient(){
	int ID,i ;
	
	printf("Donner l ID a rechercher :");
	scanf("%d",&ID);
	
	
	FILE *fpatient;
	fpatient=fopen("GestionnaireDesPatients.txt","r");
	
	if(rech(ID)==0) printf("L ID n existe pas\n");
	
	else {
		
		
		
	do{
	
    fscanf(fpatient,"ID=%d\tNom:%s\tPrenom:%s\tAdreese:%s\tDate de naissance:%d/%d/%d\tLieu de Naissance:%s\tEtat Civile:%s",&p.id,&p.nom,&p.prenom,&p.adresse,&p.Date.j,&p.Date.m,&p.Date.a,&p.nscDate,&p.lieuDate,&p.etatCivile);
    fscanf(fpatient,"\n\n\n");
    
	if(p.id==ID){
		printf("\t*************inforamation sur le patient******************\n");
    	printf("ID=%d\tNom:%s\tPrenom:%s\tAdreese:%s\tDate de naissance:%d/%d/%d\tLieu de Naissance:%s\tEtat Civile:%s",p.id,p.nom,p.prenom,p.adresse,p.Date.j,p.Date.m,p.Date.a,p.nscDate,p.lieuDate,p.etatCivile);
        printf("\n\n\n");
	}
	}while(!feof(fpatient));

		
		
	}
	
}



void modifier (){
	
	int ID,i ;
	char r,rep;
	
    printf("Donner l ID a modifie:");
	scanf("%d",&ID);
	FILE *fpatient,*f;
	f=fopen("patient.txt","a");
	fpatient=fopen("GestionnaireDesPatients.txt","r");	
	if(rech(ID)==0) printf("L ID n existe pas\n");
	
	
	else {	
	
	do{
	
    fscanf(fpatient,"ID=%d\tNom:%s\tPrenom:%s\tAdreese:%s\tDate de naissance:%d/%d/%d\tLieu de Naissance:%s\tEtat Civile:%s",&p.id,&p.nom,&p.prenom,&p.adresse,&p.Date.j,&p.Date.m,&p.Date.a,&p.lieuDate,&p.etatCivile);
    fscanf(fpatient,"\n\n\n");
    if(p.id==ID){
    	printf("Voulez vous changez l'adresse ?(tapez O pour oui):\t");
    	scanf("%s",&r);
    	if(r=='o'||r=='O'){
    	printf("\nDonner la nouvelle adresse a modifier :\t");
	    scanf("%s",&p.adresse);
	}
	printf("\nVoulez vous modifier l'etat civil?(tapez O pour oui):\t");
	scanf("%s",&rep);
	if(rep=='o'||rep=='O'){
		printf("donner la nouvelle etat civil a modifier\n");
		scanf("%s",&p.etatCivile);
}
    	
    	fscanf(fpatient,"ID=%d\tNom:%s\tPrenom:%s\tAdreese:%s\tDate de naissance:%d/%d/%d\tLieu de Naissance:%s\tEtat Civile:%s",&p.id,&p.nom,&p.prenom,&p.adresse,&p.Date.j,&p.Date.m,&p.Date.a,&p.lieuDate,&p.etatCivile);
}
     
     fprintf(f,"ID=%d\tNom:%s\tPrenom:%s\tAdreese:%s\tDate de naissance:%d/%d/%d\tLieu de Naissance:%s\tEtat Civile:%s",p.id,p.nom,p.prenom,p.adresse,p.Date.j,p.Date.m,p.Date.a,p.lieuDate,p.etatCivile);
     fprintf(f,"\n\n\n");
     
	}while(!feof(fpatient));}
	fclose(f);
	fclose(fpatient);
	remove("GestionnaireDesPatients.txt");
	rename("patient.txt","GestionnaireDesPatients.txt");
       } 
       
int rechR (int j,int m,int a, int h){
	
	FILE *frdv ;
	
	frdv=fopen("Rendez-Vous.txt","r");

	
	do{
	
    fscanf(frdv,"%d/%d/%d h:%d",&p.Date.j,&p.Date.m,&p.Date.a,&p.Date.h);
    fscanf(frdv,"\n");
		if( (p.Date.j==j) && (p.Date.m==m) && (p.Date.a==a) && (p.Date.h == h )){
		fclose(frdv);
		return 1;
	}
	}while(!feof(frdv));
	
	fclose(frdv);
    return 0;
	
}
	
	
      

void RendezVous (){
	struct patient p;
	
	printf("donner la date de reservation :\t");
	ConditionDeSaisir(&p,1);
	
	
	FILE *frdv ;
    frdv = fopen("Rendez-Vous.txt","a");
	
	if(rechR(p.Date.j,p.Date.m,p.Date.a,p.Date.h)==1) printf("date est deja reservee");
	else {
		//==============================
     
     
      
      fprintf(frdv,"%d/%d/%d h:%d",p.Date.j,p.Date.m,p.Date.a,p.Date.h);
      fprintf(frdv,"\n");
      
      
      fclose(frdv);
		
		
		
		//==============================
	}
	
	
	
}
void ModifierR(){
	struct patient p1;
	
	printf("Donner la date a modifier :");
	ConditionDeSaisir(&p1,1);
	if(rechR(p1.Date.j,p1.Date.m,p1.Date.a,p1.Date.h)==0) printf("\nla date a modifier n est pas valide");
	
	else {
		
	FILE *fRendR,*frdv;
	frdv=fopen("Rendez-Vous.txt","r");
	fRendR=fopen("tmpp.txt","a");
	
	
	do{
	fscanf(frdv,"%d/%d/%d h:%d",&p.Date.j,&p.Date.m,&p.Date.a,&p.Date.h);
    fscanf(frdv,"\n");
    
	if((p.Date.j==p1.Date.j) && (p.Date.m==p1.Date.m) && (p.Date.a==p1.Date.a) && (p.Date.h == p1.Date.h )){
    
    	
    
		printf("Donner la nouvelle date a modifier :");
	     ConditionDeSaisir(&p1,1);
		fprintf(fRendR,"%d/%d/%d h:%d\n",p1.Date.j,p1.Date.m,p1.Date.a,p1.Date.h);
		}
     else{
     fprintf(fRendR,"%d/%d/%d h:%d",p.Date.j,p.Date.m,p.Date.a,p.Date.h);
     fprintf(fRendR,"\n");
 }
	}while(!feof(frdv));
	
	fclose(frdv);
	fclose(fRendR);
	remove("Rendez-Vous.txt");
	rename("tmpp.txt","Rendez-Vous.txt");
       } 	
		
		
		
	}
	
	
void SupprimeR(){
	struct patient p1;
    
	printf("Donner la date a modifier :");
	ConditionDeSaisir(&p1,1);
	if(rechR(p1.Date.j,p1.Date.m,p1.Date.a,p1.Date.h)==0) printf("\nla date a supprimer n est pas valide");
	
	else {
	FILE *fRendR,*frdv;
	frdv=fopen("Rendez-Vous.txt","r");
	fRendR=fopen("tmpp.txt","a");
	do{
	fscanf(frdv,"%d/%d/%d h:%d",&p.Date.j,&p.Date.m,&p.Date.a,&p.Date.h);
    fscanf(frdv,"\n");
    
	if((p.Date.j==p1.Date.j) && (p.Date.m==p1.Date.m) && (p.Date.a==p1.Date.a) && (p.Date.h == p1.Date.h )) continue;
	
     
     fprintf(fRendR,"%d/%d/%d h:%d",p1.Date.j,p1.Date.m,p1.Date.a,p1.Date.h);
     fprintf(fRendR,"\n");
     
	}while(!feof(frdv)  );
	fclose(frdv);
	fclose(fRendR);
	remove("Rendez-Vous.txt");
	rename("tmpp.txt","Rendez-Vous.txt");
       } 		
		
		
		
	}
	
void AfficheListeRendezVous(){
	
	FILE *r ;
	r=fopen("Rendez-Vous.txt","r");
	printf("\t*************Liste Des Rendez-Vous******************\n");
	do{
	fscanf(r,"%d/%d/%d h:%d",&p.Date.j,&p.Date.m,&p.Date.a,&p.Date.h);
	fscanf(r,"\n");
    printf("%d/%d/%d h:%d",p.Date.j,p.Date.m,p.Date.a,p.Date.h);
    printf("\n");
		
	}while(!feof(r));
	
}	
	
	
int rechm(int ncode){
	

	FILE*f;
	f=fopen("medicaments.txt","r");
	do{
		fscanf(f,"%d%s%d",&d.code,&d.nom,&d.quantite);
		if(ncode==d.code){
			fclose(f);
			return 1;
		}
	}while(!feof(f));
	fclose(f);
	return 0;
}

void ajouterM (){
	struct medicaments d;
	int ncode;
	printf("saisir le code de medicaments:\t");
	scanf("%d",&ncode);
	FILE*f;
	f=fopen("medicaments.txt","a");
	if(rechm(ncode)==1) {
	printf("le medicament n'existe pas");
}
	if(rechm(ncode)==0){
		d.code=ncode;
		printf("saisir le nom de medicaments:\t");
		scanf("%s",&d.nom);
		printf("saisir la quantite:\t");
		scanf("%d",&d.quantite);
		fprintf(f,"%d/%s/%d\n",d.code,d.nom,d.quantite);
		fprintf(f,"\n");
		
		fclose(f);
	}
		
}
void supprimeM(){
	int ncode;
	printf("saisir le code:\t");
	scanf("%d",&ncode);
	FILE*f,*fs;
	f=fopen("medicaments.txt","r");
	fs=fopen("tempp.txt","a");
	if(rechm(ncode)==0)printf("le code du medicament n'existe pas:\n");
	else{
		do{
			fscanf(f,"%d%s%d",&d.code,&d.nom,d.quantite);
			if(d.code!=ncode){
				fprintf(fs,"%d%s%d",&d.code,&d.nom,d.quantite);
				
			}
			
		}while(!feof(f));
		fclose(f);
		fclose(fs);
		remove("medicaments.txt");
		rename("tempp.txt","medicaments.txt");
		
	}
}
void modifierM(){
	
	int ncode;
	printf("saisir le code :\t");
	scanf("%d",&ncode);
	FILE*f,*fs;
	f=fopen("medicaments.txt","r");
	fs=fopen("tempp.txt","a");
	if(rechm(ncode)==0){
	printf("le medicament n'exsite pas:\t");}
	else{
		do{
			fscanf(f,"%d/%s/%d\n",&d.code,&d.nom,&d.quantite);
		    
			if(d.code==ncode){
				
				printf("saisir le nouveau nom:\t");
				scanf("%s",&d.nom);
				printf("saisir la nouvelle quantite:\t");
				scanf("%d",&d.quantite);
				fscanf(fs,"%d/%s/%d\n",&d.code,&d.nom,&d.quantite);
		       
				
			}
			    
			    fprintf(fs,"%d/%s/%d\n",d.code,d.nom,d.quantite);
		       
	
		}while(feof(f));
	}
	
	fclose(f);
	fclose(fs);
	remove("medicaments.txt");
	rename("tempp.txt","medicaments.txt");
}
	

main(){
   
   int i,n,choix,choixm,choixd;
   do{
   printf("\t***********Menu***********\n -1- Gestion des Patients \n -2- Gestion des Rendez-Vous \n -3- Gestion des Medicaments\n -4- Quitter\t");
   scanf("%d",&choixm);
   switch(choixm){
   
   case 1:{
	   
    printf("Donner votre choix :\n -1- pour Ajouter\n -2- pour supprimer\n -3- pour rechercher\n -4- pour modifier\n -5- Pour afficher toute la liste des Patients\t");
    scanf("%d",&choix);

   
    switch(choix){   
	          
    case 1: printf("Donner les numeros des clients:\t");
     scanf("%d",&n);
     
     for(i=1;i<=n;i++) GestPatient(i);
    break;
    case 2:supprime();
    break;
    case 3:rechPatient();
    break;
    case 4:modifier();
    break ;
	case 5 : AfficheListePatient();
	break ;	
   }break;}
   
   case 2 : {
   printf("Donner votre choix :\n -1- Ajouter des Rendez-Vous\t\n -2- Modifier un Rendez-Vous\t\n -3- Supprimer un Rendez-Vous\n -4- Afficher toute la liste des Rendez-Vous\t");
   scanf("%d",&choix);
   	switch(choix){
	
	case 1 : RendezVous();
	break ;
	
	case 2: ModifierR();
	break;
	
	case 3:SupprimeR();
	break;
	case 4:AfficheListeRendezVous();
   	break;
	
	}
	break;
   }
   case 3:{
   	printf("donner votre choix:\n-1-ajouter un medicaments\t\n-2-supprimer un medicament\t\n-3-modifier un medicament\t\n");
   	scanf("%d",&choix);
   	switch(choix){
   		
   		case 1:ajouterM();
   		break;
   	
   	case 2:supprimeM();
   		break;
   	case 3: modifierM();
   	break;
   	
   }
   }
   break ;
   case 4: printf("Merci pour utiliser notre Programme cree par : \n  Mkadmi Mouadh\n  Ferjani Ramy \n  Salah Mohamed Amine\n");
   break;
   default : printf("Choix Invalide entrer un choix valide \n");
   break ;
} 


}while(choixm != 4);
getch();
}

