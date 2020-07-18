///* VARIABLES and CONSTANTS*/
/*********************************************************************************/
// sanddune down @26cm
// downmid @18cm
/************Constrains************/
int L1H_pwm_constrain = 150;      //200 for sanddune when front is to be taken. 130 for after sanddune                        (used in horizontal mov functions,updated in diagonal,turning,sanddune-initial and tussock)
int L1V_up_constrain = 150;       //Up and down 150 for Sand-dune initially on sanddune it is 70. For After tussock 150 & 120 (used in vertical mov functions,)
int L1V_down_constrain = 130;     

int L2H_pwm_constrain = 150;
int L2V_up_constrain = 150;
int L2V_down_constrain = 120;

int L3H_pwm_constrain = 150;
int L3V_up_constrain = 150;
int L3V_down_constrain =120;

int L4H_pwm_constrain = 150;
int L4V_up_constrain = 150;
int L4V_down_constrain = 120;
/***********************************/


#define kp1h    2  
#define kph1    1.3              
#define kp1v    2.5
#define ki1h    0.0007
#define kih1    0.0007
#define ki1v    0.007
#define ang_kp1v  2
#define thrs1h  10
#define thrs1v  5
#define thrs_p  5

int L1V_downmid =619, L1V_down = 713;
int L1H_val , L1H_front = 242 , L1H_diff=235, L1H_back = L1H_front+L1H_diff ,L1H_initial=L1H_back;
int L1H_err = 0 , val1h = L1H_front , base1h = 0 , L1H_mid=(L1H_back+L1H_front)/2 , L1H_midf = L1H_front + (L1H_back-L1H_front)/3 , L1H_midb = L1H_front + 2*L1H_diff/3;
int L1H_mid4=L1H_front+L1H_diff/4;
int L1V_diff_sand = 200,L1V_diff_sand_mid=110;
int L1V_diff = 70;                 //change this,done for tussock initial.
int L1V_val  , L1V_up = L1V_down-L1V_diff,L1V_up_sand=L1V_down-L1V_diff_sand , L1V_sand_mid= L1V_down-L1V_diff_sand_mid;
int L1V_err = 0, val1v = L1V_up , base1v = 0 , ang_base1v=40;
int L1V_upmid=L1V_downmid-60;
int l1v_pwm = 0 , l1h_pwm = 0;
int L1V_sum = 0 , L1H_sum = 0;
volatile bool flag1vu = 0 , flag1vd = 0 , flag1h = 0,flag1_up=0,flag1_down=0;
int ppos1v = 487;
int stall_base1v=10;
volatile int hall_count1v=0;

/*LEG 2*/
#define kp2h    2
#define kph2    1.3
#define kp2v    2.7
#define ki2h    0.00095
#define kih2    0.00095
#define ki2v    0.007
#define ang_kp2v  2

#define thrs2h  10
#define thrs2v 5

int L2V_downmid =518 ,  L2V_down = 432;
int L2H_val , L2H_front = 463, L2H_diff=225,L2H_back = L2H_front+L2H_diff ,L2H_initial=L2H_front;
int L2H_err = 0 , base2h = 0,L2H_mid=(L2H_back+L2H_front)/2,L2H_midf=L2H_front+(L2H_back-L2H_front)/3,L2H_midb=L2H_front+2*L2H_diff/3;
int val2h = L2H_mid, L2H_mid4=L2H_front+L2H_diff/4; ;
int L2V_diff_sand = 190;                //190 originally
int L2V_diff = 70,L2V_diff_sand_mid=107;
int L2V_val  , L2V_up = L2V_down+L2V_diff,L2V_up_sand = L2V_down+L2V_diff_sand ,L2V_sand_mid= L2V_down+L2V_diff_sand_mid;
int L2V_err = 0, val2v = L2V_up , base2v = 0,ang_base2v=40;
int L2V_upmid=L2V_downmid+60;

int l2v_pwm = 0 , l2h_pwm = 0;
int L2V_sum = 0 , L2H_sum = 0;
volatile bool flag2vu = 0 ,flag2vd=0, flag2h = 0,flag2_up=0,flag2_down=0;;
int ppos2v = 745;
int stall_base2v=10;
volatile int hall_count2v=0;

/*LEG 3*/
#define kp3h    2.1
#define kph3    1.3
#define kp3v    2.5
#define ki3h    0.0012
#define kih3    0.0007
#define ki3v    0.007
#define ang_kp3v  2
#define thrs3h  10
#define thrs3v  5

int L3V_downmid =647 , L3V_down = 752; 
int L3H_val , L3H_front = 500  ,L3H_diff=235, L3H_back = L3H_front-L3H_diff , L3H_initial=L3H_back;
int L3H_err = 0, val3h = L3H_front , base3h = 0,L3H_mid=(L3H_back+L3H_front)/2, L3H_midf=L3H_front+(L3H_back-L3H_front)/3, L3H_midb=L3H_front-2*L3H_diff/3;
int L3H_mid4=L3H_front-L3H_diff/4;
int L3V_diff_sand= 190,L3V_diff_sand_mid=120;                   //204 originally
int L3V_diff = 70 ;
int L3V_val ,  L3V_up = L3V_down-L3V_diff,L3V_up_sand = L3V_down-L3V_diff_sand,L3V_sand_mid= L3V_down-L3V_diff_sand_mid;
int L3V_err = 0, val3v = L3V_up , base3v = 0,ang_base3v=40;
int L3V_upmid=L3V_downmid-60;

