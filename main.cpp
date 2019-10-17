#include <bits/stdc++.h>


using namespace std;

int retornarValor(char letra){
	switch(letra){
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000; 
	}
}

void sumarExcepcion(char letra1, char letra2, int &suma){
	if(letra1 == 'I'){
		if(letra2 == 'V'){
			suma += 3;
			return;
		}
		if(letra2 == 'X'){
			suma += 8;
			return;
		}
	}
	if(letra1== 'X'){
		if(letra2 == 'L'){
			suma += 30;
			return;
		}
		if(letra2 == 'C'){
			suma += 80;
			return;
		}
	}
	if(letra1=='C'){
		if(letra2 == 'D'){
			suma += 300;
			return;
		}
		if(letra2 == 'M'){
			suma += 800;
			return;
		}
	}
}


void transformarLetra(string recibido){


	int suma = retornarValor(recibido[0]);

	char letraPrevia = recibido[0];

	for(int i=1;i<recibido.size();i++){
		char letraActual = recibido[i];
		letraPrevia = recibido[i-1];
		if(retornarValor(letraActual)>retornarValor(letraPrevia)){
			sumarExcepcion(letraPrevia,letraActual,suma);
		}
		else{
			suma += retornarValor(letraActual);
		}

	}

	std::cout<<suma<<std::endl;

}


void retornarNumero(int recibido, string &final){
	
	if(recibido>=1000){
		if(recibido == 1000){
			final+="M"; return;
		}
		if(recibido == 2000){
			final+="MM"; return;
		}
		if(recibido == 3000){
			final+="MMM"; return;
		}
	}
	if(recibido>=100){
		if(recibido == 100){
			final+="C"; return;
		}
		if(recibido == 200){
			final+="CC"; return;
		}
		if(recibido == 300){
			final+="CCC"; return;
		}
		if(recibido == 400){
			final+="CD"; return;
		}
		if(recibido == 500){
			final+="D"; return;
		}
		if(recibido == 600){
			final+="DC"; return;
		}
		if(recibido == 700){
			final+="DCC"; return;
		}
		if(recibido == 800){
			final+="DCCC"; return;
		}
		if(recibido == 900){
			final+="CM"; return;
		}
	}

	if(recibido>=10){
		if(recibido == 10){
			final+="X"; return;
		}
		if(recibido == 20){
			final+="XX"; return;
		}
		if(recibido == 30){
			final+="XXX"; return;
		}
		if(recibido == 40){
			final+="XL"; return;
		}
		if(recibido == 50){
			final+="L"; return;
		}
		if(recibido == 60){
			final+="LX"; return;
		}
		if(recibido == 70){
			final+="LXX"; return;
		}
		if(recibido == 80){
			final+="LXXX"; return;
		}
		if(recibido == 90){
			final+="XC"; return;
		}
	}


		if(recibido == 1){
			final+="I"; return;
		}
		if(recibido == 2){
			final+="II"; return;
		}
		if(recibido == 3){
			final+="III"; return;
		}
		if(recibido == 4){
			final+="IV"; return;
		}
		if(recibido == 5){
			final+="V"; return;
		}
		if(recibido == 6){
			final+="VI"; return;
		}
		if(recibido == 7){
			final+="VII"; return;
		}
		if(recibido == 8){
			final+="VIII"; return;
		}
		if(recibido == 9){
			final+="IX"; return;
		}


}


void transformarNumero(string recibido){

	vector<string> numeros;

	string final="";

	for(int i=0;i<recibido.size();i++){
		string temp(recibido.size()-i-1,'0');
		numeros.push_back(recibido[i]+temp);
	}



	for(auto x : numeros){
		//std::cout<<"-- "<<x<<" -- ";
		retornarNumero(stoi(x),final);
	}

	std::cout<<final<<endl;
	

}




int main(){

	string ingresar;

	while(cin>>ingresar){
		if(48<=ingresar[0] and ingresar[0]<=57){
			
			transformarNumero(ingresar);
		}
		else{
			transformarLetra(ingresar);
		}
	}


	return 0;
}