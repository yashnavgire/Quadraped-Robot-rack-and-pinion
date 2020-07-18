/* Contains from state170
   sanddune_walking : 171-183  
*/
/****************************************************************************/
#define down_constrain_SD 150         //used when down to be taken,when leg is not on sanddune.
#define down_constrainOn_SD 70       //used when down to be taken,when leg is on sanddune. 
#define back_constrain 150           //used when all legs are taken back on ground (150 tested,it is stable) 

void state170()                         //chasis UP
{
     L1_V_MovD(L1V_down);
     L2_V_MovD(L2V_down);
     L3_V_MovD(L3V_down);
     L4_V_MovD(L4V_down);

      if(flag1vd==1 && flag2vd==1 && flag3vd==1 && flag4vd==1)
      {
      state=171;
      analogWrite(L1Vpwm, 0);
      analogWrite(L2Vpwm, 0);
      analogWrite(L3Vpwm, 0);
      analogWrite(L4Vpwm, 0);
      flag1vd=0;
      flag2vd=0;
      flag3vd=0;
      flag4vd=0;
      L1H_pwm_constrain = back_constrain;//horizontal constrains initially,then changed to 200 for front,and again changed to 150 for all back
      L2H_pwm_constrain = back_constrain;
      L3H_pwm_constrain = back_constrain;
      L4H_pwm_constrain = back_constrain;
      L1V_up_constrain = 150;//vertical constrains will remain constant for whole sanddune
      L2V_up_constrain = 150;
      L3V_up_constrain = 150;
      L4V_up_constrain = 150;
      L1H_diff= 235;          //difference updated since it was changed during mapping 
      L1H_back = L1H_front+L1H_diff;
      L2H_back = L2H_front+L1H_diff;
      L3H_back = L3H_front-L1H_diff;
      L4H_back = L4H_front-L1H_diff;
      L1V_diff=70;            //normal difference updated which is used for changing up when leg will not be on sanddune
      L2V_diff=70;
      L3V_diff=70;
      L4V_diff=70;
      L1V_up=L1V_down-L1V_diff_sand; //up changed according to counts,initially 2,3 kept low
      L2V_up=L2V_down+L2V_diff;
      L3V_up=L3V_down-L3V_diff;
      L4V_up=L4V_down+L3V_diff_sand;
      L1V_down_constrain = down_constrainOn_SD;     //down constrain changed according to counts,initially 1 and 4 on sanddune,therefore kept low
      L2V_down_constrain = down_constrain_SD;
      L3V_down_constrain = down_constrain_SD;
      L4V_down_constrain = down_constrainOn_SD;
      delay(500);      
      } 
}

void state171()
{
//   if(sanddune_flag==1)
//     {
//      L1V_down_constrain = 150;
//      L2V_down_constrain = 150;
//      L3V_down_constrain = 150;
//      L4V_down_constrain = 150;
//
//      L1H_pwm_constrain = 180;
//      L2H_pwm_constrain = 180;
//      L3H_pwm_constrain = 180;
//      L4H_pwm_constrain = 180;
//
//      L1H_back = L1H_front+250;
//      L2H_back = L2H_front+250;
//      L3H_back = L3H_front-230;
//      L4H_back = L4H_front-230;  
//     
//      L1V_up_sand=L1V_down-215;
//      L2V_up_sand=L2V_down+215;
//      L3V_up_sand=L3V_down-215;
//      L4V_up_sand=L4V_down+215;
//      sanddune_flag= 0;
//     }

//
//      val1h = L1H_back;
//      val3h = L3H_back;
//      val2h = L2H_back;
//      val4h = L4H_back;

      L1_H_Mov(L1H_back);
      L3_H_Mov(L3H_back);
      L2_H_Mov(L2H_back);
      L4_H_Mov(L4H_back);
    
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
    state = 172;    
    L1H_pwm_constrain = 200;
    L2H_pwm_constrain = 200;
    L3H_pwm_constrain = 200;
    L4H_pwm_constrain = 200;
//    Serial.println("state 171 done");
  }
}

