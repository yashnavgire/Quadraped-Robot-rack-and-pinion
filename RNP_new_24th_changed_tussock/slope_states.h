void state401()
{
  val1h = L1H_back;
  val3h = L3H_back;
  val2h = L2H_back;
  val4h = L4H_back;

 digitalWrite(L3Vdir, 1);
  analogWrite(L3Vpwm, stall_base3v);

  L3_H_MovB(val3h);
  L2_H_MovB(val2h);
  L4_H_MovB(val4h);
  L1_H_MovB(val1h);


  //  Serial.println(L1V_err);
  if (flag1h == 1 && flag3h == 1 && flag2h == 1 && flag4h == 1)
  {
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
    state = 402;
    }
}

void state402()
{
  digitalWrite(L3Vdir, 1);
  analogWrite(L3Vpwm, stall_base3v);
  val2v = L2V_up;
  L2_V_MovUP(val2v);

  if (flag2vu == 1)
  {
    flag2vu = 0;
    L2V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    state = 403;
  }
}

void state403()
{
  digitalWrite(L3Vdir, 1);
  analogWrite(L3Vpwm, stall_base3v);
  L2_H_Mov(L2H_mid);
  if (flag2h == 1)
  {
    flag2h = 0;
    L2H_sum = 0;
    l2h_pwm = 0;
    L2H_initial = analogRead(L2Hpot);
    analogWrite(L2Hpwm, 0);
//    Serial.println("state 83");
    state = 404;
  }
}

void state404()
{
  digitalWrite(L3Vdir, 1);
  analogWrite(L3Vpwm, stall_base3v);
  L2_V_MovD(L2V_downmid);
  if (flag2vd == 1)
  {
    flag2vd = 0;
    L2V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    analogWrite(L3Vpwm,0);
    state = 405;
  }
}
void state405()
{
  // digitalWrite(L3Vdir,1);
  // analogWrite(L3Vpwm,stall_base3v);
//  digitalWrite(L3Vdir, 1);
//  analogWrite(L3Vpwm, stall_base3v);
//  digitalWrite(L2Vdir, 1);
//  analogWrite(L2Vpwm, stall_base2v);
  val1v = L1V_up;
  L1_V_MovUP(val1v);
  if (flag1vu == 1)
  {
    flag1vu = 0;
    L1V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L1Vpwm, 0);
    analogWrite(L2Vpwm, 0);
//    Serial.println("state 85 Done");
    state = 406;
  }
}

void state406()
{
//  digitalWrite(L3Vdir, 1);
//  analogWrite(L3Vpwm, stall_base3v);
//  digitalWrite(L2Vdir, 1);
//  analogWrite(L2Vpwm, stall_base2v);

  L1_H_Mov(L1H_mid);
  if (flag1h == 1)
  {
    flag1h = 0;
    L1H_sum = 0;
    l1h_pwm = 0;
    L1H_initial = analogRead(L1Hpot);
    analogWrite(L1Hpwm, 0);
    //   Serial.println("state 86");
    state = 407;
  }
}

void state407()
{
//  digitalWrite(L3Vdir, 1);
//  analogWrite(L3Vpwm, stall_base3v);
//  digitalWrite(L2Vdir, 1);
//  analogWrite(L2Vpwm, stall_base2v);

  L1_V_MovD(L1V_downmid);
  if (flag1vd == 1)
  {
    flag1vd = 0;
    L1V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L3Vpwm, 0);
    analogWrite(L2Vpwm, 0);
    analogWrite(L1Vpwm, 0);
    //   analogWrite(L3Vpwm,0);
//    Serial.println("state 87");
    state = 408;
  }
}

void state408()
{
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base3v);

  val3v = L3V_up;
  L3_V_MovUP(val3v);

  if (flag3vu == 1)
  {
    flag3vu = 0;
    L3V_sum = 0;
    l3v_pwm = 0;
    analogWrite(L3Vpwm, 0);
//    Serial.println("state 88 Done");
    state = 409;
  }
}

void state409()
{
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base3v);

  L3_H_Mov(L3H_mid);
  if (flag3h == 1)
  {
    flag3h = 0;
    L3H_sum = 0;
    l3h_pwm = 0;
    L3H_initial = analogRead(L3Hpot);
    analogWrite(L3Hpwm, 0);
//    Serial.println("state 89");
    state = 410;
  }
}

void state410()
{
  L3_V_MovD(L3V_downmid);
  if (flag3vd == 1)
  {
    flag3vd = 0;
    L3V_sum = 0;
    l3v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    analogWrite(L3Vpwm, 0);
//    Serial.println("state 90");
    state = 411;
    delay(100);
  }
}


void state411()
{
//  digitalWrite(L3Vdir, 1);
//  analogWrite(L3Vpwm, stall_base3v);

  val4v = L4V_up;
  
  L4_V_MovUP(val4v);

  if (flag4vu == 1)
  {
    flag4vu = 0;
    L4V_sum = 0;
    l4v_pwm = 0;
    analogWrite(L4Vpwm, 0);
//    Serial.println("state 91 Done");
    state = 412;
  }
}

void state412()
{
  L4_H_Mov(L4H_mid);
  if (flag4h == 1)
  {
    flag4h = 0;
    L4H_sum = 0;
    l4h_pwm = 0;
    L4H_initial = analogRead(L4Hpot);
    analogWrite(L4Hpwm, 0);
//    Serial.println("state 92");
    state = 413;
  }
}

void state413()
{
  L4_V_MovD(L4V_downmid);
  if (flag4vd == 1)
  {
//  digitalWrite(L3Vdir, 1);
  analogWrite(L3Vpwm, 0);
    flag4vd = 0;
    L4V_sum = 0;
    l4v_pwm = 0;
    analogWrite(L4Vpwm, 0);
//    Serial.println("state 93");
    delay(200);
    state = 401;
  }
}
