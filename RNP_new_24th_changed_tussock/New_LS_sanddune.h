/* Contains from state170
   sanddune_walking : 171-183  
*/  
/****************************************************************************/

void state170()
{
//  val1h = L1H_front;
//  val3h = L3H_front;
//  val2h = L2H_front;
//  val4h = L4H_front;

  flag1_down=1;    flag2_down=1;    flag3_down=1;    flag4_down=1;
  hall_count1v=1;  hall_count2v=1;  hall_count3v=1;  hall_count4v=1; 
  L1_V_MovDSD();
  L2_V_MovDSD();
  L3_V_MovDSD();
  L4_V_MovDSD();
//  
//  L1_H_Mov(val1h);
//  L3_H_Mov(val3h);
//  L2_H_Mov(val2h);
//  L4_H_Mov(val4h);

}

void state171()
{
 /* 
   if(sanddune_flag==1)
     {
      L1V_down_constrain = 150;
      L2V_down_constrain = 150;
      L3V_down_constrain = 150;
      L4V_down_constrain = 150;

      L1H_pwm_constrain = 180;
      L2H_pwm_constrain = 180;
      L3H_pwm_constrain = 180;
      L4H_pwm_constrain = 180;
      sanddune_flag= 0;
     }
*/
      val1h = L1H_back;
      val3h = L3H_back;
      val2h = L2H_back;
      val4h = L4H_back;

      L1_H_Mov(val1h);
      L3_H_Mov(val3h);
      L2_H_Mov(val2h);
      L4_H_Mov(val4h);
    
  if (flag1h == 1 && flag3h == 1 && flag2h == 1 && flag4h == 1)
  {
    attachInterrupt(digitalPinToInterrupt(L2V_hall), ISR_2V, FALLING);
    
    l1h_pwm = 0;
    l2h_pwm = 0;
    l3h_pwm = 0;
    l4h_pwm = 0;
    L1H_sum = 0;
    L3H_sum = 0;
    L2H_sum = 0;
    L4H_sum = 0;
    flag1h = 0;
    flag3h = 0;
    flag2h = 0;
    flag4h = 0;
    analogWrite(L4Hpwm, 0);
    analogWrite(L1Hpwm, 0);
    analogWrite(L2Hpwm, 0);
    analogWrite(L3Hpwm, 0);
    L1H_initial = analogRead(L1Hpot);
    L2H_initial = analogRead(L2Hpot);
    L3H_initial = analogRead(L3Hpot);
    L4H_initial = analogRead(L4Hpot);
    state = 172;
//    Serial.println("state 171 done");
//    hall_count1v=0;
//    hall_count2v=0;
//    hall_count3v=0;
//    hall_count4v=0;             //leg at 26cm(sanddune down)
  }
}

void state172()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v-5);

  flag2_up=1;
  if(sanddune_counter>=2)
  {
  L2_V_MovSU();
  L2V_down_constrain = 50;
  }
  else
  {
    L2_V_MovUP_hallD();   
    L2V_down_constrain = 120; 
  }
  
  if (flag2vu == 1)
  {
    flag2vu = 0;
    flag2_up=0;
    analogWrite(L2Vpwm, 0);
//    Serial.println("state 172 Done");
    state = 173;
//    hall_count2v=2;            // sandune up -> leg at around 11cm   
  }
}

void state173()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v-5);
  L2_H_Mov(L2H_front);
  if (flag2h == 1)
  {
    flag2h = 0;
    L2H_sum = 0;
    l2h_pwm = 0;
    L2H_initial = analogRead(L2Hpot);
    analogWrite(L2Hpwm, 0);
//    Serial.println("state 83");
    state = 174;
  }
}

void state174()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v-5);
  flag2_down=1;
  L2_V_MovSD();
  if (flag2vd == 1)
  {
    detachInterrupt(digitalPinToInterrupt(L2V_hall));
    attachInterrupt(digitalPinToInterrupt(L1V_hall), ISR_1V, FALLING);
    flag2vd = 0;
    flag2_down=0;
//    hall_count2v=0;                     // not to be made zero ,here last state is important for further up_state for this leg                 
    analogWrite(L2Vpwm, 0);
    analogWrite(L3Vpwm,0);
//    Serial.println("state 175");
//    delay(100);
    state = 175;
  }
}

void state175()
{
  // digitalWrite(L3Vdir,1);
  // analogWrite(L3Vpwm,stall_base3v);
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);
  flag1_up=1;
  if(sanddune_counter>2)
  {
  L1_V_MovUP_hallD();
  L1V_down_constrain = 120;
  }
  else
  {
    L1_V_MovSU();
    L1V_down_constrain = 60;  
  }
//  Serial.println("1v");
  if (flag1vu == 1)
  {
    flag1vu = 0;
    flag1_up=0;
//    hall_count1v=2;
    analogWrite(L1Vpwm, 0);
//    Serial.println("state 85 Done");
    state = 176;
  }
}

