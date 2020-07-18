/* Horizontal and Vertical(UP and D) functions*/

void L1_H_Mov(int16_t valh)                                                       //front reading < back reading and back_direction=1
{
  // valh=map(valh,0,250,L1Hback,L1Hfront);                                
  L1H_val = analogRead(L1Hpot);
  L1H_err = (L1H_val - valh);
//   Serial.println("<80");
if (abs(L1H_err) < 80)
 { 
   if(abs(L1H_err)< thrs1h || flag1h==1)
   {
    flag1h = 1;
    digitalWrite(L1Hdir, L1H_err > 0);  
    analogWrite(L1Hpwm, 0);
   }
   
    else
    {
//    Serial.print("   L1H   ");
    L1H_val = analogRead(L1Hpot);                                                      //Read pot
    L1H_err = L1H_val - valh;                                                          //Cal.Error
    L1H_sum = L1H_sum + L1H_err;
    digitalWrite(L1Hdir, L1H_err > 0);                                                //Def. dir
    //Serial.print(L1H_val);
    l1h_pwm = base1h+ ki1h * abs(L1H_sum) + kp1h * abs(L1H_err);                      //Cal. pwm

    if(l1h_pwm>L1H_pwm_constrain)
    l1h_pwm=L1H_pwm_constrain;
    else if(l1h_pwm<0)
    l1h_pwm=0; 
    analogWrite(L1Hpwm, l1h_pwm);                                   //Run leg
    } 
  }

else if(abs(L1H_err)>2*abs(L1H_initial-valh)/3)
  {
//    Serial.println(">2/3");
    l1h_pwm = l1h_pwm + 12;
    digitalWrite(L1Hdir, L1H_err > 0);  
    if(l1h_pwm>L1H_pwm_constrain)
    l1h_pwm=L1H_pwm_constrain;
    else if(l1h_pwm<0)
    l1h_pwm=0; 
    
    analogWrite(L1Hpwm,l1h_pwm);
                                       //Run leg
   }

else if(abs(L1H_initial-valh)/3 < abs(L1H_err) && abs(L1H_err) < 2*abs(L1H_initial-valh)/3)
  {
//    Serial.println("bet");
    l1h_pwm=L1H_pwm_constrain;
    digitalWrite(L1Hdir, L1H_err > 0);
    if(l1h_pwm>L1H_pwm_constrain)
    l1h_pwm=L1H_pwm_constrain;
    else if(l1h_pwm<0)
    l1h_pwm=0; 
    
//since front value is less than back  
//    analogWrite(L1Hpwm,constrain(l1h_pwm,0,100));
//    Serial.print(l1h_pwm);
//    Serial.print("\t ");    
//    Serial.println(L1H_err);
    
    analogWrite(L1Hpwm,l1h_pwm);                                   //Run leg
  }
  
}


void L1_V_MovUP(int16_t valv)
{
  L1V_val = analogRead(L1Vpot);
  L1V_err = (L1V_val - valv);

  if(abs(L1V_err)<10)
  {
    flag1_up=1;
    if(abs(L1V_err)<thrs1v)
    {
      analogWrite(L1Vpwm,0);
      flag1_up=0;
      flag1vu=1;
    }
    else if(flag1vu==1)
    {
      analogWrite(L1Vpwm,0);
      flag1_up=0;
    }
  }
  else
  {
  L1V_sum = L1V_sum+L1V_err;
  l1v_pwm = base1v + abs(L1V_err) * (kp1v+0.3) + ki1v*abs(L1V_sum);
  digitalWrite(L1Vdir, L1V_err>0);
  
  if(l1v_pwm>L1V_up_constrain)
  l1v_pwm=L1V_up_constrain;
  else if(l1v_pwm<0)
  l1v_pwm=0;
  analogWrite(L1Vpwm ,l1v_pwm);
  }
}