void state172()
{ 
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v-5);

  Serial.println(flag2vu);
  L2_V_MovUP(L2V_up);

  if(flag2vu == 1)
  {
    flag2vu = 0;
    flag2_up=0;
    L2V_sum = 0;
    l2v_pwm = 0;
    analogWrite(L2Vpwm, 0);
//    Serial.println("state 172 Done");
    state = 173;
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

  L2_V_MovLS(L2V_down);
  Serial.println(flag2vd);
  if (flag2vd == 1)
  {
    flag2vd = 0;
    flag2_down=0;
    L2V_sum = 0;
    l2v_pwm = 0;
    flag2vu=0;
    analogWrite(L2Vpwm, 0);
    analogWrite(L3Vpwm,0);
    state = 175;
    flag1vu=0;
  }
}

void state175()
{
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);
  L1_V_MovUP(L1V_up);
  Serial.println(flag1vu);
  if (flag1vu == 1)
  {
    flag1vu = 0;
    flag1vd = 0;
    flag1_up=0;
    L1V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L1Vpwm, 0);
    state = 176;
  }
}

void state176()
{
  L1_H_Mov(L1H_front);
  if (flag1h == 1)
  {
    flag1h = 0;
    L1H_sum = 0;
    l1h_pwm = 0;
    L1H_initial = analogRead(L1Hpot);
    analogWrite(L1Hpwm, 0);
    state = 177;
  }
}

void state177()
{
  L1_V_MovLS(L1V_down);
  if (flag1vd == 1)
  {
    flag1vd = 0;
    flag1vu=0;
    flag1_down=0;
    L1V_sum = 0;
    l1v_pwm = 0;
    analogWrite(L3Vpwm, 0);
    analogWrite(L2Vpwm, 0);
    analogWrite(L1Vpwm, 0);
    state = 178;
    flag3vu=0;
//    delay(10);
  }
}

void state178()
{
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);

  L3_V_MovUP(L3V_up);
  Serial.println(flag3vu);
  if (flag3vu == 1)
  {
    flag3vd = 0;
    flag3vu = 0;
    flag3_up=0;
    L3V_sum = 0;
    l3v_pwm = 0;
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
  L3_V_MovLS(L3V_down);
  if (flag3vd == 1)
  {
    flag3vd = 0;
    flag3vu = 0;
    flag3_down=0;
    L3V_sum = 0;
    l3v_pwm = 0;
    analogWrite(L2Vpwm, 0);
    analogWrite(L3Vpwm, 0);
//    Serial.println("state 90");
    state = 181;
    flag4vu=0;
//    delay(100);
//////delay(500);
  }
}


void state181()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v-5);

  L4_V_MovUP(L4V_up);
  Serial.println(flag4vu);
  if (flag4vu == 1)
  {
    flag4vu = 0;
    flag4vd = 0;
    flag4_up=0;
    L4V_sum = 0;
    l4v_pwm = 0;
    analogWrite(L4Vpwm, 0);
//    Serial.println("state 91 Done");
    state = 182;
    //////delay(500);
  }
}

void state182()
{
  L4_H_Mov(L4H_front);
  if (flag4h == 1)
  {
    flag4h = 0;
    L4H_sum = 0;
    l4h_pwm = 0;
    L4H_initial = analogRead(L4Hpot);
    analogWrite(L4Hpwm, 0);
    flag4vd=0;
//    Serial.println("state 92");
    state = 183;
    //////delay(500);
  }
}

void state183()
{
  L4_V_MovLS(L4V_down);
  if (flag4vd == 1)
  {
  analogWrite(L3Vpwm, 0);
    flag4vd = 0;
    flag4vu=0;
    flag4_down=0;
    flag2vu=0;
    L4V_sum = 0;
    l4v_pwm = 0;
    analogWrite(L4Vpwm, 0);
    state = 171;
    delay(30);
    sanddune_counter++;

    if(sanddune_counter==2)
    {     
//          L2V_diff_sand = 190;
//          L3V_diff_sand = 204;         
      L2V_up=L2V_down+L2V_diff_sand;
      L3V_up=L3V_down-L3V_diff_sand;
      
      L2V_down_constrain = down_constrainOn_SD;           ///decreased down constrain,since in next down it will be not on sanddune
      L3V_down_constrain = down_constrainOn_SD;
      L1V_down_constrain = down_constrain_SD;             //increased down constrain,since in next down it will be not on sanddune
      L4V_down_constrain = down_constrain_SD;
    }
    else if(sanddune_counter==3)
    {
        L1V_up=L1V_down-L1V_diff ;
        L4V_up=L4V_down+L4V_diff ;
    }
    else if(sanddune_counter==4)
    {
        L2V_down_constrain = down_constrain_SD;
        L3V_down_constrain = down_constrain_SD;  
    }

      L1H_pwm_constrain = back_constrain;
      L2H_pwm_constrain = back_constrain;
      L3H_pwm_constrain = back_constrain;
      L4H_pwm_constrain = back_constrain;
//    if(sanddune_counter==5)
//    {
//      turn_flag = 0;
//      turnAngleFlag = 0;
//      state=201;                //left turn 60 initial
//      sanddune_counter=0;
//    }
 }
}

