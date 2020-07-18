/*left initial : 101 - 106

  left_turn : 111-131
*/

void state110()
{
  // right TURN INITIAL
  L1_V_MovD(L1V_down);
  L2_V_MovD(L2V_down);
  L3_V_MovD(L3V_down);
  L4_V_MovD(L4V_down);

  L1_H_Mov(L1H_back);
  L2_H_Mov(L2H_mid);
  L3_H_Mov(L3H_front);
  L4_H_Mov(L4H_front);
}

void state101()
{
  Serial.println("Sandune initial Entered");
  flag1_up=1;
  flag3_up=1;
  L1_V_MovUP_hallD();
  L3_V_MovUP_hallD();
   digitalWrite(L2Vdir,1);
   analogWrite(L2Vpwm,stall_base2v);
  // digitalWrite(L3Vdir,1);
  // analogWrite(L3Vpwm,stall_base3v);
  if (flag1vu == 1 && flag3vu == 1)
  {
    flag1_up=0;
    flag3_up=0;
    flag1vu = 0;
    flag3vu=0;
    analogWrite(L1Vpwm, 0);
    state = 102;
  }
}

void state102()
{
  L1_H_Mov(L1H_front);
  L3_H_Mov(L3H_front);
  // digitalWrite(L2Vdir,1);
  // analogWrite(L2Vpwm,stall_base2v);
  if (flag1h == 1 && flag3h==1)
  {
    flag1h = 0;
    flag3h=0;
    L1H_sum = 0;
    L3H_sum=0;
    L1H_initial = analogRead(L1Hpot);
    L3H_initial = analogRead(L3Hpot);
    analogWrite(L1Hpwm, 0);
    analogWrite(L3Hpwm, 0);
    state = 103;
  }
}

void state103()
{
  flag1_down=1;  
  flag3_down=1;
  L1_V_MovD_hallD();
  L3_V_MovD_hallD();
//  digitalWrite(L2Vdir, 0);
//  analogWrite(L2Vpwm, 0);
//  digitalWrite(L3Vdir, 1);
//  analogWrite(L3Vpwm, 0);

  //  L1_V_MovD(L1V_down);
  //  Serial.println("state39");
  //  digitalWrite(L2Vdir,0);
  //  analogWrite(L2Vpwm,stall_base2v);

  if (flag1vd == 1 && flag3vd==1)
  {
    flag1vd = 0;
    flag3vd =0;
    flag1_down=0;
    flag3_down=0;
    analogWrite(L1Vpwm, 0);
    analogWrite(L3Vpwm, 0);
    state = 104;
  }
}


////////////////////////////use this when right turn is to be taken  with 1 and 3 at front///////////////////////// 
void state104()
{
  flag2_up=1;
  flag4_up=1;
  L2_V_MovUP_hallD();
  L4_V_MovUP_hallD();
  // Serial.println("state34");
//  digitalWrite(L3Vdir, 1);
//  analogWrite(L3Vpwm, stall_base3v);
 if (flag2vu == 1 && flag4vu==1)
  {
    flag4vu=0;
    flag2vu=0;
    flag2_up=0;
    flag4_up=0;
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
    state = 105;
  }
}

void state105()
{
  L2_H_Mov(L2H_front);
  L4_H_Mov(L4H_front);
  if (flag2h == 1 && flag4h==1)
  {
    flag2h = 0;
    flag4h=0;
    L2H_sum = 0;
    L4H_sum=0;
    L2H_initial = analogRead(L2Hpot);
    analogWrite(L2Hpwm, 0);
    L4H_initial = analogRead(L4Hpot);
    analogWrite(L4Hpwm, 0);
    state = 106;
  }
}

