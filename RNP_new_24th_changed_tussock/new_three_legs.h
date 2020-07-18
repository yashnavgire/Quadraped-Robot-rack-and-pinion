    void state25()
{
  L2_H_Mov(L2H_front);
  L4_H_Mov(L4H_mid);
  L1_H_Mov(L1H_front);
  L3_H_Mov(L3H_mid);

  L1_V_MovD(L1V_down);
  L2_V_MovD(L2V_down);
  L3_V_MovD(L3V_down);
  L4_V_MovD(L4V_down);
delay(20);
  //  if (flag1h == 1 && flag3h == 1 && flag2h == 1 && flag4vd == 1 && flag1vd == 1 && flag3vd == 1 && flag2vd == 1 && flag4h == 1)
  //  {
  //    l1h_pwm = 0;
  //    l2h_pwm = 0;
  //    l3h_pwm = 0;
  //    l4h_pwm = 0;
  //    L1H_sum = 0;
  //    L3H_sum = 0;
  //    L2H_sum = 0;
  //    L4H_sum = 0;
  //
  //
  //    //        delay(5000);
  //    //        state=26;
  //  }
  //  else
  //  {
  //    L2_H_Mov(L2H_front);
  //    L4_H_Mov(L4H_mid);
  //    L1_H_Mov(L1H_front);
  //    L3_H_Mov(L3H_mid);
  //
  //    L1_V_MovD(L1V_down);
  //    L2_V_MovD(L2V_down);
  //    L3_V_MovD(L3V_down);
  //    L4_V_MovD(L4V_down);
  //  }
}




void state500()
{
  // Serial.print("state26");

  if(sanddune_flag==1)
     {
      L1V_down_constrain = 120;
      L2V_down_constrain = 120;
      L3V_down_constrain = 120;
      L4V_down_constrain = 120;
//
//      L1H_pwm_constrain = 120;
//      L2H_pwm_constrain = 150;
//      L3H_pwm_constrain = 120;
//      L4H_pwm_constrain = 120;

      
      L1H_back = L1H_front+250;
      L2H_back = L2H_front+250;
      L3H_back = L3H_front-230;
      L4H_back = L4H_front-230;  
     
      L1V_up_sand=L1V_down-215;
      L2V_up_sand=L2V_down+215;
      L3V_up_sand=L3V_down-215;
      L4V_up_sand=L4V_down+215;
      sanddune_flag=0;
     }

  val1h = L1H_mid;
  val2h = L2H_mid;
  val3h = L3H_back;
  val4h = L4H_back;

  L1_H_Mov(val1h);
  L3_H_Mov(val3h);
  L2_H_Mov(val2h);
  L4_H_Mov(val4h);


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
    l1h_pwm = 0;
    l2h_pwm = 0;
    l3h_pwm = 0;
    l4h_pwm = 0;
    L1H_initial = analogRead(L1Hpot);
    L2H_initial = analogRead(L2Hpot);
    L3H_initial = analogRead(L3Hpot);
    L4H_initial = analogRead(L4Hpot);
    analogWrite(L4Hpwm, 0);
    analogWrite(L1Hpwm, 0);
    analogWrite(L2Hpwm, 0);
    analogWrite(L3Hpwm, 0);
    state = 501;
    //delay(200);
  }
}


void state501()
{
  val3v = L3V_up_sand;
  L3_V_MovUP(val3v);
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v);


  //  Serial.println("state27");
  if (flag3vu == 1)
  {
    flag3vu = 0;
    L3V_sum = 0;
    l3v_pwm = 0;
    analogWrite(L3Vpwm, 0);
    state = 502;
  }
}


void state502()
{
  L3_H_Mov(L3H_front);
  // Serial.println("state28");
  // Serial.print(" ");
  // Serial.print("L3H ");
  // Serial.print(L3H_err);
  // Serial.print(" ");
  // Serial.println(l3h_pwm);
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v);

  if (flag3h == 1)
  {
    flag3h = 0;
    L3H_sum = 0;
    l3h_pwm = 0;
    L3H_initial = analogRead(L3Hpot);
    analogWrite(L3Hpwm, 0);
    state = 503;
    //   delay(200);
  }
}


void state503()
{
  //  L3_V_MovLS(L3V_down);
  L3_V_MovD(L3V_down);
  //  Serial.println("state29");
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v);

  if (flag3vd == 1)
  {
    flag3vd = 0;
    L3V_sum = 0;
    l3v_pwm = 0;
    analogWrite(L3Vpwm, 0);
    state = 504;
    //   delay(200);
    digitalWrite(L2Vdir, 0);
    analogWrite(L2Vpwm, 0);

  }
}