void L1_V_MovD(int16_t valv)                                                          
{
  L1V_val = analogRead(L1Vpot);
  L1V_err = (L1V_val - valv);

  if (abs(L1V_err) < thrs1v||flag1vd==1)
  {
    flag1vd = 1;
    analogWrite(L1Vpwm, 0);
   // state=2;
//    delay(300);
  }
  else
  {
//    Serial.print("   L1V    ");
    L1V_val = analogRead(L1Vpot);                                                       //Read pot
    L1V_err = L1V_val - valv;                                                           //Cal.Error
    L1V_sum = L1V_sum + L1V_err;
    digitalWrite(L1Vdir, L1V_err>0);                                                 //Def. dir
//    Serial.print(L1V_val);
//    Serial.print("\t ");
    l1v_pwm = ki1v * abs(L1V_sum) + kp1v * abs(L1V_err);                      //Cal. pwm
//    Serial.print("  ");
//    Serial.print(l1v_pwm);
//    Serial.println("\t ");
  if(l1v_pwm>L1V_down_constrain)
  l1v_pwm=L1V_down_constrain;
  else if(l1v_pwm<0)
  l1v_pwm=0;
  
  analogWrite(L1Vpwm ,l1v_pwm);
  }
}

void L2_H_Mov(int16_t valh)                                                       //front reading < back reading and back_direction=1
{
  // valh=map(valh,0,250,L1Hback,L1Hfront);                                       
  L2H_val = analogRead(L2Hpot);
  L2H_err = (L2H_val - valh);
  
  if (abs(L2H_err) < 80)
 {
   if(abs(L2H_err)< thrs2h || flag2h==1)
   {
    flag2h = 1;
    digitalWrite(L2Hdir, L2H_err< 0);  
    analogWrite(L2Hpwm, 0);
   }
   
    else
    {
//    Serial.print("   L2H   ");
    L2H_val = analogRead(L2Hpot);                                                      //Read pot
    L2H_err = L2H_val - valh;                                                          //Cal.Error
    L2H_sum = L2H_sum + L2H_err;
    digitalWrite(L2Hdir, L2H_err < 0);                                                //Def. dir
    //Serial.print(L2H_val);
    l2h_pwm = base2h+ ki2h * abs(L2H_sum) + kp2h * abs(L2H_err);                      //Cal. pwm
    if(l2h_pwm>L2H_pwm_constrain)
    l2h_pwm=L2H_pwm_constrain;
    else if(l2h_pwm<0)
    l2h_pwm=0; 
    
    analogWrite(L2Hpwm,l2h_pwm);
    } 
  }
else if(abs(L2H_err)>2*abs(L2H_initial-valh)/3)
  {
    l2h_pwm = l2h_pwm + 12;
    digitalWrite(L2Hdir, L2H_err < 0);  
    if(l2h_pwm>L2H_pwm_constrain)
    l2h_pwm=L2H_pwm_constrain;
    else if(l2h_pwm<0)
    l2h_pwm=0;     
    analogWrite(L2Hpwm,l2h_pwm);
//                                       //Run leg
   }

else if(abs(L2H_initial-valh)/3 < abs(L2H_err) && abs(L2H_err) < 2*abs(L2H_initial-valh)/3)
  {
    l2h_pwm=L2H_pwm_constrain;
    digitalWrite(L2Hdir, L2H_err < 0);                                            //since front value is less than back  
    analogWrite(L2Hpwm,constrain(l2h_pwm,0,200));
    if(l2h_pwm>L2H_pwm_constrain)
    l2h_pwm=L2H_pwm_constrain;
    else if(l2h_pwm<0)
    l2h_pwm=0; 
    
    analogWrite(L2Hpwm,l2h_pwm);
    }
  
}


