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

#include "module_runningled.h"
int *displays[] = {
  num_1, num_2, num_3, num_4, num_5, num_6, num_7, num_8, num_9, num_0, //10
  empty, //1
  h, E, L, L, O, // 5 
  empty, // 1
  A, L, E, X, //4 
  empty, //1
  O, y, y, y, // 4
  empty, // 1
  n, y, O, b, A, // 5 
  empty, empty,
  s, E, k, A, r, A, n, g, //8
  empty, //1
  d, i, A, // 3
  empty, // 1
  L, A, g, i, // 4 
  empty,//1
  g, A, b, u, t, //5
  empty, //1
  strips, strips, // 2
  n, y, O, b, A, //5
  empty, //1
  s, A, j, A, //4
  strips, strips, empty
}; //3
void setup() {
  // put your setup code here, to run once:
  setupRunning4x();
}

void loop() {
  animateFromLeft4(displays, 71, 256);
}
