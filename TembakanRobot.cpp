// NAMA		: Fairuuz Azmi Firas
// NRP		: 5025221057
// Jurusan	: Teknik Informatika

#include <iostream>
#include <cmath>
using namespace std;

#define GRAVITASI 10 //10 m/s^2
#define START_PENGUKURAN 1 //pengukuran dimulai dari 1 meter
#define SUDUT 45 //sudut elevasi tembakan
#define PI 3.14159265

int mencari_V0(int vTangen, int kurang){
	int vAwal = vTangen - kurang;
  	return vAwal;
}

int speed_dgn_loss(int speed){
	int loss;
	if(speed >= 1 && speed <= 10){
		loss = 1;
	} else if(speed >= 11 && speed <= 20){
		loss = 3;
	} else if(speed >= 21 && speed <= 30){
		loss = 5;
	}
	return loss;
}

int main() {

  	int kecepatan, vAwal, kurang;
	float vTangensial, jarak;
	cin >> kecepatan;

 	kurang =  speed_dgn_loss(kecepatan);
	vAwal = mencari_V0(kecepatan, kurang);
	jarak = pow(vAwal, 2) * sin(2*SUDUT*PI/180) / GRAVITASI - START_PENGUKURAN;
	jarak = round(jarak);
	vTangensial = sqrt(jarak * GRAVITASI) + kurang;

	cout << jarak << " " << vTangensial << endl;
    return 0;
}