////////////////////////sanddune diagonal pattern///////////////////

void state184()
{
    L1V_down_constrain = 150; 
    L2V_down_constrain = 150;
    L3V_down_constrain = 150;
    L4V_down_constrain = 150;
  
  //all down
     L1_V_MovD(L1V_down);
     L2_V_MovD(L2V_down);
     L3_V_MovD(L3V_down);
     L4_V_MovD(L4V_down);
     if(flag1vd==1 &&flag2vd==1 && flag3vd==1 && flag4vd==1)
      {
      analogWrite(L1Vpwm, 0);
      analogWrite(L2Vpwm, 0);
      analogWrite(L3Vpwm, 0);
      analogWrite(L4Vpwm, 0);
      flag1vd=0;
      flag2vd=0;
      flag3vd=0;
      flag4vd=0;

       L1H_back = L1H_front+235;
       L2H_back = L2H_front+235;
       L3H_back = L3H_front-235;
       L4H_back = L4H_front-235;
        if(left_flag==1)
        {
           L1H_pwm_constrain = 150;      //200 for sanddune when front is to be taken. 130 for after sanddune                               (used in horizontal mov functions,updated in diagonal,turning,sanddune-initial and tussock)
           L1V_up_constrain = 200;       //Up and down 150 for Sand-dune initially on sanddune it is 70. For After tussock 150 & 120       (used in vertical mov functions,)
           L1V_down_constrain = 80;     
          
           L2H_pwm_constrain = 150;
           L2V_up_constrain = 200;
           L2V_down_constrain = 100;
          
           L3H_pwm_constrain = 150;
           L3V_up_constrain = 200;
           L3V_down_constrain =100;
          
           L4H_pwm_constrain = 150;
           L4V_up_constrain = 200;
           L4V_down_constrain = 80;

      
           state = 185;   
//             state=0; 
         }
        else if(right_flag==1)
        {
           L1H_pwm_constrain = 150;      
           L1V_up_constrain = 200;       
           L1V_down_constrain = 100;     
          
           L2H_pwm_constrain = 150;
           L2V_up_constrain = 200;
           L2V_down_constrain = 80;
          
           L3H_pwm_constrain = 150;
           L3V_up_constrain = 200;
           L3V_down_constrain =80;
          
           L4H_pwm_constrain = 150;
           L4V_up_constrain = 200;
           L4V_down_constrain = 100;
      
           state = 191;
//             state=0;
        }
        delay(500);
      }
      //add the sanddune constrains
      //  state=185   //if 1,3 back after mapping,set left flag after mapping
      //  state=191      //if 2,4 back after mapping,set right flag after mapping
}

void state185()
{
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);

//  flag1_up=1;
//  flag3_up=1;
val1v=L1V_up_sand;        //use this for general sanddune,if counts are not working.
val3v=L3V_up_sand;
//  if(sanddune_counter1<2)
//  {
//    val3v=L3V_down-80;
//    val1v=L1V_up_sand;  
//  }
//  else if(sanddune_counter1>=2)
//  {
//    val3v=L3V_up_sand;
//    val1v=L1V_down-80;
//  }
//
//  if(sanddune_counter1==2)
//  {
//    val1v=L1V_up_sand;
//  }
    L1_V_MovUP(val1v);
    L3_V_MovUP(val3v);
 
  if (flag1vu == 1 && flag3vu ==1)
  {
    flag1vu = 0;
    flag3vu=0;
    flag1vd=0;
    L1V_sum = 0;
    L3V_sum = 0;
//    l1v_pwm = 0;
    flag1_up=0;
    flag3_up=0;
//    L2H_pwm_constrain = 90; 
//    L4H_pwm_constrain = 90; 
    L1H_pwm_constrain = 200; 
    L3H_pwm_constrain = 200; 
    analogWrite(L1Vpwm, 0);
    analogWrite(L3Vpwm, 0);
    state = 186;
  }
}


