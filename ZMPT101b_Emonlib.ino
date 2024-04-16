#include "EmonLib.h"
EnergyMonitor emon1;    // Crea una instancia de Energy Monitor
#define VOLT_CAL 350    // Valor de calibración del sensor
#define PHASE_SHIFT 1.7 // Defasaje
#define ZMPTpin A0      // Sensor de Tensión GPIO

//******************************************** SETUP ********************************************************************
void setup() {
 
 Serial.begin(115200);
 emon1.voltage(ZMPTpin, VOLT_CAL, PHASE_SHIFT); //Configuración de función 'voltage' (Pin de lectura, Calibración, Defasaje)
}
//******************************************** LOOP ********************************************************************
void loop() {

 emon1.calcVI(20,2000); //Función de cálculo (20 semiciclos, tiempo de espera para tomar medición) 
 
 int tension = emon1.Vrms; //Valor V RMS obtenido

 Serial.print(tension);
 Serial.println("V RMS");
}