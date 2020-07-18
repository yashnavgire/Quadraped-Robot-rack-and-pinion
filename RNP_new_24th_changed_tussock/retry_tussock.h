////////////////////////////direct 2/3 rack in tussock//////////////////////////left flag 1//////////////////////////////////////////////////
 void state601()
 {
  left_flag=1;
  right_flag=0;
    L1V_down_constrain = 150; 
    L2V_down_constrain = 150;
    L3V_down_constrain = 150;
    L4V_down_constrain = 150;
  
  //all down
     L1_V_MovD(L1V_down);
     L2_V_MovD(L2V_down);
     L3_V_MovD(L3V_down);
     L4_V_MovD(L4V_down);
     L4_H_Mov(L4H_front);
     L2_H_Mov(L2H_front);
     L3_H_Mov(L3H_back);
     L1_H_Mov(L1H_back);

     
     if(flag1vd==1 &&flag2vd==1 && flag3vd==1 && flag4vd==1&& flag1h==1 && flag2h==1 && flag3h==1 && flag4h==1)
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
        flag1h=0;
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

      delay(2000);
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

////////////////////direct half rack in tussock///////////////////////////////////////////
void state602()
{
  left_flag=1;
  right_flag=0;
    L1V_down_constrain = 150; 
    L2V_down_constrain = 150;
    L3V_down_constrain = 150;
    L4V_down_constrain = 150;
  
  //all down
     L1_V_MovD(L1V_down);
     L2_V_MovD(L2V_down);
     L3_V_MovD(L3V_down);
     L4_V_MovD(L4V_down);

  L2_H_Mov(L2H_front);
  L4_H_Mov(L4H_mid);
  L1_H_Mov(L1H_back);
  L3_H_Mov(L3H_mid);

     
     if(flag1vd==1 &&flag2vd==1 && flag3vd==1 && flag4vd==1&& flag1h==1 && flag2h==1 && flag3h==1 && flag4h==1)
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
        flag1h=0;
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

      delay(2000);
      state=41;
//      
//      if(left_flag==1&& right_flag==0)
//     {
//      state=351;
////      state=41;
//     }
//
//
//      else if(right_flag==1 && left_flag==0 )
//     {
//      state=354;
////      state=44;
//     }
}
}

//////////////////////////left flag in sanddune//////////////////////////////////
void state603()
{
  left_flag=1;
  right_flag=0;
    L1V_down_constrain = 150; 
    L2V_down_constrain = 150;
    L3V_down_constrain = 150;
    L4V_down_constrain = 150;
  
  //all down
     L1_V_MovD(L1V_down);
     L2_V_MovD(L2V_down);
     L3_V_MovD(L3V_down);
     L4_V_MovD(L4V_down);

   L4_H_Mov(L4H_front);
   L2_H_Mov(L2H_front);
   L3_H_Mov(L3H_back);
   L1_H_Mov(L1H_back);

     if(flag1vd==1 &&flag2vd==1 && flag3vd==1 && flag4vd==1 && flag1h==1 && flag2h==1 && flag3h==1 && flag4h==1)
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
        flag1h=0;
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

        
       
        if(left_flag==1&& right_flag==0)
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
        else if(right_flag==1 && left_flag==0)
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
        delay(2000);
      }
      //add the sanddune constrains
      //  state=185   //if 1,3 back after mapping,set left flag after mapping
      //  state=191      //if 2,4 back after mapping,set right flag after mapping
}

//////////////////////////////right flag in sanddune////////////////////////////////////////
void state604()
{
  left_flag=0;
  right_flag=1;
    L1V_down_constrain = 150; 
    L2V_down_constrain = 150;
    L3V_down_constrain = 150;
    L4V_down_constrain = 150;
  
  //all down
     L1_V_MovD(L1V_down);
     L2_V_MovD(L2V_down);
     L3_V_MovD(L3V_down);
     L4_V_MovD(L4V_down);

   L4_H_Mov(L4H_back);
   L2_H_Mov(L2H_back);
   L3_H_Mov(L3H_front);
   L1_H_Mov(L1H_front);

     if(flag1vd==1 &&flag2vd==1 && flag3vd==1 && flag4vd==1 && flag1h==1 && flag2h==1 && flag3h==1 && flag4h==1)
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
        flag1h=0;
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

        
       
        if(left_flag==1&& right_flag==0)
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
        else if(right_flag==1 && left_flag==0)
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
        delay(2000);
      }
      //add the sanddune constrains
      //  state=185   //if 1,3 back after mapping,set left flag after mapping
      //  state=191      //if 2,4 back after mapping,set right flag after mapping
}
