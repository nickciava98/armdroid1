//abilitazione buffer tristare
const byte enableBuffer = 22; //attivo basso

//motore Base 011, Spalla 101, Braccio 001, Polso1 110, Polso2 010, Mano 100
const byte selMotoreC4 = 25;
const byte selMotoreC3 = 24;
const byte selMotoreC2 = 23;

//avanti 1100 - 1001 - 0011 - 0110 rispettivamente faseC8faseC6faseC5faseC4
const byte faseC8 = 29;
const byte faseC7 = 28;
const byte faseC6 = 27;
const byte faseC5 = 26;
const byte enableMotori = 5;
const byte swMotoreBase = 6;   //          interrutore motore base su pulsantiera
const byte swMotoreSpalla = 2;  //10;
const byte swMotoreBraccio = 3;  //11;
const byte swMotorePolso1 = 4;   //12;
const byte swMotorePolso2 = 7;  //A2
const byte swMotoreMano = 8;    //A3
const byte pbAvanti = 10;       //A5     pulsante Avanti su pulsantiera
const byte pbIndietro = 9;     //A4     pulsante indietro su pulsantiera
byte velocita;
byte velocitaIniziale = 5;
byte delta = 10;

void setup()
{
  pinMode(selMotoreC4, OUTPUT);
  pinMode(selMotoreC3, OUTPUT);
  pinMode(selMotoreC2, OUTPUT);
  pinMode(faseC8, OUTPUT);
  pinMode(faseC7, OUTPUT);
  pinMode(faseC6, OUTPUT);
  pinMode(faseC5, OUTPUT);
  pinMode(enableMotori, INPUT);
  pinMode(swMotoreBase, INPUT);
  pinMode(swMotoreSpalla, INPUT);
  pinMode(swMotoreBraccio, INPUT);
  pinMode(swMotorePolso1, INPUT);
  pinMode(swMotorePolso2, INPUT);
  pinMode(swMotoreMano, INPUT);
  pinMode(pbAvanti, INPUT);
  pinMode(pbIndietro, INPUT);
  pinMode(enableBuffer, OUTPUT);

  digitalWrite(enableBuffer, HIGH); //disabilita buffer (in tristate)

  Serial.begin(9600);

  delay(3000);

  velocita = velocitaIniziale;
}

void loop()
{
  if(digitalRead(enableMotori) == HIGH && digitalRead(enableMotori) != LOW)
  {
    char val = Serial.read();

    if(val == '0')
    {
      raspberryAuto();
    }

    else if(val == '1')
    {
      motoreBaseOn();

      digitalWrite(swMotoreBase, HIGH);

      val = Serial.read();

      while(val != '3')
      {
        motoreAvanti(45, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);

        val = Serial.read();
      }

      digitalWrite(swMotoreBase, LOW);
    }

    else if(val == '2')
    {
      motoreBaseOn();

      digitalWrite(swMotoreBase, HIGH);

      val = Serial.read();

      while(val != '3')
      {
        motoreIndietro(45, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);

        val = Serial.read();
      }

      digitalWrite(swMotoreBase, LOW);
    }

    else if(val == '4')
    {
      motoreSpallaOn();

      digitalWrite(swMotoreSpalla, HIGH);

      val = Serial.read();
      
      while(val != '3')
      {
        motoreAvanti(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);

        val = Serial.read();
      }

      digitalWrite(swMotoreSpalla, LOW);
    }

    else if(val == '5')
    {
      motoreSpallaOn();

      digitalWrite(swMotoreSpalla, HIGH);

      val = Serial.read();

      while(val != '3')
      {
        motoreIndietro(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);

        val = Serial.read();
      }

      digitalWrite(swMotoreSpalla, LOW);
    }

    else if(val == '6')
    {
      motoreBraccioOn();

      digitalWrite(swMotoreBraccio, HIGH);

      val = Serial.read();

      while(val != '3')
      {
        motoreAvanti(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);

        val = Serial.read();
      }

      digitalWrite(swMotoreBraccio, LOW);
    }

    else if(val == '7')
    {
      motoreBraccioOn();

      digitalWrite(swMotoreBraccio, HIGH);

      val = Serial.read();

      while(val != '3')
      {
        motoreIndietro(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);

        val = Serial.read();
      }

      digitalWrite(swMotoreBraccio, LOW);
    }

    else if(val == '8')
    {
      motorePolso1On();

      digitalWrite(swMotorePolso1, HIGH);

      val = Serial.read();

      while(val != '3')
      {
        motoreAvanti(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);

        val = Serial.read();
      }

      digitalWrite(swMotorePolso1, LOW);
    }

    else if(val == '9')
    {
      motorePolso1On();

      digitalWrite(swMotorePolso1, HIGH);

      val = Serial.read();

      while(val != '3')
      {
        motoreIndietro(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);

        val = Serial.read();
      }

      digitalWrite(swMotorePolso1, LOW);
    }

    else if(val == 'a')
    {
      motorePolso2On();

      digitalWrite(swMotorePolso2, HIGH);

      val = Serial.read();

      while(val != '3')
      {
        motoreAvanti(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);

        val = Serial.read();
      }

      digitalWrite(swMotorePolso2, LOW);
    }

    else if(val == 'b')
    {
      motorePolso2On();

      digitalWrite(swMotorePolso2, HIGH);

      val = Serial.read();

      while(val != '3')
      {
        motoreIndietro(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);

        val = Serial.read();
      }

      digitalWrite(swMotorePolso2, LOW);
    }

    else if(val == 'c')
    {
      motoreManoOn();

      digitalWrite(swMotoreMano, HIGH);
      
      val = Serial.read();

      while(val != '3')
      {
        motoreAvanti(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);

        val = Serial.read();
      }

      digitalWrite(swMotoreMano, LOW);
    }

    else if(val == 'd')
    {
      motoreManoOn();

      digitalWrite(swMotoreMano, HIGH);

      val = Serial.read();
      
      while(val != '3')
      {
        motoreIndietro(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);

        val = Serial.read();
      }

      digitalWrite(swMotoreMano, LOW);
    }
  }

  else if(selezionaMotore(swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano))
  {
    /*if(velocita > 10)
      {
      velocita = velocita - delta;
      }

      else
      {
      velocita = 40;
      }*/

    if(digitalRead(pbAvanti) == HIGH && digitalRead(pbIndietro) == LOW)
    {
      motoreAvanti(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);
    }

    if(digitalRead(pbAvanti) == LOW && digitalRead(pbIndietro) == HIGH)
    {
      motoreIndietro(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);
    }
  }

  if(!selezionaMotore || (digitalRead(pbAvanti) == LOW && digitalRead(pbIndietro) == LOW))
  {
    velocita = velocitaIniziale;
  }
}

