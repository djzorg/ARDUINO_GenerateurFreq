volatile int isr1 = 0;

 ISR(TIMER1_COMPA_vect)
 {
 // Fonction appele chaque fois que timer−compare galise ICR1 ou OCR1A
 isr1++;
 }
int inPin = 7;
int outPin = 2;
int OUTOrangePin = 4;
int OUTRougePin = 5;
 void setup()
 {
 pinMode (outPin,OUTPUT);
  pinMode (OUTOrangePin,OUTPUT);
  pinMode (OUTRougePin,OUTPUT);
 pinMode(inPin,INPUT);
 pinMode(inPin,INPUT);
 TCCR1A = 0b10100000;
 TCCR1B =0B00001010;//prescaler 8;
 TCCR1C = 0;
 TIMSK1 |= 1 << OCIE1A;// bit 4 : Met en place le Timer−Output−CompareAatch Interrupt
 OCR1A=20;//valeur de comparaison.
 Serial.begin(115200);
 }

 void loop()
 {
    if(digitalRead(inPin))
    {//60Hz
        if (isr1 >= 792 )//ISR() galise 2 fois par priode
        {
        if (digitalRead(outPin)==HIGH) 
            digitalWrite(outPin,LOW);
        else if (digitalRead(outPin) == LOW) 
            digitalWrite(outPin,HIGH);
        isr1=0;
        digitalWrite(OUTRougePin,LOW);
        digitalWrite(OUTOrangePin,HIGH);
        }
    }
 else 
    {
    if(isr1 >= 950 )
    {
        if (digitalRead(outPin)==HIGH) 
            digitalWrite(outPin,LOW);
        else if (digitalRead(outPin) == LOW) 
            digitalWrite(outPin,HIGH);
        isr1=0;
        digitalWrite(OUTRougePin,HIGH);
        digitalWrite(OUTOrangePin,LOW);
    }
 }

}
