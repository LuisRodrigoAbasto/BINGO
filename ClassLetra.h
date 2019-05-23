const maxfL=100;
const maxcL=100;
 class CLetra
{ private:
		int m,n;
		float Letra[maxfL][maxcL];
		int GetM();
		void SetM(int valor);
		int GetN();
		void SetN(int valor);
		char GetElem(int f, int c);
		UnicodeString SetElem(int f, int c, char valor);

	public:
		CLetra();
		__property int Filas={read=GetM, write=SetM};
		__property int Columnas={read=GetN, write=SetN};
		__property char Casilla[int f][int c]={read=GetElem, write=SetElem};
		 void generar();
		void cambiarDato(int dato);
		bool bingoHorizontal();
		bool bingoVertical();
		bool bingoCruzado();
		bool bingoEsquina();
		UnicodeString generarLetra();
		bool repiteLetra(int letra);
		bool repite_bolo_letra(int bolo);
		void guardar_letra(int num,int bolo);
		void generarBlanco();
		void generarH();
		bool repiteLetraH(int letra);
		void guardarLetraH(int num, int bolo);
		bool repite_bolo_letraH(int bolo);
		bool bingoHorizontalH();
		bool bingoVerticalH();
		void cambiarDatoH(int dato);
};

 CLetra::CLetra()
{ m=0; n=0;}

int CLetra::GetM()
{ return m;}

void CLetra::SetM(int valor)
{  if(valor<=maxfL)
	 { m=valor;}
	 else
	 { ShowMessage("Error de dimensión");}
}

int CLetra::GetN()
{  return n;}

void CLetra::SetN(int valor)
{  if(valor<=maxcL)
	 { n=valor;}
	 else
	 { ShowMessage("Error de dimensión");}
}

char CLetra::GetElem(int f, int c)
{  if( f<m && c<n )
	 { return Letra[f][c];}
	 else
	 {  ShowMessage("Error en posición");}
}

UnicodeString CLetra::SetElem(int f, int c, char valor)
{  if( f<m && c<n  )
	 { Letra[f][c]=valor;}
	 else
	 {  ShowMessage("Error en posición");}
}


  UnicodeString CLetra::generarLetra(){
  n=5;
  m=1;
  char B='B',I='I',N='N',G='G',O='O';
  int j=0;
  for (int i = 0; i < n ; i++) {
			   Letra[j][i]=B ;

	  if (i==1) {
			  Letra [j][i]=I ;  }
			  else{ if (i==2) {
			  Letra [j][i]=N ;  }
			  else{  if (i==3) {
			  Letra [j][i]=G ;  }
			  else{ if (i==4) {
			  Letra [j][i]=O ;  }

              }

              }

			  }
  }
  }


