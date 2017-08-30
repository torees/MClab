
%% Init file for master thesis
clear all, close all, clc

%% ctrl_sixaxis

% Threshold to avoid joystick angle noise at small inclinations
u_threshold = 0.2;



%% Controls for the system
% Thruster_lock = 1;      % if 0 --> Thrusters locked to predescribed angles, if 1 --> Azimuth thrusters
% Thruster_control = 4;   % Chooses Controller: 1 = Speed , 2 = Torque , 3 = Power , 4 = Power & torque



%% Parameters



% Thrust coefficients
K_T1f = 0.3763;
K_T2f = 0.3901;
K_T3f = 0.3776;
K_T4f = 0.5641;
K_T5f = 0.4799;
K_T6f = 0.5588;
K_T1r = K_T1f;
K_T2r = K_T2f;
K_T3r = K_T3f;
K_T4r = K_T4f;
K_T5r = K_T5f;
K_T6r = K_T6f;

% Torque coefficients
K_q1f = 0.0113;
K_q2f = 0.0117;
K_q3f = 0.0113;
K_q4f = 0.0169;
K_q5f = 0.0144;
K_q6f = 0.0168;
K_q1r = K_q1f;
K_q2r = K_q2f;
K_q3r = K_q3f;
K_q4r = K_q4f;
K_q5r = K_q5f;
K_q6r = K_q6f;
eps = 1E-5;         % Constant for avoiding singularities

%% Model vessel parameters
lambda = 90;        % Scaling parameter
Rho_m = 1000;                           % Water density tank [Kg/m^3]
D = 3.0/100;                             % Propeller diameter model vessel  [m]                    
T_max = 1.5034;      % Max produced thrust [N]
I_s = 25000 /747225;                    % Moment of inertia [kg*m^2]
Rho = Rho_m;
Max_rotation = 12*sqrt(lambda);          % Max rotation of thrusters [1/s]
Max_thrust = 1.5;                      % maximum force for each thruster
Min_thrust = -0.8;
Max_Acceleration = 5;                   % Max propeller accelleration [1/s^2]
Thruster.T1 = [ 96.1/90  0         180   2];    %[m,m,Deg,Deg/s]
Thruster.T2 = [ 84.1/90  9.9/90    -135  2];    %[m,m,Deg,Deg/s] 45
Thruster.T3 = [ 84.1/90 -9.9/90    90 2];    %[m,m,Deg,Deg/s] -45
Thruster.T4 = [-104.8/90 0         0 2];    %[m,m,Deg,Deg/s] 179.5
Thruster.T5 = [-89.2/90 -14.9/90   45 2];    %[m,m,Deg,Deg/s] 135
Thruster.T6 = [-89.2/90  14.9/90   -90 2];    %[m,m,Deg,Deg/s] -135

% Thruster control
eps_c = 5;        % Constant for switching between positive and negative thrust
n_c = 5;          % Switching width between K_tc and K_tcr
omega_r0 = 0.90;  % Natural frequency [1/s] Initial: 0.75 VIRKER
zeta_r = .78;     % Damping ratio [-]       Initial: 0.9 0.36 VIRKER
H1 = tf(omega_r0^2,[1 2*zeta_r*omega_r0 omega_r0^2]);
hd = c2d(H1,0.01,'foh');

% Transfer function for Engine
H2 = tf(1,[0.02 1]);
hd2 = c2d(H2,0.01,'zoh');

Kp = 3.3;         % Core controller gain [-]
nd_slew = 2*90; % Max RPS rate [1/s^2]
K_omega = 0.3;    % Linear friction coefficient [-] 0.3
epsilon = 0.5;    % Constant for friction component
Q_f0 = 0.3;       % Friction constant

% Core thruster parameters for combined torque and power
k_cc = 1;
p_cc = 0.5;
r_cc = 4;

% constraints on thrusters:
%ABS GUIDE Table
x = [ 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15];
v = [ 30 26.3 22.8 20.6 19 17.8 16.8 16 15.3 14.7 14.2 13.8 13.3 13 12.6];

% Thruster 1 ok
x13 = sqrt((Thruster.T1(1)-Thruster.T3(1))^2+(Thruster.T1(2)-Thruster.T3(2))^2);
Ratio13 = x13/D;
C13 = interp1(x,v,Ratio13);
C13 = round(C13,1);
x12 = sqrt((Thruster.T1(1)-Thruster.T2(1))^2+(Thruster.T1(2)-Thruster.T2(2))^2);
Ratio12 = x12/D;
C12 = interp1(x,v,Ratio12);
C12 = round(C12,1);
C1 = [atan2d((Thruster.T1(2)-Thruster.T3(2)),(Thruster.T1(1)-Thruster.T3(1)))+C13/2 atan2d((Thruster.T1(2)-Thruster.T3(2)),(Thruster.T1(1)-Thruster.T3(1)))-C13/2 ...
      atan2d((Thruster.T1(2)-Thruster.T2(2)),(Thruster.T1(1)-Thruster.T2(1)))-C12/2 atan2d((Thruster.T1(2)-Thruster.T2(2)),(Thruster.T1(1)-Thruster.T2(1)))+C12/2];
