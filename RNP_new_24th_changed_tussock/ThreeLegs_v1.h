
////////////////////normal walking initial/////////////////
void state1()
{
//  val1v = L1V_up;
  
  L1_V_MovUP(L1V_up_sand);
  if (flag1vu == 1)
  {
    flag1vu = 0;
    L1V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L1Vpwm, 0);
    state = 2;
  }
} 

void state2()
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
    state = 3;
  }
}

void state3()
{
  //  L1_V_MovLS(L1V_down);
  L1_V_MovD(L1V_down);

  if (flag1vd == 1)
  {
    flag1vd = 0;
    L1V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L1Vpwm, 0);
    analogWrite(L2Vpwm, 0);
    state = 4;
  }
}

void state4()
{
//  val2v = L2V_up;
//  L2_V_MovUP(val2v);
// Serial.println("state34");
//  digitalWrite(L3Vdir, 1);
//  analogWrite(L3Vpwm, stall_base3v);

L2_V_MovUP(L2V_up_sand);

  if (flag2vu == 1)
  {
    flag2vu = 0;
    L2V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    state = 5;
  }
}

void state5()
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
    state = 6;
  }
}

void state6()
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
    state = 7;
  }
}


void state7()
{
//  val3v = L3V_up;
//  L3_V_MovUP(val3v);
//  digitalWrite(L2Vdir, 1);
//  analogWrite(L2Vpwm, stall_base2v);

L3_V_MovUP(L3V_up_sand);
  //  Serial.println("state27");
  if (flag3vu == 1)
  {
    flag3vu = 0;
    L3V_sum = 0;
    l3v_pwm = 0;
    analogWrite(L3Vpwm, 0);
    state = 8;
  }
}


void state8()
{
  L3_H_Mov(L3H_front);
//  digitalWrite(L2Vdir, 1);
//  analogWrite(L2Vpwm, stall_base2v);

  if (flag3h == 1)
  {
    flag3h = 0;
    L3H_sum = 0;
    l3h_pwm = 0;
    L3H_initial = analogRead(L3Hpot);
    analogWrite(L3Hpwm, 0);
    state = 9;
    //   delay(200);
  }
}


void state9()
{
  //  L3_V_MovLS(L3V_down);
  L3_V_MovD(L3V_down);
  //  Serial.println("state29");
//  digitalWrite(L2Vdir, 1);
//  analogWrite(L2Vpwm, stall_base2v);

  if (flag3vd == 1)
  {
    flag3vd = 0;
    L3V_sum = 0;
    l3v_pwm = 0;
    analogWrite(L3Vpwm, 0);
    state = 10;
    //   delay(200);
    digitalWrite(L2Vdir, 0);
    analogWrite(L2Vpwm, 0);

  }
}

void state10()
{
//  val4v = L4V_up;
//  L4_V_MovUP(val4v);
  // digitalWrite(L2Vdir,1);
//  // analogWrite(L2Vpwm,stall_base2v);
//  digitalWrite(L3Vdir, 1);
//  analogWrite(L3Vpwm, stall_base3v);


L4_V_MovUP(L4V_up_sand);

if (flag4vu == 1)
  {
    flag4vu = 0;
    L4V_sum = 0;
    l4v_pwm = 0;
    analogWrite(L4Vpwm, 0);
    state = 11;
  }
}


void state11()
{
  L4_H_Mov(L4H_front);
  if (flag4h == 1)
  {
    flag4h = 0;
    L4H_sum = 0;
    l4h_pwm = 0;
    L4H_initial = analogRead(L4Hpot);
    analogWrite(L4Hpwm, 0);
    state = 12;
  }
}


void state12()
{
  L4_V_MovD(L4V_down);

  digitalWrite(L2Vdir, 0);
  analogWrite(L2Vpwm, 0);
  digitalWrite(L3Vdir, 1);
  analogWrite(L3Vpwm, 0);

  //  Serial.println("state32");
  if (flag4vd == 1)
  {
    flag4vd = 0;
    L4V_sum = 0;
    l4v_pwm = 0;
    analogWrite(L4Vpwm, 0);  
    analogWrite(L3Vpwm, 0);

    state = 15;
  }
}



/* Contains from state15 to 27*/

void normal_conditions()
{
 L1V_up = L1V_down-80;
L2V_up =L2V_down+70;
L3V_up = L3V_down-70;
L4V_up = L4V_down+100;


L4H_pwm_constrain = 180;
L4V_up_constrain = 200;
L4V_down_constrain = 150;

L1H_pwm_constrain = 180;
L1V_up_constrain = 200;
L1V_down_constrain = 150;

L2H_pwm_constrain = 180;
L2V_up_constrain = 200;
L2V_down_constrain = 150;

L3H_pwm_constrain = 180;
L3V_up_constrain = 200;
L3V_down_constrain = 150;

}

void state15()
{
  val1h = L1H_back;
  val3h = L3H_back;
  val2h = L2H_back;
  val4h = L4H_back;

  L1_H_Mov(val1h);
  L3_H_Mov(val3h);
  L2_H_Mov(val2h);
  L4_H_Mov(val4h);

    Serial.println(L1V_err);
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
    state = 16;
    }
}


void state16()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v);
  val2v = L2V_up_sand;
  L2_V_MovUP(val2v);

  if (flag2vu == 1)
  {
    flag2vu = 0;
    L2V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    state = 17;
  }
}

