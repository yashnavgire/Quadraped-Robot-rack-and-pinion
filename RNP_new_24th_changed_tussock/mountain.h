  //For Mountain.
//States 500 to 505

void state499()
{

  
digitalWrite(mpu_mode,1);
  
   val1h = L1H_midf;
   val3h = L3H_midf;
   val2h = L2H_back;
   val4h = L4H_back;  

  val1v = L1V_downmid;
  val3v = L3V_downmid;
  val2v = L2V_downmid;
  val4v = L4V_downmid;

  L1_V_MovD(val1v);
  L3_V_MovD(val3v);
  L2_V_MovD(val2v);
  L4_V_MovD(val4v);

  L1_H_Mov2(val1h);
  L3_H_Mov2(val3h);
  L2_H_Mov2(val2h);
  L4_H_Mov2(val4h);

  if(flag1h == 1 && flag3h == 1 && flag2h == 1 && flag4h == 1 && flag2vd == 1 && flag4vd == 1 && flag1vd == 1 && flag3vd == 1)
  {
     l1h_pwm=0;
    l2h_pwm=0;
    l3h_pwm=0;
    l4h_pwm=0;
    L1H_sum = 0;
    L3H_sum = 0;
    L2H_sum = 0;
    L4H_sum = 0;
    flag1h = 0;
    flag3h = 0;
    flag2h = 0;
    flag4h = 0;
    analogWrite(L4Hpwm,0);
    analogWrite(L1Hpwm,0);
    analogWrite(L2Hpwm,0);
    analogWrite(L3Hpwm,0);
    L1H_initial=analogRead(L1Hpot);
    L2H_initial=analogRead(L2Hpot);
    L3H_initial=analogRead(L3Hpot);
    L4H_initial=analogRead(L4Hpot);

    analogWrite(L1Vpwm, 0);
    analogWrite(L3Vpwm, 0);    
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
    L2V_sum = 0;
    L4V_sum = 0;
    flag2vd = 0;
    flag4vd = 0;
    L1V_sum = 0;
    L3V_sum = 0;
    flag1vd = 0;
    flag3vd = 0;

    while(digitalRead(proxy_mountain)==1);                        //wait till proxy is detected
    delay(100);
    state=500;
    
  }


  
}

void state500()
{
  base1h=20;
  base2h=30;
  base3h=30;
  base4h=20;

  val2v = L2V_upmid;
  val4v = L4V_up_sand;

  if(slope_counter>=3)
  {
      val4v = L4V_downmid+40;
  }
  L2_V_MovUP(val2v);
  L4_V_MovUP(val4v);
  
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v);
//  digitalWrite(L4Vdir, 0);
//  analogWrite(L4Vpwm, stall_base4v);

//  Serial.println("31");
  if (flag2vu == 1 && flag4vu == 1)
  {
    L2V_sum = 0;
    L4V_sum = 0;
    flag2vu = 0;
    flag4vu = 0;
    flag2_up=0;
    flag4_up=0;
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);

    state = 501;
    
  }
}

void state501()
{
  val1h = L1H_back;
  val3h = L3H_back;
  val2h = L2H_front;
  val4h = L4H_front;

  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v);
//  digitalWrite(L4Vdir, 0);
//  analogWrite(L4Vpwm, stall_base4v);
  if(slope_counter>=3)
  {
  val1h = L1H_back;
  val3h = L3H_back;
  val2h = L2H_midf;
  val4h = L4H_midf;

  }

  L1_H_Mov2(val1h);
  L3_H_Mov2(val3h);
  L2_H_Mov2(val2h);
  L4_H_Mov2(val4h);

  if (flag1h == 1 && flag3h == 1 && flag2h == 1 && flag4h == 1)
  {
    l1h_pwm=0;
    l2h_pwm=0;
    l3h_pwm=0;
    l4h_pwm=0;
    L1H_sum = 0;
    L3H_sum = 0;
    L2H_sum = 0;
    L4H_sum = 0;
    flag1h = 0;
    flag3h = 0;
    flag2h = 0;
    flag4h = 0;
    analogWrite(L4Hpwm,0);
    analogWrite(L1Hpwm,0);
    analogWrite(L2Hpwm,0);
    analogWrite(L3Hpwm,0);
    L1H_initial=analogRead(L1Hpot);
    L2H_initial=analogRead(L2Hpot);
    L3H_initial=analogRead(L3Hpot);
    L4H_initial=analogRead(L4Hpot);
    state = 502;
    
  }
}

void state502()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v);
//  digitalWrite(L4Vdir, 0);
//  analogWrite(L4Vpwm, stall_base4v);

  val2v = L2V_downmid;
  val4v = L4V_downmid;

  L2_V_MovD(val2v);
  L4_V_MovD(val4v);
  
  if (flag2vd == 1 && flag4vd == 1)
  {
    
    analogWrite(L1Vpwm, 0);
    analogWrite(L3Vpwm, 0);    
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
    L2V_sum = 0;
    L4V_sum = 0;
    flag2vd = 0;
    flag4vd = 0;
    state = 503;
    slope_counter++;
    if(slope_counter>20)    //check for ukhai
    {
      if(digitalRead(mpu1)==1 && digitalRead(mpu2)==1) //i.e pitch reached to zero(+-5)
      {
        ukhai_counter++;            //required since immediately after pitch reaching the thresh chasis can't be taken up ,since back legs might be still on mountain
        if(ukhai_counter==1)      //4
        {
          state=510;
        }
          //chasis up and actuating ukhai driver    
       }
     }    
  }
}

