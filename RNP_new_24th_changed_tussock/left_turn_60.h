  /*left initial : 201 - 206

  left_turn : 111-131
*/ 
void state210()
{
  // LEFT TURN INITIAL
  L1_V_MovD(L1V_down);
  L2_V_MovD(L2V_down);
  L3_V_MovD(L3V_down);
  L4_V_MovD(L4V_down);

      L1_H_Mov(L1H_back);
      L2_H_Mov(L2H_mid);
      L3_H_Mov(L3H_front);
      L4_H_Mov(L4H_front);
 

}
void state201()
{
  L1V_down_constrain = 140;
  L2V_down_constrain = 140;

      L1V_up = L1V_down-80;    //normal height after sanddune
      L2V_up = L2V_down+80;
      L3V_up = L3V_down-80;
      L4V_up = L4V_down+80;
      
//  Serial.println("*** Turn Initial ***");
  val1v = L1V_up;
  L1_V_MovUP(val1v);

  // digitalWrite(L2Vdir,1);
  // analogWrite(L2Vpwm,stall_base2v);
  // digitalWrite(L3Vdir,1);
  // analogWrite(L3Vpwm,stall_base3v);

  // Serial.println("state37");
  // digitalWrite(L2Vdir,0);
  // analogWrite(L2Vpwm,stall_base2v);
  if (flag1vu == 1)
  {
    flag1vu = 0;
    L1V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L1Vpwm, 0);
    state = 202;
//    delay(100);
  }
}

void state202()
{
  L1_H_Mov(L1H_back);
  // digitalWrite(L2Vdir,1);
  // analogWrite(L2Vpwm,stall_base2v);
  if (flag1h == 1)
  {
    flag1h = 0;
    L1H_sum = 0;
    l1h_pwm = 0;
    L1H_initial = analogRead(L1Hpot);
    analogWrite(L1Hpwm, 0);
    state = 203;
  }
}

void state203()
{
//  L1_V_MovLS(L1V_down);
  L1_V_MovD(L1V_down);
//  digitalWrite(L2Vdir, 0);
//  analogWrite(L2Vpwm, 0);
//  digitalWrite(L3Vdir, 1);
//  analogWrite(L3Vpwm, 0);
  if (flag1vd == 1)
  {
    flag1vd = 0;
    L1V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L1Vpwm, 0);
    analogWrite(L2Vpwm, 0);
    state = 204;
  }
}

void state204()
{
  val2v = L2V_up;
  L2_V_MovUP(val2v);
  // Serial.println("state34");
//  digitalWrite(L3Vdir, 1);
//  analogWrite(L3Vpwm, stall_base3v);

  if (flag2vu == 1)
  {
    flag2vu = 0;
    L2V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    state = 205;
  }
}

void state205()
{
  L2_H_Mov(L2H_mid);

  if (flag2h == 1)
  {
    flag2h = 0;
    L2H_sum = 0;
    l2h_pwm = 0;
    L2H_initial = analogRead(L2Hpot);
    analogWrite(L2Hpwm, 0);
    state = 206;
  }
}

void state206()
{
  //  L2_V_MovLS(L2V_down);
  L2_V_MovD(L2V_down);
  digitalWrite(L3Vdir, 1);
  analogWrite(L3Vpwm, 0);

  //  L2_V_MovD(L2V_down);
  //  Serial.println("state36");
  if (flag2vd == 1)
  {
    flag2vd = 0;
    L2V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    state = 211;       
  }
}  
/*Left initial ends*/  
  
  
/* Contains state211() to state232()*/
void state211()
{
  base4h=30;
  base3h=30;
  
  val4h = L4H_back;
  val3h = L3H_back;
  val2h = L2H_front;
  val1h = L1H_front;
    L4_H_Mov(val4h);
    L3_H_Mov(val3h);
    L1_H_Mov(val1h);
    L2_H_Mov(val2h);
    if (flag4h == 1 && flag3h == 1 && flag1h==1 && flag2h==1)
    {
      l4h_pwm = 0;
      l3h_pwm = 0;
      L4H_sum = 0;
      L3H_sum = 0;
      flag4h = 0;
      flag3h = 0;
      flag2h = 0;
      flag1h = 0;
      analogWrite(L4Hpwm, 0);
      analogWrite(L3Hpwm, 0);
      analogWrite(L1Hpwm, 0);
      analogWrite(L2Hpwm, 0);
      L4H_initial = analogRead(L4Hpot);
      L3H_initial = analogRead(L3Hpot);
      L1H_initial = analogRead(L1Hpot);
      L2H_initial = analogRead(L2Hpot);
      state = 212;
//      Serial.println("state 130 done");
    }
}

void state212()
{
  val1v = L1V_up;
  val3v = L3V_up;
  L1_V_MovUP(val1v);
  L3_V_MovUP(val3v);
  if (flag3vu==1 && flag1vu==1)
  {
    flag1vu = 0;
    flag3vu = 0;
    L1V_sum = 0;
    L3V_sum = 0;
    analogWrite(L1Vpwm, 0);
    analogWrite(L3Vpwm, 0);
    state = 213;
  }
}

