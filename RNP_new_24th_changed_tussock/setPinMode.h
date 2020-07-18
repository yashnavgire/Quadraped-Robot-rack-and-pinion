void setPM() 
{
  pinMode(L1Hpwm , OUTPUT);
  pinMode(L1Hdir , OUTPUT);
  pinMode(L1Hpot , INPUT);

  pinMode(L1Vpwm , OUTPUT);
  pinMode(L1Vdir , OUTPUT);
  pinMode(L1Vpot , INPUT);

  pinMode(L2Hpwm , OUTPUT);
  pinMode(L2Hdir , OUTPUT);
  pinMode(L2Hpot , INPUT);

  pinMode(L2Vpwm , OUTPUT);
  pinMode(L2Vdir , OUTPUT);
  pinMode(L2Vpot , INPUT);

  pinMode(L3Hpwm , OUTPUT);
  pinMode(L3Hdir , OUTPUT);
  pinMode(L3Hpot , INPUT);

  pinMode(L3Vpwm , OUTPUT);
  pinMode(L3Vdir , OUTPUT);
  pinMode(L3Vpot , INPUT);

  pinMode(L4Hpwm , OUTPUT);
  pinMode(L4Hdir , OUTPUT);
  pinMode(L4Hpot , INPUT);

  pinMode(L4Vpwm , OUTPUT);
  pinMode(L4Vdir , OUTPUT);
  pinMode(L4Vpot , INPUT);
//LS
  pinMode(LS_L1, INPUT_PULLUP);
  pinMode(LS_L2, INPUT_PULLUP);
  pinMode(LS_L3, INPUT_PULLUP);
  pinMode(LS_L4, INPUT_PULLUP);
  
//  pinMode(LS_L1b, INPUT_PULLUP);
//  pinMode(LS_L2b, INPUT_PULLUP);
//  pinMode(LS_L3b, INPUT_PULLUP);
//  pinMode(LS_L4b, INPUT_PULLUP);

//  pinMode(L1V_hall, INPUT_PULLUP);
//  pinMode(L2V_hall, INPUT_PULLUP);
//  pinMode(L3V_hall, INPUT_PULLUP);
//  pinMode(L4V_hall, INPUT_PULLUP);

  pinMode(mode_select,INPUT);
  pinMode(start_L1,INPUT);
  pinMode(sd_L2,INPUT);
  pinMode(tus_dir ,INPUT);
  pinMode(initial,INPUT);
  pinMode(motor_pwm ,INPUT);

//ultra
    pinMode(ultra_trig_pin4,OUTPUT);
    pinMode(ultra_echo_pin4,INPUT);
    pinMode(ultra_trig_pin1,OUTPUT);
    pinMode(ultra_echo_pin1,INPUT);
    
  pinMode(LS_G,INPUT_PULLUP);


  pinMode(mpu_mode,OUTPUT);
  pinMode(mpu1,INPUT);
  pinMode(mpu2,INPUT);

  pinMode(Upwm,OUTPUT);
  pinMode(Udir,OUTPUT);

  pinMode(proxy_mountain ,INPUT);
  
  
//  pinMode(52,OUTPUT);
}