void state504()
{
  val4v = L4V_up_sand;
  L4_V_MovUP(val4v);

  // digitalWrite(L2Vdir,1);
  // analogWrite(L2Vpwm,stall_base2v);
  digitalWrite(L3Vdir, 1);
  analogWrite(L3Vpwm, stall_base3v);

  // Serial.println("state30");
  if (flag4vu == 1)
  {
    flag4vu = 0;
    L4V_sum = 0;
    l4v_pwm = 0;
    analogWrite(L4Vpwm, 0);
    state = 505;
  }
}


void state505()
{
  L4_H_Mov(L4H_front);
  // Serial.println("state31");
  // Serial.print(" ");
  // Serial.print("L4H ");
  // Serial.print(L4H_err);
  // Serial.print(" ");
  // Serial.println(l4h_pwm);
  //
  if (flag4h == 1)
  {
    flag4h = 0;
    L4H_sum = 0;
    l4h_pwm = 0;
    L4H_initial = analogRead(L4Hpot);
    analogWrite(L4Hpwm, 0);
    state = 506;
  }
}


void state506()
{
  //  L4_V_MovLS(L4V_down);
  L4_V_MovD(L4V_down);

  
  //  Serial.println("state32");
  if (flag4vd == 1)
  {
    flag4vd = 0;
    L4V_sum = 0;
    l4v_pwm -= 0;
    analogWrite(L4Vpwm, 0);
    state = 507;
    delay(50);
  }
}

void state507()
{
  // Serial.print("state33");
  val1h = L1H_back;
  val2h = L2H_back;
  val3h = L3H_mid;
  val4h = L4H_mid;

  L1_H_Mov(val1h);
  L3_H_Mov(val3h);
  L2_H_Mov(val2h);
  L4_H_Mov(val4h);


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
    l1h_pwm = 0;
    l2h_pwm = 0;
    l3h_pwm = 0;
    l4h_pwm = 0;
    L1H_initial = analogRead(L1Hpot);
    L2H_initial = analogRead(L2Hpot);
    L3H_initial = analogRead(L3Hpot);
    L4H_initial = analogRead(L4Hpot);
    analogWrite(L4Hpwm, 0);
    analogWrite(L1Hpwm, 0);
    analogWrite(L2Hpwm, 0);
    analogWrite(L3Hpwm, 0);
    state = 508;
  }
}


void state508()
{
  val2v = L2V_up_sand;
  L2_V_MovUP(val2v);
  // Serial.println("state34");
  digitalWrite(L3Vdir, 1);
  analogWrite(L3Vpwm, stall_base3v);


  if (flag2vu == 1)
  {
    flag2vu = 0;
    L2V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    state = 509;
  }
}

void state509()
{
  L2_H_Mov(L2H_front);
  // Serial.println("state35");
  // Serial.print(" ");
  // Serial.print("L2H ");
  // Serial.print(L2H_err);
  // Serial.print(" ");
  // Serial.println(l2h_pwm);

  if (flag2h == 1)
  {
    flag2h = 0;
    L2H_sum = 0;
    l2h_pwm = 0;
    L2H_initial = analogRead(L2Hpot);
    analogWrite(L2Hpwm, 0);
    state = 510;
  }
}

void state510()
{
  //  L2_V_MovLS(L2V_down);
  L2_V_MovD(L2V_down);
  digitalWrite(L3Vdir, 1);
  analogWrite(L3Vpwm, 0);
  
  //  L2_V_MovNLS(L2V_down);
  //  Serial.println("state36");
  if (flag2vd == 1)
  {
    flag2vd = 0;
    L2V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    state = 511;
    delay(10);
  }
}

void state511()
{
  val1v = L1V_up_sand;
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
    state = 512;
    delay(10);
  }
}

void state512()
{
  L1_H_Mov(L1H_front);

  // digitalWrite(L2Vdir,1);
  // analogWrite(L2Vpwm,stall_base2v);
  if (flag1h == 1)
  {
    flag1h = 0;
    L1H_sum = 0;
    l1h_pwm = 0;
    L1H_initial = analogRead(L1Hpot);
    analogWrite(L1Hpwm, 0);
    state = 513;
  }
}

void state513()
{
  //  L1_V_MovLS(L1V_down);
  L1_V_MovD(L1V_down);
  digitalWrite(L2Vdir, 0);
  analogWrite(L2Vpwm, 0);
  digitalWrite(L3Vdir, 1);
  analogWrite(L3Vpwm, 0);

  //  L1_V_MovNLS(L1V_down);
  //  Serial.println("state39");
  //  digitalWrite(L2Vdir,0);
  //  analogWrite(L2Vpwm,stall_base2v);

  if (flag1vd == 1)
  {
    flag1vd = 0;
    L1V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L1Vpwm, 0);
    analogWrite(L2Vpwm, 0);
    state = 500;
    counter = counter + 1;
    delay(50);
    Serial.print("Counter ");
    Serial.print(counter);
    //    Serial.print(" Angle ");
    // angle=getDMPAngle('y');
  
    }
 }