void state186()
{  
//  if(sanddune_counter1==1)
//  {
//      val1h=L1H_front+80;
//      val3h=L3H_front-100;
//  }
  
 /* if(sanddune_counter1==2)
  {
      val1h=L1H_front+80;
      val3h=L3H_front;
  }*/ 
//  else
//  {
    val1h=L1H_front;
    val3h=L3H_front;
//  }
  L1_H_Mov2(val1h);
  L3_H_Mov2(val3h);
//  L2_H_Mov2(L2H_back);
//  L4_H_Mov2(L4H_back);

/*
  if(counter<=3 || counter>=6)
  {
    digitalWrite(L1Vdir,0);
    digitalWrite(L3Vdir,0);
    analogWrite(L1Vpwm,50);
    analogWrite(L3Vpwm,50);
  }  
*/

  if (flag1h == 1 && flag3h == 1 )
  {
    L1H_sum = 0;
    L3H_sum = 0;
    flag1h = 0;
    flag3h = 0;
    analogWrite(L4Hpwm, 0);
    analogWrite(L1Hpwm, 0);
    analogWrite(L2Hpwm, 0);
    analogWrite(L3Hpwm, 0);
    L1H_pwm_constrain = 140; 
    L3H_pwm_constrain = 140; 
    
    L1H_initial = analogRead(L1Hpot);
//    L2H_initial = analogRead(L2Hpot);
    L3H_initial = analogRead(L3Hpot);
//    L4H_initial = analogRead(L4Hpot);
    state = 187;
  }
}


void state187()
{
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);
//  digitalWrite(L4Vdir, 1);
//  analogWrite(L4Vpwm, stall_base4v-10);

  val2h=L2H_back;
  val4h=L4H_back;
  if(sanddune_counter1==0)
  {
     val1v=L1V_sand_mid;
     val3v=L3V_down;
  }
  else if(sanddune_counter1==1)
  {
        val1v=L1V_sand_mid;
        val3v=L3V_down;
  }
  else if(sanddune_counter1>=2)
  {
        val1v=L1V_down;
        L3V_down_constrain=70;
        L1V_down_constrain=120;
        val3v=L3V_sand_mid;
  }
   else
  {
        val1v=L1V_down;
        val3v=L3V_down;
  }
  if(sanddune_counter1>=3)
  {
    L3V_down_constrain=120;
    val3v=L3V_down;   
  }
  if(sanddune_counter2==2)
  {
    val4h=L4H_front-120;  
  }
  L1_V_MovLS(val1v);
  L3_V_MovLS(val3v);
  L2_H_Mov2(val2h);
  L4_H_Mov2(val4h);

   if (flag1vd == 1 && flag3vd == 1 && flag2h==1 && flag4h==1)
  {
    L1V_sum = 0;
    L3V_sum = 0;
    L2H_sum = 0;
    L4H_sum = 0;
    flag1vd = 0;
    flag3vd = 0;
    flag2h = 0;
    flag4h = 0;
    state = 188;
    L2H_initial = analogRead(L2Hpot);
    L4H_initial = analogRead(L4Hpot);
    analogWrite(L2Hpwm, 0);
    analogWrite(L4Hpwm, 0);
    analogWrite(L1Vpwm, 0);
    analogWrite(L3Vpwm, 0);
    sanddune_counter1++;
  }  
}


void state188()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v);

//  flag2_up=1;
//  flag4_up=1;
////    
//val2v=L2V_up_sand;
//val4v=L4V_up_sand;
if(sanddune_counter2==0)
{
  val2v=L2V_down+80;
  val4v=L4V_up_sand;
}
else if(sanddune_counter2==1)
{
  val2v=L2V_up_sand;
  val4v=L4V_up_sand;
}
else if(sanddune_counter2>1)
{
  val2v=L2V_up_sand;
  val4v=L4V_down+80;
}
  L2_V_MovUP(val2v);
  L4_V_MovUP(val4v);
