class Bolo
{ private:

	public:

		int numeroBolo();     //para Los cartones numeros
		char letraBoloBingo(int num);
		char letraBolo();
		int numeroBoloH();
}  ;

  int numeroBolo(){
  srand (time(NULL));
  int numero=0;
  do{ numero=rand()% 76;}
  while (numero<=0) ;
  return numero;
  }

   int numeroBoloH(){
  srand (time(NULL));
  int numero=0;
  do{ numero=rand()% 91;}
  while (numero<=0) ;
  return numero;
  }

  char letraBoloBingo(int num){
	char letra=' ';
			if (num<15) {
			letra='B';}
	  else { if (num<=30) {
			  letra='I';}
	  else { if (num<=45) {
			  letra='N';}
	  else { if (num<=60) {
			   letra='G';}
	  else { if (num<=75) {
			 letra='O';}

	  }
	  }

	  }

	  }
	  return letra;
  }


  char letraBolo(){
	srand (time(NULL));
  int numero=0;
  do{ numero=rand()% 91;}
  while (numero<65);
  return numero;
  }

  AnsiString Bingo(){
   int c=0;
   AnsiString letra=' ';
   char B='B',I='I',N='N',G='G',O='O';
   while (c<5){
	 letra=B+AnsiString(I+N+G+O);

   }
	 return letra;
  }