C1 = round(C1,1);  


% Thruster 2 ok
x21 = sqrt((Thruster.T2(1)-Thruster.T1(1))^2+(Thruster.T2(2)-Thruster.T1(2))^2);
Ratio21 = x21/D;
C21 = interp1(x,v,Ratio21);
C21 = round(C21,1);
x23 = sqrt((Thruster.T2(1)-Thruster.T3(1))^2+(Thruster.T2(2)-Thruster.T3(2))^2);
Ratio23 = x23/D;
C23 = interp1(x,v,Ratio23);
C23 = round(C23,1);
C2 = [ atan2d((Thruster.T2(2)-Thruster.T3(2)),(Thruster.T2(1)-Thruster.T3(1)))+C23/2 atan2d((Thruster.T2(2)-Thruster.T3(2)),(Thruster.T2(1)-Thruster.T3(1)))-C23/2 ...
    atan2d((Thruster.T2(2)-Thruster.T1(2)),(Thruster.T2(1)-Thruster.T1(1)))+C21/2 atan2d((Thruster.T2(2)-Thruster.T1(2)),(Thruster.T2(1)-Thruster.T1(1)))-C21/2]; 
C2 = round(C2,1);

% Thruster 3 ok
x31 = sqrt((Thruster.T3(1)-Thruster.T1(1))^2+(Thruster.T3(2)-Thruster.T1(2))^2);
Ratio31 = x31/D;
C31 = interp1(x,v,Ratio31);
C31 = round(C31,1);
x32 = sqrt((Thruster.T3(1)-Thruster.T2(1))^2+(Thruster.T3(2)-Thruster.T2(2))^2);
Ratio32 = x32/D;
C32 = interp1(x,v,Ratio32);
C32 = round(C32,1);
C3 = [atan2d((Thruster.T3(2)-Thruster.T2(2)),(Thruster.T3(1)-Thruster.T2(1)))-C32/2 atan2d((Thruster.T3(2)-Thruster.T2(2)),(Thruster.T3(1)-Thruster.T2(1)))+C32/2 ...
    atan2d((Thruster.T3(2)-Thruster.T1(2)),(Thruster.T3(1)-Thruster.T1(1)))-C31/2 atan2d((Thruster.T3(2)-Thruster.T1(2)),(Thruster.T3(1)-Thruster.T1(1)))+C31/2];
 C3 = round(C3,1);


% Thruster 4 ok
x45 = sqrt((Thruster.T4(1)-Thruster.T5(1))^2+(Thruster.T4(2)-Thruster.T5(2))^2);
Ratio45 = x45/D;
C45 = interp1(x,v,Ratio45);
C45 = round(C45,1);
x46 = sqrt((Thruster.T4(1)-Thruster.T6(1))^2+(Thruster.T4(2)-Thruster.T6(2))^2);
Ratio46 = x46/D;
C46 = interp1(x,v,Ratio46);
C46 = round(C46,1);
C4 = [atan2d((Thruster.T4(2)-Thruster.T6(2)),(Thruster.T4(1)-Thruster.T6(1)))-C46/2 atan2d((Thruster.T4(2)-Thruster.T6(2)),(Thruster.T4(1)-Thruster.T6(1)))+C46/2 ... 
    atan2d((Thruster.T4(2)-Thruster.T5(2)),(Thruster.T4(1)-Thruster.T5(1)))+C45/2 atan2d((Thruster.T4(2)-Thruster.T5(2)),(Thruster.T4(1)-Thruster.T5(1)))-C45/2];
C4 = round(C4,1);

% Thruster 5
x54 = sqrt((Thruster.T5(1)-Thruster.T4(1))^2+(Thruster.T5(2)-Thruster.T4(2))^2);
Ratio54 = x54/D;
C54 = interp1(x,v,Ratio54);
C54 = round(C54,1);
x56 = sqrt((Thruster.T5(1)-Thruster.T6(1))^2+(Thruster.T5(2)-Thruster.T6(2))^2);
Ratio56 = x56/D;
C56 = interp1(x,v,Ratio56);
C56 = round(C56,1);
C5 = [atan2d((Thruster.T5(2)-Thruster.T6(2)),(Thruster.T5(1)-Thruster.T6(1)))-C56/2 atan2d((Thruster.T5(2)-Thruster.T6(2)),(Thruster.T5(1)-Thruster.T6(1)))+C56/2 ...
    atan2d((Thruster.T5(2)-Thruster.T4(2)),(Thruster.T5(1)-Thruster.T4(1)))-C54/2 atan2d((Thruster.T5(2)-Thruster.T4(2)),(Thruster.T5(1)-Thruster.T4(1)))+C54/2];
C5 = round(C5,1);

