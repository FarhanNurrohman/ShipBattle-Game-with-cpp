#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <unistd.h>

using namespace std;

const int element = 10;
int matrix[element][element], maxKapal = 10;

void setGame(){
	for(int i = 0; i < element; i++){
		for(int j = 0; j < element; j++){
			matrix[i][j] = 0;
		}
	}
}

int hitungKapal(){
	int k = 0;
	for(int i = 0; i < element; i++){
		for(int j = 0; j < element; j++){
			if(matrix[i][j] == 1){
				k++;
			}
		}
	}
	return k;
}

int kapalHancur(){
	int k = 0;
	for(int i = 0; i < element; i++){
		for(int j = 0; j < element; j++){
			if(matrix[i][j] == 8){
				k++;
			}
		}
	}
	return k;
}

void setKapal(){
	int k = 0;
	while(k < maxKapal){
		int x=rand()%element;
		int y=rand()%element;
		
		if(matrix[x][y] != 1){
			matrix[x][y] = 1;
		}
		k++;
	}
	
}

void showKapal(){
	for(int i = 0; i < element; i++){
		for(int j = 0; j < element; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void serang(){
	int kx, ky;
	serang:
	cout << "Kapten scot : Kami butuh koorditan dimana kapal musuh berada, tolong segera berikan koorinatnya? " << endl <<"koordinat x: ";
	cin >> kx;
	cout << "koordinat y: ";
	cin >> ky;
	
	if(matrix[ky][kx] == 1){
		matrix[ky][kx] = 8;
		cout << "Kapten scot : Salah Satu kapal musuh berhasil dijatuhkan!" << endl;
		sleep(3);
	}else{
		cout << "Kapten scot : Tembakan tidak mengenai apa - apa dikarenakan koordinat kurang akurat!" << endl;
		sleep(3);
	}
	
}


bool surend(){
	surend:
	char isGiveup;
	cout << "Kapten scot : Apakah kamu masih sanggup menjadi operator kami?(Y/N)";
	cin >> isGiveup;
	if(isGiveup == 'y' || isGiveup == 'Y'){
		return false;
	}else if(isGiveup == 'n'||isGiveup == 'N'){
		return true;
	}else{
		cout << "Kapten scot : Jawablah dengan benar!!!" << endl;
		goto surend;
	}
}
int main(){
	
	cout << "Lo adalah operator untuk tentara angkatan laut Amerika." << endl;
	sleep(3);
	cout << "Disini lo ditugaskan memberikan koordinat dimana kapal musuh berada." << endl;
	sleep(3);
	cout << "Hiup dan mati tentara angkatan laut Amerika ada di tangan lo." << endl;
	sleep(3);
	int jk = hitungKapal();
	bool gameOver = false;
	setGame();
	setKapal();
	
	
	while(!gameOver){
		cout << "Kapten scot : Kapal musuh tersisa " <<  hitungKapal() << " buah!" << endl;
		serang();
		if(hitungKapal() != 0){
			gameOver = surend();
		}else{
			gameOver = true;
		}
		system("cls");
	}
	
	cout << "0 = Tidak Ada kapal" << endl;
	cout << "1 = Kapal" << endl;
	cout << "8 = kapal Hancur" << endl;
	sleep(3);
	cout << "===================" << endl;
	sleep(1.5);
	cout << "Peta : " << endl;
	sleep(1.5);
	showKapal();
	sleep(2.5);
	cout << endl;
	cout << "Kapten scot : " <<  kapalHancur() << " buah telah kita hancurkan!" << endl;
	
}
