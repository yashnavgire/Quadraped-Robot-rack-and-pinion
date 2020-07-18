  void ISR_4V()
{
//  analogWrite(L4Vpwm,0);
 if(flag4_up==1)
 {
   flag4vu=1;
   hall_count4v++;
 }
 else if(flag4_down==1)
 {
  hall_count4v--;
   flag4vd=1;
 }
}

void ISR_3V()
{
//  analogWrite(L4Vpwm,0);
if(flag3_up==1)
{ 
  flag3vu=1;
   hall_count3v++;
 }
 else if(flag3_down==1)
 {
  hall_count3v--;
  flag3vd=1;
 }
}

void ISR_2V()
{
 if(flag2_up==1)
 {
  flag2vu=1;
  hall_count2v++;
 }
 else if(flag2_down==1)
 {
  hall_count2v--;
  flag2vd=1;
 }  
}

void ISR_1V()
{
 if(flag1_up==1)
 { 
  flag1vu=1;
  hall_count1v++;
 }
 else if(flag1_down==1)
 {
  hall_count1v--;
  flag1vd=1;
 }
}

void L1_V_MovUP_hallD()
{
  if(flag1vu==1)
  {
    analogWrite(L1Vpwm,0);
  }
  else
  {
    digitalWrite(L1Vdir,1);
    analogWrite(L1Vpwm,L1V_up_constrain);
  }
}

void L2_V_MovUP_hallD()
{
  if(flag2vu==1)
  {
    analogWrite(L2Vpwm,0);
  }
  else
  {
    Serial.println("2v");
    digitalWrite(L2Vdir,0);
    analogWrite(L2Vpwm,L2V_up_constrain);
  }
}

void L3_V_MovUP_hallD()
{

  if(flag3vu==1)
  {
    analogWrite(L3Vpwm,0);
  }
  else
  {
    digitalWrite(L3Vdir,1);
    analogWrite(L3Vpwm,L3V_up_constrain);
  }
}


void L4_V_MovUP_hallD()
{

  if(flag4vu==1)
  {
    analogWrite(L4Vpwm,0);
  }
  else
  {
    digitalWrite(L4Vdir,0);
    analogWrite(L4Vpwm,L4V_up_constrain);
  }
}

/////////HALL functions for only down//////////////////
void L1_V_MovD_hallD()
{

  if(flag1vd==1)
  {
    if(digitalRead(LS_L1)==0)
    analogWrite(L1Vpwm,0);
  }
  else
  {
    digitalWrite(L1Vdir,0);
    analogWrite(L1Vpwm,L1V_down_constrain);
  }
}

void L2_V_MovD_hallD()
{
  if(flag2vd==1)
  {
    if(digitalRead(LS_L2)==0)
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
     if( digitalRead(LS_L3)==0)
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
   if( digitalRead(LS_L4)==0)
    analogWrite(L4Vpwm,0);
  }
  else
  {
    digitalWrite(L4Vdir,1);
    analogWrite(L4Vpwm,L4V_down_constrain);
  }
}

////////////////////sanddune down from diagonal down/////////////////////
void L1_V_MovDSD()
{
// hall_count1v=1;   //to be set only once before calling this function  
  if(hall_count1v==0)
  {
    flag1vd=1;
//    Serial.println("S");
    analogWrite(L1Vpwm,0);
  }
  else if(hall_count1v==1)
  {
//    Serial.println("A");
    digitalWrite(L1Vdir,0);
    analogWrite(L1Vpwm,L1V_down_constrain);
  }
  else
  {
      analogWrite(L1Vpwm,0);
  }
}

void L2_V_MovDSD()
{
// hall_count2v=1;   //to be set only once before calling this function  
  if(hall_count2v==0)
  {
    flag2vd=1;
    analogWrite(L2Vpwm,0);
  }
  else if(hall_count2v==1)
  {
    digitalWrite(L2Vdir,1);
    analogWrite(L2Vpwm,L2V_down_constrain);
  }
  else
  {
      analogWrite(L2Vpwm,0);
  }
}