void state213()
{
  val3h = L3H_front;
  val1h = L1H_mid;
  L3_H_Mov(val3h);
  L1_H_Mov(val1h);
 if (flag3h == 1 && flag1h==1)
    {
      L1H_sum = 0;
      L3H_sum = 0;
      flag3h = 0;
      flag1h = 0;
      analogWrite(L3Hpwm, 0);
      analogWrite(L1Hpwm, 0);
//      L4H_initial = analogRead(L4Hpot);
      L3H_initial = analogRead(L3Hpot);
      L1H_initial = analogRead(L1Hpot);
//      L2H_initial = analogRead(L2Hpot);
      state = 214;
//      Serial.println("state 130 done");
    }
}


void state214()
{
  L1_V_MovD(L1V_down);
  L3_V_MovD(L3V_down);
  if (flag3vd == 1 && flag1vd==1)
  {
    flag3vd = 0;
    L3V_sum = 0;
    flag1vd = 0;
    L1V_sum = 0;
    analogWrite(L1Vpwm, 0);
    analogWrite(L3Vpwm, 0);
    state = 215;
//       Serial.println("state 132 done");
 
//    delay(100);
  }
}

void state215()
{
  val2v = L2V_up;
  val4v = L4V_up;
  L2_V_MovUP(val2v);
  L4_V_MovUP(val4v);
  if (flag4vu == 1 && flag2vu==1)
  {
    flag2vu = 0;
    flag4vu = 0;
    L2V_sum = 0;
    L4V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
//       Serial.println("state 133 done");
    state = 216;
//      Serial.println(L2V_val);
//    Serial.println(500);
//    delay(50)
  }
}


void state216()
{
  val2h = L2H_mid;
  val4h = L4H_front;
  L2_H_Mov(val2h);
  L4_H_Mov(val4h);
 if (flag4h == 1 && flag2h==1)
    {
      L2H_sum = 0;
      L4H_sum = 0;
      flag2h = 0;
      flag4h = 0;
      analogWrite(L2Hpwm, 0);
      analogWrite(L4Hpwm, 0);
//      L4H_initial = analogRead(L4Hpot);
      L2H_initial = analogRead(L2Hpot);
      L4H_initial = analogRead(L4Hpot);
//      L2H_initial = analogRead(L2Hpot);
      state = 217;
//      Serial.println("state 130 done");
    }
}

void state217()
{
  L2_V_MovD(L2V_down);
  L4_V_MovD(L4V_down);
  if (flag4vd == 1 && flag2vd==1)
  {
    flag2vd = 0;
    flag4vd = 0;
    L2V_sum = 0;
    L4V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
    state = 211;
  }
}

void state218()
{
  if(turnAngleFlag)    
  {
    angle = getDMPAngle('y');
    Serial.print("Current Angle:  ");
    Serial.println(angle);
    turnAngleFlag = 0;
  }
  
  if(angle>angle_thrs_left)
  {
  val4h = L4H_midb;
  val3h = L3H_midb;

  L4_H_Mov(val4h);
  L3_H_Mov(val3h);

  if (flag4h == 1 && flag3h == 1)
  {
    l4h_pwm = 0;
    l3h_pwm = 0;
    L4H_sum = 0;
    L3H_sum = 0;

    flag4h = 0;
    flag3h = 0;

    analogWrite(L4Hpwm, 0);
    analogWrite(L3Hpwm, 0);

    L4H_initial = analogRead(L4Hpot);
    L3H_initial = analogRead(L3Hpot);
    state = 217;
        Serial.println("state135 done");
//    delay(50);
    }
   }
   else
   {
      state = 1;
      normal_conditions();
      counter=0;
      countThres=4;
      turn_flag=0;
      angle_thrs_left=0;
   }

  }

void state2177()
{
  val1v = L1V_up;
  L1_V_MovUP(val1v);

  if (flag1vu == 1)
  {
    flag1vu = 0;
    L1V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L1Vpwm, 0);
    state = 218;
       Serial.println("state 136 done");
    delay(100);
  }
}

void state2188()
{
  L1_V_MovD(L1V_down);
  if (flag1vd == 1)
  {
    flag1vd = 0;
    L1V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L1Vpwm, 0);
    state = 219;
    Serial.println("state 137 done");
//    delay(100);
  }
}

void state219()
{
  val2v = L2V_up;
  L2_V_MovUP(val2v);

  if (flag2vu == 1)
  {
    flag2vu = 0;
    L2V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    state = 220;
//    Serial.println("state 138 done");
  Serial.println(L2V_val);
//    Serial.println(500);
    delay(300);
  }
}

void state220()
{
  L2_V_MovD(L2V_down);
  if (flag2vd == 1)
  {
    flag2vd = 0;
    L2V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    state = 221;
//    Serial.println("state 139 done");
  Serial.println(L2V_val);
//    Serial.println(600);
//    delay(50);
  }
}