void state106()
{
  //  L2_V_MovLS(L2V_down);
  flag2_down=1;
  flag4_down=1;
  L2_V_MovD_hallD();
  L4_V_MovD_hallD();
//  digitalWrite(L3Vdir, 1);
//  analogWrite(L3Vpwm, 0);

  if (flag2vd == 1 && flag4vd==1)
  {
    flag2vd = 0;
    flag4vd = 0;
    flag2_down=0;
    flag4_down = 0;
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
    state = 170;
  }
}
/*Left initial ends*/  
  
  
/* Contains state111() to state132()*/
void state111()
{
//  base4h=20;
//  base3h=20;
//  if(!turnAngleFlag)    
//  {
//    angle = getDMPAngle('y');
//    Serial.print("Current Angle:  ");
//    Serial.println(angle);
//    turnAngleFlag = 1;
//  }

//  if (angle > (angle_thrs_left))
//  {
//  digitalWrite(L3Vdir, 1);
//  analogWrite(L3Vpwm, stall_base3v);
//
//    val4h = L4H_midf;
//    val3h = L3H_midf;
//
//    L4_H_Mov(val4h);
//    L3_H_Mov(val3h);
//
////    Serial.println("Turning");
//    if (flag4h == 1 && flag3h == 1)
//    {
//      l4h_pwm = 0;
//      l3h_pwm = 0;
//      L4H_sum = 0;
//      L3H_sum = 0;
//      flag4h = 0;
//      flag3h = 0;
//
//      analogWrite(L4Hpwm, 0);
//      analogWrite(L3Hpwm, 0);
//
//      L4H_initial = analogRead(L4Hpot);
//      L3H_initial = analogRead(L3Hpot);
//      state = 112;
//      Serial.println("state 130 done");
////      delay(50);
//    }
//  }
//  else
//  {
//    if(angle_thrs_left==-45)
//    {
//      turn_flag=1;
//      base3h=0;
//      base4h=0;
//      state = 151;      //sandune initial
//    }
//    else if(angle_thrs_left==-60)
//    {
//      state = 1;      //normal walking initial
//      normal_conditions();
//      counter=0;
//      countThres=4;
//      angle_thrs_left=0;
//     }
////    state=0;
//    Serial.println("*** SANDUNE INITIAL ***");
//  }
    L4_H_Mov(L4H_back);
    L3_H_Mov(L3H_back);
    L1_H_Mov(L1H_back);
    L2_H_Mov(L2H_midf);
    if (flag4h == 1 && flag3h == 1 && flag1h==1 && flag2h==1)
    {
      l4h_pwm = 0;
      l3h_pwm = 0;
      L4H_sum = 0;
      L3H_sum = 0;
      flag4h = 0;
      flag3h = 0;
      flag1h = 0;
      flag2h = 0;
      analogWrite(L4Hpwm, 0);
      analogWrite(L3Hpwm, 0);
      analogWrite(L2Hpwm, 0);
      analogWrite(L1Hpwm, 0);
      L1H_initial = analogRead(L1Hpot);
      L2H_initial = analogRead(L2Hpot);
      L4H_initial = analogRead(L4Hpot);
      L3H_initial = analogRead(L3Hpot);
      state = 112;
//      delay(50);
    }

}


void state112()
{
  flag1_up=1;
  flag3_up=1;
  L1_V_MovUP_hallD();
  L3_V_MovUP_hallD();
  
  if (flag1vu == 1 && flag3vu==1)
  {
    flag1_up=0;
    flag3_up=0;
    flag1vu = 0;
    flag3vu=0;
    L1V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L1Vpwm, 0);
    analogWrite(L3Vpwm, 0);
    state = 113;
  }
}

void state113()
{
    L3_H_Mov(L3H_front);
    L1_H_Mov(L1H_mid);
    if(flag1h==1 && flag3h==1)
    {
      flag1h = 0;
      flag3h = 0;
      analogWrite(L4Hpwm, 0);
      analogWrite(L3Hpwm, 0);
      analogWrite(L2Hpwm, 0);
      analogWrite(L1Hpwm, 0);
      L1H_initial = analogRead(L1Hpot);
      L3H_initial = analogRead(L3Hpot);
      state = 114;
    }
}


void state114()
{
  flag1_down=1;  
  flag3_down=1;
  L1_V_MovD_hallD();
  L3_V_MovD_hallD();
  if (flag1vd == 1 && flag3vd==1 && (digitalRead(LS_L1f)==0 || digitalRead(LS_L1b)==0) && (digitalRead(LS_L3f)==0 ||digitalRead(LS_L3b)==0) )
  {
    flag3_down=0;
    flag1_down=0;
    flag1vd = 0;
    flag3vd=0;
    L1V_sum = 0;
    L3V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L1Vpwm, 0);
    analogWrite(L3Vpwm, 0);
    state = 115;
//       Serial.println("state 132 done");
 
//    delay(100);
  }
}

void state115()
{
  flag2_up=1;
  flag4_up=1;
  L2_V_MovUP_hallD();
  L4_V_MovUP_hallD();
  
  if (flag2vu == 1 && flag4vu==1)
  {
    flag4vu=0;
    flag2vu = 0;
    flag2_up=0;
    flag4_up=0;
    L2V_sum = 0;
    L4V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
//       Serial.println("state 133 done");
    state = 116;
//      Serial.println(L2V_val);
//    Serial.println(500);
//    delay(50);
//    delay(100);
  }
}