% Thruster 6
x64 = sqrt((Thruster.T6(1)-Thruster.T4(1))^2+(Thruster.T6(2)-Thruster.T4(2))^2);
Ratio64 = x64/D;
C64 = interp1(x,v,Ratio64);
C64 = round(C64,1);
x65 = sqrt((Thruster.T6(1)-Thruster.T5(1))^2+(Thruster.T6(2)-Thruster.T5(2))^2);
Ratio65 = x65/D;
C65 = interp1(x,v,Ratio65);
C65 = round(C65,1);
C6 = [atan2d((Thruster.T6(2)-Thruster.T5(2)),(Thruster.T6(1)-Thruster.T5(1)))+C65/2 atan2d((Thruster.T6(2)-Thruster.T5(2)),(Thruster.T6(1)-Thruster.T5(1)))-C65/2 ...
      atan2d((Thruster.T6(2)-Thruster.T4(2)),(Thruster.T6(1)-Thruster.T4(1)))+C64/2 atan2d((Thruster.T6(2)-Thruster.T4(2)),(Thruster.T6(1)-Thruster.T4(1)))-C64/2];
C6 = round(C6,1);

C = [C1;C2;C3;C4;C5;C6]; % All constraints for Thruster-Thruster Interaction


%% Curves for mapping commanded force to commanded PWM signal

load('signal mapping\force_to_pwm_thr1_forward')
pwm_thr1_forward = coeffvalues(ForceToPWM);

load('signal mapping\force_to_pwm_thr2_forward')
pwm_thr2_forward = coeffvalues(ForceToPWM);

load('signal mapping\force_to_pwm_thr3_forward')
pwm_thr3_forward = coeffvalues(ForceToPWM);

load('signal mapping\force_to_pwm_thr4_forward')
pwm_thr4_forward = coeffvalues(ForceToPWM);

load('signal mapping\force_to_pwm_thr5_forward')
pwm_thr5_forward = coeffvalues(ForceToPWM);

load('signal mapping\force_to_pwm_thr6_forward')
pwm_thr6_forward = coeffvalues(ForceToPWM);

load('signal mapping\force_to_pwm_thr1_backward')
pwm_thr1_backward = coeffvalues(ForceToPWM);

load('signal mapping\force_to_pwm_thr2_backward')
pwm_thr2_backward = coeffvalues(ForceToPWM);

load('signal mapping\force_to_pwm_thr3_backward')
pwm_thr3_backward = coeffvalues(ForceToPWM);

load('signal mapping\force_to_pwm_thr4_backward')
pwm_thr4_backward = coeffvalues(ForceToPWM);

load('signal mapping\force_to_pwm_thr5_backward')
pwm_thr5_backward = coeffvalues(ForceToPWM);

load('signal mapping\force_to_pwm_thr6_backward')
pwm_thr6_backward = coeffvalues(ForceToPWM);

n_max = 152;

%% u2pwm

% Thruster steering rate
% According to Preben Frederich, Constrained Optimal Thrust Allocation for
% C/S Inocean Cat I Drillship, 2016 master thesis, Sec 2.1
% Fullscale 2 rpm
alpha_max_rate = 0.012;                            % deg/s
ctrl_frequency = 100;                           % Hz
alpha_max_step = alpha_max_rate/ctrl_frequency; % deg/step

% Thruster - motor
min_pwm     = 5;
max_pwm     = 10;
u2pwm_gain  = (max_pwm-min_pwm)/2;
zero_pwm    = min_pwm + u2pwm_gain;

% Thruster - servo
zero_alpha_1  = -90; 
zero_alpha_2  = -40; 
zero_alpha_3  = 5; 
zero_alpha_4  = -17;
zero_alpha_5  = 127;
zero_alpha_6  = -36;


%% ctrl_custom

Lx1 =  1.0678;   Ly1 =  0.0;
Lx2 =  0.9344;   Ly2 =  0.11;
Lx3 =  0.9344;   Ly3 = -0.11;
Lx4 = -1.1644;   Ly4 =  0.0;
Lx5 = -0.9911;   Ly5 = -0.1644;
Lx6 = -0.9911;   Ly6 =  0.1644;

% Thrust coefficients
K_T = [0.3763; 0.3901; 0.3776; 0.5641; 0.4799; 0.5588];
% Torque coefficients
K_q = [0.0113; 0.0117; 0.0113; 0.0169; 0.0144; 0.0168];

% Sec. 12.3.1
% tau = T_e * K_e * u_e
T_e = [eye(2)   eye(2)   eye(2)   eye(2)   eye(2)   eye(2)
       -Ly1 Lx1 -Ly2 Lx2 -Ly3 Lx3 -Ly4 Lx4 -Ly5 Lx5 -Ly6 Lx6] 
K_e = diag([K_T(1) K_T(1) K_T(2) K_T(2) K_T(3) K_T(3) K_T(4) K_T(4) K_T(5) K_T(5) K_T(6) K_T(6)])

T      = T_e*K_e;
T_pinv = T'*inv(T*T');



