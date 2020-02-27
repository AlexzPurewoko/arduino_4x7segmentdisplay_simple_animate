 /**
  * Copyright @2020 by Alexzander Purwoko Widiantoro <purwoko908@gmail.com>
  * Permission is hereby granted, free of charge, to any person obtaining a copy
  * of this software and associated documentation files (the "Software"), to deal
  * in the Software without restriction, including without limitation the rights
  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  * copies of the Software, and to permit persons to whom the Software is
  * furnished to do so, subject to the following conditions:

  * The above copyright notice and this permission notice shall be included in all
  * copies or substantial portions of the Software.

  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  * SOFTWARE.
  */

  /*
   * To use this scripts, you must understand the layout board of 4x 7segment display
   * That is used in this script.
   * 
   * 
   */
const int pin_a = 12;
const int pin_b = 8;
const int pin_c = 4;
const int pin_d = 6;
const int pin_e = 7;
const int pin_f = 11;
const int pin_g = 3;
const int pin_d1 = 13;
const int pin_d2 = 10;
const int pin_d3 = 9;
const int pin_d4 = 2;
const int pin_dp = 5;

int definedPins[] = {
  pin_a, pin_b, pin_c, pin_d, pin_e, pin_f, pin_g, pin_dp
};

// Defined constants for POSITION
/**
 *      - (a   , b   , c  , d   , e  ,  f , g   , dp}
 */
int h[] = {HIGH, HIGH, LOW, HIGH, LOW, LOW, LOW, HIGH};
int E[] = {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, HIGH};
int L[] = {HIGH, HIGH, HIGH, LOW, LOW, LOW, HIGH, HIGH};
int O[] = {LOW, LOW, LOW, LOW, LOW, LOW, HIGH, HIGH};
int A[] = {LOW, LOW, LOW, HIGH, LOW, LOW, LOW, HIGH};
int X[] = {HIGH, LOW, LOW, HIGH, LOW, LOW, LOW, HIGH};

// numbers
int *num_0 = O;
int num_1[] = {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH, HIGH};
int num_2[] = {LOW, LOW, HIGH, LOW, LOW, HIGH, LOW, HIGH};
int num_3[] = {LOW, LOW, LOW, LOW, HIGH, HIGH, LOW, HIGH};
int num_4[] = {HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH};
int num_5[] = {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, HIGH};
int num_6[] = {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, HIGH};
int num_7[] = {LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH, HIGH};
int num_8[] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH};
int num_9[] = {LOW, LOW, LOW, LOW, HIGH, LOW, LOW, HIGH};


void setupRunning4x(){
  
  pinMode(pin_a, OUTPUT);
  pinMode(pin_b, OUTPUT);
  pinMode(pin_c, OUTPUT);
  pinMode(pin_d, OUTPUT);
  pinMode(pin_e, OUTPUT);
  pinMode(pin_f, OUTPUT);
  pinMode(pin_g, OUTPUT);

  
  pinMode(pin_d1, OUTPUT);
  pinMode(pin_d2, OUTPUT);
  pinMode(pin_d3, OUTPUT);
  pinMode(pin_d4, OUTPUT);

  
  pinMode(pin_dp, OUTPUT);
}


void clearDisp() {
  digitalWrite(pin_d1, LOW);
  digitalWrite(pin_d2, LOW);
  digitalWrite(pin_d3, LOW);
  digitalWrite(pin_d4, LOW);
}
void clearLEDS() {
  digitalWrite(pin_a, HIGH);
  digitalWrite(pin_b, HIGH);
  digitalWrite(pin_c, HIGH);
  digitalWrite(pin_d, HIGH);
  digitalWrite(pin_e, HIGH);
  digitalWrite(pin_f, HIGH);
  digitalWrite(pin_g, HIGH);
  digitalWrite(pin_dp, HIGH);
}
void pickDisp(int p) {
  if(p < 1 && p > 4) return;
  int a[] = {pin_d1, pin_d2, pin_d3, pin_d4};
  for(int x = 0; x < 4; x++) {
    digitalWrite(a[x], LOW);
  }
  digitalWrite(a[p-1], HIGH);
}
void disp(int *pinArr, bool hasDotted) {
  int sizeArr = sizeof(definedPins) / sizeof(int);
  for(int x = 0; x < sizeArr; x++){
    digitalWrite(definedPins[x], pinArr[x]);
  }
  if(hasDotted) digitalWrite(definedPins[sizeArr - 1], HIGH);
}
void show(int numDisp, int *chars, bool hasDotted = false) {
  clearLEDS();
  pickDisp(numDisp);
  disp(chars, hasDotted);
  //delay(1);
}

void animationWords4(int **displayWords){
  int sizePins = sizeof(definedPins) / sizeof(int);
  int sizeWords = sizeof(displayWords) / (sizePins * sizeof(int));
  if(sizeWords > 4) return;
  int delayBetweenWords = 1000;
  delay (1500);

  // slide left 
  for(int x = 0; x < sizeWords; x++) {
    clearDisp();
    clearLEDS();
    for(int de = 0; de < delayBetweenWords; de++){
      int steps = x+1;
      for(int y = steps; y > 0 ; y--){
        show(sizeWords - y + 1, displayWords[steps - y]);
      }
      delayMicroseconds(de);
    }
  }

  // lets we force display the words (all)
  clearDisp();
  clearLEDS();
  delay(delayBetweenWords/2);
  for(int de = 0; de < delayBetweenWords; de++) {
    for(int x = 0; x < sizeWords; x++) {
      show(x + 1, displayWords[x]);
    }
    delayMicroseconds(de);
  }

  // fade out for slide left (decrease the number [gone])
  
  for(int x = sizeWords; x >= 0; x--) {
    clearDisp();
    clearLEDS();
      int steps = x+1;
      int startsDisplay = x;
    for(int de = 0; de < delayBetweenWords; de++){
      int startsElement = sizeWords - x;
      for(int y = 1; y <= startsDisplay && startsElement != sizeWords; y++){
        show(y, displayWords[startsElement++]);
      }
      delayMicroseconds(de);
    }
  }
}