void state17()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v);
  L2_H_Mov(L2H_front);
  if (flag2h == 1)
  {
    flag2h = 0;
    L2H_sum = 0;
    l2h_pwm = 0;
    L2H_initial = analogRead(L2Hpot);
    analogWrite(L2Hpwm, 0);
//    Serial.println("state 83");
    state = 18;
  }
}

void state18()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v);
  L2_V_MovD(L2V_down);
  if (flag2vd == 1)
  {
    flag2vd = 0;
    L2V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    analogWrite(L3Vpwm,0);
    state = 19;
  }
}
void state19()
{
  // digitalWrite(L3Vdir,1);
  // analogWrite(L3Vpwm,stall_base3v);
//  digitalWrite(L3Vdir, 1);
//  analogWrite(L3Vpwm, stall_base3v);
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v);
  val1v = L1V_up_sand;
  L1_V_MovUP(val1v);
  if (flag1vu == 1)
  {
    flag1vu = 0;
    L1V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L1Vpwm, 0);
    analogWrite(L2Vpwm, 0);
//    Serial.println("state 85 Done");
    state = 20;
  }
}

void state20()
{
//  digitalWrite(L3Vdir, 1);
//  analogWrite(L3Vpwm, stall_base3v);
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v);

  L1_H_Mov(L1H_front);
  if (flag1h == 1)
  {
    flag1h = 0;
    L1H_sum = 0;
    l1h_pwm = 0;
    L1H_initial = analogRead(L1Hpot);
    analogWrite(L1Hpwm, 0);
    //   Serial.println("state 86");
    state = 21;
  }
}

void state21()
{
//  digitalWrite(L3Vdir, 1);
//  analogWrite(L3Vpwm, stall_base3v);
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v);

  L1_V_MovD(L1V_down);
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
    state = 22;
    delay(20);
  }
}

void state22()
{
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base3v);

  val3v = L3V_up_sand;
  L3_V_MovUP(val3v);

  if (flag3vu == 1)
  {
    flag3vu = 0;
    L3V_sum = 0;
    l3v_pwm = 0;
    analogWrite(L3Vpwm, 0);
//    Serial.println("state 88 Done");
    state = 23;
  }
}

void state23()
{
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base3v);

  L3_H_Mov(L3H_front);
  if (flag3h == 1)
  {
    flag3h = 0;
    L3H_sum = 0;
    l3h_pwm = 0;
    L3H_initial = analogRead(L3Hpot);
    analogWrite(L3Hpwm, 0);
//    Serial.println("state 89");
    state = 24;
  }
}

void state24()
{
  L3_V_MovD(L3V_down);
  if (flag3vd == 1)
  {
    flag3vd = 0;
    L3V_sum = 0;
    l3v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    analogWrite(L3Vpwm, 0);
//    Serial.println("state 90");
    state = 25;
    delay(20);
  }
}


void state25()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v-5);

  val4v = L4V_up_sand;
  
  L4_V_MovUP(val4v);

  if (flag4vu == 1)
  {
    flag4vu = 0;
    L4V_sum = 0;
    l4v_pwm = 0;
    analogWrite(L4Vpwm, 0);
//    Serial.println("state 91 Done");
    state = 26;
  }
}

void state26()
{
  L4_H_Mov(L4H_front);
  if (flag4h == 1)
  {
    flag4h = 0;
    L4H_sum = 0;
    l4h_pwm = 0;
    L4H_initial = analogRead(L4Hpot);
    analogWrite(L4Hpwm, 0);
//    Serial.println("state 92");
    state = 27;
  }
}

void state27()
{
  L4_V_MovD(L4V_down);
  if (flag4vd == 1)
  {
//  digitalWrite(L3Vdir, 1);
  analogWrite(L3Vpwm, 0);
    flag4vd = 0;
    L4V_sum = 0;
    l4v_pwm = 0;
    analogWrite(L4Vpwm, 0);
    analogWrite(L3Vpwm, 0);
//    Serial.println("state 93");
    delay(20);
    state = 15;
/*
    counter = counter + 1;
    Serial.print("Counter ");
    Serial.println(counter);
    
    if (counter == countThres)
    {
      counter=0;
      angle = getDMPAngle('y');
      Serial.print("Angle in Straight Walk  ");
      Serial.println(angle);
      if (angle > angle_thrs_left && angle_thrs_left==-45)
     {
      state = 101;          //left turn initial
      Serial.println("*** TURN INITIAL ***");
      L1V_down_constrain = 100;
      L2V_down_constrain = 100;   
      angle_thrs_left=-45;
//      counter=0;
     }
     else if (angle < angle_thrs_left && angle_thrs_left==0) //angle_thrs_left updated to zero,after taking left -60.
     {
      state=301;                              //right turn
      Serial.println("*** Right TURN INITIAL ***");
      L3V_down_constrain = 100;
      L4V_down_constrain = 100;      
     }
    else
    {
    state = 171;          //sandune walking
    turn_flag=1;
    sanddune_flag=1;
    Serial.println("*** SANDDUNE ***")  ;
    }
  }

   else if(turn_flag==1)
  {
      distance();
      Serial.println(dist);
      if(dist>25)
      {
        state=15;
      }
      else if(dist<=25 && dist>6)
      {
     L1H_diff=map(dist,6,25,40,180);
     L1H_back = L1H_front+L1H_diff;
     L2H_back = L2H_front+L1H_diff;
     L3H_back = L3H_front-L1H_diff;
     L4H_back = L4H_front-L1H_diff;  
     state=15;
      }
      else if(dist<=6)
      {
      state=171;      //sanddune walking
      sanddune_flag=1;
      }
  }*/
 }
}