/*void L2_V_MovUP(int16_t valv)
{
  L2V_val = analogRead(L2Vpot);
  L2V_err = (L2V_val - valv);

  if(abs(L2V_err)<thrs2v)
  {
    analogWrite(L2Vpwm,L2V_err>0);
    flag2vu=1;
//    state=1;
//    delay(300);
  }
  else
  {
  l2v_pwm = abs(L2V_err) * (kp2v+0.5)+;
//  Serial.print(l2v_pwm);
//  Serial.print("\t");
//  Serial.println(L2V_val);
  if(l2v_pwm>255)
  l2v_pwm=255;
  else if(l2v_pwm<0)
  l2v_pwm=0;
  digitalWrite(L2Vdir, L2V_err>0);
  analogWrite(L2Vpwm ,l2v_pwm);
  }
}
*/
void L2_V_MovUP(int16_t valv)                                                          
{
  L2V_val = analogRead(L2Vpot);
  L2V_err = (L2V_val - valv);

  if (abs(L2V_err) < 10)
  {
    flag2_up=1;
    if(abs(L2V_err)<thrs2v)
    {
      analogWrite(L2Vpwm,0);
      flag2_up=0;
      flag2vu=1;
    }
    else if(flag2vu==1)
    {
     analogWrite(L2Vpwm, 0);
     flag2_up=0;
   }
   // state=2;
   // delay(300);
  }
  else
  {

    L2V_val = analogRead(L2Vpot);                                                       //Read pot
    L2V_err = L2V_val - valv;                                                           //Cal.Error
    L2V_sum = L2V_sum + abs(L2V_err);
    digitalWrite(L2Vdir,L2V_err>0);                                                 //Def. dir
    l2v_pwm = ki2v * abs(L2V_sum) + (kp2v +0.5)* abs(L2V_err) ;                      //Cal. pwm
    if(l2v_pwm>L2V_up_constrain)
      l2v_pwm=L2V_up_constrain;
    else if(l2v_pwm<0)
      l2v_pwm=0;
  analogWrite(L2Vpwm ,l2v_pwm);
   }
}

//void L2_V_MovUP_LS(int16_t valv)                                                          
//{
//  L2V_val = analogRead(L2Vpot);
//  L2V_err = (L2V_val - valv);
//
//
//  if(digitalRead(LS_L2up)==0)
//  {
//    analogWrite(L2Vpwm,0);
//    flag2vu=1;
//  }
//  else if(abs(L2V_err)<thrs2v && digitalRead(LS_L2up)==1)
//  {
//    digitalWrite(L2Vdir,0);
//    analogWrite(L2Vpwm,50);
////    flag4vu=1;
////  Serial.println("A");
//  }
//  else
//  {
//
//    L2V_val = analogRead(L2Vpot);                                                       //Read pot
//    L2V_err = L2V_val - valv;                                                           //Cal.Error
//    L2V_sum = L2V_sum + abs(L2V_err);
//    digitalWrite(L2Vdir,L2V_err>0);                                                 //Def. dir
//
//    l2v_pwm = ki2v * abs(L2V_sum) + (kp2v +0.5)* abs(L2V_err) ;                      //Cal. pwm
//
//  if(l2v_pwm>L2V_up_constrain)
//  l2v_pwm=L2V_up_constrain;
//  else if(l2v_pwm<0)
//  l2v_pwm=0;
//  analogWrite(L2Vpwm ,l2v_pwm);
//                                  //Run leg
//  }
//}

void L2_V_MovD(int16_t valv)                                                          
{
  L2V_val = analogRead(L2Vpot);
  L2V_err = (L2V_val - valv);

  if (abs(L2V_err) < thrs2v||flag2vd==1)
  {
    flag2vd = 1;
    analogWrite(L2Vpwm, 0);
   // state=2;
   // delay(300);
  }
  else
  {
//    Serial.print("   L2V    ");
    L2V_val = analogRead(L2Vpot);                                                       //Read pot
    L2V_err = L2V_val - valv;                                                           //Cal.Error
    L2V_sum = L2V_sum + L2V_err;
    digitalWrite(L2Vdir,L2V_err>0);                                                 //Def. dir
//    Serial.print(L2V_val);
//    Serial.print("\t ");
    l2v_pwm = ki2v * abs(L2V_sum) + kp2v * abs(L2V_err);                      //Cal. pwm
//    Serial.print("  ");
//    Serial.print(l2v_pwm);
//    Serial.println("\t ");
  if(l2v_pwm>L2V_down_constrain)
  l2v_pwm=L2V_down_constrain;
  else if(l2v_pwm<0)
  l2v_pwm=0;
  analogWrite(L2Vpwm ,l2v_pwm);
                                  //Run leg
  }
}