void state176()
{
//  digitalWrite(L3Vdir, 1);
////  analogWrite(L3Vpwm, stall_base3v);
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);

  L1_H_Mov(L1H_front);
  if (flag1h == 1)
  {
    flag1h = 0;
    L1H_sum = 0;
    l1h_pwm = 0;
    L1H_initial = analogRead(L1Hpot);
    analogWrite(L1Hpwm, 0);
//       Serial.println("state 86");
    state = 177;
    //////delay(500);
  }
}

void state177()
{
//  digitalWrite(L3Vdir, 1);
//  analogWrite(L3Vpwm, stall_base3v);
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);
   flag1_down=1;
   L1_V_MovSD();                 
  if (flag1vd == 1)
  {
    detachInterrupt(digitalPinToInterrupt(L1V_hall));
    attachInterrupt(digitalPinToInterrupt(L3V_hall), ISR_3V, FALLING);
    flag1vd = 0;
    flag1_down=0;
//    hall_count1v=0;                         // not to be made zero ,here last state is important for further up_state for this leg
    delay(50);
    analogWrite(L3Vpwm, 0);
    analogWrite(L2Vpwm, 0);
    analogWrite(L1Vpwm, 0);
    //   analogWrite(L3Vpwm,0);
//    Serial.println("state 87");
    state = 178;
    //////delay(500);
  }
}

void state178()
{
    digitalWrite(L2Vdir, 1);
    analogWrite(L2Vpwm, stall_base2v-5);
    flag3_up=1;
    if(sanddune_counter>=2)
    {
      L3_V_MovSU();
      L3V_down_constrain = 60;
    }
    else
    {
      L3V_down_constrain = 120;
      L3_V_MovUP_hallD();   
    }
  if (flag3vu == 1)
  {
    flag3vu = 0;
    flag3_up=0;
//    hall_count3v=2;
    analogWrite(L3Vpwm, 0);
//    Serial.println("state 88 Done");
    state = 179;
    //////delay(500);
  }
}

void state179()
{
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);

  L3_H_Mov(L3H_front);
  if (flag3h == 1)
  {
    flag3h = 0;
    L3H_sum = 0;
    l3h_pwm = 0;
    L3H_initial = analogRead(L3Hpot);
    analogWrite(L3Hpwm, 0);
//    Serial.println("state 89");
    state = 180;
    //////delay(500);
  }
}

void state180()
{
  
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);

  flag3_down=1;
  L3_V_MovSD();
  
  if (flag3vd == 1)
  {
    attachInterrupt(digitalPinToInterrupt(L4V_hall), ISR_4V, FALLING);
    detachInterrupt(digitalPinToInterrupt(L3V_hall));
    flag3vd = 0;
    flag3_down=0;
//    hall_count3v=0;           // not to be made zero ,here last state is important for further up_state for this leg
    analogWrite(L2Vpwm, 0);
    analogWrite(L3Vpwm, 0);
//    Serial.println("state 90");
    state = 181;
//    delay(100);
//////delay(500);

  }
}


void state181()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v);

    flag4_up=1;
   if(sanddune_counter>2)
   {
      L4_V_MovUP_hallD();
      L4V_down_constrain = 120;
   }
  else
  {
    L4_V_MovSU();  
    L4V_down_constrain = 50;
  }
//    Serial.println("181");
  if (flag4vu == 1)
  {
    flag4vu = 0;
    flag4_up=0;
//    hall_count4v=2;
    analogWrite(L4Vpwm, 0);
//    Serial.println("state 91 Done");
    state = 182;
    //////delay(500);
  }
}

void state182()
{
  
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v);
  
  L4_H_Mov(L4H_front);
  if (flag4h == 1)
  {
    flag4h = 0;
    L4H_sum = 0;
    l4h_pwm = 0;
    L4H_initial = analogRead(L4Hpot);
    analogWrite(L4Hpwm, 0);
//    Serial.println("state 92");
    state = 183;
    //////delay(500);
  }
}

void state183()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v);
  flag4_down=1;
  L4_V_MovSD();
  if (flag4vd == 1)
  {
  detachInterrupt(digitalPinToInterrupt(L4V_hall));
  attachInterrupt(digitalPinToInterrupt(L2V_hall), ISR_2V, FALLING);
  analogWrite(L3Vpwm, 0);
    flag4vd = 0;
    analogWrite(L4Vpwm, 0);
//    Serial.println("state 93");
    flag4_down=0;               // not to be made zero ,here last state is important for further up_state for this leg
//    hall_count4v=0;
    state = 171;
    delay(50);
    sanddune_counter++;
//    Serial.print("SD Counter = ");
//    Serial.println(sanddune_counter);
  /* if(sanddune_counter==5)
    {
      turn_flag = 0;
      turnAngleFlag = 0;
      state=201;                //left turn 60 initial
      sanddune_counter=0;
    }*/  
 }
}