void L3_V_MovDSD()
{
// hall_count1v=1;   //to be set only once before calling this function  
  if(hall_count3v==0)
  {
    flag3vd=1;
    analogWrite(L3Vpwm,0);
  }
  else if(hall_count3v==1)
  {
    digitalWrite(L3Vdir,0);
    analogWrite(L3Vpwm,L3V_down_constrain);
  }
  else
  {
      analogWrite(L3Vpwm,0);
  }
}

void L4_V_MovDSD()
{
// hall_count1v=1;   //to be set only once before calling this function  
  if(hall_count4v==0)
  {
    flag4vd=1;
    analogWrite(L4Vpwm,0);
  }
  else if(hall_count4v==1)
  {
    digitalWrite(L4Vdir,1);
    analogWrite(L4Vpwm,L4V_down_constrain);
  }
  else
  {
      analogWrite(L4Vpwm,0);
  }
}


///////////////sanddune up and down///////////////////

/////////sanddune up functions//////////
void L1_V_MovSU()
{
// hall_count1v=2;   //to be set only once before calling this function  
  if(hall_count1v==2)
  {
    flag1vu=1;
    analogWrite(L1Vpwm,0);
  }
  else if(hall_count1v==0)
  {
//    Serial.println("          in =0 ");
    digitalWrite(L1Vdir,1);
    analogWrite(L1Vpwm,L1V_up_constrain);
  }
  else if(hall_count1v==1)
  {
//    Serial.println("in =1");
    digitalWrite(L1Vdir,1);
    analogWrite(L1Vpwm,2*L1V_up_constrain/3);
  }
  
  else
  {
      analogWrite(L1Vpwm,0);
      Serial.println("M");
  }
}

void L2_V_MovSU()
{
// hall_count2v=2;   //to be set only once before calling this function  
    if(hall_count2v==2)
  {
//    Serial.println("11");
    flag2vu=1;
    analogWrite(L2Vpwm,0);
  }
  else if(hall_count2v==0)
  {
//    Serial.println("22");
    digitalWrite(L2Vdir,0);
    analogWrite(L2Vpwm,L2V_up_constrain);
  }
  else if(hall_count2v==1)
  {
//    Serial.println("33");
    digitalWrite(L2Vdir,0);
    analogWrite(L2Vpwm,2*L2V_up_constrain/3);
  }
  else
  {
      Serial.println("M");
      analogWrite(L2Vpwm,0);
  }
}

void L3_V_MovSU()
{
// hall_count1v=2;   //to be set only once before calling this function  
  if(hall_count3v==2)
  {
    flag3vu=1;
    analogWrite(L3Vpwm,0);
  }
  else if(hall_count3v==0)
  {
    digitalWrite(L3Vdir,1);
    analogWrite(L3Vpwm,L3V_up_constrain);
  }
  else if(hall_count3v==1)
  {
    digitalWrite(L3Vdir,1);
    analogWrite(L3Vpwm,2*L3V_up_constrain/3);
  }
  else
  {
      Serial.println("M");
      analogWrite(L3Vpwm,0);
  }
}

void L4_V_MovSU()
{
// hall_count2v=2;   //to be set only once before calling this function  
    if(hall_count4v==2)
  {
    flag4vu=1;
    analogWrite(L4Vpwm,0);
  }
  else if(hall_count4v==0)
  {
    digitalWrite(L4Vdir,0);
    analogWrite(L4Vpwm,L4V_up_constrain);
  }
  else if(hall_count4v==1)
  {
    digitalWrite(L4Vdir,0);
    analogWrite(L4Vpwm,2*L4V_up_constrain/3);
  }
  else
  {
    Serial.println("M");
    analogWrite(L4Vpwm,0);
  }
}

