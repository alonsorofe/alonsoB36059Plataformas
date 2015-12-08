#ifndef SENSORES_H_INCLUDED
#define SENSORE_H_INCLUDED

//_____sensor_____
class sensor
{
  protected:
    float  minSalida, maxSalida, optSalida, salida;
    string estado, tipo, tipoSalida; ///tipoSalida: rango, digital, analogico. tipo: temperatura, gas y humo...
    bool  activo;
    void Setup(float=0, float=1, float=0, float=0, bool=true); ///minimo, maximo, optimo, valor, activo

  public:
    sensor(string="creado");
    ~sensor(void);
    void setEstado(const string*);
    void setSalida(const float*);
    const string getEstado(void);
    const string getTipo(void);
    const string getTipoSalida(void);
    int getMinSalida(void);
    int getMaxSalida(void);
    int getOptSalida(void);
    int getSalida(void);
};

class sensorTemperatura : public sensor
{
  protected:
    string altura; ///altura: bajo, medio, alto

  public:
    sensorTemperatura(string="creado");
    ~sensorTemperatura(void);
    void setup(float=0, float=1, float=0, float=0, bool=true, string="temperatura", string="rango", string="medio"); ///minimo, maximo, optimo, valor, activo, tipo, tipoSalida, altura
    const string getAltura(void);
};

class sensorGasyHumo : public sensor
{
  protected:
    string altura;

  public:
    sensorGasyHumo(string="creado");
    ~sensorGasyHumo(void);
    void setup(float=0, float=1, float=0, float=0, bool=true, string="gas y humo", string="digital", string="alto");
    const string getAltura(void);
};

class sensorPresencia : public sensor
{
  protected:
    string altura;

  public:
    sensorPresencia(string="creado");
    ~sensorPresencia(void);
    void setup(float=0, float=1, float=0, float=0, bool=true, string="presencia", string="digital", string="alto");
    const string getAltura(void);
};

class sensorMagnetico : public sensor ///sensor de puerta o ventana abierta
{
  public:
    sensorMagnetico(string="creado");
    ~sensorMagnetico(void);
    void setup(float=0, float=1, float=0, float=0, bool=true, string="magnetico", string="digital"); ///minimo, maximo, optimo, valor, activo, tipo, tipoSalida
};

class sensorLuminico : public sensor
{
  public:
    sensorLuminico(string="creado");
    ~sensorLuminico(void);
    void setup(float=0, float=1, float=0, float=0, bool=true, string="luminico", string="digital");
};

class sensorRoturaCristal : public sensor
{
  public:
    sensorRoturaCristal(string="creado");
    ~sensorRoturaCristal(void);
    void setup(float=0, float=1, float=0, float=0, bool=true, string="rotura de cristal", string="digital");
};

class sensorCorto : public sensor
{
  public:
    sensorCorto(string="creado");
    ~sensorCorto(void);
    void setup(float=0, float=1, float=0, float=0, bool=true, string="corto circuito", string="digital");
};
//____________________________________________________________________________________________
//____________________________________________________________________________________________


#endif // CASAINTELIGENTE_H_INCLUDED