void state116()
{
    L2_H_Mov(L2H_mid);
    L4_H_Mov(L4H_front);
    if(flag2h==1 && flag4h==1)
    {
      flag2h = 0;
      flag4h = 0;
      analogWrite(L4Hpwm, 0);
      analogWrite(L3Hpwm, 0);
      analogWrite(L2Hpwm, 0);
      analogWrite(L1Hpwm, 0);
      L2H_initial = analogRead(L2Hpot);
      L4H_initial = analogRead(L4Hpot);
      state = 117;
    }
}


void state117()
{
  
  flag2_down=1;  
  flag4_down=1;
  L2_V_MovD_hallD();
  L4_V_MovD_hallD();
  if (flag2vd == 1 && flag4vd==1 && (digitalRead(LS_L2f)==0 || digitalRead(LS_L2b)==0) && (digitalRead(LS_L4f)==0 ||digitalRead(LS_L4b)==0)) 
  {
    flag2vd = 0;
    flag4vd=0;
    L2V_sum = 0;
    L4V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
    state = 111;
//     Serial.println(L2V_val);
//    Serial.println(600);
//       Serial.println("state 134 done");
//    delay(100);
  }
}

/////////////////////////////////////////////////////////////

void state1166()
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
    state = 117;
        Serial.println("state135 done");
//    delay(50);
    }
   }
   else
   {
    if(angle_thrs_left==-45)
    {
      turn_flag=1;
      base3h=0;
      base4h=0;
      state = 151;      //sandune initial
    }
    else if(angle_thrs_left==-60)
    {
      state = 1;       //normal walking initial
      normal_conditions();
      counter=0;
      countThres=4;
      angle_thrs_left=0;
     }

    }
}
void state1177()
{
  val1v = L1V_up;
  L1_V_MovUP(val1v);

  if (flag1vu == 1)
  {
    flag1vu = 0;
    L1V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L1Vpwm, 0);
    state = 118;
       Serial.println("state 136 done");
    delay(100);
  }
}

void state118()
{
  L1_V_MovD(L1V_down);
  if (flag1vd == 1)
  {
    flag1vd = 0;
    L1V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L1Vpwm, 0);
    state = 119;
    Serial.println("state 137 done");
//    delay(100);
  }
}

void state119()
{
  val2v = L2V_up;
  L2_V_MovUP(val2v);

  if (flag2vu == 1)
  {
    flag2vu = 0;
    L2V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    state = 120;
//    Serial.println("state 138 done");
  Serial.println(L2V_val);
//    Serial.println(500);
    delay(300);
  }
}

void state120()
{
  L2_V_MovD(L2V_down);
  if (flag2vd == 1)
  {
    flag2vd = 0;
    L2V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    state = 121;
//    Serial.println("state 139 done");
  Serial.println(L2V_val);
//    Serial.println(600);
//    delay(50);
  }
}

void state121()
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
    state = 122;
    Serial.println("state140 done");
//    delay(50);
  }
  }
  else
  {
    if(angle_thrs_left==-45)
    {
      turn_flag=1;
      base3h=0;
      base4h=0;
      state = 151;      //sandune initial
    }
    else if(angle_thrs_left==-60)
    {
      state = 1;      //walking initial 
      normal_conditions();
      counter=0;
      countThres=4;
      angle_thrs_left=0;
     }
   
  }
}

void state122()
{
  val1v = L1V_up;
  L1_V_MovUP(val1v);
  if (flag1vu == 1)
  {
    flag1vu = 0;
    L1V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L1Vpwm, 0);
    Serial.println("state x done");
    state = 123;
    delay(100);
  }
}

void state123()
{
  L1_V_MovD(L1V_down);
  if (flag1vd == 1)
  {
    flag1vd = 0;
    L1V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L1Vpwm, 0);
    state = 124;
    Serial.println("state 142 done");
//    delay(10);
  }
}

void state124()
{
  val2v = L2V_up;
  L2_V_MovUP(val2v);

  if (flag2vu == 1)
  {
    flag2vu = 0;
    L2V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    state = 125;
//    Serial.println("state 143 done");
     Serial.println(L2V_val);
//    Serial.println(500);
    delay(300);
  }
}

void state125()
{
  L2_V_MovD(L2V_down);
  if (flag2vd == 1)
  {
    flag2vd = 0;
    L2V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    state = 126;
//    Serial.println("state 144 done");
    Serial.println(L2V_val);
    Serial.println(600);
//    delay(100);
  }
}

