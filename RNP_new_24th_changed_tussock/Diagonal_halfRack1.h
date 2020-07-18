    /*diagonal full rack : 31 - 36
 * diagonal half rack : 40 -46
  
 */

void state37()
{
L1H_pwm_constrain = 150;      //200 for sanddune when front is to be taken. 130 for after sanddune                        (used in horizontal mov functions,updated in diagonal,turning,sanddune-initial and tussock)
L1V_up_constrain = 150;       //Up and down 150 for Sand-dune initially on sanddune it is 70. For After tussock 150 & 120 (used in vertical mov functions,)
L1V_down_constrain = 130;     

L2H_pwm_constrain = 150;
L2V_up_constrain = 150;
L2V_down_constrain = 120;

L3H_pwm_constrain = 150;
L3V_up_constrain = 150;
L3V_down_constrain =130;

L4H_pwm_constrain = 150;
L4V_up_constrain = 150;
L4V_down_constrain = 130;  

state=31;
}

void state30()
{

   L1_V_MovD(L1V_downmid);
   L2_V_MovD(L2V_downmid);
   L3_V_MovD(L3V_downmid);
   L4_V_MovD(L4V_downmid);

  L1_H_Mov(L1H_front);
  L2_H_Mov(L2H_back);
  L3_H_Mov(L3H_front);
  L4_H_Mov(L4H_back);

 
       if(flag1vd==1 && flag2vd==1 && flag3vd==1 && flag4vd==1 && flag1h == 1 && flag3h == 1 && flag2h == 1 && flag4h == 1)
      {
        
      analogWrite(L1Vpwm, 0);
      analogWrite(L2Vpwm, 0);
      analogWrite(L3Vpwm, 0);
      analogWrite(L4Vpwm, 0);
      L1V_sum = 0;
      L3V_sum = 0;
      L2V_sum = 0;
      L4V_sum = 0;
      flag1vd=0;
      flag2vd=0;
      flag3vd=0;
      flag4vd=0;
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
//        state = 31;
        state=0;
//        if(retry_flag==1)
          delay(1000);
      }  
}


 
 void state31()
{
  base2h=30;
  base3h=30;
  base1h=15;
  base4h=15;
  
  digitalWrite(mpu_mode,0);
  val2v = L2V_upmid;
  val4v = L4V_upmid;
  L2_V_MovUP(val2v);
  L4_V_MovUP(val4v);
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v-5);
//  digitalWrite(L4Vdir, 0);
//  analogWrite(L4Vpwm, stall_base4v);

  Serial.println("31");
  if (flag2vu == 1 && flag4vu == 1)
  {
    L2V_sum = 0;
    L4V_sum = 0;
    flag2vu = 0;
    flag4vu = 0;
    flag2_up=0;
    flag4_up=0;
    analogWrite(L3Vpwm,0);
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
    state = 32;
  }
}

void state32()
{
  val1h = L1H_back;
  val3h = L3H_back;
  val2h = L2H_front;
  val4h = L4H_front;

  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v-5);
//  digitalWrite(L4Vdir, 0);
//  analogWrite(L4Vpwm, stall_base4v);

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
    
  }
}

void state33()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v-5);
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
    state = 34;
    