void state221()
{
  if(!turnAngleFlag)    
  {
    angle = getDMPAngle('y');
    Serial.print("Current Angle:  ");
    Serial.println(angle);
    turnAngleFlag = 1;
  }
  
  if(angle>angle_thrs_left)
  {
  val4h = L4H_back;
  val3h = L3H_back;

  L4_H_Mov(val4h);
  L3_H_Mov(val3h);

  if (flag4h == 1 && flag3h == 1)
  {
    l4h_pwm = 0;
    l3h_pwm = 0;
    L4H_sum = 0;
    L3H_sum = 0;

    flag4h = 0;
    flag3h = 0;

    analogWrite(L4Hpwm, 0);
    analogWrite(L3Hpwm, 0);

    L4H_initial = analogRead(L4Hpot);
    L3H_initial = analogRead(L3Hpot);
    state = 222;
    Serial.println("state140 done");
//    delay(50);
  }
  }
  else
  {
     state = 1;
     normal_conditions();
     counter=0;
     countThres=4;
     turn_flag=0;
     angle_thrs_left=0;
   }
   
 }

void state222()
{
  val1v = L1V_up;
  L1_V_MovUP(val1v);
  if (flag1vu == 1)
  {
    flag1vu = 0;
    L1V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L1Vpwm, 0);
    Serial.println("state 141 done");
    state = 223;
    delay(100);
  }
}

void state223()
{
  L1_V_MovD(L1V_down);
  if (flag1vd == 1)
  {
    flag1vd = 0;
    L1V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L1Vpwm, 0);
    state = 224;
    Serial.println("state 142 done");
//    delay(10);
  }
}

void state224()
{
  val2v = L2V_up;
  L2_V_MovUP(val2v);

  if (flag2vu == 1)
  {
    flag2vu = 0;
    L2V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    state = 225;
//    Serial.println("state 143 done");
     Serial.println(L2V_val);
//    Serial.println(500);
    delay(300);
  }
}

void state225()
{
  L2_V_MovD(L2V_down);
  if (flag2vd == 1)
  {
    flag2vd = 0;
    L2V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    state = 226;
//    Serial.println("state 144 done");
    Serial.println(L2V_val);
    Serial.println(600);
//    delay(100);
  }
}

void state226()
{
  val3v = L3V_up;
  L3_V_MovUP(val3v);

  if (flag3vu == 1)
  {
    flag3vu = 0;
    L3V_sum = 0;
    l3v_pwm = 0;
    analogWrite(L3Vpwm, 0);
    state = 227;
    Serial.println("state 145 done");
//    delay(50);
  }
}

void state227()
{
  L3_H_Mov(L3H_front);
  if (flag3h == 1)
  {
    flag3h = 0;
    L3H_sum = 0;
    l3h_pwm = 0;
    L3H_initial = analogRead(L3Hpot);
    analogWrite(L2Hpwm, 0);
    state = 228;
    Serial.println("state 146 done");
//    delay(50);
  }
}

void state228()
{
  L3_V_MovD(L3V_down);
  if (flag3vd == 1)
  {
    flag3vd = 0;
    L3V_sum = 0;
    l3v_pwm = 0;
    analogWrite(L3Vpwm, 0);
    state = 229;
    Serial.println("state 147 done");
//    delay(50);
  }
}

void state229()
{
  val4v = L4V_up;
  L4_V_MovUP(val4v);

  //digitalWrite(L2Vdir,1);
  //analogWrite(L2Vpwm,stall_base2v);

  if (flag4vu == 1)
  {
    flag4vu = 0;
    L4V_sum = 0;
    l4v_pwm = 0;
    analogWrite(L4Vpwm, 0);
    state = 230;
    Serial.println("state 148 done");
//    delay(50);
  }
}

void state230()
{
  L4_H_Mov(L4H_front);

  //digitalWrite(L2Vdir,1);
  //analogWrite(L2Vpwm,stall_base2v);
  if (flag4h == 1)
  {
    flag4h = 0;
    L4H_sum = 0;
    l4h_pwm = 0;
    L4H_initial = analogRead(L4Hpot);
    analogWrite(L4Hpwm, 0);
    state = 231;
    Serial.println("state 149 done");
//    delay(50);
  }
}

void state231()
{
  L4_V_MovD(L4V_down);
  //  digitalWrite(L2Vdir,1);
  //  analogWrite(L2Vpwm,stall_base2v);

  if (flag4vd == 1)
  {
    flag4vd = 0;
    L4V_sum = 0;
    l4v_pwm = 0;
    analogWrite(L4Vpwm, 0);
    analogWrite(L2Vpwm, 0);
    state = 211;
    
    Serial.println("state 150 done");
    turnAngleFlag = 0;
    turnCount=turnCount+1;
    Serial.print("turnCount = ");
    Serial.println(turnCount);
    
//    delay(100);
  }
  
}