void CLetra::generar()
{  m=5, n=5;
 srand (time(NULL));
  int max=91, min=65;
  int valor_aletorio=0;
	for (int i = 0; i < n; i++) {
		 for (int j = 0; j < m; j++) {
		   do{
			do{ valor_aletorio=rand()% max;
			   }  while( min>valor_aletorio);
				} while(repiteLetra(valor_aletorio));
			   Letra[j][i]=valor_aletorio;
		 }

		}
  }


  bool CLetra::repiteLetra(int letra){
  m=5, n=5;
  int sw=false;
  for (int i = 0; i < m; i++) {
	  for (int j = 0; j < n; j++) {
		if (Letra[j][i]==letra) {
			  sw=true;
		}
	  }
  }
  return sw;
  }


  void CLetra::cambiarDato(int dato){
  m=5;
  n=5;
  bool sw=false;
   for (int i = 0; i < n; i++) {
	   for (int j = 0; j < m; j++ && sw==false) {
				 if (Letra[j][i]==dato) {
				   Letra[j][i]='-';
				   sw=true;	 }
		   }

	   }
	 }


	  bool CLetra::bingoHorizontal(){
   m=6;
  n=5;
  bool sw=false;
  float s=0;
   for (int i = 0; i < m; i++ && sw==false) {
   s=0;
	   for (int j = 0; j < n; j++ ) {
			   if (Letra[i][j]=='-'){
			   s--;}
	   }

	   if (s==-5) {
	   sw=true;
	   }

   }
   return sw;
   }


 bool CLetra::bingoVertical(){
	 m=5;
  n=5;
  bool sw=false;
  float s=0;
   for (int i = 0; i < n; i++ && sw==false) {
   s=0;
	   for (int j = 0; j < m; j++ ) {
		  if (Letra[j][i]=='-'){
		  s--;}
	   }

	   if (s==-5) {
	   sw=true;
	   }
   }
   return sw;
   }



   bool CLetra::bingoCruzado(){
	m=5;
  n=5;
   bool sw=false;
   float s=0,c=0;

		for (int j = 0; j < m; j++&& sw==false) {
		 if (Letra[j][j]=='-' || Letra[j-n][j]=='-'){
		 s--;
		 c--;
		 }

		 if (s==-5 || c==-5) {
			 sw=true;
		 }

		}
   return sw;
   }

	 bool CLetra::bingoEsquina(){
   bool sw=false;
   m=5;
   n=5;
		if (Letra[0][0]=='-' && Letra[0][4]=='-' && Letra[4][0]=='-' && Letra[4][4]=='-' && Letra[2][2]=='-') {
	   sw=true;
		  }
	return sw;

   }



	   bool CLetra::repite_bolo_letra(int bolo){
  n=75;
  m=1;
  bool sw=false;
  for (int i = 0; i < n; i++) {
		 if (Letra[0][i]==bolo) {
			sw=true;
		 }
  }
  return sw;
  }

  void CLetra::guardar_letra(int num,int bolo){
  n=75;
  m=1;
	   for (int i = num-1 ; i > 0; i--) {
		   Letra[0][i]=Letra[0][i-1] ;


				}
				Letra[0][0]=bolo;

  }



  void CLetra::generarBlanco(){
	m=3,n=9;
	int j=0,c=0;
	for (int i = 0; i < m; i++) {
	c=0;
	  while(c<4){
		do{j=rand()%9;}
		 while(Letra[i][j]==' ');
		  Letra[i][j]=' ';

		c++;}
		}
	}





  void CLetra::generarH()
{  m=3, n=9;
 srand (time(NULL));
  int max=91, min=65;
  int valor_aletorio=0;
	for (int i = 0; i < m; i++) {
		 for (int j = 0; j < n; j++) {
		   do{
			do{ valor_aletorio=rand()% max;
			   }  while( min>valor_aletorio);
				} while(repiteLetraH(valor_aletorio));
			   Letra[i][j]=valor_aletorio;
		 }
	 }
  }

	bool CLetra::repiteLetraH(int letra){
  m=3, n=9;
  int sw=false;
  for (int i = 0; i < m; i++) {
	  for (int j = 0; j < n; j++) {
		if (Letra[j][i]==letra) {
			  sw=true;
		}
	  }
  }
  return sw;
  }


   void CLetra::guardarLetraH(int num,int bolo){
  n=90;
  m=1;
	   for (int i = num-1 ; i > 0; i--) {
		   Letra[0][i]=Letra[0][i-1] ;


				}
				Letra[0][0]=bolo;

  }

  bool CLetra::repite_bolo_letraH(int bolo){
  n=90;
  m=1;
  bool sw=false;
  for (int i = 0; i < n; i++) {
		 if (Letra[0][i]==bolo) {
			sw=true;
		 }
  }
  return sw;
  }
   void CLetra::cambiarDatoH(int dato){
  m=3;
  n=9;
  bool sw=false;
   for (int i = 0; i < n; i++) {
	   for (int j = 0; j < m; j++ && sw==false) {
				 if (Letra[j][i]==dato) {
				   Letra[j][i]='-';
				   sw=true;	 }
		   }

	   }
	 }


	  bool CLetra::bingoHorizontalH(){
   m=3;
  n=9;
  bool sw=false;
  float s=0;
   for (int i = 0; i < m; i++ && sw==false) {
   s=0;
	   for (int j = 0; j < n; j++ ) {
			   if (Letra[i][j]=='-'){
			   s--;}
	   }

	   if (s==-5) {
	   sw=true;
	   }

   }
   return sw;
   }


 bool CLetra::bingoVerticalH(){
	 m=3;
  n=9;
  bool sw=false;
  float s=0;
   for (int i = 0; i < n; i++ && sw==false) {
   s=0;
	   for (int j = 0; j < m; j++ ) {
		  if (Letra[j][i]=='-'){
		  s--;}
	   }

	   if (s==-3) {
	   sw=true;
	   }

   }
   return sw;
   }