//     Serial.println("state33");
//    delay(50);
//    Serial.println("state3 done");
 counter++;
    if(counter==countThres && turn_flag==0 && sanddune_flag==0)
    {
      counter=0;
      state= 132;
    }
    if(turn_flag==1 && sanddune_flag==0)
    {
      distance4();
      Serial.print("f");
      Serial.print(" ");
      Serial.println(dist);
      if(dist>33)
      {
        state=34;
//           state=0;
      }
      else if(dist<=33 && dist>12)
      {
       L4H_diff=map(dist,12,33,40,200);
       L2H_back = L2H_front+L4H_diff;
       L4H_back = L4H_front-L4H_diff;  
       state=34;
       
//     Serial.println("3315");
//        state=0;
       }
      else if(dist<=12)
      {
      state=184;      //sanddune walking
//      state=0;
      right_flag=0;
      left_flag=1;
      }
    }
    
    if(counter==countThres && sanddune_flag==1)
    {
      counter=0;
      state= 144;
      L1H_back = L1H_front+235;
      L2H_back = L2H_front+235;
      L3H_back = L3H_front-235;
      L4H_back = L4H_front-235;
      
     }
       else if(counter==2 && sanddune_flag==1)
     {
      state=34; 
      L3H_diff=235;
      L3H_back = L3H_front-L3H_diff;
      L4H_back = L4H_front-L3H_diff;
     }

    if(tussock_flag1==1)
    {
      state=34;
        if(counter==2)
        {
          L1H_diff=235;
          L1H_back=L1H_front+L1H_diff/2;
          L2H_back=L2H_front+L1H_diff/2;  
        }
        else if(counter==3)
        {
          left_flag=1;
          right_flag=0;
            state=357;
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
//  digitalWrite(L2Vdir, 1);
//  analogWrite(L2Vpwm, stall_base2v-5);
//  digitalWrite(L1Vdir, 1);
//  analogWrite(L1Vpwm, stall_base1v);

  val1v = L1V_upmid;
  val3v = L3V_upmid;
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
    analogWrite(L2Vpwm,0);
    analogWrite(L1Vpwm,0);
    analogWrite(L3Vpwm,0);
    state = 35;
//    analogWrite(L4Vpwm ,0);
//    Serial.println("state4 done");
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


//  digitalWrite(L2Vdir, 1);
//  analogWrite(L2Vpwm, stall_base2v-5);
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
    state = 36;
//    Serial.println("state5 done");
  }
}

void state36()
{ 
//  digitalWrite(L2Vdir, 1);
//  analogWrite(L2Vpwm, stall_base2v-5);
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
    
     state = 31;
     Serial.println("state 36");
//     delay(50);
       counter++;
    if(counter==countThres && turn_flag==0 && sanddune_flag==0)
    {
      counter=0;
      state= 135;
    }
    if(turn_flag==1 && sanddune_flag==0)
        {
          distance1();
          Serial.print("o");
          Serial.print(" ");
          Serial.println(dist);
          if(dist>33)
          {
            state=31;
//              state=0;
          }
          else if(dist<=33 && dist>12)
          {
            
//     Serial.println("3315");
           L1H_diff=map(dist,12,33,40,200);
           L1H_back = L1H_front+L1H_diff;
           L3H_back = L3H_front-L1H_diff;  
           state=31;
//            state=0;
           }
          else if(dist<=12)
          {
          state=184;      //sanddune walking
//          state=0;
          right_flag=1;
          left_flag=0;
//          sanddune_flag=1;
          }
        }

    if(counter==countThres && sanddune_flag==1)
    {
      counter=0;
      state=141;
      
      L1H_back = L1H_front+235;
      L2H_back = L2H_front+235;
      L3H_back = L3H_front-235;
      L4H_back = L4H_front-235;
      
     }
     else if(counter==2 && sanddune_flag==1)
     {
      state=31; 
      L3H_diff=235;
      L3H_back = L3H_front-L3H_diff;
      L4H_back = L4H_front-L3H_diff;
     }

     
    if(tussock_flag1==1)
    {
      state=31;
        if(counter==2)
        {
          L1H_diff=235;
          L1H_back=L1H_front+L1H_diff/2;
          L2H_back=L2H_front+L1H_diff/2;  
        }
        else if(counter==3)
        {
          
          L1H_diff=235;
          L1H_back=L1H_front+L1H_diff;
          L2H_back=L2H_front+L1H_diff;  
          left_flag=0;
          right_flag=1;
            state=357;
        }
    }    
   }
//    Serial.println("state6 done");
    //delay(2000);
}





/*
* States 41 - 46 
* Diagonal Pattern using just half the rack - to avoid toppling
* 40 - initial state
 */