void L3_H_Mov(int16_t valh)                                                       //front reading > back reading and back_direction=1
{
  // valh=map(valh,0,250,L1Hback,L1Hfront);                                        
  L3H_val = analogRead(L3Hpot);
  L3H_err = (L3H_val - valh);
if (abs(L3H_err) < 80)
 {
   if(abs(L3H_err)< thrs3h || flag3h==1)
   {
    flag3h = 1;
    digitalWrite(L3Hdir, L3H_err < 0);  
    analogWrite(L3Hpwm, 0);
   }
   
    else
    {
    L3H_val = analogRead(L3Hpot);                                                      //Read pot
    L3H_err = L3H_val - valh;                                                          //Cal.Error
    L3H_sum = L3H_sum + L3H_err;
    digitalWrite(L3Hdir, L3H_err < 0);                                                //Def. dir
    //Serial.print(L1H_val);
    l3h_pwm = base3h + ki3h * abs(L3H_sum) + kp3h * abs(L3H_err);                      //Cal. pwm
    
    if(l3h_pwm>L3H_pwm_constrain)
    l3h_pwm=L3H_pwm_constrain;
    else if(l3h_pwm<0)
    l3h_pwm=0; 
    
    analogWrite(L3Hpwm,l3h_pwm);
    } 
  }

else if(abs(L3H_err)>2*abs(L3H_initial-valh)/3)
  {
    l3h_pwm = l3h_pwm + 12;
    digitalWrite(L3Hdir, L3H_err < 0);                                      //since front reading > back reading and direction for 3Hback=1 
    if(l3h_pwm>L3H_pwm_constrain)
    l3h_pwm=L3H_pwm_constrain;
    else if(l3h_pwm<0)
    l3h_pwm=0; 
    
    analogWrite(L3Hpwm,l3h_pwm);
                                       //Run leg
   }

else if(abs(L3H_initial-valh)/3 < abs(L3H_err) && abs(L3H_err) < 2*abs(L3H_initial-valh)/3)
  {
    l3h_pwm=L3H_pwm_constrain;
    digitalWrite(L3Hdir, L3H_err < 0);                                            //since front value is less than back  
//    Serial.print(l3h_pwm);
    if(l3h_pwm>L3H_pwm_constrain)
    l3h_pwm=L3H_pwm_constrain;
    else if(l3h_pwm<0)
    l3h_pwm=0; 
    
    analogWrite(L3Hpwm,l3h_pwm);
    
  }
}


void L3_V_MovUP(int16_t valv)
{
  L3V_val = analogRead(L3Vpot);
  L3V_err = (L3V_val - valv);

  if(abs(L3V_err)<10)
  {
    if(abs(L3V_err)<thrs3v)
    {
      analogWrite(L3Vpwm,0);
      flag3_up=0;
      flag3vu=1;
    }
    else if(flag3vu==1)
    {
    analogWrite(L3Vpwm,0);
    flag3_up=0;
    }
  }
  else
  {
   L3V_sum=L3V_sum  + L3V_err;
   l3v_pwm = base3v + abs(L3V_err) * (kp3v+0.3) + ki3v*abs(L3V_sum);
    
    digitalWrite(L3Vdir, L3V_err>0);
    if(l3v_pwm>L3V_up_constrain)
    l3v_pwm=L3V_up_constrain;
    else if(l3v_pwm<0)
    l3v_pwm=0; 
    analogWrite(L3Vpwm,l3v_pwm);
   }
}


