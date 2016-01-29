#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
unsigned long long int funcionfactorial(int x);
double euler(int x);
double distancia(int x1,int y1, int x2,int y2);
double semiperimetros(double l1,double l2, double l3 );


int main (int argc, char*argv[]){
	int resp;
	cout<<"Elija"<<endl
	    <<"1 para factorial"<<endl
	    <<"2 para coordenadas"<<endl
	    <<"Cualquier tecla para salir"<<endl;
	cin>>resp;
	if(resp==1){
		int num;
		double eulertotal;
		unsigned long long int totalfactorial;
		cout<<"ingrese el numero a realizarle el factorial:";
		cin>>num;
		eulertotal=euler(num);
		 
		cout<<"total euler "<< eulertotal<<endl;
	
	}else if(resp==2){
		bool proceda=false;
		int x1,x2,x3,x4,y1,y2,y3,y4;	
		double d_ad,d_dc,d_cb,d_ba,d_diagonaldb,semiperimetro1,semiperimetro2,h1t1,h2t1,h3t1,h1t2,h2t2,h3t2;
		cout<<"Ingrese la coordenada 1 ";
		cin>>x1;
		cin>>y1;

		cout<<"Ingrese la coordenada 2 ";
		cin>>x2;
		cin>>y2;

		cout<<"Ingrese la coordenada 3 ";
		cin>>x3;
		cin>>y3;

		cout<<"Ingrese la coordenada 4 ";
		cin>>x4;
		cin>>y4;

		if((x1==x2 && x2==x3 && x3==x4) || (y1==y2 && y2==y3 && y3==y4) ){
			cout<<"se forma una linea no puede hacer nada"<<endl;	
			proceda==false;	
		}else{
			proceda==true;
		}

		if((x1==x2 && y1==y2)||(x2==x3 && y2==y3)||(x3==x4 && y3==y4)){
			cout<<"algun punto de los ingresados son iguales"<<endl;
			proceda=false;
		}else{
			proceda=true;
		}
		
		if(proceda==true){
			d_ad=distancia(x3,y3,x1,y1);
			d_dc=distancia(x1,y1,x2,y2);
			d_cb=distancia(x2,y2,x4,y4);
			d_ba=distancia(x4,y4,x3,y3);
			d_diagonaldb=distancia(x3,y3,x1,y1);
		
			cout<<"los lados del trapezoide son"<<endl
			    <<"lado 1"<<d_ad<<endl
			    <<"lado 2"<<d_dc<<endl
			    <<"lado 3"<<d_cb<<endl
			    <<"lado 4"<<d_ba<<endl
			    <<"diagonal "<<d_diagonaldb<<endl;

			cout<<"los lados del triangulo 1 son"<<endl
			    <<"lado 1"<<d_ad<<endl
			    <<"lado 2"<<d_ba<<endl
			    <<"lado 3 (diagobnal)"<<d_diagonaldb<<endl;
			
			cout<<"los lados del triangulo 2 son"<<endl
			    <<"lado 1"<<d_dc<<endl
			    <<"lado 2"<<d_cb<<endl
			    <<"lado 3 (diagobnal)"<<d_diagonaldb<<endl;
			

			semiperimetro2=(d_dc+d_cb+d_diagonaldb);
			semiperimetro1=(d_ba+d_ad+d_diagonaldb);
			cout<<"el semiperimetro del triangulo 1 es :"<<semiperimetro1/2<<endl;
			cout<<"el semiperimetro del triangulo 2 es :"<<semiperimetro2/2<<endl;
			cout<<"el perimetro del triangulo 1 es :"<<semiperimetro1<<endl;
			cout<<"el perimetro del triangulo 2 es :"<<semiperimetro2<<endl;
			
			//h1t1=altura_A(semiperimetro1,d_ba,d_ad,d_diagonaldb);
		}

		
		
		
	}

	return 0;
}
 

unsigned long long int funcionfactorial(int x){
	int multiplicacion=1;
	if((x==1) || (x==0)){
		return 1;
	}else{
		for(int i=1; i<x;i++){
		 multiplicacion=multiplicacion+multiplicacion*i;
		 cout<<multiplicacion<<endl;
		}
		return multiplicacion;
	}


}

double euler(int num){
	double acumulador=0;
	for(int i=0;i<=14;i++){
		acumulador +=pow(num,i)/funcionfactorial(i);
	}
	return acumulador;

}

double distancia(int x1,int y1, int x2,int y2){
	double r1,r2,dis;
	r1=pow((x2-x1),2.0);
	r2-=pow((y2-y1),2.0);
	dis=sqrt(r1-r2);
	return dis;
 }
double semiperimetros(double l1,double l2, double l3 ){
	return l1+l2+l3;

}

/*double altura_A(double s,double a,double b, double c){
	
}*/

				
