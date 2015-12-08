#include <string.h>
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <stdio.h>

using namespace std;
#include "Sensores.h"
#include "CasaInteligente.h"


///_____habitacion_____
///+++++++++++++++++++++
habitacion::habitacion(string str) :estado(str)
{
  activo = false;
}

habitacion::~habitacion(void)
{
  delete [] arrSLuminico;
  delete [] arrSCorto;
  delete [] arrSRotCristal;
  delete [] arrSMagnetico;
  delete [] sGas;
  delete [] sPres;
  delete [] sTemp;
}

void habitacion::Setup(float valArea, int luz, int toma, int vent, int puert, int gas, string sttipo, bool temp, bool pres)
{
  area = valArea;
  numLuzS = luz;
  numTomasS = toma;
  numVentanasS = vent;
  numPuertasS = puert;
  numGasS = gas;
  tipo = sttipo;
  siSTemp = temp;
  siSPresen = pres;
  estado = "inicializado";
  activo = true;

  arrSLuminico = new sensorLuminico [numLuzS];
  arrSCorto = new sensorCorto[numTomasS];
  arrSRotCristal = new sensorRoturaCristal [numVentanasS];
  arrSMagnetico = new sensorMagnetico [numPuertasS];
  sGas = new sensorGasyHumo [numGasS];
  sPres = new sensorPresencia [1];
  sTemp = new sensorTemperatura [1];
}

//gets
float habitacion::getArea(void)
{
  if (activo) return area;
  return 0;
}

int habitacion::getNumLuzS(void)
{
  if (activo) return numLuzS;
  return 0;
}

int habitacion::getNumTomasS(void)
{
  if (activo) return numTomasS;
  return 0;
}

int habitacion::getNumVentanasS(void)
{
  if (activo) return numVentanasS;
  return 0;
}

int habitacion::getNumPuertasS(void)
{
  if (activo) return numPuertasS;
  return 0;
}

int habitacion::getNumGasS(void)
{
  if (activo) return numGasS;
  return 0;
}

const string habitacion::getTipo(void)
{
  return tipo;
}

const string habitacion::getEstado(void)
{
  return estado;
}

sensorLuminico &habitacion::getArrSLum(int num)
{
  return arrSLuminico[num];
}

sensorCorto &habitacion::getArrSCorto(int num)
{
  return arrSCorto[num];
}

sensorRoturaCristal &habitacion::getArrSRot(int num)
{
  return arrSRotCristal[num];
}

sensorMagnetico &habitacion::getArrSMag(int num)
{
  return arrSMagnetico[num];
}

sensorGasyHumo &habitacion::getArrSGas(int num)
{
  return sGas[num];
}

sensorTemperatura &habitacion::getSTemp(int num)
{
  return *sTemp;
}

sensorPresencia &habitacion::getSPres(int num)
{
  return *sPres;
}

///: taller_
///++++++++++
taller::taller(string str) :habitacion(str)
{}

taller::~taller(void)
{
  delete [] arrSCortoMotor;
}

void taller::setup(float valArea, int luz, int toma, int vent, int puert, bool pres, int tomMot)
{
    string sttipo ="taller";
    bool temp = true;

    int numSGasyHumo;
    if(valArea <= 9) numSGasyHumo = 1;
    else numSGasyHumo = (valArea/9);

    Setup(valArea,luz,toma,vent,puert,numSGasyHumo,sttipo,temp,pres);

    numTomasMotor = tomMot;

    arrSCortoMotor = new sensorCorto [numTomasMotor];
}

int taller::getNumTomasMotor(void)
{
    return numTomasMotor;
}

sensorCorto &taller::getArrSMotor(int num)
{
    return arrSCortoMotor[num];
}


/// cocina
///+++++++++
cocina::cocina(string str) :habitacion(str)
{}

cocina::~cocina(void)
{
  delete [] arrSCortoCocina;
}

void cocina::setup(float valArea, int luz, int toma, int vent, int puert, bool pres, int tomCoc)
{
    string sttipo ="cocina";
    bool temp = true;

    int numSGasyHumo;
    if(valArea <= 9) numSGasyHumo = 1;
    else numSGasyHumo = (valArea/9);

    Setup(valArea,luz,toma,vent,puert,numSGasyHumo,sttipo,temp,pres);

    numTomasCocina = tomCoc;

    arrSCortoCocina = new sensorCorto [numTomasCocina];
}

int cocina::getNumTomasCocina(void)
{
    return numTomasCocina;
}

sensorCorto &cocina::getArrSCocina(int num)
{
    return arrSCortoCocina[num];
}

/// casa
///+++++++
casa::casa(int hab, int tall, int coc) : numHabitaciones(hab), numTalleres(tall), numCocinas(coc)
{
  arrHabitaciones = new habitacion [numHabitaciones];
  arrTalleres = new taller [numTalleres];
  arrCocinas = new cocina [numCocinas];
}

casa::~casa(void)
{
  delete [] arrHabitaciones;
  delete [] arrTalleres;
  delete [] arrCocinas;
}

int casa::getNumHabitaciones(void)
{
  return numHabitaciones;
}

int casa::getNumTalleres(void)
{
  return numTalleres;
}

int casa::getNumCocinas(void)
{
  return numCocinas;
}

habitacion &casa::getArrHabitaciones(int num)
{
  return arrHabitaciones[num];
}

taller &casa::getArrTalleres(int num)
{
  return arrTalleres[num];
}

cocina &casa::getArrCocinas(int num)
{
  return arrCocinas[num];
}


