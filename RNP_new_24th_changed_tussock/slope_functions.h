/* Horizontal and Vertical(UP and D) functions*/

void L1_H_MovB(int16_t valh)                                                       //front reading < back reading and back_direction=1
{
  // valh=map(valh,0,250,L1Hback,L1Hfront);                                
  L1H_val = analogRead(L1Hpot);
  L1H_err = (L1H_val - valh);
//   Serial.println("<80");
if (abs(L1H_err) < 80)
 { 
   if(abs(L1H_err)< thrs1h)
   {
    flag1h = 1;
    digitalWrite(L1Hdir, L1H_err < 0);  
    analogWrite(L1Hpwm, 0);
   }
   
    else
    {
//    Serial.print("   L1H   ");
    L1H_val = analogRead(L1Hpot);                                                      //Read pot
    L1H_err = L1H_val - valh;                                                          //Cal.Error
    L1H_sum = L1H_sum + L1H_err;
    digitalWrite(L1Hdir, L1H_err < 0);                                                //Def. dir
    //Serial.print(L1H_val);
    l1h_pwm = base1h + ki1h * abs(L1H_sum) + kp1h * abs(L1H_err);                      //Cal. pwm

    if(l1h_pwm>slope_constrain)
    l1h_pwm=slope_constrain;
    else if(l1h_pwm<0)
    l1h_pwm=0; 
    analogWrite(L1Hpwm, l1h_pwm);                                   //Run leg
    } 
  }

else if(abs(L1H_err)>2*abs(L1H_initial-valh)/3)
  {
//    Serial.println(">2/3");
    l1h_pwm = l1h_pwm + 2;
    digitalWrite(L1Hdir, L1H_err < 0);  
    if(l1h_pwm>slope_constrain)
    l1h_pwm=slope_constrain;
    else if(l1h_pwm<0)
    l1h_pwm=0; 
    
    analogWrite(L1Hpwm,l1h_pwm);
        
                                       //Run leg
   }

else if(abs(L1H_initial-valh)/3 < abs(L1H_err) && abs(L1H_err) < 2*abs(L1H_initial-valh)/3)
  {
//    Serial.println("bet");
    l1h_pwm=100;
    digitalWrite(L1Hdir, L1H_err < 0);
    if(l1h_pwm>slope_constrain)
    l1h_pwm=slope_constrain;
    else if(l1h_pwm<0)
    l1h_pwm=0; 
    
    analogWrite(L1Hpwm,l1h_pwm);                                   //Run leg
  }
  
}


void L2_H_MovB(int16_t valh)                                                       //front reading < back reading and back_direction=1
{
  // valh=map(valh,0,250,L1Hback,L1Hfront);                                       
  L2H_val = analogRead(L2Hpot);
  L2H_err = (L2H_val - valh);
  
  if (abs(L2H_err) < 80)
 {
   if(abs(L2H_err)< thrs2h)
   {
    flag2h = 1;
    digitalWrite(L2Hdir, L2H_err> 0);  
    analogWrite(L2Hpwm, 0);
   }
   
    else
    {
//    Serial.print("   L2H   ");
    L2H_val = analogRead(L2Hpot);                                                      //Read pot
    L2H_err = L2H_val - valh;                                                          //Cal.Error
    L2H_sum = L2H_sum + L2H_err;
    digitalWrite(L2Hdir, L2H_err > 0);                                                //Def. dir
    //Serial.print(L2H_val);
    l2h_pwm = base2h+ ki2h * abs(L2H_sum) + kp2h * abs(L2H_err);                      //Cal. pwm
    if(l2h_pwm>slope_constrain)
    l2h_pwm=slope_constrain;
    else if(l2h_pwm<0)
    l2h_pwm=0; 
    
    analogWrite(L2Hpwm,l2h_pwm);
    } 
  }
else if(abs(L2H_err)>2*abs(L2H_initial-valh)/3)
  {
    l2h_pwm = l2h_pwm + 2;
    digitalWrite(L2Hdir, L2H_err > 0);  
    if(l2h_pwm>slope_constrain)
    l2h_pwm=slope_constrain;
    else if(l2h_pwm<0)
    l2h_pwm=0;     
    analogWrite(L2Hpwm,l2h_pwm);
    //    Serial.println(">2/3");
//    Serial.print(l2h_pwm);
//    Serial.print("\t ");
//    Serial.println(L2H_err);
//                                       //Run leg
   }

else if(abs(L2H_initial-valh)/3 < abs(L2H_err) && abs(L2H_err) < 2*abs(L2H_initial-valh)/3)
  {
    l2h_pwm=slope_constrain;
    digitalWrite(L2Hdir, L2H_err > 0);                                            //since front value is less than back  
    analogWrite(L2Hpwm,constrain(l2h_pwm,0,200));
 //   Serial.print(l2h_pwm);
//    Serial.println("bet");    
//    Serial.println(L2H_err);
    if(l2h_pwm>slope_constrain)
    l2h_pwm=slope_constrain;
    else if(l2h_pwm<0)
    l2h_pwm=0; 
    
    analogWrite(L2Hpwm,l2h_pwm);
    }
  
}

