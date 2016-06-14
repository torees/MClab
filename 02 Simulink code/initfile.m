%% Init file for master thesis
clc
clear

%% Controls for the system
tc = [1;2;0.5];           % Control thrust into thrust allocation
r = 0;                  % Chooses if real vessel or model parameters are used r = 1 Real , r = 0 Model
Thruster_lock = 1;      % if 0 --> Thrusters locked to predescribed angles, if 1 --> Azimuth thrusters
Thruster_control = 1;   % Chooses Controller: 1 = Speed , 2 = Torque , 3 = Power , 4 = Power & torque
Thrust_algorithm = 1;   % Chooses which algorithm is used 1 = Quadratic solver , 0 = Pseudoinverse solver
%% Parameters
lambda = 90;        % Scaling parameter
Kt = 0.445;         % Thrust coefficient [-]
Kq = 0.266;         %  Torque coefficient [-]
Kt0 = 0.445;        % Nominal Thrust coefficent [-] --> Ktc
Kq0 = 0.266;        % Nominal Torque coefficient [-]--> Kqc
Ktr = 0.445;        % Reverse Thrust coefficient
Kqr = 0.266;        % Reverse Torque coefficient
k = 1.2;            % Coefficient for max Torque/power [-]
eps = 1E-5;         % Constant for avoiding singularities

%% Actual vessel parameters
if r == 1
Rho_r = 1025;                                % Water density sea  [Kg/m^3]
D = 3.7;                                     % Propeller diameter [m]
n_max = 170;                                 % Maximum propeller speed [RPM]
T_max = (Kt0*Rho_r*D^4*n_max^2*k);           % Max produced thrust [N]
Q_max = (Kq0*Rho_r*D^5*n_max^2*k);           % Max torque  [Nm]
P_max = (6000000*k);                         % Max power [W]
I_s = 25000;                                 % Moment of inertia [Kg*m^2]
Rho = Rho_r;
Max_rotation = 2;                       % Max rotation of thrusters [1/s]
Max_thrust = 0.89*lambda^4;             % maximum force for each thruster
Max_Acceleration = 5;                   % Max propeller accelleration [1/s^2]
Thruster.T1 = [ 96.1   0      180.1 2];  % [m,m,Deg,Deg/s] 
Thruster.T2 = [ 84.1  9.9   145 2];    % [m,m,Deg,Deg/s]
Thruster.T3 = [ 84.1 -9.9   215 2];    % [m,m,Deg,Deg/s]
Thruster.T4 = [-104.8  0      0   2];    % [m,m,Deg,Deg/s]
Thruster.T5 = [-89.2  -14.9    35  2];    % [m,m,Deg,Deg/s]
Thruster.T6 = [-89.2  14.9   305  2];    % [m,m,Deg,Deg/s]

% Thruster control
eps_c = 3;        % Constant for switching between positive and negative thrust
n_c = 1;          % Switching width between K_tc and K_tcr
omega_r0 = 0.90;  % Natural frequency [1/s] Initial: 0.75 VIRKER
zeta_r = 0.98;     % Damping ratio [-]       Initial: 0.9 0.36 VIRKER
H1 = tf(omega_r0^2,[1 2*zeta_r*omega_r0 omega_r0^2]);
hd = c2d(H1,0.01,'foh');

% Transfer function for Engine
H2 = tf(1,[0.2 1]);
hd2 = c2d(H2,0.01,'zoh');

Kp = 150000;         % Core controller gain [-]
nd_slew = 0.5*90; % Max RPS rate [1/s^2]
K_omega = 90000;    % Linear friction coefficient [-] 0.3
epsilon = 0.3;    % Constant for friction component
Q_f0 = 200;       % Friction constant

% Core thruster parameters for combined torque and power
k_cc = 1;
p_cc = 0.5;
r_cc = 2;
%% Model vessel parameters
elseif r == 0
Rho_m = 1000;                           % Water density tank [Kg/m^3]
D = 3.0/100;                             % Propeller diameter model vessel  [m] 
n_max = (lambda/sqrt(lambda))*170/1.4;  % Maximum propeller speed model [RPM] 
Q_max = (Kq0*Rho_m*D^5*n_max^2*k);      % Max torque [Nm]                     
T_max = (Kt0*Rho_m*D^4*n_max^2*k);      % Max produced thrust [N]
P_max = 2*pi*n_max*Q_max;               % Max power[W]
I_s = 25000 /747225;                    % Moment of inertia [kg*m^2]
Rho = Rho_m;
Max_rotation = 5*sqrt(lambda);          % Max rotation of thrusters [1/s]
Max_thrust = 0.12;                      % maximum force for each thruster
Max_Acceleration = 5;                   % Max propeller accelleration [1/s^2]
Thruster.T1 = [ 96.1/90  0         0   2];    %[m,m,Deg,Deg/s]
Thruster.T2 = [ 84.1/90  9.9/90    0  2];    %[m,m,Deg,Deg/s] 45
Thruster.T3 = [ 84.1/90 -9.9/90    0 2];    %[m,m,Deg,Deg/s] -45
Thruster.T4 = [-104.8/90 0         0 2];    %[m,m,Deg,Deg/s] 179.5
Thruster.T5 = [-89.2/90 -14.9/90   0 2];    %[m,m,Deg,Deg/s] 135
Thruster.T6 = [-89.2/90  14.9/90   0 2];    %[m,m,Deg,Deg/s] -135

% Thruster control
eps_c = 3;        % Constant for switching between positive and negative thrust
n_c = 5;          % Switching width between K_tc and K_tcr
omega_r0 = 0.90;  % Natural frequency [1/s] Initial: 0.75 VIRKER
zeta_r = .78;     % Damping ratio [-]       Initial: 0.9 0.36 VIRKER
H1 = tf(omega_r0^2,[1 2*zeta_r*omega_r0 omega_r0^2]);
hd = c2d(H1,0.01,'foh');

% Transfer function for Engine
H2 = tf(1,[0.02 1]);
hd2 = c2d(H2,0.01,'zoh');

Kp = 3.3;         % Core controller gain [-]
nd_slew = 0.5*90; % Max RPS rate [1/s^2]
K_omega = 0.3;    % Linear friction coefficient [-] 0.3
epsilon = 0.5;    % Constant for friction component
Q_f0 = 0.3;       % Friction constant

% Core thruster parameters for combined torque and power
k_cc = 1;
p_cc = 0.5;
r_cc = 2;
end


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


%% Curves for shaft speed, volt and thrust
load('ForceToPWM.mat')
thrust_to_pwm_coeff = coeffvalues(ForceToPWM);
load('PWMToForce.mat')
pwm_to_thrust_coeff = coeffvalues(PWMToForce);
load('ShaftToPWM.mat')
shaft_to_pwm_coeff = coeffvalues(ShaftToPWM);
load('PWMToShaft.mat')
pwm_to_shaft_coeff = coeffvalues(PWMToShaft);
load('VoltToPWM.mat')
volt_to_pwm_coeff = coeffvalues(VoltToPWM);
load('PWMToVolt.mat')
pwm_to_volt_coeff = coeffvalues(PWMToVolt);

%% Denne kjører og tar tiden på simuleringen
% tic
% sim Thrustcontrol.slx
% toc



