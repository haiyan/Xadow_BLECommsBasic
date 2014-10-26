/*-----------------------------------------------------------------------------------
** demo xadow accelermeter
** Haiyan Zhang 2014-10-26
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or (at your option) any later version.
**
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
**
** You should have received a copy of the GNU Lesser General Public
** License along with this library; if not, write to the Free Software
** Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
**--------------------------------------------------------------------------------*/

#include <Wire.h>
#include <SeeedOLED.h>


#define SerialBaud   9600
#define Serial1Baud  9600
int row = 1;
int col = 0;

void setup()
{
  Wire.begin();
  SeeedOled.init();  //initialze SEEED OLED display
  DDRB|=0x21;        //digital pin 8, LED glow indicates Film properly Connected .
  PORTB |= 0x21;
  SeeedOled.clearDisplay();          //clear the screen and set start position to top left corner
  SeeedOled.setNormalDisplay();      //Set display to normal mode (i.e non-inverse mode)
  SeeedOled.setPageMode();           //Set addressing mode to Page Mode
  SeeedOled.setTextXY(0,0);          //Set the cursor to Xth Page, Yth Column  
  SeeedOled.putString("Hello World!"); //Print the String
  SeeedOled.setTextXY(1,0);          //Set the cursor to Xth Page, Yth Column  

  Serial1.begin(Serial1Baud);
  Serial1.print("AT+ROLE0");
  
}

void loop()
{
  // if msg has been received via BLE
  if (Serial1.available())
  {
    // if we've reached the bottom of the OLED screen, clear it and start from the top
    if (row > 7) {
      SeeedOled.clearDisplay();
      row = 0;
    }
    char c = Serial1.read();
    SeeedOled.putChar(c); //Print the String
    if (c == '\n') {
      row++;
      SeeedOled.setTextXY(row,0);          //Set the cursor to Xth Page, Yth Column
      Serial1.print("Hello this is Xadow");                   
    }
  }
}