void state126()
{
  val3v = L3V_up;
  L3_V_MovUP(val3v);

  if (flag3vu == 1)
  {
    flag3vu = 0;
    L3V_sum = 0;
    l3v_pwm = 0;
    analogWrite(L3Vpwm, 0);
    state = 127;
    Serial.println("state 145 done");
//    delay(50);
  }
}

void state127()
{
  L3_H_Mov(L3H_front);
  if (flag3h == 1)
  {
    flag3h = 0;
    L3H_sum = 0;
    l3h_pwm = 0;
    L3H_initial = analogRead(L3Hpot);
    analogWrite(L2Hpwm, 0);
    state = 128;
    Serial.println("state 146 done");
//    delay(50);
  }
}

void state128()
{
  L3_V_MovD(L3V_down);
  if (flag3vd == 1)
  {
    flag3vd = 0;
    L3V_sum = 0;
    l3v_pwm = 0;
    analogWrite(L3Vpwm, 0);
    state = 129;
    Serial.println("state 147 done");
//    delay(50);
  }
}

void state129()
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
    state = 130;
    Serial.println("state 148 done");
//    delay(50);
  }
}

void state130()
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
    state = 131;
    Serial.println("state 149 done");
//    delay(50);
  }
}

void state131()
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
    state = 111;
    
    Serial.println("state 150 done");
    turnAngleFlag = 0;
    turnCount=turnCount+1;
    Serial.print("turnCount = ");
    Serial.println(turnCount);
    
//    delay(100);
  }
  
}



                                  //////////////diagonal pattern////////////////
void state132()
{

L1H_pwm_constrain = 170;    
L2H_pwm_constrain = 170;
L3H_pwm_constrain = 110;
L4H_pwm_constrain = 110;
base1h=30;
base2h=30;
  flag1_up=1;
  flag3_up=1;
  
  L1_V_MovUP_hallD();
  L3_V_MovUP_hallD();
  
//  Stall
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);
  digitalWrite(L4Vdir, 1);
  analogWrite(L4Vpwm, stall_base4v-10);

//  Serial.println("31");
  if (flag1vu == 1 && flag3vu == 1)
  {
    L1V_sum = 0;
    L3V_sum = 0;
    flag1vu = 0;
    flag3vu = 0;
    flag3_up=0;
    flag1_up=0;
//    analogWrite(L4Vpwm, 0);
//    analogWrite(L2Vpwm, 0);
    analogWrite(L1Vpwm,0);
    analogWrite(L3Vpwm,0);
//    detachInterrupt(digitalPinToInterrupt(L1V_hall));
//    detachInterrupt(digitalPinToInterrupt(L3V_hall));
    state = 133;
  }
}

void state133()
{
  val1h = L1H_front;
  val3h = L3H_front;
  val2h = L2H_back;
  val4h = L4H_mid;

//  Stall
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);
  digitalWrite(L4Vdir, 1);
  analogWrite(L4Vpwm, stall_base4v-10);

  L1_H_Mov(val1h);
  L3_H_Mov(val3h);
  L2_H_Mov(val2h);
  L4_H_Mov(val4h);

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
    state = 134;
//    delay(100);
//    Serial.println("32");
  }
}

void state134()
{
//  Stall  
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);
//  digitalWrite(L4Vdir, 1);
//  analogWrite(L4Vpwm, stall_base4v-10);

  flag1_down=1;
  flag3_down=1;

  L1_V_MovD_hallD();
  L3_V_MovD_hallD();
  
  if (flag1vd == 1 && flag3vd == 1 && (digitalRead(LS_L1f)==0 || digitalRead(LS_L1b)==0) && (digitalRead(LS_L3f)==0 ||digitalRead(LS_L3b)==0))
  {
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
    analogWrite(L1Vpwm, 0);
    analogWrite(L3Vpwm, 0);
    L1V_sum = 0;
    L3V_sum = 0;
    flag1vd = 0;
    flag3vd = 0;
    flag3_down=0;
    flag1_down=0;
    state = 135;
//    attachInterrupt(digitalPinToInterrupt(L1V_hall), ISR_1V, FALLING);
//    attachInterrupt(digitalPinToInterrupt(L3V_hall), ISR_3V, FALLING);
    flag2vu=0;
    flag4vu=0;

    state=135;

    if(digitalRead(mpu1)==0 && digitalRead(mpu2)==0)
    {
      state =135;
    }
    else
    {

//      state=34;
//      state=0;
         distance1();
          Serial.print("o");
          Serial.print(" ");
          Serial.println(dist);
          if(dist>33)
          {
            state=34;
          }
          else if(dist<=33 && dist>15)
          {
           L1H_diff=map(dist,15,33,40,200);
           L1H_back = L1H_front+L1H_diff;
           L3H_back = L3H_front-L1H_diff;  
           state=34;
           }
          else if(dist<=15)
          {
          state=184;      //sanddune walking
//          state=0;
          right_flag=0;
          left_flag=1;
    //      sanddune_flag=1;
          }
      base1h=0;
      base2h=0;
      turn_flag=1;
    }
   }
}