//  Serial.println(flag1vu);
  if (flag2vu == 1 && flag4vu ==1)
  {
    flag2vu = 0;
    flag4vu=0;
    L2V_sum = 0;
    L4V_sum = 0;
    flag2_up=0;
    flag4_up=0;
    L2H_pwm_constrain = 200; 
    L4H_pwm_constrain = 200; 
    
    
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
    state = 189;
  }
}


void state189()
{  
//  L1_H_Mov(L1H_back);
//  L3_H_Mov(L3H_back);
if(sanddune_counter2==1)
{
  val2h=L2H_front+110;
  val4h=L4H_front;  
}
else
{
  val2h=L2H_front;
  val4h=L4H_front;
}
  L2_H_Mov2(val2h);
  L4_H_Mov2(val4h);

/*
  if(counter<=3 || counter>=6)
  {
    digitalWrite(L1Vdir,0);
    digitalWrite(L3Vdir,0);
    analogWrite(L1Vpwm,50);
    analogWrite(L3Vpwm,50);
  }  
*/

  if (flag2h == 1 && flag4h == 1)
  {
    L2H_sum = 0;
    L4H_sum = 0;
    flag1h = 0;
    flag3h = 0;
    flag2h = 0;
    flag4h = 0;
    analogWrite(L4Hpwm, 0);
//    analogWrite(L1Hpwm, 0);
    analogWrite(L2Hpwm, 0);
//    analogWrite(L3Hpwm, 0);
//    L1H_initial = analogRead(L1Hpot);
    L2H_initial = analogRead(L2Hpot);
//    L3H_initial = analogRead(L3Hpot);
    L4H_initial = analogRead(L4Hpot);
    L2H_pwm_constrain = 150; 
    L4H_pwm_constrain = 150; 
    
    state = 190;
  }
}


void state190()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v-5);
//  digitalWrite(L4Vdir, 1);
//  analogWrite(L4Vpwm, stall_base4v-10);

  if(sanddune_counter2==0)
  {
     val4v=L4V_sand_mid;
     val2v=L2V_down;
  }
  else if(sanddune_counter2==1)
  {
       val4v=L4V_down;
       val2v=L2V_down;  
  }
  else
  {
        val2v=L2V_down;
        val4v=L4V_down;
  }
  if(sanddune_counter2==2)
  {
     val2v=L2V_down;  
  }
  L2_V_MovLS(val2v);
  L4_V_MovLS(val4v);
  L1_H_Mov2(L1H_back);
  L3_H_Mov2(L3H_back);

   if (flag2vd == 1 && flag4vd == 1 && flag1h==1 && flag3h==1)
  {
    flag2vd = 0;
    flag4vd = 0;
    L2V_sum = 0;
    L4V_sum = 0;
    L1H_sum = 0;
    L3H_sum = 0;
    flag1h = 0;
    flag3h = 0;
    analogWrite(L4Hpwm, 0);
    analogWrite(L1Hpwm, 0);
    analogWrite(L2Hpwm, 0);
    analogWrite(L3Hpwm, 0);
    L1H_initial = analogRead(L1Hpot);
//    L2H_initial = analogRead(L2Hpot);
    L3H_initial = analogRead(L3Hpot);
//    L4H_initial = analogRead(L4Hpot);
//    state = 191;
    state = 185;
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
//    analogWrite(L1Vpwm, 0);
//    analogWrite(L3Vpwm, 0);
    sanddune_counter2++;
  }  
}

/////////////////////////////////states for diagonal sanddune ,if 2 and 4 back(right flag will be 1 here)
void state191()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v);

