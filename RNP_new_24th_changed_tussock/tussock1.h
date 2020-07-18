/* Contains from state350
 *  initial : 351-362
   tussock_walking : 371-383  
*/
/****************************************************************************/

/* Contains state351() to state356() : new tussock states*/

///////////////////
void state350()
{
     L1_V_MovD(L1V_downmid);
     L2_V_MovD(L2V_downmid);
     L3_V_MovD(L3V_downmid);
     L4_V_MovD(L4V_downmid);

     if(flag1vd==1 &&flag2vd==1 && flag3vd==1 && flag4vd==1)
    
     {  counter=0;
       countThres=5;
//       state=0;
       sanddune_flag=1; 
      if(left_flag==1 && right_flag==0)
       state= 34;              //left flag=1,     
      else if(right_flag==1 && left_flag==0)
       state=31;
       
      analogWrite(L1Vpwm, 0);
      analogWrite(L2Vpwm, 0);
      analogWrite(L3Vpwm, 0);
      analogWrite(L4Vpwm, 0);
      flag1vd=0;
      flag2vd=0;
      flag3vd=0;
      flag4vd=0;
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
        
      L1H_pwm_constrain = 150;      //horizontal constrains initially,then changed to 200 for front,and again changed to 150 for all back
      L2H_pwm_constrain = 150;
      L3H_pwm_constrain = 150;
      L4H_pwm_constrain = 150;
      
      L1V_up_constrain = 150;       //vertical constrains will remain constant for whole sanddune
      L2V_up_constrain = 150;
      L3V_up_constrain = 150;
      L4V_up_constrain = 150;
   
      L1H_diff= 235;          //difference updated since it was changed during mapping 
      L3H_diff= L1H_diff/4;   //to take one cycle of left turn after sanddune  
      L4H_diff= L1H_diff/4;
      L1H_back = L1H_front+L1H_diff;
      L2H_back = L2H_front+L1H_diff;
      L3H_back = L3H_front-L3H_diff;
      L4H_back = L4H_front-L4H_diff;
      L1V_diff=60;            //normal difference updated which is used for changing up when leg will not be on sanddune
      L2V_diff=60;
      L3V_diff=60;
      L4V_diff=60;
      L1V_up=L1V_down-L1V_diff; 
      L2V_up=L2V_down+L2V_diff;
      L3V_up=L3V_down-L3V_diff;
      L4V_up=L4V_down+L3V_diff;
      L1V_down_constrain = 120 ;
      L2V_down_constrain = 120;
      L3V_down_constrain = 120;
      L4V_down_constrain = 120;  
}
}

///////////////
void state358()
{
  left_flag=1;
  right_flag=0;
   L1_V_MovD(L1V_downmid);
   L2_V_MovD(L2V_downmid);
   L3_V_MovD(L3V_downmid);
   L4_V_MovD(L4V_downmid);
   L1_H_Mov(L1H_midb);
   L2_H_Mov(L2H_front);
   L3_H_Mov(L3H_front);
   L4_H_Mov(L4H_front);

//   flag1vd==1 ,flag2vd==1 , flag3vd==1 , flag4vd==1;
   if(flag1vd==1 && flag2vd==1 && flag3vd==1 && flag4vd==1 &&flag1h==1 && flag2h==1 && flag3h==1 && flag4h==1)
      {
       state=0;
       counter=0;
       countThres=5;
       sanddune_flag=1;
      
      analogWrite(L1Vpwm, 0);
      analogWrite(L2Vpwm, 0);
      analogWrite(L3Vpwm, 0);
      analogWrite(L4Vpwm, 0);
      flag1vd=0;
      flag2vd=0;
      flag3vd=0;
      flag4vd=0;
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
        
      L1H_pwm_constrain = 150;      //horizontal constrains initially,then changed to 200 for front,and again changed to 150 for all back
      L2H_pwm_constrain = 150;
      L3H_pwm_constrain = 150;
      L4H_pwm_constrain = 150;
      
      L1V_up_constrain = 120;       //vertical constrains will remain constant for whole sanddune
      L2V_up_constrain = 150;
      L3V_up_constrain = 150;
      L4V_up_constrain = 120;
   
      L1H_diff= 235;          //difference updated since it was changed during mapping 
      L3H_diff= L1H_diff/4;   //to take one cycle of left turn after sanddune  
      L4H_diff= L1H_diff/4;
      L1H_back = L1H_front+L1H_diff;
      L2H_back = L2H_front+L1H_diff;
      L3H_back = L3H_front-L3H_diff;
      L4H_back = L4H_front-L4H_diff;
      L1V_diff=60;            //normal difference updated which is used for changing up when leg will not be on sanddune
      L2V_diff=60;
      L3V_diff=60;
      L4V_diff=60;
      L1V_up=L1V_down-L1V_diff; 
      L2V_up=L2V_down+L2V_diff;
      L3V_up=L3V_down-L3V_diff;
      L4V_up=L4V_down+L3V_diff;
      L1V_down_constrain = 120 ;
      L2V_down_constrain = 120;
      L3V_down_constrain = 120;
      L4V_down_constrain = 120;
      delay(100);      
      } 
}

