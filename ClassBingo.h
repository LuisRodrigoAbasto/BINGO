#include <vcl.h>
#include <tchar.h>


const maxf=100;
const maxc=100;
 class CMatriz
{ private:
		int m,n;
		float Matriz[maxf][maxc];
		int GetM();
		void SetM(int valor);
		int GetN();
		void SetN(int valor);
		float GetElem(int f, int c);
		void SetElem(int f, int c, float valor);
	public:
		CMatriz();
		__property int Filas={read=GetM, write=SetM};
		__property int Columnas={read=GetN, write=SetN};
		__property float Casilla[int f][int c]={read=GetElem, write=SetElem};
		void generar();
		bool repite(int num);
		bool repite_bolo(int bolo);
		void guardar(int num,int bolo);
		void cambiarDato(int dato);
		bool bingoHorizontal();
		bool bingoVertical();
		bool bingoCruzado();
		bool bingoEsquina();
		void generarHorizontal();
		bool repiteHorizontal(int num);
		void PonerCeroH();
		bool repite_boloH(int bolo);
		void guardarH(int num,int bolo);
		bool comparaMatriz(CMatriz *A) ;
 //		void generarCarton(int num);
		void cambiarDatoH(int dato);
		bool bingoHorizontalH();
		bool bingoVerticalH();
};

 CMatriz::CMatriz()
{ m=0; n=0;}

int CMatriz::GetM()
{ return m;}

void CMatriz::SetM(int valor)
{  if(valor<=maxf)
	 { m=valor;}
	 else
	 { ShowMessage("Error de dimensión");}
}

int CMatriz::GetN()
{  return n;}

void CMatriz::SetN(int valor)
{  if(valor<=maxc)
	 { n=valor;}
	 else
	 { ShowMessage("Error de dimensión");}
}

float CMatriz::GetElem(int f, int c)
{  if( f<m && c<n )
	 { return Matriz[f][c];}
	 else
	 {  ShowMessage("Error en posición");}
}

void CMatriz::SetElem(int f, int c, float valor)
{  if( f<m && c<n  )
	 { Matriz[f][c]=valor;}
	 else
	 {  ShowMessage("Error en posición");}
}