void L3_V_MovD(int16_t valv)                                                          
{
  L3V_val = analogRead(L3Vpot);
  L3V_err = (L3V_val - valv);

  if (abs(L3V_err) < thrs3v||flag3vd==1)
  {
    flag3vd = 1;
    analogWrite(L3Vpwm, 0);
   
  }
  else
  {
    L3V_val = analogRead(L3Vpot);                                                       //Read pot
    L3V_err = L3V_val - valv;                                                           //Cal.Error
    L3V_sum = L3V_sum + L3V_err;
    digitalWrite(L3Vdir, L3V_err>0);                                                    //Def. dir
    l3v_pwm = ki3v * abs(L3V_sum) + kp3v * abs(L3V_err);                                //Cal. pwm
    
    if(l3v_pwm>L3V_down_constrain)
    l3v_pwm=L3V_down_constrain;
    else if(l3v_pwm<0)
    l3v_pwm=0; 
    
    analogWrite(L3Vpwm,l3v_pwm);
  }
}

void L4_H_Mov(int16_t valh)                                                       //front reading > back reading and back_direction=1
{
  // valh=map(valh,0,250,L1Hback,L1Hfront);                                        
  L4H_val = analogRead(L4Hpot);
  L4H_err = (L4H_val - valh);

  if (abs(L4H_err) < 80)
 {
   if(abs(L4H_err)< thrs4h || flag4h==1)
   {
    flag4h = 1;
    digitalWrite(L4Hdir, L4H_err < 0);  
    analogWrite(L4Hpwm, 0);
   }
   
    else
    {
    L4H_val = analogRead(L4Hpot);                                                      //Read pot
    L4H_err = L4H_val - valh;                                                          //Cal.Error
    L4H_sum = L4H_sum + L4H_err;
    digitalWrite(L4Hdir,L4H_err < 0);                                                //Def. dir
    //Serial.print(L1H_val);
    l4h_pwm = base4h+ ki4h * abs(L4H_sum) + kp4h * abs(L4H_err);                      //Cal. pwm
   
    if(l4h_pwm>L4H_pwm_constrain)
    l4h_pwm=L4H_pwm_constrain;
    else if(l4h_pwm<0)
    l4h_pwm=0; 
    
    analogWrite(L4Hpwm,l4h_pwm);
    } 
  }
else if(abs(L4H_err)>2*abs(L4H_initial-valh)/3)
  {
    l4h_pwm = l4h_pwm + 12;
    digitalWrite(L4Hdir, L4H_err < 0);  
    if(l4h_pwm>L4H_pwm_constrain)
    l4h_pwm=L4H_pwm_constrain;
    else if(l4h_pwm<0)
    l4h_pwm=0; 
    
    analogWrite(L4Hpwm,l4h_pwm);
                                       //Run leg
   }

else if(abs(L4H_initial-valh)/3 < abs(L4H_err) && abs(L4H_err) < 2*abs(L4H_initial-valh)/3)
  {
    l4h_pwm=L4H_pwm_constrain;
    digitalWrite(L4Hdir, L4H_err < 0);                                            //since front value is less than back  
    if(l4h_pwm>L4H_pwm_constrain)
    l4h_pwm=L4H_pwm_constrain;
    else if(l4h_pwm<0)
    l4h_pwm=0; 
    
    analogWrite(L4Hpwm,l4h_pwm);
   }
}

void L4_V_MovUP(int16_t valv)
{
  L4V_val = analogRead(L4Vpot);
  L4V_err = (L4V_val - valv);

  if(abs(L4V_err)<10)
  {
    flag4_up=1;
    if(abs(L4V_err)<thrs4v)
    {
      analogWrite(L4Vpwm,0);
      flag4_up=0;
      flag4vu=1;
    }
    else if(flag4vu==1)
    {
    analogWrite(L4Vpwm,0);
    flag4_up=0;
    }
  }
  else
  {
  L4V_sum=L4V_sum+L4V_err;
  l4v_pwm = base4v + abs(L4V_err) * (kp4v+0.3) + ki4v*abs(L4V_sum);
  digitalWrite(L4Vdir,L4V_err>0);
    
  if(l4v_pwm>L4V_up_constrain)
  l4v_pwm=L4V_up_constrain;
  else if(l4v_pwm<0)
  l4v_pwm=0; 
    
  analogWrite(L4Vpwm,l4v_pwm);
  }

}