void state357()
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
      
      L1H_pwm_constrain = 160;//horizontal constrains initially,then changed to 200 for front,and again changed to 150 for all back
      L2H_pwm_constrain = 160;
      L3H_pwm_constrain = 160;
      L4H_pwm_constrain = 160;
      
      L1V_up_constrain = 200;//vertical constrains will remain constant for whole sanddune
      L2V_up_constrain = 200;
      L3V_up_constrain = 200;
      L4V_up_constrain = 200;

      L1V_down_constrain = 120; 
      L2V_down_constrain = 120;
      L3V_down_constrain = 120;
      L4V_down_constrain = 120;
      
      L1H_diff= 235;          //difference updated since it was changed during mapping 
      L1H_back = L1H_front+L1H_diff;
      L2H_back = L2H_front+L1H_diff;
      L3H_back = L3H_front-L1H_diff;
      L4H_back = L4H_front-L1H_diff;

      tussock_flag1=0;
      if(left_flag==1&& right_flag==0)
     {
      state=351;
//      state=41;
     }


      else if(right_flag==1 && left_flag==0 )
     {
      state=354;
//      state=44;
     }
}
}



void state351()
{
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);

//  flag1_up=1;
//  flag3_up=1;
val1v=L1V_up_sand;        //use this for general sanddune,if counts are not working.
val3v=L3V_up_sand;

if(tussock_counter<=1)
{
  val3v=L3V_down-70;  
}
/*
  if(tussock_counter<=1 || (tussock_counter>5 && tussock_counter<=8))
  {
    val3v=L3V_down-80;
//    val1v=L1V_up_sand;  
  }
  else if(tussock_counter>1 || tussock_counter>8)
  {
    val3v=L3V_up_sand;
//    val1v=L1V_down-80;
  }
  if(tussock_counter<=1 || tussock_counter>7)
  {
    val1v=L1V_up_sand;
  }
  else
  {
     val1v=L1V_down-80;
  }
 */
 
    L1_V_MovUP(val1v);              //val1v
    L3_V_MovUP(val3v);              //val3v
 
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
    state = 352;
  }
}


void state352()
{  
//  if(sanddune_counter1==1)
//  {
//      val1h=L1H_front;
//      val3h=L3H_front-100;
//  }
//  else
//  {

    val1h=L1H_front;
    val3h=L3H_midf;
    
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
    L1H_pwm_constrain = 120; 
    L3H_pwm_constrain = 120; 
    
    L1H_initial = analogRead(L1Hpot);
//    L2H_initial = analogRead(L2Hpot);
    L3H_initial = analogRead(L3Hpot);
//    L4H_initial = analogRead(L4Hpot);
    state = 353;
  }
}


