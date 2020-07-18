/*diagonal full rack : 31 - 36
 * diagonal half rack : 40 -46
 * initial state: L1 & L3 back ; L2 & L4 Front
 */
 
 void state31()
{
  
  flag2_up=1;
  flag4_up=1;
  
  L2_V_MovUP_hallD();
  L4_V_MovUP_hallD();

//  Stall
  digitalWrite(L3Vdir, 1);
  analogWrite(L3Vpwm, stall_base3v-5);
//  digitalWrite(L4Vdir, 1);
//  analogWrite(L4Vpwm, stall_base4v-10);

//  Serial.println("31");
  if (flag2vu == 1 && flag4vu == 1)
  {
    L2V_sum = 0;
    L4V_sum = 0;
    flag2vu = 0;
    flag4vu = 0;
    flag4_up=0;
    flag2_up=0;
//    analogWrite(L4Vpwm, 0);
//    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm,0);
    analogWrite(L2Vpwm,0);
//    detachInterrupt(digitalPinToInterrupt(L1V_hall));
//    detachInterrupt(digitalPinToInterrupt(L3V_hall));
    state = 32;
  }
}

void state32()
{
  val1h = L1H_back;
  val3h = L3H_back;
  val2h = L2H_front;
  val4h = L4H_front;

//  Stall
  digitalWrite(L3Vdir, 1);
  analogWrite(L3Vpwm, stall_base3v-5);
//  digitalWrite(L4Vdir, 1);
//  analogWrite(L4Vpwm, stall_base4v-10);

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
    state = 33;
    
//    delay(100);
//    Serial.println("32");
  }
}

void state33()
{
//  Stall  
  digitalWrite(L3Vdir, 1);
  analogWrite(L3Vpwm, stall_base3v-5);
//  digitalWrite(L4Vdir, 1);
//  analogWrite(L4Vpwm, stall_base4v-10);

  flag2_down=1;
  flag4_down=1;

  L2_V_MovD_hallD();
  L4_V_MovD_hallD();
  
  if (flag2vd == 1 && flag4vd == 1 && (digitalRead(LS_L2f)==0 || digitalRead(LS_L2b)==0) && (digitalRead(LS_L4f)==0 ||digitalRead(LS_L4b)==0))
  {
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
    analogWrite(L1Vpwm, 0);
    analogWrite(L3Vpwm, 0);
    L1V_sum = 0;
    L3V_sum = 0;
    flag2vd = 0;
    flag4vd = 0;
    flag2_down= 0;
    flag4_down= 0;
    state = 34;
//    attachInterrupt(digitalPinToInterrupt(L1V_hall), ISR_1V, FALLING);
//    attachInterrupt(digitalPinToInterrupt(L3V_hall), ISR_3V, FALLING);
    
// counter++;
//    if(counter==countThres && turn_flag==0)
//    {
//      counter=0;
//      state= 132;
//    }
        if(turn_flag==1)
        {
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
           L1H_diff=map(dist,15,33,40,180);
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
//          sanddune_flag=1;
          }
        }
   }
}


void state34()
{
/*
  val2v = L2V_up - 80 ;
  val4v = L4V_up - 80 ;
*/
//  Stall
  digitalWrite(L2Vdir, 0);
  analogWrite(L2Vpwm, stall_base2v-5);
//  digitalWrite(L1Vdir, 0);
//  analogWrite(L1Vpwm, stall_base1v-5);


  flag1_up=1;
  flag3_up=1;
  
  L1_V_MovUP_hallD();
  L3_V_MovUP_hallD();
 
  if (flag1vu == 1 && flag3vu == 1)
  {
//    L1V_sum = 0;
//    L3V_sum = 0;
    flag1vu = 0;
    flag3vu = 0;
    flag1_up=0;
    flag3_up=0;   
//    detachInterrupt(digitalPinToInterrupt(L4V_hall));
//    detachInterrupt(digitalPinToInterrupt(L2V_hall));
    
//    analogWrite(L1Vpwm,0);
    analogWrite(L1Vpwm,0);
//    analogWrite(L3Vpwm,0);
    analogWrite(L3Vpwm,0);
    state = 35;
//    Serial.println("34");
  }
}

