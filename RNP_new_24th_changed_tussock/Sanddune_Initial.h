/* Contains state151() to state156()*/

////////////////////////////use this when sanddune is mapped with 2 and 4 at front/////////////////////////
void state151()
{
  Serial.println("Sandune initial Entered");
  flag1_up=1;
  flag3_up=1;
  L1_V_MovUP_hallD();
  L3_V_MovUP_hallD();
  // digitalWrite(L2Vdir,1);
  // analogWrite(L2Vpwm,stall_base2v);
  // digitalWrite(L3Vdir,1);
  // analogWrite(L3Vpwm,stall_base3v);
  if (flag1vu == 1 && flag3vu == 1)
  {
    flag1_up=0;
    flag3_up=0;
    flag1vu = 0;
    flag3vu=0;
    analogWrite(L1Vpwm, 0);
    state = 152;
  }
}

void state152()
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
    state = 153;
  }
}

void state153()
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
    state = 170;
  }
}


////////////////////////////use this when sanddune is mapped with 1 and 3 at front///////////////////////// 
void state154()
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
    flag2vu = 0;
    flag2_up=0;
    flag4_up=0;
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
    state = 155;
  }
}

void state155()
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
    state = 156;
  }
}

void state156()
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
