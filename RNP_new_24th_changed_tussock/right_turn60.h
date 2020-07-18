    /* Contains state40() to state57()*/



void state310()
{
  // RIGHT TURN INITIAL
  L1_V_MovD(L1V_down);
  L2_V_MovD(L2V_down);
  L3_V_MovD(L3V_down);
  L4_V_MovD(L4V_down);

      L1_H_Mov(L1H_front);
      L2_H_Mov(L2H_front);
      L3_H_Mov(L3H_mid);
      L4_H_Mov(L4H_mid);

 

}

void state301()
{
  L3V_down_constrain = 100;
  L4V_down_constrain = 100;
//  Serial.println("*** Turn Initial-right ***");
  val4v = L4V_up;
  L4_V_MovUP(val4v);

  // digitalWrite(L2Vdir,1);
  // analogWrite(L2Vpwm,stall_base2v);
   digitalWrite(L3Vdir,1);
   analogWrite(L3Vpwm,stall_base3v);

  // Serial.println("state37");
  // digitalWrite(L2Vdir,0);
  // analogWrite(L2Vpwm,stall_base2v);
  if (flag4vu == 1)
  {
    flag4vu = 0;
    L4V_sum = 0;
    l4v_pwm = 0;
    analogWrite(L4Vpwm, 0);
    state = 302;
//    delay(100);
  }
}

void state302()
{
  L4_H_Mov(L4H_back);
  // digitalWrite(L2Vdir,1);
  // analogWrite(L2Vpwm,stall_base2v);
  if (flag4h == 1)
  {
    flag4h = 0;
    L4H_sum = 0;
    l4h_pwm = 0;
    L4H_initial = analogRead(L4Hpot);
    analogWrite(L4Hpwm, 0);
    state = 303;
  }
}

void state303()
{
//  L1_V_MovLS(L1V_down);
  L4_V_MovD(L4V_down);
//  digitalWrite(L2Vdir, 0);
//  analogWrite(L2Vpwm, 0);
//  digitalWrite(L3Vdir, 1);
//  analogWrite(L3Vpwm, 0);


  if (flag4vd == 1)
  {
    flag4vd = 0;
    L4V_sum = 0;
    l4v_pwm = 0;
    analogWrite(L4Vpwm, 0);
    analogWrite(L2Vpwm, 0);
    state = 304;
  }
}

void state304()
{
  val3v = L3V_up;
  L3_V_MovUP(val3v);
  // Serial.println("state34");
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v);

  if (flag3vu == 1)
  {
    flag3vu = 0;
    L3V_sum = 0;
    l3v_pwm = 0;
    analogWrite(L3Vpwm, 0);
    state = 305;
  }
}

void state305()
{
  L3_H_Mov(L3H_mid);

  if (flag3h == 1)
  {
    flag3h = 0;
    L3H_sum = 0;
    l3h_pwm = 0;
    L3H_initial = analogRead(L3Hpot);
    analogWrite(L3Hpwm, 0);
    state = 306;
  }
}

void state306()
{
  //  L2_V_MovLS(L2V_down);
  L3_V_MovD(L3V_down);
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, 0);

  //  L2_V_MovD(L2V_down);
  //  Serial.println("state36");
  if (flag3vd == 1)
  {
    flag3vd = 0;
    L3V_sum = 0;
    l3v_pwm = 0;
    analogWrite(L3Vpwm, 0);
    state = 311;       
    turnAngleFlag=0;
  }

}
///////////////////////////////////////////////////////////////////////////////////////////////
void state311()
{
  if(!turnAngleFlag)    
  {
    angle = getDMPAngle('y');
    Serial.print("Current Angle:  ");
    Serial.println(angle);
    turnAngleFlag = 1;    
  }
  if (angle < 0)
{
  val1h = L1H_midf;
  val2h = L2H_midf;

  L1_H_Mov(val1h);
  L2_H_Mov(val2h);

  //Serial.println(L1V_err);

  if (flag1h == 1 && flag2h == 1)
  {
    l1h_pwm=0;
    l2h_pwm=0;
    L1H_sum =0;
    L2H_sum =0;
  
    flag1h = 0;
    flag2h = 0;
 
    analogWrite(L1Hpwm,0);
    analogWrite(L2Hpwm,0);

    L1H_initial=analogRead(L1Hpot);
    L2H_initial=analogRead(L2Hpot);
    state = 312;
    Serial.println("state40 done");
  }
}
else
  {
     state = 351;
     tussock_flag=1;
  }
}
void state312()
{
 val4v=L4V_up;
 digitalWrite(L3Vdir, 1);
  analogWrite(L3Vpwm, stall_base3v);
 L4_V_MovUP(val4v);
  Serial.println("state41");
  

 if(flag4vu==1)
 {
   flag4vu=0;
   L4V_sum = 0;
   l4v_pwm=0;
   analogWrite(L4Vpwm,0);
   state=313;
 } 
}

