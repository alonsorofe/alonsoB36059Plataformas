#include <string.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdio.h>

using namespace std;

#include "Sensores.h"

//_____sensor_____

//constructor y destructor
sensor::sensor(string str) : estado(str)
{
  activo = false;
}

sensor::~sensor(void)
{

}

void sensor::Setup(float minimo, float maximo, float optimo, float valor, bool act)
{
  minSalida = minimo;
  maxSalida = maximo;
  optSalida = optimo;
  salida = valor;
  activo = act;
  estado = "inicializado";
}

//sets
void sensor::setEstado(const string *defEstado)
{
  if (activo) estado = *defEstado;
}

void sensor::setSalida(const float *valor)
{
  if (activo) salida = *valor;
}

//gets
const string sensor::getEstado(void)
{
  return estado;
}

const string sensor::getTipo(void)
{
  if (activo) return tipo;
  return 0;
}

const string sensor::getTipoSalida(void)
{
  if (activo) return tipoSalida;
  return 0;
}

int sensor::getMinSalida(void)
{
  if (activo) return minSalida;
  return 0;
}

int sensor::getMaxSalida(void)
{
  if (activo) return maxSalida;
  return 0;
}

int sensor::getOptSalida(void)
{
  if (activo) return optSalida;
  return 0;
}

int sensor::getSalida(void)
{
  if (activo) return salida;
  return 0;
}
//______________________________________________________________________________________________________________

//sensores heredados: Temperatura
sensorTemperatura::sensorTemperatura(string str) : sensor(str)
{

}

sensorTemperatura::~sensorTemperatura(void)
{

}

void sensorTemperatura::setup(float minimo, float maximo, float optimo, float valor, bool act, string a, string b, string c)
{
    Setup(minimo,maximo,optimo,valor,act);
    tipo=a;
    tipoSalida=b;
    altura=c;
}

const string sensorTemperatura::getAltura(void)
{
    if (activo) return altura;
    return NULL;
}

//sensores heredados: GasyHumo
sensorGasyHumo::sensorGasyHumo(string str) : sensor("estado")
{

}

sensorGasyHumo::~sensorGasyHumo(void)
{

}

void sensorGasyHumo::setup(float minimo, float maximo, float optimo, float valor, bool act, string a, string b, string c)
{
    Setup(minimo,maximo,optimo,valor,act);
    tipo=a;
    tipoSalida=b;
    altura=c;
}

const string sensorGasyHumo::getAltura(void)
{
    if (activo) return altura;
    return NULL;
}

//sensores heredados: Presencia
sensorPresencia::sensorPresencia(string str) : sensor(str)
{}

sensorPresencia::~sensorPresencia(void)
{

}

void sensorPresencia::setup(float minimo, float maximo, float optimo, float valor, bool act, string a, string b, string c)
{
    Setup(minimo,maximo,optimo,valor,act);
    tipo=a;
    tipoSalida=b;
    altura=c;
}

const string sensorPresencia::getAltura(void)
{
    if (activo) return altura;
    return NULL;
}

//sensores heredados: Magnetico
sensorMagnetico::sensorMagnetico(string str) : sensor("creado")
{

}

sensorMagnetico::~sensorMagnetico(void)
{

}

void sensorMagnetico::setup(float minimo, float maximo, float optimo, float valor, bool act, string a, string b)
{
    Setup(minimo,maximo,optimo,valor,act);
    tipo=a;
    tipoSalida=b;
}

//sensores heredados: Luminico
sensorLuminico::sensorLuminico(string str) : sensor("creado")
{

}

sensorLuminico::~sensorLuminico(void)
{

}

void sensorLuminico::setup(float minimo, float maximo, float optimo, float valor, bool act, string a, string b)
{
    Setup(minimo,maximo,optimo,valor,act);
    tipo=a;
    tipoSalida=b;
}

//sensores heredados: RoturaCristal
sensorRoturaCristal::sensorRoturaCristal(string str) : sensor("creado")
{

}

sensorRoturaCristal::~sensorRoturaCristal(void)
{

}

void sensorRoturaCristal::setup(float minimo, float maximo, float optimo, float valor, bool act, string a, string b)
{
    Setup(minimo,maximo,optimo,valor,act);
    tipo=a;
    tipoSalida=b;
}

//sensores heredados: Corto
sensorCorto::sensorCorto(string str) : sensor("creado")
{

}

sensorCorto::~sensorCorto(void)
{

}

void sensorCorto::setup(float minimo, float maximo, float optimo, float valor, bool act, string a, string b)
{
    Setup(minimo,maximo,optimo,valor,act);
    tipo=a;
    tipoSalida=b;
}
//_____________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________