void CMatriz::generar()
{m=6,n=5;
   srand (time(NULL));
  int max=16, min=1;
  int valor_aletorio=0;
	for (int i = 0; i < n; i++) {
		 for (int j = 1; j < m; j++) {
			 do{
			do{ valor_aletorio=rand()% max;
			   }  while( min>valor_aletorio);
			   }while(repite(valor_aletorio));
			   Matriz[j][i]=valor_aletorio;
		 }
		 min=max;
		 max=max+15;
	}
  }


  bool CMatriz::repite(int num){
	 m=6,n=5;
  int sw=false;
  for (int i = 0; i < m; i++) {
	  for (int j = 1; j < n; j++) {
		if (Matriz[j][i]==num) {
			  sw=true;
		}
	  }
  }
  return sw;
  }

  bool CMatriz::repite_bolo(int bolo){
  n=75;
  m=2;
  int j=1;
  bool sw=false;
  for (int i = 0; i < n; i++) {
		 if (Matriz[j][i]==bolo) {
			sw=true;
		 }
  }
  return sw;
  }

  void CMatriz::cambiarDato(int dato){
  m=6;
  n=5;
  bool sw=false;
   for (int i = 0; i < n; i++) {
	   for (int j = 1; j < m; j++ && sw==false) {
				 if (Matriz[j][i]==dato) {
				   Matriz[j][i]=-1;
				   sw=true;	 }
		   }

	   }
	 }


  void CMatriz::guardar(int num,int bolo){
  n=75;
  m=2;
	   for (int i = num-1 ; i > 0; i--) {
		   Matriz[1][i]=Matriz[1][i-1] ;


				}
				Matriz[1][0]=bolo;

  }

  bool CMatriz::bingoHorizontal(){
   m=6;
  n=5;
  bool sw=false;
  float s=0;
   for (int i = 1; i < m; i++ && sw==false) {
   s=0;
	   for (int j = 0; j < n; j++ ) {
					 s+=Matriz[i][j];
	   }

	   if (s==-5) {
	   sw=true;
	   }

   }
   return sw;
   }

   bool CMatriz::bingoVertical(){
     m=6;
  n=5;
  bool sw=false;
  float s=0;
   for (int i = 0; i < n; i++ && sw==false) {
   s=0;
	   for (int j = 1; j < m; j++ ) {
					 s+=Matriz[j][i];
	   }

	   if (s==-5) {
	   sw=true;
	   }

   }
   return sw;
   }



   bool CMatriz::bingoCruzado(){
	m=6;
  n=5;
   bool sw=false;
   float s=0,c=0;

		for (int j = 0; j < m; j++&& sw==false) {
		 s+=Matriz[j+1][j];
		 c+=Matriz[j-n][j];
		 if (s==-5 || c==-5) {
			 sw=true;
		 }

		}
   return sw;
   }

   bool CMatriz::bingoEsquina(){
   bool sw=false;
   m=6;
   n=5;
	float s=0;
	 s+=Matriz[1][0];
	 s+=Matriz[1][4];
	 s+=Matriz[5][0];
	 s+=Matriz[5][4];
	 s+=Matriz[3][2];
		if (s==-5) {
	   sw=true;
		  }
	return sw;

   }

 void CMatriz::generarHorizontal(){
	 srand (time(NULL));
	 m=3, n=9;
  int max=11, min=1,c=0,i=0;
  int valor_aletorio=0;
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++ ) {
		 do{
		   do{valor_aletorio=rand()% max;}
		   while (min>valor_aletorio);  }
			  while (repiteHorizontal(valor_aletorio));
			  Matriz[j][i]=valor_aletorio;
	   }
	   min=max;
	   max=max+10;
	   
	}
 }


  bool CMatriz::repiteHorizontal(int num){
  int sw=false;
  m=3;
  n=9;
  for (int i = 0; i < m; i++) {
	  for (int j = 0; j < n; j++) {
		if (Matriz[i][j]==num) {
			  sw=true;
		}
	  }
  }
  return sw;
  }



  void CMatriz::PonerCeroH(){
  m=3,n=9;
  int j=0,c=0;
  for (int i = 0; i < m; i++) {
  c=0;
	 while (c<4){
	 do{  j=rand()%9; }
		while (Matriz[i][j]==0) ;
		  Matriz[i][j]=0;
	 c++;
	  }
	}
  
  }

  bool CMatriz::repite_boloH(int bolo){
  n=90;
  m=1;
  int j=0;
  bool sw=false;
  for (int i = 0; i < n; i++) {
		 if (Matriz[j][i]==bolo) {
			sw=true;
		 }
  }
  return sw;
  }

  void CMatriz::guardarH(int num,int bolo){
  n=90;
  m=1;
  int j=0;
	   for (int i = num-1 ; i > 0; i--) {
		   Matriz[j][i]=Matriz[0][i-1] ;
				}
				Matriz[j][0]=bolo;

  }

  bool CMatriz::comparaMatriz(CMatriz *A){
	 bool sw=false;
	  m=6;
	  n=5;
	  int c=0;
	  for (int i = 0; i < n; i++) {
	   for (int j = 1; j < m; j++) {
		  if (Matriz[j][i]==A->Casilla[j][i]) {
		  c++ ;
		  }  
	   } 
	  }
	   if (c==24) {
		   sw=true; }
	return sw;
  }




	void CMatriz::cambiarDatoH(int dato){
  m=3;
  n=9;
  bool sw=false;
   for (int i = 0; i < n; i++) {
	   for (int j = 0; j < m; j++ && sw==false) {
				 if (Matriz[j][i]==dato) {
				   Matriz[j][i]=-1;
				   sw=true;	 }
		   }

	   }
	 }


	  bool CMatriz::bingoHorizontalH(){
   m=3;
  n=9;
  bool sw=false;
  float s=0;
   for (int i = 0; i < m; i++ && sw==false) {
   s=0;
	   for (int j = 0; j < n; j++ ) {
			 s+=Matriz[i][j];
	   }

	   if (s==-5) {
	   sw=true;
	   }

   }
   return sw;
   }

   bool CMatriz::bingoVerticalH(){
	 m=3;
  n=9;
  bool sw=false;
  float s=0;
   for (int i = 0; i < n; i++ && sw==false) {
   s=0;
	   for (int j = 0; j < m; j++ ) {
					 s+=Matriz[j][i];
	   }

	   if (s==-3) {
	   sw=true;
	   }

   }
   return sw;
   }