void L4_V_MovUP_IR(int16_t valv)
{
  L4V_val = analogRead(L4Vpot);
  L4V_err = (L4V_val - valv);

  if(flag4vu==1)
  {
    analogWrite(L4Vpwm,0);
//    flag4vu=1;
  }
  else if(abs(L4V_err)<thrs4v && flag4vu==0)
  {
    digitalWrite(L4Vdir,0);
    analogWrite(L4Vpwm,40);
//    flag4vu=1;
//  Serial.println("A");
  }
  else
  {
  L4V_sum=L4V_sum+L4V_err;
  l4v_pwm = base4v + abs(L4V_err) * (kp4v+0.3) + ki4v*abs(L4V_sum);
  digitalWrite(L4Vdir,0);                                   //L4V_err>0
    
  if(l4v_pwm>L4V_up_constrain)
  l4v_pwm=L4V_up_constrain;
  else if(l4v_pwm<0)
  l4v_pwm=0; 
//    Serial.println("pwm");
  analogWrite(L4Vpwm,l4v_pwm);
  }
}



void L4_V_MovD(int16_t valv)                                                          
{
  L4V_val = analogRead(L4Vpot);
  L4V_err = (L4V_val - valv);

  if (abs(L4V_err) < thrs4v)
  {
    flag4vd = 1;
    analogWrite(L4Vpwm, 0);
  }
  else
  {
    L4V_val = analogRead(L4Vpot);                                                       //Read pot
    L4V_err = L4V_val - valv;                                                           //Cal.Error
    L4V_sum = L4V_sum + L4V_err;
    digitalWrite(L4Vdir, L4V_err>0);                                                 //Def. dir

    l4v_pwm = ki4v * abs(L4V_sum) + kp4v * abs(L4V_err);                      //Cal. pwm

    if(l4v_pwm>L4V_down_constrain)
    l4v_pwm=L4V_down_constrain;
    else if(l4v_pwm<0)
    l4v_pwm=0; 
    
    analogWrite(L4Vpwm,l4v_pwm);
  }
}



void const_all_down()
{ 
  L4V_val = analogRead(L4Vpot);
  L4V_err = (L4V_val - L4V_down);

  L3V_val = analogRead(L3Vpot);
  L3V_err = (L3V_val - L3V_down);

  L2V_val = analogRead(L2Vpot);
  L2V_err = (L2V_val - L2V_down);

  L1V_val = analogRead(L1Vpot);
  L1V_err = (L1V_val - L1V_down);

  if (abs(L4V_err) < thrs4v || flag4vd ==1)
  {
    flag4vd = 1;
    analogWrite(L4Vpwm, 0);
  }
  else
  {
    digitalWrite(L4Vdir, L4V_err>0);                                                 //Def. dir
    analogWrite(L4Vpwm,L4V_down_constrain);
  }
   
  if (abs(L3V_err) < thrs3v || flag3vd ==1)
  {
    flag3vd = 1;
    analogWrite(L3Vpwm, 0);
  }
  else
  {
    digitalWrite(L3Vdir, L3V_err>0);                                                 //Def. dir
    analogWrite(L3Vpwm,L3V_down_constrain);
  }
  
  if (abs(L2V_err) < thrs2v || flag2vd ==1)
  {
    flag2vd = 1;
    analogWrite(L2Vpwm, 0);
  }
  else
  {
    digitalWrite(L2Vdir, L2V_err>0);                                                 //Def. dir
    analogWrite(L2Vpwm,L2V_down_constrain);
  }
  
  if (abs(L1V_err) < thrs1v || flag1vd ==1)
  {
    flag1vd = 1;
    analogWrite(L1Vpwm, 0);
  }
  else
  {
    digitalWrite(L1Vdir, L1V_err>0);                                                 //Def. dir
    analogWrite(L1Vpwm,L1V_down_constrain);
  }
  
}
