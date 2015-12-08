#ifndef CASAINTELIGENTE_H_INCLUDED
#define CASAINTELIGENTE_H_INCLUDED

//_____habitacion_____
class habitacion
{
  protected:
    float  area;
    int numLuzS, numTomasS, numVentanasS, numPuertasS, numGasS; ///se asume que las ventanas abren, por lo tanto involucran 2 sensores
    string tipo, estado; ///tipo: sala, comedor, cuarto, oficina, estudio, armario, transicion
    sensorLuminico *arrSLuminico;
    sensorCorto *arrSCorto;
    sensorRoturaCristal *arrSRotCristal;
    sensorMagnetico *arrSMagnetico;
    sensorGasyHumo *sGas; ///puede ser un arreglo o no
    sensorTemperatura *sTemp; ///este no es un arreglo
    sensorPresencia *sPres; ///este no es un arreglo

  public:
    bool siSTemp, siSPresen, activo;
    habitacion(string="creado");
    ~habitacion(void);
    void Setup(float, int, int, int, int, int=1, string="habitacion", bool=false, bool=false); ///valArea, numSLuz, numSToma, numVentanas, numPuertas, numSGas, tipo, siSTemp, siSPres
    float getArea(void);
    int getNumLuzS(void);
    int getNumTomasS(void);
    int getNumVentanasS(void);
    int getNumPuertasS(void);
    int getNumGasS(void);
    const string getTipo(void);
    const string getEstado(void);
    sensorLuminico &getArrSLum(int);
    sensorCorto &getArrSCorto(int);
    sensorRoturaCristal &getArrSRot(int);
    sensorMagnetico &getArrSMag(int);
    sensorGasyHumo &getArrSGas(int=0);
    sensorTemperatura &getSTemp(int=0);
    sensorPresencia &getSPres(int=0);
};

class taller : public habitacion
{
  protected:
    int numTomasMotor;
    sensorCorto *arrSCortoMotor;

  public:
    taller(string="creado");
    ~taller(void);
    void setup(float, int, int, int, int, bool, int); ///area, sLuz, sToma, sVentana, sPuertas, siPres, sTomasMotor
    int getNumTomasMotor(void);
    sensorCorto &getArrSMotor(int);
};

class cocina : public habitacion
{
  protected:
    int numTomasCocina;
    sensorCorto *arrSCortoCocina;

  public:
    cocina(string="creado");
    ~cocina(void);
    void setup(float, int, int, int, int, bool, int); ///area, sLuz, sToma, sVentana, sPuertas, siPres, sTomasCocina
    int getNumTomasCocina(void);
    sensorCorto &getArrSCocina(int);
};
//_______________________________________________________________________________
//_______________________________________________________________________________

//_____casa_____
class casa
{
    protected:
        int numHabitaciones, numTalleres, numCocinas;
        habitacion *arrHabitaciones;
        taller *arrTalleres;
        cocina *arrCocinas;

    public:
        casa(int, int, int); ///numHabitaciones, numTalleres, numCocinas
        ~casa(void);
        int getNumHabitaciones(void);
        int getNumTalleres(void);
        int getNumCocinas(void);
        habitacion &getArrHabitaciones(int);
        taller &getArrTalleres(int);
        cocina &getArrCocinas(int);
};

#endif // CASA_H_INCLUDED