void state503()
{
/*
  val2v = L2V_up - 80 ;
  val4v = L4V_up - 80 ;
 */
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);
//  digitalWrite(L1Vdir, 1);
//  analogWrite(L1Vpwm, stall_base1v);

  val1v = L1V_up_sand;
  val3v = L3V_upmid;

  
  if(slope_counter>=3)
  {
      val1v = L1V_downmid-40;
  }
  L1_V_MovUP(val1v);
  L3_V_MovUP(val3v);

  if (flag1vu == 1 && flag3vu == 1)
  {
    flag1_up=0;
    flag3_up=0;
    L1V_sum = 0;
    L3V_sum = 0;
    flag1vu = 0;
    flag3vu = 0;
    
    analogWrite(L1Vpwm,0);
    analogWrite(L3Vpwm,0);
    state = 504;
//    analogWrite(L4Vpwm ,0);
  }
}

void state504()
{

  val2h = L2H_back;
  val4h = L4H_back;
  val1h = L1H_front;
  val3h = L3H_front;

if(slope_counter>=3)
  {
   
   val1h = L1H_midf;
   val3h = L3H_midf;
   val2h = L2H_back;
   val4h = L4H_back;  
  }

  L1_H_Mov2(val1h);
  L3_H_Mov2(val3h);
  L2_H_Mov2(val2h);
  L4_H_Mov2(val4h);


  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);
//  digitalWrite(L1Vdir, 1);
//  analogWrite(L1Vpwm, stall_base1v);
  if (flag1h == 1 && flag3h == 1 && flag2h == 1 && flag4h == 1)
  {
    L1H_sum = 0;
    L3H_sum = 0;
    L2H_sum = 0;
    L4H_sum = 0;
    flag1h = 0;
    flag3h = 0;
    flag2h = 0;
    flag4h = 0;
    L1H_initial=analogRead(L1Hpot);
    L2H_initial=analogRead(L2Hpot);
    L3H_initial=analogRead(L3Hpot);
    L4H_initial=analogRead(L4Hpot);
    analogWrite(L4Hpwm,0);
    analogWrite(L1Hpwm,0);
    analogWrite(L2Hpwm,0);
    analogWrite(L3Hpwm,0);
    state = 505;
  }
}

void state505()
{ 
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);
//  digitalWrite(L1Vdir, 1);
//  analogWrite(L1Vpwm, stall_base1v);
  val1v = L1V_downmid;
  val3v = L3V_downmid;

  L1_V_MovD(val1v);
  L3_V_MovD(val3v);

  //Serial.println(L1V_err);
  if (flag1vd == 1 && flag3vd == 1)
  {
    L3V_sum = 0;
    L1V_sum = 0;
    flag1vd = 0;
    flag3vd = 0;
    analogWrite(L1Vpwm ,0);
    analogWrite(L2Vpwm ,0);
    analogWrite(L3Vpwm ,0);
    analogWrite(L4Vpwm ,0);
    l1h_pwm=0;
    l2h_pwm=0;
    l3h_pwm=0;
    l4h_pwm=0;
    slope_counter++;
    state = 500;
    if(slope_counter>20)    //check for ukhai
    {
      if(digitalRead(mpu1)==1 && digitalRead(mpu2)==1) //i.e pitch reached to zero(+-5)
      {
        ukhai_counter++;            //required since immediately after pitch reaching the thresh chasis can't be taken up ,since back legs might be still on mountain
        if(ukhai_counter==1)  //4
        {
          state=510;
        }
          //chasis up and actuating ukhai driver    
       }
     }
   }
}



void state510()                                                //ukhai state
{                                                              // all down ,give pwm to ukhai motor anywhere here.
    L1V_down_constrain = 150; 
    L2V_down_constrain = 150;
    L3V_down_constrain = 150;
    L4V_down_constrain = 150;
  
     L1_V_MovD(L1V_down);
     L2_V_MovD(L2V_down);
     L3_V_MovD(L3V_down);
     L4_V_MovD(L4V_down);

     

      if(flag1vd==1 &&flag2vd==1 && flag3vd==1 && flag4vd==1)
      {
//        delay(1000);
//      state=185;
      analogWrite(L1Vpwm, 0);
      analogWrite(L2Vpwm, 0);
      analogWrite(L3Vpwm, 0);
      analogWrite(L4Vpwm, 0);
      flag1vd=0;
      flag2vd=0;
      flag3vd=0;
      flag4vd=0;
      digitalWrite(Udir,1);
      analogWrite(Upwm,100);
      
      }
} 