void state35()
{

  val2h = L2H_back;
  val4h = L4H_back;
  val1h = L1H_front;
  val3h = L3H_front;

  L1_H_Mov(val1h);
  L3_H_Mov(val3h);
  L2_H_Mov(val2h);
  L4_H_Mov(val4h);

//  Stall
  digitalWrite(L2Vdir, 0);
  analogWrite(L2Vpwm, stall_base2v-5);
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
    state = 36;
  }
}

void state36()
{ 
//  Stall
  digitalWrite(L2Vdir, 0);
  analogWrite(L2Vpwm, stall_base2v-5);
//  digitalWrite(L1Vdir, 0);
//  analogWrite(L1Vpwm, stall_base1v-10);
//  
  flag1_down=1;
  flag3_down=1;
  
  L1_V_MovD_hallD();
  L3_V_MovD_hallD();

  if (flag1vd == 1 && flag3vd == 1 && (digitalRead(LS_L1f)==0 || digitalRead(LS_L1b)==0) && (digitalRead(LS_L3f)==0 ||digitalRead(LS_L3b)==0))
  {
//    L2V_sum = 0;
//    L4V_sum = 0;
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
    flag1_down=0;
    flag3_down=0; 
//    attachInterrupt(digitalPinToInterrupt(L2V_hall), ISR_2V, FALLING);
//    attachInterrupt(digitalPinToInterrupt(L4V_hall), ISR_4V, FALLING);
   
    state = 31; 
//    delay(50);
    counter++;
    if(counter==countThres && turn_flag==0)
    {
      counter=0;
      state= 132;
    }
    else if(turn_flag==1)
    {
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
       L4H_diff=map(dist,15,33,40,180);
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
    }
  }
}





/*
* States 41 - 46 
* Diagonal Pattern using just half the rack - to avoid toppling
* 40 - initial state
*/

void state40()
{
  L2_H_Mov2(L2H_front);
  L4_H_Mov2(L4H_mid);
  L1_H_Mov2(L1H_back);
  L3_H_Mov2(L3H_mid);

  L1_V_MovD(L1V_down);
  L2_V_MovD(L2V_down);
  L3_V_MovD(L3V_down);
  L4_V_MovD(L4V_down);
}

void state41()
{
  /*
    val1v = L1V_up - 80;
    val3v = L3V_up - 80;
  */
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);
  digitalWrite(L4Vdir, 1);
  analogWrite(L4Vpwm, stall_base4v-10);
//
//  val1v = L1V_up;
//  val3v = L3V_up;
  L1_V_MovUP(L1V_up);
  L3_V_MovUP(L3V_up);

  if (flag1vu == 1 && flag3vu == 1)
  {
    
    L1V_sum = 0;
    L3V_sum = 0;
    flag1vu = 0;
    flag3vu = 0;
    analogWrite(L4Vpwm, 0);
    analogWrite(L2Vpwm, 0);
    analogWrite(L1Vpwm,0);
    analogWrite(L3Vpwm,0);
    state = 42;
//      L1H_pwm_constrain = 130;
     
    }
}

void state42()
{
//
//  val1h = L1H_front;
//  val3h = L3H_mid;              //front for full rack
//  val2h = L2H_back;
//  val4h = L4H_mid;              //back for full rack
  
  L1_H_Mov2(val1h);
  L3_H_Mov2(val3h);
  L2_H_Mov2(val2h);
  L4_H_Mov2(val4h);

  if(counter<=3 || counter>=6)
  {
    digitalWrite(L1Vdir,0);
    digitalWrite(L3Vdir,0);
    analogWrite(L1Vpwm,50);
    analogWrite(L3Vpwm,50);
  }  
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
    state = 43;
  }
}

void state43()
{
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);
  digitalWrite(L4Vdir, 1);
  analogWrite(L4Vpwm, stall_base4v-10);

  val1v = L1V_down;
  val3v = L3V_down;

  L1_V_MovD(val1v);
  L3_V_MovD(val3v);

  //Serial.println(L1V_err);
  if (flag1vd == 1 && flag3vd == 1)
  {
    L1V_sum = 0;
    L3V_sum = 0;
    flag1vd = 0;
    flag3vd = 0;
    state = 44;
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
    analogWrite(L1Vpwm, 0);
    analogWrite(L3Vpwm, 0);
    //    Serial.println("state3 done");
    //delay(2000);
    counter++;
    if(counter<=3 || counter>=8)
    {
      val1h = L1H_mid;            //front for full rack
      val3h = L3H_mid;            //front for full rack
      val2h = L2H_front;              //back for full rack
      val4h = L4H_front;              //back for full rack
      L1V_diff=L1V_diff_sand;
      L4V_diff=L4V_diff_sand; 
      L1V_up=L1V_down-L1V_diff;
      L4V_up=L4V_down+L4V_diff;
    }
    else                              //using full rack
    {
      val1h = L1H_back;
      val3h = L3H_back;              //front for full rack
      val2h = L2H_front;
      val4h = L4H_front;              //back for full rack
      L1V_diff = 50; 
      L4V_diff = 50; 
      L1V_up=L1V_down-L1V_diff;
      L4V_up=L4V_down+L4V_diff;
  }
 }
}