//  flag1_up=1;
//  flag3_up=1;
//val1v=L1V_up_sand;        //use this for general sanddune,if counts are not working.
//val3v=L3V_up_sand;
  if(sanddune_counter2<2)
  {
    val2v=L2V_down+80;
    val4v=L4V_up_sand;  
  }
  else if(sanddune_counter2>=2)
  {
    val2v=L2V_up_sand;
    val4v=L4V_down+80;
  }

  if(sanddune_counter2==2)
  {
    val4v=L4V_up_sand;
  }
    L4_V_MovUP(val4v);
    L2_V_MovUP(val2v);
 
  if (flag2vu == 1 && flag4vu ==1)
  {
    flag2vu = 0;
    flag4vu=0;
    L2V_sum = 0;
    L4V_sum = 0;
//    l1v_pwm = 0;
    flag2_up=0;
    flag4_up=0;
//    L2H_pwm_constrain = 90; 
//    L4H_pwm_constrain = 90; 
    L4H_pwm_constrain = 200; 
    L2H_pwm_constrain = 200; 
    analogWrite(L4Vpwm, 0);
    analogWrite(L2Vpwm, 0);
    state = 192;
  }
}


void state192()
{  
  if(sanddune_counter2==1)
  {
      val4h=L4H_front-80;
      val2h=L2H_front+100;
  }
  
 /* if(sanddune_counter1==2)
  {
      val1h=L1H_front+80;
      val3h=L3H_front;
  }*/ 
  else
  {
    val4h=L4H_front;
    val2h=L2H_front;
  }
  L4_H_Mov2(val4h);
  L2_H_Mov2(val2h);
//  L2_H_Mov2(L2H_back);
//  L4_H_Mov2(L4H_back);

/*
  if(counter<=3 || counter>=6)
  {
    digitalWrite(L1Vdir,0);
    digitalWrite(L3Vdir,0);
    analogWrite(L1Vpwm,50);
    analogWrite(L3Vpwm,50);
  }  
*/

  if (flag2h == 1 && flag4h == 1 )
  {
    L2H_sum = 0;
    L4H_sum = 0;
    flag4h = 0;
    flag2h = 0;
    analogWrite(L4Hpwm, 0);
    analogWrite(L1Hpwm, 0);
    analogWrite(L2Hpwm, 0);
    analogWrite(L3Hpwm, 0);
    L2H_pwm_constrain = 140; 
    L4H_pwm_constrain = 140; 
    analogWrite(L3Vpwm,0);
    
    L2H_initial = analogRead(L2Hpot);
//    L2H_initial = analogRead(L2Hpot);
    L4H_initial = analogRead(L4Hpot);
//    L4H_initial = analogRead(L4Hpot);
    state = 193;
  }
}


void state193()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v);
//  digitalWrite(L4Vdir, 1);
//  analogWrite(L4Vpwm, stall_base4v-10);

  val1h=L1H_back;
  val3h=L3H_back;
  if(sanddune_counter2==0)
  {
     val1v=L1V_sand_mid;
     val3v=L3V_down;
  }
  else if(sanddune_counter2==1)
  {
        val1v=L1V_sand_mid;
        val3v=L3V_down;
  }
  else if(sanddune_counter2>=2)
  {
        val1v=L1V_down;
        L3V_down_constrain=70;
        L1V_down_constrain=120;
        val3v=L3V_sand_mid;
  }
   else
  {
        val1v=L1V_down;
        val3v=L3V_down;
  }
  if(sanddune_counter1>=3)
  {
    L3V_down_constrain=120;
    val3v=L3V_down;   
  }
  if(sanddune_counter2==2)
  {
    val4h=L4H_front-100;  
  }
  L4_V_MovLS(val4v);
  L2_V_MovLS(val2v);
  L3_H_Mov2(L3H_back);
  L1_H_Mov2(L1H_back);

   if (flag4vd == 1 && flag2vd == 1 && flag3h==1 && flag1h==1)
  {
    L4V_sum = 0;
    L2V_sum = 0;
    L1H_sum = 0;
    L3H_sum = 0;
    flag4vd = 0;
    flag2vd = 0;
    flag1h = 0;
    flag3h = 0;
    state = 194;
    L1H_initial = analogRead(L1Hpot);
    L3H_initial = analogRead(L3Hpot);
    analogWrite(L3Vpwm, 0);
    analogWrite(L1Hpwm, 0);
    analogWrite(L3Hpwm, 0);
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
    sanddune_counter2++;
  }  
}


void state194()
{
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v);