void L3_H_MovB(int16_t valh)                                                       //front reading > back reading and back_direction=1
{
  // valh=map(valh,0,250,L1Hback,L1Hfront);                                        
  L3H_val = analogRead(L3Hpot);
  L3H_err = (L3H_val - valh);
if (abs(L3H_err) < 80)
 {
   if(abs(L3H_err)< thrs3h)
   {
    flag3h = 1;
    digitalWrite(L3Hdir, L3H_err > 0);  
    analogWrite(L3Hpwm, 0);
   }
   
    else
    {
    L3H_val = analogRead(L3Hpot);                                                      //Read pot
    L3H_err = L3H_val - valh;                                                          //Cal.Error
    L3H_sum = L3H_sum + L3H_err;
    digitalWrite(L3Hdir, L3H_err > 0);                                                //Def. dir
    //Serial.print(L1H_val);
    l3h_pwm = base3h + ki3h * abs(L3H_sum) + kp3h * abs(L3H_err);                      //Cal. pwm
    
    if(l3h_pwm>slope_constrain)
    l3h_pwm=slope_constrain;
    else if(l3h_pwm<0)
    l3h_pwm=0; 
    
    analogWrite(L3Hpwm,l3h_pwm);
    } 
  }

else if(abs(L3H_err)>2*abs(L3H_initial-valh)/3)
  {
    l3h_pwm = l3h_pwm + 2;
    digitalWrite(L3Hdir, L3H_err > 0);                                      //since front reading > back reading and direction for 3Hback=1 
    if(l3h_pwm>slope_constrain)
    l3h_pwm=slope_constrain;
    else if(l3h_pwm<0)
    l3h_pwm=0; 
    
    analogWrite(L3Hpwm,l3h_pwm);
                                       //Run leg
   }

else if(abs(L3H_initial-valh)/3 < abs(L3H_err) && abs(L3H_err) < 2*abs(L3H_initial-valh)/3)
  {
    l3h_pwm=slope_constrain;
    digitalWrite(L3Hdir, L3H_err > 0);                                            //since front value is less than back  
//    Serial.print(l3h_pwm);
    if(l3h_pwm>slope_constrain)
    l3h_pwm=slope_constrain;
    else if(l3h_pwm<0)
    l3h_pwm=0; 
    
    analogWrite(L3Hpwm,l3h_pwm);
    
  }
}


void L4_H_MovB(int16_t valh)                                                       //front reading > back reading and back_direction=1
{
  // valh=map(valh,0,250,L1Hback,L1Hfront);                                        
  L4H_val = analogRead(L4Hpot);
  L4H_err = (L4H_val - valh);

  if (abs(L4H_err) < 80)
 {
   if(abs(L4H_err)< thrs4h)
   {
    flag4h = 1;
    digitalWrite(L4Hdir, L4H_err > 0);  
    analogWrite(L4Hpwm, 0);
   }
   
    else
    {
    L4H_val = analogRead(L4Hpot);                                                      //Read pot
    L4H_err = L4H_val - valh;                                                          //Cal.Error
    L4H_sum = L4H_sum + L4H_err;
    digitalWrite(L4Hdir,L4H_err > 0);                                                //Def. dir
    //Serial.print(L1H_val);
    l4h_pwm = base4h+ ki4h * abs(L4H_sum) + kp4h * abs(L4H_err);                      //Cal. pwm
   
    if(l4h_pwm>slope_constrain)
    l4h_pwm=slope_constrain;
    else if(l4h_pwm<0)
    l4h_pwm=0; 
    
    analogWrite(L4Hpwm,l4h_pwm);
    } 
  }
else if(abs(L4H_err)>2*abs(L4H_initial-valh)/3)
  {
    l4h_pwm = l4h_pwm + 2;
    digitalWrite(L4Hdir, L4H_err > 0);  
    if(l4h_pwm>slope_constrain)
    l4h_pwm=slope_constrain;
    else if(l4h_pwm<0)
    l4h_pwm=0; 
    
    analogWrite(L4Hpwm,l4h_pwm);
                                       //Run leg
   }

else if(abs(L4H_initial-valh)/3 < abs(L4H_err) && abs(L4H_err) < 2*abs(L4H_initial-valh)/3)
  {
    l4h_pwm=slope_constrain;
    digitalWrite(L4Hdir, L4H_err > 0);                                            //since front value is less than back  
    if(l4h_pwm>slope_constrain)
    l4h_pwm=slope_constrain;
    else if(l4h_pwm<0)
    l4h_pwm=0; 
    
    analogWrite(L4Hpwm,l4h_pwm);
   }
}