////////////sanddune down functions/////////////
void L1_V_MovSD()
{
// hall_count1v=2;   //to be set only once before calling this function  
  if(hall_count1v==0 || digitalRead(LS_L1)==0)
  {
    delay(200);
    if(hall_count1v==2)
    {
     hall_count1v=1;  
    flag1vd=1;
    analogWrite(L1Vpwm,0);
    }
    else if(hall_count1v==1 && sanddune_counter<=2)
    {
     flag1vd=1;
     analogWrite(L1Vpwm,0);       
    }
    else if(hall_count1v==0)
    {
     flag1vd=1;
     analogWrite(L1Vpwm,0);    
    }
  }
  else if(hall_count1v==2)
  {
    digitalWrite(L1Vdir,0);
    analogWrite(L1Vpwm,L1V_down_constrain);
  }
  else if(hall_count1v==1)
  {
    digitalWrite(L1Vdir,0);
    analogWrite(L1Vpwm,2*L1V_down_constrain/3);
  }
  else
  {
      analogWrite(L1Vpwm,0);
  }
}

void L2_V_MovSD()
{
// hall_count2v=2;   //to be set only once before calling this function  
  if(hall_count2v==0 || digitalRead(LS_L2)==0)
  {
    delay(100);
    if(hall_count2v==2)
    {
     hall_count2v=1;  
    flag2vd=1;
    analogWrite(L2Vpwm,0);
    }
    else if(hall_count2v==1 && sanddune_counter>=2)
    {
     flag2vd=1;
     analogWrite(L2Vpwm,0);    
    }
    else if(hall_count2v==0)
    {
     flag2vd=1;
     analogWrite(L2Vpwm,0);    
    }
  }
  else if(hall_count2v==2)
  {
    digitalWrite(L2Vdir,1);
    analogWrite(L2Vpwm,L2V_down_constrain);
  }
  else if(hall_count2v==1)
  {
    digitalWrite(L2Vdir,1);
    analogWrite(L2Vpwm,2*L2V_down_constrain/3);
  }
  else
  {
      analogWrite(L2Vpwm,0);
  }
}

void L3_V_MovSD()
{
// hall_count1v=2;   //to be set only once before calling this function  
  if(hall_count3v==0 || digitalRead(LS_L3)==0 )
  {
    delay(100);
    if(hall_count3v==2)
    {
     hall_count3v=1;  
    flag3vd=1;
    analogWrite(L3Vpwm,0);
    }
    else if(hall_count3v==1 && sanddune_counter>=2)
    {
     flag3vd=1;
     analogWrite(L3Vpwm,0);
    }
    else if(hall_count3v==0)
    {
     flag3vd=1;
     analogWrite(L3Vpwm,0);    
    }
  }
  else if(hall_count3v==2)
  {
    digitalWrite(L3Vdir,0);
    analogWrite(L3Vpwm,L3V_down_constrain);
  }
  else if(hall_count3v==1)
  {
    digitalWrite(L3Vdir,0);
    analogWrite(L3Vpwm,2*L3V_down_constrain/3);
  }
  else
  {
      analogWrite(L3Vpwm,0);
  }
}

void L4_V_MovSD()
{
// hall_count2v=2;   //to be set only once before calling this function  
  if(hall_count4v==0 ||  digitalRead(LS_L4)==0)
  {
    delay(200);
    if(hall_count4v==2)
    {
     hall_count4v=1;  
     flag4vd=1;
     analogWrite(L4Vpwm,0);
    }
    else if(hall_count4v==1 && sanddune_counter<=2)
    {
     flag4vd=1;
     analogWrite(L4Vpwm,0);
    }
    else if(hall_count4v==0)
    {
     flag4vd=1;
     analogWrite(L4Vpwm,0);    
    }
  }
  else if(hall_count4v==2)
  {
    digitalWrite(L4Vdir,1);
    analogWrite(L4Vpwm,L4V_down_constrain);
  }
  else if(hall_count4v==1)
  {
    digitalWrite(L4Vdir,1);
    analogWrite(L4Vpwm,2*L4V_down_constrain/3);
  }
  else
  {
    Serial.println("M");
      analogWrite(L4Vpwm,0);
  }
}