void raspberryAuto()
{
  if(baseAuto())
  {
    if(spallaAuto())
    {
      if(braccioAuto())
      {
        if(polso1Auto())
        {
          if(polso2Auto())
          {
            if(manoAuto())
            {
              return;
            }         
          }

          else
          {
            return;
          }
        }

        else
        {
          manoAuto();
        }
      }

      else
      {
        return;
      }
    }

    else
    {
      return;
    }
  }

  else
  {
    return;
  }
}

bool baseAuto()
{
  motoreBaseOn();

  int c = 0;
  char val = Serial.read();
  
  while(c < 50 && val != '3')
  {
    motoreAvanti(45, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);

    c++;

    val = Serial.read();

    if(val == '3')
    {
      return false;
    }
  }

  c = 0;
  val = Serial.read();

  while(c < 90 && val != '3')
  {
    motoreIndietro(45, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);

    c++;

    val = Serial.read();

    if(val == '3')
    {
      return false;
    }
  }

  c = 0;
  val = Serial.read();
  
  while(c < 45 && val != '3')
  {
    motoreAvanti(45, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);

    c++;

    val = Serial.read();

    if(val == '3')
    {
      return false;
    }
  }

  return true;
}

bool spallaAuto()
{
  motoreSpallaOn();

  int c = 0;
  char val = Serial.read();
  
  while(c < 50 && val != '3')
  {
    motoreAvanti(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);

    c++;

    val = Serial.read();

    if(val == '3')
    {
      return false;
    }
  }

  c = 0;
  val = Serial.read();

  while(c < 90 && val != '3')
  {
    motoreIndietro(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);
  
    c++;

    val = Serial.read();

    if(val == '3')
    {
      return false;
    }
  }

  c = 0;
  val = Serial.read();

  while(c < 40 && val != '3')
  {
    motoreAvanti(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);
  
    c++;

    val = Serial.read();

    if(val == '3')
    {
      return false;
    }
  }

  return true;
}

bool braccioAuto()
{
  motoreBraccioOn();

  int c = 0;
  char val = Serial.read();

  while(c < 50 && val != '3')
  {
    motoreAvanti(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);
  
    c++;

    val = Serial.read();

    if(val == '3')
    {
      return false;
    }
  }

  c = 0;
  val = Serial.read();

  while(c < 90 && val != '3')
  {
    motoreIndietro(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);
  
    c++;

    val = Serial.read();

    if(val == '3')
    {
      return false;
    }
  }

  while(c < 40 && val != '3')
  {
    motoreAvanti(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);
  
    c++;

    val = Serial.read();

    if(val == '3')
    {
      return false;
    }
  }

  return true;
}