void state135()
{
/*
  val2v = L2V_up - 80 ;
  val4v = L4V_up - 80 ;
*/
//  Stall
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v-5);
  digitalWrite(L1Vdir, 0);
  analogWrite(L1Vpwm, stall_base1v-5);

  flag2_up=1;
  flag4_up=1;
  
  L2_V_MovUP_hallD();
  L4_V_MovUP_hallD();
 
  if (flag2vu == 1 && flag4vu == 1)
  {
    L2V_sum = 0;
    L4V_sum = 0;
    flag2vu = 0;
    flag4vu = 0;
    flag2_up=0;
    flag4_up=0;   
//    detachInterrupt(digitalPinToInterrupt(L4V_hall));
//    detachInterrupt(digitalPinToInterrupt(L2V_hall));
    
//    analogWrite(L1Vpwm,0);
    analogWrite(L2Vpwm,0);
//    analogWrite(L3Vpwm,0);
    analogWrite(L4Vpwm,0);
    state = 136;
    Serial.println("34");
  }
}

void state136()
{

  val2h = L2H_front;
  val4h = L4H_front;
  val1h = L1H_back;
  val3h = L3H_mid;

  L1_H_Mov(val1h);
  L3_H_Mov(val3h);
  L2_H_Mov(val2h);
  L4_H_Mov(val4h);

//  Stall
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v-5);
//  digitalWrite(L1Vdir, 0);
//  analogWrite(L1Vpwm, stall_base1v-10);
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
    state = 137;
//    delay(50);
//    Serial.println("35");
  }
}

void state137()
{ 
//  Stall
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v-5);
//  digitalWrite(L1Vdir, 0);
//  analogWrite(L1Vpwm, stall_base1v-10);
//  
  flag2_down=1;
  flag4_down=1;
  
  L2_V_MovD_hallD();
  L4_V_MovD_hallD();

  //Serial.println(L1V_err);
  if (flag2vd == 1 && flag4vd == 1 && (digitalRead(LS_L2f)==0 || digitalRead(LS_L2b)==0) && (digitalRead(LS_L4f)==0 ||digitalRead(LS_L4b)==0))
  {
    L2V_sum = 0;
    L4V_sum = 0;
    flag2vd = 0;
    flag4vd = 0;
    analogWrite(L1Vpwm ,0);
    analogWrite(L2Vpwm ,0);
    analogWrite(L3Vpwm ,0);
    analogWrite(L4Vpwm ,0);
    l1h_pwm=0;
    l2h_pwm=0;
    l3h_pwm=0;
    l4h_pwm=0;
    flag2_down=0;
    flag4_down=0; 
//    attachInterrupt(digitalPinToInterrupt(L2V_hall), ISR_2V, FALLING);
//    attachInterrupt(digitalPinToInterrupt(L4V_hall), ISR_4V, FALLING);
    flag1vu=0;
    flag3vu=0;
//    state = 132; 
    if(digitalRead(mpu1)==0 && digitalRead(mpu2)==0)
    {
      state =132; 
    }
    else
    {
//      state = 31
//       state=0;
      
      L1H_pwm_constrain = 160;    
      L2H_pwm_constrain = 160;
      L3H_pwm_constrain = 160;
      L4H_pwm_constrain = 160;      
     distance4();
      Serial.print("f");
      Serial.print(" ");
      Serial.println(dist);
      if(dist>33)
      {
        state=31;
      }
      else if(dist<=33 && dist>15)
      {
       L4H_diff=map(dist,15,33,40,200);
       L2H_back = L2H_front+L4H_diff;
       L4H_back = L4H_front-L4H_diff;  
       state=31;
       }
      else if(dist<=15)
      {
      state=184;      //sanddune walking
//      state=0;
      right_flag=1;
      left_flag=0;
//      sanddune_flag=1;
      }
      base1h=0;
      base2h=0;
        turn_flag=1;
    }
    
//    counter+=1;
//    Serial.println(counter);
//    Serial.println("36");
  }
}