//  flag2_up=1;
//  flag4_up=1;
////    
//val2v=L2V_up_sand;
//val4v=L4V_up_sand;
if(sanddune_counter1==0)
{
  val3v=L3V_down-80;
  val1v=L1V_up_sand;
}
else if(sanddune_counter1==1)
{
  val3v=L3V_up_sand;
  val1v=L1V_up_sand;
}
else if(sanddune_counter1>1)
{
  val3v=L3V_up_sand;
  val1v=L1V_down+80;
}
  L3_V_MovUP(val3v);
  L1_V_MovUP(val1v);
//  Serial.println(flag1vu);
  if (flag1vu == 1 && flag3vu ==1)
  {
    flag1vu = 0;
    flag3vu=0;
    L1V_sum = 0;
    L3V_sum = 0;
    flag1_up=0;
    flag3_up=0;
    L1H_pwm_constrain = 200; 
    L3H_pwm_constrain = 200; 
    
    
    analogWrite(L1Vpwm, 0);
    analogWrite(L3Vpwm, 0);
    state =195;
  }
}


void state195()
{  
//  L1_H_Mov(L1H_back);
//  L3_H_Mov(L3H_back);
if(sanddune_counter1==1)
{
  val3h=L3H_front-0;
  val1h=L1H_front;  
}
else
{
  val3h=L3H_front;
  val1h=L1H_front;
}
  L3_H_Mov2(val3h);
  L1_H_Mov2(val1h);

/*
  if(counter<=3 || counter>=6)
  {
    digitalWrite(L1Vdir,0);
    digitalWrite(L3Vdir,0);
    analogWrite(L1Vpwm,50);
    analogWrite(L3Vpwm,50);
  }  
*/

  if (flag1h == 1 && flag3h == 1)
  {
    L1H_sum = 0;
    L3H_sum = 0;
    flag1h = 0;
    flag3h = 0;
    flag2h = 0;
    flag4h = 0;
    analogWrite(L1Hpwm, 0);
//    analogWrite(L1Hpwm, 0);
    analogWrite(L3Hpwm, 0);
//    analogWrite(L2Vpwm,0);
//    analogWrite(L3Hpwm, 0);
//    L1H_initial = analogRead(L1Hpot);
    L1H_initial = analogRead(L1Hpot);
//    L3H_initial = analogRead(L3Hpot);
    L3H_initial = analogRead(L3Hpot);
    L1H_pwm_constrain = 150; 
    L3H_pwm_constrain = 150; 
    
    state = 196;
  }
}


void state196()
{
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v);
//  digitalWrite(L4Vdir, 1);
//  analogWrite(L4Vpwm, stall_base4v-10);
  
  if(sanddune_counter1==0)
  {
     val1v=L1V_sand_mid;
     val3v=L3V_down;
  }
  else if(sanddune_counter1==1)
  {
        val1v=L1V_down;
        val3v=L3V_sand_mid;
  }
  else
  {
        val3v=L3V_down;
        val1v=L1V_down;
  }

  L3_V_MovLS(val3v);
  L1_V_MovLS(val1v);
  L4_H_Mov2(L4H_back);
  L2_H_Mov2(L2H_back);

   if (flag1vd == 1 && flag3vd == 1 && flag4h==1 && flag2h==1)
  {
    flag1vd = 0;
    flag3vd = 0;
    L1V_sum = 0;
    L3V_sum = 0;
    L2H_sum = 0;
    L4H_sum = 0;
    flag2h = 0;
    flag4h = 0;
    analogWrite(L4Hpwm, 0);
    analogWrite(L2Hpwm, 0);
    analogWrite(L1Hpwm, 0);
    analogWrite(L3Hpwm, 0);

    analogWrite(L2Vpwm,0);
    L2H_initial = analogRead(L2Hpot);
//    L2H_initial = analogRead(L2Hpot);
    L4H_initial = analogRead(L4Hpot);
//    L4H_initial = analogRead(L4Hpot);
//    state = 191;
    state = 191;
    analogWrite(L1Vpwm, 0);
    analogWrite(L3Vpwm, 0);
//    analogWrite(L1Vpwm, 0);
//    analogWrite(L3Vpwm, 0);
    sanddune_counter1++;
  }  
}
