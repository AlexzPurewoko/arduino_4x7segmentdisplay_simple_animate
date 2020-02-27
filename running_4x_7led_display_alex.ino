

#include "module_runningled.h"
int *displayWords[] = {A, L, E, X};
void setup() {
  // put your setup code here, to run once:
  setupRunning4x();
}

void loop() {
  // put your main code here, to run repeatedly:
  animationWords4(displayWords);
}
