#include <string.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

using namespace std;
#include "Sensores.h"
#include "CasaInteligente.h"

#define AREACUARTO  9
#define SENSORESLUZ 1
#define SENSORESLUZ2 2
#define SENSORESTOMAS 2
#define SENSORESVENTANAS 1
#define SENSORESVENTANAS2 2
#define SENSORESPUERTAS 1
#define SENSORGAS 1

#define AREATALLER 18
#define SENSORESTOMAS3 3
#define SENSORESTOMASMOTOR 2

#define AREACOCINA 12
#define SENSORESPUERTASCOCINA 2
#define SENSORESTOMASCOCINA 1

#define NUMHABITACIONES 2
#define NUMTALLERES 1
#define NUMCOCINAS 1

int main(void)
{
  ///Crear Objeto CasaInteligente
  casa CasaInteligente(NUMHABITACIONES, NUMTALLERES, NUMCOCINAS);

  ///Extraer cada habitacion y configurarla con Setup
  habitacion &cuarto1 = CasaInteligente.getArrHabitaciones(0);
  habitacion &cuarto2 = CasaInteligente.getArrHabitaciones(1);
  taller &taller1 = CasaInteligente.getArrTalleres(0);
  cocina &cocina1 = CasaInteligente.getArrCocinas(0);

  cuarto1.Setup(AREACUARTO, SENSORESLUZ, SENSORESTOMAS, SENSORESVENTANAS, SENSORESPUERTAS, SENSORGAS,"cuarto", false, false);
  cuarto2.Setup(AREACUARTO, SENSORESLUZ, SENSORESTOMAS, SENSORESVENTANAS2, SENSORESPUERTAS,SENSORGAS, "cuarto", false, false);

  taller1.setup(AREATALLER, SENSORESLUZ2, SENSORESTOMAS3, SENSORESVENTANAS2, SENSORESPUERTAS, true, SENSORESTOMASMOTOR);
  cocina1.setup(AREACOCINA, SENSORESLUZ, SENSORESTOMAS, 0, SENSORESPUERTASCOCINA, false, SENSORESTOMASCOCINA);


  ///Configurar cada sensor

  //Luminico
  for (int i=0;i<SENSORESLUZ;i++) //uno solo para ambos cuartos y la cocina porque tienen misma cantidad
  {
    sensorLuminico &SenSLumCuarto1 = cuarto1.getArrSLum(i);
    sensorLuminico &SenSLumCuarto2 = cuarto2.getArrSLum(i);
    sensorLuminico &SenSLumCocina = cocina1.getArrSLum(i);
    SenSLumCuarto1.setup();
    SenSLumCuarto2.setup();
    SenSLumCocina.setup();
  }
  for (int i=0;i<SENSORESLUZ2;i++) //uno solo para ambos cuartos y la cocina porque tienen misma cantidad
  {
    sensorLuminico &SenSLumTaller = taller1.getArrSLum(i);
    SenSLumTaller.setup();
  }

  //Tomas
  for (int i=0;i<SENSORESTOMAS;i++) //uno solo para ambos cuartos y la cocina porque tienen misma cantidad
  {
    sensorCorto &SenSCortoCuarto1 = cuarto1.getArrSCorto(i);
    sensorCorto &SenSCortoCuarto2 = cuarto2.getArrSCorto(i);
    sensorCorto &SenSCortoCocina = cocina1.getArrSCorto(i);
    SenSCortoCuarto1.setup();
    SenSCortoCuarto2.setup();
    SenSCortoCocina.setup();
  }
  for (int i=0;i<SENSORESTOMAS3;i++)
  {
    sensorCorto &SenSCortoTaller = taller1.getArrSCorto(i);
    SenSCortoTaller.setup();
  }

  //Ventanas
  for (int i=0;i<SENSORESVENTANAS;i++)
  {
    sensorRoturaCristal &SenSRotCuarto1 = cuarto1.getArrSRot(i);
    SenSRotCuarto1.setup();
  }
  for (int i=0;i<SENSORESVENTANAS2;i++)
  {
    sensorRoturaCristal &SenSRotCuarto2 = cuarto2.getArrSRot(i);
    sensorRoturaCristal &SenSRotTaller = taller1.getArrSRot(i);
    SenSRotCuarto2.setup();
    SenSRotTaller.setup();
  }

  //Puertas
  for (int i=0;i<SENSORESPUERTAS;i++)
  {
    sensorMagnetico &SenSCuarto1 = cuarto1.getArrSMag(i);
    sensorMagnetico &SenSCuarto2 = cuarto2.getArrSMag(i);
    sensorMagnetico &SenSTaller = taller1.getArrSMag(i);
    SenSCuarto1.setup();
    SenSCuarto2.setup();
    SenSTaller.setup();
  }
  for (int i=0;i<SENSORESPUERTASCOCINA;i++)
  {
    sensorMagnetico &SenSCocina = cocina1.getArrSMag(i);
    SenSCocina.setup();
  }

  //Gas
  {
    sensorGasyHumo &SenSCuarto1 = cuarto1.getArrSGas();
    sensorGasyHumo &SenSCuarto2 = cuarto2.getArrSGas();
    SenSCuarto1.setup();
    SenSCuarto2.setup();
  }

  for (int i=0;i<taller1.getNumGasS();i++)
  {
    sensorGasyHumo &SenSTaller = taller1.getArrSGas(i);
    SenSTaller.setup();
  }

  for (int i=0;i<cocina1.getNumGasS();i++)
  {
    sensorGasyHumo &SenSCocina = cocina1.getArrSGas(i);
    SenSCocina.setup();
  }

  //Presencia
  if(taller1.siSPresen==true)
  {
    sensorPresencia &SenSTaller = taller1.getSPres();
    SenSTaller.setup();
  }

  //Tomas Cocina
  for (int i=0;i<SENSORESTOMASCOCINA;i++)
  {
    sensorCorto &SenSCocina = cocina1.getArrSCocina(i);
    SenSCocina.setup();
  }

  //Tomas Motor
  for (int i=0;i<SENSORESTOMASMOTOR;i++)
  {
    sensorCorto &SenSTaller = taller1.getArrSMotor(i);
    SenSTaller.setup();
  }


  float salidaVal = 1;
  string estadoVal = "activado";
  sensorCorto &SCorto1Cuarto1 = cuarto1.getArrSCorto(0);
  SCorto1Cuarto1.setSalida(&salidaVal);
  SCorto1Cuarto1.setEstado(&estadoVal);
  while (true)
  {
    if(SCorto1Cuarto1.getEstado() == "activado")
        cout << "Tomacorriente 1 se encuentra activo" << endl;
    sleep(1);
  }
  return 0;
}
