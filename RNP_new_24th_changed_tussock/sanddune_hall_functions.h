
/////////HALL functions for only up//////////////////
void L1_V_MovUP_hall()
{
  if(hall_count1v==1)
  {
    analogWrite(L1Vpwm,0);
    flag1vu=1;
  }
  else if(hall_count1v==0)
  {
    digitalWrite(L1Vdir,1);
    analogWrite(L1Vpwm,L1V_up_constrain);
  }
  else
  {
      Serial.println("M");
     analogWrite(L1Vpwm,0); 
  }
}

void L2_V_MovUP_hall()
{
  if(hall_count2v==1)
  {
    analogWrite(L2Vpwm,0);
    flag2vu=1;
  }
  else if(hall_count2v==0)
  {
    digitalWrite(L2Vdir,0);
    analogWrite(L2Vpwm,L2V_up_constrain);
  }
  else
  {
    analogWrite(L2Vpwm,0);
    Serial.println("M");
  }
}

void L3_V_MovUP_hall()
{
  if(hall_count3v==1)
  {
    analogWrite(L3Vpwm,0);
    flag3vu=1;
  }
  else if(hall_count3v==0)
  {
    digitalWrite(L3Vdir,1);
    analogWrite(L3Vpwm,L3V_up_constrain);
  }
  else
  {
     analogWrite(L3Vpwm,0);
     Serial.println("M");
  }
}


void L4_V_MovUP_hall()
{

  if(hall_count4v==1)
  {
    analogWrite(L4Vpwm,0);
    flag4vu=1;
  }
  else if(hall_count4v==0)
  {
    digitalWrite(L4Vdir,0);
    analogWrite(L4Vpwm,L4V_up_constrain);
  }
  else
  {
   Serial.println("M");
   analogWrite(L4Vpwm,0);
  }
}

/////////HALL functions for only down//////////////////
void L1_V_MovD_hallD()
{

  if(flag1vd==1)
  {
    if(digitalRead(LS_L1f)==0 || digitalRead(LS_L1b)==0)
    analogWrite(L1Vpwm,0);
  }
  else
  {
    digitalWrite(L1Vdir,0);
    analogWrite(L1Vpwm,L1V_down_constrain);
  }
}

void L2_V_MovD_hall()
{
  if(flag2vd==1)
  {
    if(digitalRead(LS_L2f)==0 || digitalRead(LS_L2b)==0)
    analogWrite(L2Vpwm,0);
  }
  else
  {
    digitalWrite(L2Vdir,1);
    analogWrite(L2Vpwm,L2V_down_constrain);
  }
}

void L3_V_MovD_hallD()
{
  if(flag3vd==1)
  {
     if(digitalRead(LS_L3f)==0 || digitalRead(LS_L3b)==0)
    analogWrite(L3Vpwm,0);
  }
  else
  {
    digitalWrite(L3Vdir,0);
    analogWrite(L3Vpwm,L3V_down_constrain);
  }
}


void L4_V_MovD_hallD()
{
  if(flag4vd==1)
  {
   if(digitalRead(LS_L4f)==0 || digitalRead(LS_L4b)==0)
    analogWrite(L4Vpwm,0);
  }
  else
  {
    digitalWrite(L4Vdir,1);
    analogWrite(L4Vpwm,L4V_down_constrain);
  }
}