void state313()
{
  L4_V_MovD(L4V_down);
//  Serial.println("state42");
  if(flag4vd==1)
  {
   flag4vd=0;
   L4V_sum=0; 
   l4v_pwm-=0; 
   analogWrite(L4Vpwm,0);
   state=314; 
  }
}

void state314()
{
 val3v=L3V_up;
 L3_V_MovUP(val3v);

//  Serial.println("state43");
 if(flag3vu==1)
 {
   flag3vu=0;
   L3V_sum = 0;
   l3v_pwm=0;
   analogWrite(L3Vpwm,0);
   state=315;
 } 
}

void state315()
{
  L3_V_MovD(L3V_down);
//  Serial.println("state44");
  if(flag3vd==1)
  {
   flag3vd=0;
   L3V_sum=0;  
   l3v_pwm=0;
   analogWrite(L3Vpwm,0);
   state=316;
   delay(200); 
  }
}

void state316()
{
  if(turnAngleFlag)    
  {
    angle = getDMPAngle('y');
    Serial.print("Current Angle:  ");
    Serial.println(angle);
    turnAngleFlag = 0;
  }
  if (angle < 0)
{
  val1h = L1H_midb;
  val2h = L2H_midb;

  L1_H_Mov(val1h);
  L2_H_Mov(val2h);

  //Serial.println(L1V_err);
  if (flag1h == 1 && flag2h == 1)
  {
    l1h_pwm=0;
    l2h_pwm=0;
    L1H_sum = 0;
    L2H_sum = 0;
  
    flag1h = 0;
    flag2h = 0;
 
    analogWrite(L1Hpwm,0);
    analogWrite(L2Hpwm,0);

    L1H_initial=analogRead(L1Hpot);
    L2H_initial=analogRead(L2Hpot);
    state = 317;
//    Serial.println("state45 done");
  }
}
 else
   {
//      normal_conditions();
      state = 351;
      tussock_flag=1;
    }
}
void state317()
{
 val4v=L4V_up;
 digitalWrite(L3Vdir, 1);
  analogWrite(L3Vpwm, stall_base3v);
 L4_V_MovUP(val4v);
//  Serial.println("state46");

 if(flag4vu==1)
 {
   flag4vu=0;
   L4V_sum = 0;
   l4v_pwm=0;
   analogWrite(L4Vpwm,0);
   state=318;
 } 
}

void state318()
{
  L4_V_MovD(L4V_down);
  Serial.println("state47");
  if(flag4vd==1)
  {
   flag4vd=0;
   L4V_sum=0; 
   l4v_pwm-=0; 
   analogWrite(L4Vpwm,0);
   state=319; 
  }
}

void state319()
{
 val3v=L3V_up;
 digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v);
 L3_V_MovUP(val3v);

  Serial.println("state48");
 if(flag3vu==1)
 {
   flag3vu=0;
   L3V_sum = 0;
   l3v_pwm=0;
   analogWrite(L3Vpwm,0);
   state=320;
 } 
}

void state320()
{
  L3_V_MovD(L3V_down);
  Serial.println("state49");
  if(flag3vd==1)
  {
   flag3vd=0;
   L3V_sum=0;  
   l3v_pwm=0;
   analogWrite(L3Vpwm,0);
   state=321; 
  }
}

