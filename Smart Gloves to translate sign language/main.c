#include <LiquidCrystal.h>

int Thumb;
int Index_Finger;
int Middle_Finger;
int Ring_Finger;
int Pinky_Finger;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(A4, INPUT);
    Serial.begin(9600);
    lcd.begin(16, 2);
}

void loop()
{

    int Thumb = analogRead(A0);
    int Index_Finger = analogRead(A1);
    int Middle_Finger = analogRead(A2);
    int Ring_Finger = analogRead(A3);
    int Pinky_Finger = analogRead(A4);

    Serial.print("Thumb = ");
    Serial.println(Thumb);
    Serial.print("\n");
    Serial.print("Index_Finger = ");
    Serial.println(Index_Finger);
    Serial.print("\n");
    Serial.print("Middle_Finger= ");
    Serial.println(Middle_Finger);
    Serial.print("\n");
    Serial.print("Ring_Finger = ");
    Serial.println(Ring_Finger);
    Serial.print("\n");
    Serial.print("Pinky_Finger = ");
    Serial.println(Pinky_Finger);
    Serial.print("\n");

    if(Thumb == 1017 )
    {
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print("4");
        delay(1000);
    }


    while(Thumb == 990 && Index_Finger ==990 &&  Middle_Finger ==990  && Ring_Finger == 990&& Pinky_Finger== 990 )
    {
        lcd.clear();
        lcd.print("Nothing");
        delay(1000);
        Thumb = analogRead(A0);
        Index_Finger = analogRead(A1);
        Middle_Finger = analogRead(A2);
        Ring_Finger = analogRead(A3);
        Pinky_Finger = analogRead(A4);

    }



    while(Thumb == 1017 && Index_Finger== 990 && Middle_Finger == 1017&& Ring_Finger == 1017&& Pinky_Finger == 1017 )
    {
        lcd.clear();

        lcd.setCursor(1,0);
        lcd.print("I Am");
        delay(1000);
        Thumb = analogRead(A0);
        Index_Finger = analogRead(A1);
        Middle_Finger = analogRead(A2);
        Ring_Finger = analogRead(A3);
        Pinky_Finger = analogRead(A4);

    }


    while(Thumb == 1017 && Index_Finger== 990 && Middle_Finger == 990&& Ring_Finger == 1017&& Pinky_Finger == 1017 )
    {
        lcd.clear();

        lcd.setCursor(1,0);
        lcd.print("VICTORY");
        delay(1000);
        Thumb = analogRead(A0);
        Index_Finger = analogRead(A1);
        Middle_Finger = analogRead(A2);
        Ring_Finger = analogRead(A3);
        Pinky_Finger = analogRead(A4);

    }

    while(Thumb == 1017 && Index_Finger ==1017 && Middle_Finger ==1017  && Ring_Finger == 1017&& Pinky_Finger== 1017 )
    {
        lcd.clear();

        lcd.setCursor(1,0);
        lcd.print("Yes");
        delay(1000);

        Thumb = analogRead(A0);
        Index_Finger = analogRead(A1);
        Middle_Finger = analogRead(A2);
        Ring_Finger = analogRead(A3);
        Pinky_Finger = analogRead(A4);

    }


    while(Thumb == 990 &&  Index_Finger ==990 &&  Middle_Finger ==1017  && Ring_Finger == 1017&& Pinky_Finger== 990 )
    {
        lcd.clear();

        lcd.setCursor(1,0);
        lcd.print("Love U");
        delay(1000);

        Thumb = analogRead(A0);
        Index_Finger = analogRead(A1);
        Middle_Finger = analogRead(A2);
        Ring_Finger = analogRead(A3);
        Pinky_Finger = analogRead(A4);

    }
    while(Thumb == 1017 && Index_Finger ==1017 &&  Middle_Finger ==1017  && Ring_Finger == 1017 && Pinky_Finger== 990 )
    {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Promise");
        delay(1000);

    }






}

    while(thumb == 990 && index_finger ==990 &&  middle_finger ==1017  && ring_finger == 1017&& little_finger== 990 )
    {
        lcd.clear();

        lcd.setCursor(1,0);
        lcd.print("ROCK!!!");
        delay(1000);

        thumb = analogRead(A0);
        index_finger = analogRead(A1);
        middle_finger = analogRead(A2);
        ring_finger = analogRead(A3);
        little_finger = analogRead(A4);

    }


    while(thumb == 990 && index_finger ==990 &&  middle_finger ==990  && ring_finger == 990&& little_finger== 990 )
    {
        lcd.clear();

        //lcd.setCursor(1,0);
        //lcd.print("ROCK");
        //delay(1000);

        thumb = analogRead(A0);
        index_finger = analogRead(A1);
        middle_finger = analogRead(A2);
        ring_finger = analogRead(A3);
        little_finger = analogRead(A4);

    }






}