void state353()
{
  digitalWrite(L2Vdir, 1);
  analogWrite(L2Vpwm, stall_base2v-5);
//  digitalWrite(L4Vdir, 1);
//  analogWrite(L4Vpwm, stall_base4v-10);

  val1v=L1V_down;
  val3v=L3V_down;
  val2h=L2H_back;
  val4h=L4H_midb;
 
  L1_V_MovD(val1v);
  L3_V_MovD(val3v);
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
    state = 354;
    L2H_initial = analogRead(L2Hpot);
    L4H_initial = analogRead(L4Hpot);
    analogWrite(L2Hpwm, 0);
    analogWrite(L4Hpwm, 0);
    analogWrite(L1Vpwm, 0);
    analogWrite(L3Vpwm, 0);
    tussock_counter++;
  }  
}


void state354()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v-5);

//  flag2_up=1;
//  flag4_up=1;
////    
val2v=L2V_up_sand;
val4v=L4V_up_sand;
if(tussock_counter<=1)
{
  val2v=L2V_down+70;  
}
/*
if(tussock_counter<=1 || (tussock_counter>5 && tussock_counter<=8))
  {
    val2v=L2V_down-80;
//     L2V_down_constrain=100;
//     L4V_down_constrain=130;
//    val1v=L1V_up_sand;  
  }
  else if(tussock_counter>1 || tussock_counter>8)
  {
    val2v=L2V_up_sand;
//    val1v=L1V_down-80;
  }
if(tussock_counter<=1 || tussock_counter>7)
  {
    val4v=L4V_up_sand;
  }
  else
  {
     val4v=L4V_down-80;
  }
 */
  
//if(tussock_counter<=1)
//{
//  val2v=L2V_down+80;
//  val4v=L4V_up_sand;
//  L2V_down_constrain=100;
//  L4V_down_constrain=130;
//}
//else if(tussock_counter>1)
//{
//  val2v=L2V_up_sand;
//  val4v=L4V_down+80;
//  L2V_down_constrain=130;
//  L4V_down_constrain=100;
//}
//else if(tussock_counter>1)
//{
//  val2v=L2V_up_sand;
//  val4v=L4V_down+80;
//}

  L2_V_MovUP(val2v);
  L4_V_MovUP(val4v);

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
//    
    
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
    state = 355;
  }
}


void state355()
{  
//  L1_H_Mov(L1H_back);
//  L3_H_Mov(L3H_back);
//if(sanddune_counter2==1)
//{
//  val2h=L2H_front+0;
//  val4h=L4H_front;  
//}
//else
//{
  val2h=L2H_midf;
  val4h=L4H_front;
//}
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
    L2H_pwm_constrain = 120; 
    L4H_pwm_constrain = 120; 
    
    state = 356;
  }
}


void state356()
{
  digitalWrite(L3Vdir, 0);
  analogWrite(L3Vpwm, stall_base3v-5);
//  digitalWrite(L4Vdir, 1);
//  analogWrite(L4Vpwm, stall_base4v-10);
  
//  if(sanddune_counter2==0)
//  {
//     val4v=L4V_sand_mid;
//     val2v=L2V_down;
//  }
//  else if(sanddune_counter2==1)
//  {
//        val4v=L4V_down;
//        val2v=L2V_sand_mid;
//  }
//  else
//  {
        val2v=L2V_down;
        val4v=L4V_down;
//  }
        val1h=L1H_midb;
        val3h=L3H_back;
  L2_V_MovD(val2v);
  L4_V_MovD(val4v);
  L1_H_Mov2(val1h);
  L3_H_Mov2(val3h);

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
    state = 351;
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
    analogWrite(L1Vpwm, 0);
    analogWrite(L3Vpwm, 0);
    tussock_counter++;
  }  
}
////////////////////////////////////////////////////tussock done///////////////////////////////