void state40()
{
  L2_H_Mov(L2H_front);
  L4_H_Mov(L4H_mid);
  L1_H_Mov(L1H_back);
  L3_H_Mov(L3H_mid);

  L1_V_MovD(L1V_down);
  L2_V_MovD(L2V_down);
  L3_V_MovD(L3V_down);
  L4_V_MovD(L4V_down);
}

//Diagonal Half Rack

void state41()
{
  /*
    val1v = L1V_up - 80;
    val3v = L3V_up - 80;*/
   
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);
  val1v = L1V_up_sand;
  val3v = L3V_up_sand;
  L1_V_MovUP(val1v);
  L3_V_MovUP(val3v);

  if (flag1vu == 1 && flag3vu == 1)
  {
    L1V_sum = 0;
    L3V_sum = 0;
    flag1vu = 0;
    flag3vu = 0;
    state = 42;
    L1H_pwm_constrain = 200;
//    L2H_pwm_constrain = 120;
      L3H_pwm_constrain = 200;
//      L4H_pwm_constrain = 120;
      
  }
}

void state42()
{

  val1h = L1H_front;
  val3h = L3H_mid;
  val2h = L2H_back;
  val4h = L4H_mid;

  L1_H_Mov2(val1h);
  L3_H_Mov2(val3h);
  L2_H_Mov2(val2h);
  L4_H_Mov2(val4h);

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
    digitalWrite(L2Vdir, 0);
    analogWrite(L2Vpwm, 0);
    //    Serial.println("state3 done");
    //delay(2000);

        L1H_pwm_constrain = 120;
//    L2H_pwm_constrain = 120;
      L3H_pwm_constrain = 120;
//      L4H_pwm_constrain = 120;

  }
}

void state44()
{
  /*
    val2v = L2V_up - 80 ;
    val4v = L4V_up - 80 ;*/
   
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v -5);
  val2v = L2V_up_sand;
  val4v = L4V_up_sand;
  L2_V_MovUP(val2v);
  L4_V_MovUP(val4v);

  //Serial.println(L1V_err);
  if (flag2vu == 1 && flag4vu == 1)
  {
    L2V_sum = 0;
    L4V_sum = 0;
    flag2vu = 0;
    flag4vu = 0;
    state = 45;
    //  state = 16;
    analogWrite(L4Vpwm , 0);
    analogWrite(L2Vpwm,0);
//        L1H_pwm_constrain = 200;
    L2H_pwm_constrain = 200;
//      L3H_pwm_constrain = 200;
      L4H_pwm_constrain = 200;


    //    Serial.println("state4 done");
    //delay(2000);
  }
}

void state45()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v -5);
  val2h = L2H_mid;
  val4h = L4H_front;
  val1h = L1H_mid;
  val3h = L3H_back;

  L1_H_Mov2(val1h);
  L3_H_Mov2(val3h);
  L2_H_Mov2(val2h);
  L4_H_Mov2(val4h);

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
//        L1H_pwm_constrain = 200;
    L2H_pwm_constrain = 120;
//      L3H_pwm_constrain = 200;
      L4H_pwm_constrain = 120;

    analogWrite(L4Hpwm, 0);
    analogWrite(L1Hpwm, 0);
    analogWrite(L2Hpwm, 0);
    analogWrite(L3Hpwm, 0);
    state = 46;
    Serial.println("state5 done");
    //delay(2000);
  }
}

void state46()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v -5);

  val2v = L2V_down;
  val4v = L4V_down;

  L2_V_MovD(val2v);
  L4_V_MovD(val4v);

  //Serial.println(L1V_err);
  if (flag2vd == 1 && flag4vd == 1)
  {
    L2V_sum = 0;
    L4V_sum = 0;
    flag2vd = 0;
    flag4vd = 0;
    digitalWrite(L3Vdir, 1);
    analogWrite(L3Vpwm, 0);
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm , 0);
    l1h_pwm = 0;
    l2h_pwm = 0;
    l3h_pwm = 0;
    l4h_pwm = 0;
    analogWrite(L3Vpwm, 0);

    state = 41;
    //    Serial.println("state6 done");
    //delay(2000);
  }
}