int l3v_pwm = 0 , l3h_pwm = 0;
int L3V_sum = 0 , L3H_sum = 0;
volatile bool flag3vu=0 ,flag3vd=0, flag3h = 0,flag3_up=0,flag3_down=0;;
int ppos3v = 505;
int stall_base3v=15;
volatile int hall_count3v=0;

/*LEG 4*/
#define kp4h    2
#define kph4    1.3
#define kp4v    2.5
#define ki4h    0.0006
#define kih4    0.0007
#define ki4v    0.007  
#define ang_kp4v  2

#define thrs4h   10
#define thrs4v  5

int L4V_downmid=455, L4V_down = 369;
int L4H_val , L4H_front = 708 ,L4H_diff=225,L4H_back = L4H_front-L4H_diff ,L4H_initial =L4H_front;
int L4H_err = 0 , base4h = 0,L4H_mid=(L4H_back+L4H_front)/2, L4H_midf=L4H_front+(L4H_back-L4H_front)/3, L4H_midb=L4H_front-2*L4H_diff/3;
int val4h = L4H_mid ;
int L4V_diff_sand = 190,L4V_diff_sand_mid=110;
int L4V_diff = 60;
int L4V_val ,  L4V_up = L4V_down+L4V_diff,L4V_up_sand= L4V_down+L4V_diff_sand,L4V_sand_mid= L4V_down+L4V_diff_sand_mid;
int L4V_err = 450, val4v = L4V_up , base4v = 0,ang_base4v=40;
int L4V_upmid=L4V_downmid+60;
int L4H_mid4=L4H_front-L4H_diff/4;  
int l4v_pwm = 0 , l4h_pwm = 0;
int L4V_sum = 0 , L4H_sum = 0;
volatile bool flag4vu = 0 ,flag4vd=0, flag4h = 0,flag4_down=0,flag4_up=0;
int ppos4v = 680;
int stall_base4v=10;
volatile int hall_count4v=0;

//other flags
bool turnAngleFlag = 0;
bool turn_flag = 0;
bool sanddune_flag=0;
bool left_flag=0 , right_flag=0;
bool tussock_flag=0,tussock_flag1=0;
bool retry_flag=1;

//ultra variables
//#define ultra_trig_pin 20
//#define ultra_echo_pin 21

long duration=0,dist=0;

/*
110 - left turn 45 initial
170 - Sanddune initial
210 - left turn 60 initial
310 - right turn 0 initial
350 - Turning till Tussock
357 - For Tussock Walking

1000 - all down
1001 - all up  
1002 - all back
1003 - all front
1004 - get DMP angle
1005 - ultra
1007 - all mid
1008 - all downmid
1009 - diagonal walk horizontal intial
1010 - up mid
*Three legs walk--state 15 to 27    
*Left_Turn45---state 111 to 131
*New_LS_sanddune.h--state 171 to 183
*Left_Turn60---state 211 to 231
*Right turn---state 311 to 331
*tussock1----state
/*slope-------state401 to 413
*diagonal full rack : 31 - 36
*diagonal half rack : 40 -46
 */
///////variables description//////////////
/*counter=for normal walking 26
 * countThres=for no.of steps in straight walking 
 * sanddune_counter=for no. of steps on sanddune
 * turnAngleFlag=used to call angle function only once in turning loop 
 * sanddune_flag=used to change constrain and height when switched to sanddune mode
 * turn_flag=used to check -45 degree for sanddune and switch between the states : 26,81 to enter sanddune mode
 */

 /*direction of motors*/
/*
  * L1V - up:1(-) 
  * L2V - up:0(+)
  * L3V - up:1(-)
  * L4V - up:0(+)
  * 
  * horizontal : 
  * L1Hback= +
    L2Hback= +
    L3Hback= -
    L4Hback= -
*/


/*
left flag= 1 and 3 back-----185
right flag= 1 and 3 front---191
*/


///if mpu_mode==0 : yaw
//      mpu_mode==1 : pitch
//Current flow state41-46(Normal) -> state132-137(Left 45)

 

int counter=0, countThres=12,turnCount=0,turnCountright=0,sanddune_counter=0;
int sanddune_counter1=0,sanddune_counter2=0,tussock_counter=0;
int slope_counter=0,ukhai_counter=0;

//********************for now interrupts of halls are detached**********************//
 
 
//int state   =  350;
int state = 30;
//int state = ;

/*gyro variables*/
String  data = "";
float  angle = 0,angle_thrs_left=-45;
char c;
int thrsh_pu_gyro=5, thrsh_pd_gyro=-5;

int slope_constrain=150;