void state321()
{
  if(!turnAngleFlag)    
  {
    angle = getDMPAngle('y');
    Serial.print("Current Angle:  ");
    Serial.println(angle);
    turnAngleFlag = 1;
  }
  if (angle < 0)
{
  val1h = L1H_back;
  val2h = L2H_back;

  L1_H_Mov(val1h);
  L2_H_Mov(val2h);

  //Serial.println(L1V_err);
  if (flag1h == 1 && flag2h == 1)
  {
    l1h_pwm=0;
    l2h_pwm=0;
    L1H_sum = 0;
    L2H_sum = 0;
  
    flag1h = 0;
    flag2h = 0;
 
    analogWrite(L1Hpwm,0);
    analogWrite(L2Hpwm,0);

    L1H_initial=analogRead(L1Hpot);
    L2H_initial=analogRead(L2Hpot);
    state = 322;
    Serial.println("state50 done");
  }
}
 else
   {
//     normal_conditions();
      state = 351;
      tussock_flag=1;
    }

}



void state322()
{
 val4v=L4V_up;
 digitalWrite(L3Vdir, 1);
  analogWrite(L3Vpwm, stall_base3v);
 L4_V_MovUP(val4v);
  Serial.println("state51");

 if(flag4vu==1)
 {
   flag4vu=0;
   L4V_sum = 0;
   l4v_pwm=0;
   analogWrite(L4Vpwm,0);
   state=323;
 } 
}

void state323()
{
  L4_V_MovD(L4V_down);
  Serial.println("state52");
  if(flag4vd==1)
  {
   flag4vd=0;
   L4V_sum=0; 
   l4v_pwm-=0; 
   analogWrite(L4Vpwm,0);
   state=324; 
  }
}

void state324()
{
 val3v=L3V_up;

 digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v);
 L3_V_MovUP(val3v);

  Serial.println("state53");
 if(flag3vu==1)
 {
   flag3vu=0;
   L3V_sum = 0;
   l3v_pwm=0;
   analogWrite(L3Vpwm,0);
   state=325;
 } 
}

void state325()
{
  L3_V_MovD(L3V_down);
  Serial.println("state54");
  if(flag3vd==1)
  {
   flag3vd=0;
   L3V_sum=0;  
   l3v_pwm=0;
   analogWrite(L3Vpwm,0);
   state=326; 
  }
}

void state326()
{
 val1v=L1V_up;
 L1_V_MovUP(val1v);
  Serial.println("state55");
 digitalWrite(L2Vdir,1);
 analogWrite(L2Vpwm,stall_base2v);
 if(flag1vu==1)
 {
   flag1vu=0;
   L1V_sum = 0;
   l1v_pwm=0;
   analogWrite(L1Vpwm,0);
   state=327;
 } 
}

void state327()
{
 L1_H_Mov(L1H_front);
  Serial.println("state56");
 
  
 //digitalWrite(L2Vdir,1);
 //analogWrite(L2Vpwm,stall_base2v);
  if(flag1h==1)
  {
   flag1h=0;
   L1H_sum=0;
   l1h_pwm=0;
   L1H_initial=analogRead(L1Hpot);
   analogWrite(L1Hpwm,0);
   state=328;
  }
}

void state328()
{
  L1_V_MovD(L1V_down);
  Serial.println("state57");
  digitalWrite(L2Vdir,1);
  analogWrite(L2Vpwm,stall_base2v);

  if(flag1vd==1)
  {
   flag1vd=0;
   L1V_sum=0;  
   l1v_pwm=0;
   analogWrite(L1Vpwm,0);
   analogWrite(L2Vpwm,0);  
   state=329; 
   delay(200);
  }
}
void state329()
{
 val2v=L2V_up;
 digitalWrite(L3Vdir, 1);
  analogWrite(L3Vpwm, stall_base3v);
 L2_V_MovUP(val2v);
//  Serial.println("state58");

 if(flag2vu==1)
 {
   flag2vu=0;
   L2V_sum = 0;
   l2v_pwm=0;
   analogWrite(L2Vpwm,0);
   state=330;
 } 
}

void state330()
{
  L2_H_Mov(L2H_front); 


  if(flag2h==1)
  {
   flag2h=0;
   L2H_sum=0;
   l2h_pwm=0;
   L2H_initial=analogRead(L2Hpot);
   analogWrite(L2Hpwm,0);
   state=331;
  }
}

void state331()
{
  L2_V_MovD(L2V_down);
  if(flag2vd==1)
  {
   flag2vd=0; 
   L2V_sum=0;  
   l2v_pwm=0;
   analogWrite(L2Vpwm,0);
   state=311; 
    turnAngleFlag = 0;
    turnCountright=turnCountright+1;
    Serial.print("turnCountright = ");
    Serial.println(turnCountright);
  }
}