bool polso1Auto()
{
  motorePolso1On();

  int c = 0;
  char val = Serial.read();

  while(c < 40 && val != '3')
  {
    motoreAvanti(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);
  
    c++;

    val = Serial.read();

    if(val == '3')
    {
      return false;
    }
  }

  c = 0;
  val = Serial.read();

  while(c < 80 && val != '3')
  {
    motoreIndietro(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);
  
    c++;

    val = Serial.read();

    if(val == '3')
    {
      return false;
    }
  }

  c = 0;
  val = Serial.read();

  while(c < 30 && val != '3')
  {
    motoreAvanti(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);
  
    c++;

    val = Serial.read();

    if(val == '3')
    {
      return false;
    }
  }

  return true;
}

bool polso2Auto()
{
  motorePolso2On();

  int c = 0;
  char val = Serial.read();

  while(c < 40 && val != '3')
  {
    motoreAvanti(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);
  
    c++;

    val = Serial.read();

    if(val == '3')
    {
      return false;
    }
  }

  c = 0;
  val = Serial.read();

  while(c < 80 && val != '3')
  {
    motoreIndietro(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);
  
    c++;

    val = Serial.read();

    if(val == '3')
    {
      return false;
    }
  }

  c = 0;
  val = Serial.read();

  while(c < 30 && val != '3')
  {
    motoreAvanti(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);
  
    c++;

    val = Serial.read();

    if(val == '3')
    {
      return false;
    }
  }

  return true;
}

bool manoAuto()
{
  motoreManoOn();

  int c = 0;
  char val = Serial.read();

  while(c < 20 && val != '3')
  {
    motoreAvanti(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);

    c++;
    
    val = Serial.read();

    if(val == '3')
    {
      return false;
    }
  }

  c = 0;
  val = Serial.read();

  while(c < 40 && val != '3')
  {
    motoreIndietro(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);

    c++;

    val = Serial.read();
    
    if(val == '3')
    {
      return false;
    }
  }

  c = 0;
  val = Serial.read();

  while(c < 20 && val != '3')
  {
    motoreAvanti(velocita, swMotoreBase, swMotoreSpalla, swMotoreBraccio, swMotorePolso1, swMotorePolso2, swMotoreMano);

    c++;

    val = Serial.read();

    if(val == '3')
    {
      return false;
    }
  }

  return true;
}

void motoreBaseOn()
{
  digitalWrite(selMotoreC4, LOW); digitalWrite(selMotoreC3, HIGH); digitalWrite(selMotoreC2, HIGH);
}

void motoreSpallaOn()
{
  digitalWrite(selMotoreC4, HIGH); digitalWrite(selMotoreC3, LOW); digitalWrite(selMotoreC2, HIGH);
}

void motoreBraccioOn()
{
  digitalWrite(selMotoreC4, LOW); digitalWrite(selMotoreC3, LOW); digitalWrite(selMotoreC2, HIGH);
}

void motorePolso1On()
{
  digitalWrite(selMotoreC4, LOW); digitalWrite(selMotoreC3, LOW); digitalWrite(selMotoreC2, LOW);
}

void motorePolso2On()
{
  digitalWrite(selMotoreC4, LOW); digitalWrite(selMotoreC3, HIGH); digitalWrite(selMotoreC2, LOW);
}

void motoreManoOn()
{
  digitalWrite(selMotoreC4, HIGH); digitalWrite(selMotoreC3, LOW); digitalWrite(selMotoreC2, LOW);
}

void motoriOff()
{
  digitalWrite(selMotoreC4, LOW); digitalWrite(selMotoreC3, LOW); digitalWrite(selMotoreC2, LOW);
}

void motoreAvanti(byte v, byte swBa, byte swS, byte swBr, byte swP1, byte swP2, byte swM)
{
  if((digitalRead(swBa) == HIGH) && (digitalRead(swS) == LOW) && (digitalRead(swBr) == LOW)
      && 
      (digitalRead(swP1) == LOW) && (digitalRead(swP2) == LOW) && (digitalRead(swM) == LOW))
  {
    v = 45;
  }

  //avanti 1100 - 1001 - 0011 - 0110 rispettivamente faseC8faseC6faseC5faseC4
  digitalWrite(faseC8, HIGH); digitalWrite(faseC7, HIGH); digitalWrite(faseC6, LOW); digitalWrite(faseC5, LOW);
  digitalWrite(enableBuffer, LOW);

  delay(10);

  digitalWrite(enableBuffer, HIGH);
  delay(v);
  digitalWrite(faseC8, HIGH); digitalWrite(faseC7, LOW); digitalWrite(faseC6, LOW); digitalWrite(faseC5, HIGH);
  digitalWrite(enableBuffer, LOW);

  delay(10);

  digitalWrite(enableBuffer, HIGH);
  delay(v);
  digitalWrite(faseC8, LOW); digitalWrite(faseC7, LOW); digitalWrite(faseC6, HIGH); digitalWrite(faseC5, HIGH);
  digitalWrite(enableBuffer, LOW);

  delay(10);

  digitalWrite(enableBuffer, HIGH);
  delay(v);
  digitalWrite(faseC8, LOW); digitalWrite(faseC7, HIGH); digitalWrite(faseC6, HIGH); digitalWrite(faseC5, LOW);
  digitalWrite(enableBuffer, LOW);

  delay(10);

  digitalWrite(enableBuffer, HIGH);
  delay(v);
}