void state44()
{
  /*
    val2v = L2V_up - 80 ;
    val4v = L4V_up - 80 ;
  */
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v-5);
  digitalWrite(L1Vdir, 0);
  analogWrite(L1Vpwm, stall_base1v-5);

//  val2v = L2V_up_sand;
//  val4v = L4V_up_sand;
  L2_V_MovUP(L2V_up_sand);
  L4_V_MovUP(L4V_up);

  //Serial.println(L1V_err);
  if (flag2vu == 1 && flag4vu == 1)
  {
    L2V_sum = 0;
    L4V_sum = 0;
    flag2vu = 0;
    flag4vu = 0;
    state = 45;
    //  state = 16;
    analogWrite(L4Vpwm,0);
    analogWrite(L2Vpwm,0);
    analogWrite(L1Vpwm,0); 
    analogWrite(L3Vpwm,0);

    //    Serial.println("state4 done");
    //delay(2000);
  }
}

void state45()
{
//  val2h = L2H_mid;            //front for full rack
//  val4h = L4H_front;
//  val1h = L1H_mid;           //back for full rack
//  val3h = L3H_back;

  L1_H_Mov2(val1h);
  L3_H_Mov2(val3h);
  L2_H_Mov2(val2h);
  L4_H_Mov2(val4h);

if(counter<=3 || counter>=8)
{
  digitalWrite(L2Vdir,1);
  digitalWrite(L4Vdir,1);
  analogWrite(L2Vpwm,50);
  analogWrite(L4Vpwm,50);
}   


  //Serial.println(L1V_err);
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
    L1H_initial = analogRead(L1Hpot);
    L2H_initial = analogRead(L2Hpot);
    L3H_initial = analogRead(L3Hpot);
    L4H_initial = analogRead(L4Hpot);
    analogWrite(L4Hpwm, 0);
    analogWrite(L1Hpwm, 0);
    analogWrite(L2Hpwm, 0);
    analogWrite(L3Hpwm, 0);
    state = 46;
//    Serial.println("state5 done");
    //delay(2000);
  }
}

void state46()
{

  val2v = L2V_down;
  val4v = L4V_down;

  L2_V_MovD(val2v);
  L4_V_MovD(val4v);

  //Serial.println(L1V_err);
  if (flag2vd == 1 && flag4vd == 1)
  {
    counter++;
    L2V_sum = 0;
    L4V_sum = 0;
    flag2vd = 0;
    flag4vd = 0;
//    digitalWrite(L3Vdir, 1);
    analogWrite(L3Vpwm, 0);
    analogWrite(L4Vpwm , 0);
    l1h_pwm = 0;
    l2h_pwm = 0;
    l3h_pwm = 0;
    l4h_pwm = 0;
    
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
    analogWrite(L1Vpwm, 0);
    analogWrite(L3Vpwm, 0);
    
    if(counter<=3 || counter>=8)
    {
      val1h = L1H_front;            //front for full rack
      val3h = L3H_front;            //front for full rack
      val2h = L2H_mid;              //back for full rack
      val4h = L4H_mid;              //back for full rack
      L1V_diff=L1V_diff_sand;
      L4V_diff=L4V_diff_sand; 
      L1V_up=L1V_down-L1V_diff;
      L4V_up=L4V_down+L4V_diff;
    }
    else                              //using full rack
    {
      val1h = L1H_front;
      val3h = L3H_front;              //front for full rack
      val2h = L2H_back;
      val4h = L4H_back;              //back for full rack
      L1V_diff = 50;
      L4V_diff = 50; 
      L1V_up=L1V_down-L1V_diff;
      L4V_up=L4V_down+L4V_diff;
//      L1H_pwm_constrain = 130;
    }
    state = 41;
    //    Serial.println("state6 done");
    //delay(2000);
  }
}