void motoreIndietro(byte v, byte swBa, byte swS, byte swBr, byte swP1, byte swP2, byte swM)
{
  if((digitalRead(swBa) == HIGH) && (digitalRead(swS) == LOW) && (digitalRead(swBr) == LOW)
      && (digitalRead(swP1) == LOW) && (digitalRead(swP2) == LOW) && (digitalRead(swM) == LOW))
  {
    v = 45;
  }
  
  //avanti 1100 - 1001 - 0011 - 0110 rispettivamente faseC8faseC6faseC5faseC4
  //indietro 0110 - 0011 - 1001 - 1100 rispettivamente faseC8faseC6faseC5faseC4
  digitalWrite(faseC8, LOW); digitalWrite(faseC7, HIGH); digitalWrite(faseC6, HIGH); digitalWrite(faseC5, LOW);

  digitalWrite(enableBuffer, LOW);

  delay(10);

  digitalWrite(enableBuffer, HIGH);
  delay(v);
  digitalWrite(faseC8, LOW); digitalWrite(faseC7, LOW); digitalWrite(faseC6, HIGH); digitalWrite(faseC5, HIGH);
  digitalWrite(enableBuffer, LOW);

  delay(10);

  digitalWrite(enableBuffer, HIGH);
  delay(v);
  digitalWrite(faseC8, HIGH); digitalWrite(faseC7, LOW); digitalWrite(faseC6, LOW); digitalWrite(faseC5, HIGH);
  digitalWrite(enableBuffer, LOW);

  delay(10);

  digitalWrite(enableBuffer, HIGH);
  delay(v);
  digitalWrite(faseC8, HIGH); digitalWrite(faseC7, HIGH); digitalWrite(faseC6, LOW); digitalWrite(faseC5, LOW);
  digitalWrite(enableBuffer, LOW);

  delay(10);

  digitalWrite(enableBuffer, HIGH);
  delay(v);
}

bool selezionaMotore(byte swBa, byte swS, byte swBr, byte swP1, byte swP2, byte swM)
{
  if((digitalRead(swBa) == HIGH) && (digitalRead(swS) == LOW) && (digitalRead(swBr) == LOW)
      && (digitalRead(swP1) == LOW) && (digitalRead(swP2) == LOW) && (digitalRead(swM) == LOW))
  {
    //Serial.println("base");

    motoreBaseOn();

    return true;
  }

  else if((digitalRead(swBa) == LOW) && (digitalRead(swS) == HIGH) && (digitalRead(swBr) == LOW)
           && (digitalRead(swP1) == LOW) && (digitalRead(swP2) == LOW) && (digitalRead(swM) == LOW))
  {
    //Serial.println("spalla");

    motoreSpallaOn();

    return true;
  }

  else if((digitalRead(swBa) == LOW) && (digitalRead(swS) == LOW) && (digitalRead(swBr) == HIGH)
           && (digitalRead(swP1) == LOW) && (digitalRead(swP2) == LOW) && (digitalRead(swM) == LOW))
  {
    //Serial.println("braccio");

    motoreBraccioOn();

    return true;
  }

  else if((digitalRead(swBa) == LOW) && (digitalRead(swS) == LOW) && (digitalRead(swBr) == LOW)
           && (digitalRead(swP1) == HIGH) && (digitalRead(swP2) == LOW) && (digitalRead(swM) == LOW))
  {
    //Serial.println("polso1");

    motorePolso1On();

    return true;
  }

  else if((digitalRead(swBa) == LOW) && (digitalRead(swS) == LOW) && (digitalRead(swBr) == LOW)
           && (digitalRead(swP1) == LOW) && (digitalRead(swP2) == HIGH) && (digitalRead(swM) == LOW))
  {
    //Serial.println("polso2");

    motorePolso2On();

    return true;
  }

  else if((digitalRead(swBa) == LOW) && (digitalRead(swS) == LOW) && (digitalRead(swBr) == LOW)
           && (digitalRead(swP1) == LOW) && (digitalRead(swP2) == LOW) && (digitalRead(swM) == HIGH))
  {
    //Serial.println("mano");

    motoreManoOn();

    return true;
  }

  else
  {
    return false;
  }
}
