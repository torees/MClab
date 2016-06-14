function [sys,ThrusterPos,str,ts] = thrustallocationQuadraticFixed(t,x,u,flag) 
% Function for finding optimal thrust and angle
% Work in progress  
% Author: Preben Frederich
% 12/12-2015

% Version 1.0 : Pseudo inverse optimalization created
%               12/12-2015 Preben Frederich
% Version 1.1 : Desired angle implemented
%               02/03-2016 Preben Frederich
% Version 1.2 : Individual & coupled constrained thrust allocation implemented
%               07/04-2016 Preben Frederih
% Version 1.3 : Quadratic control allocation implemented with optimal
%               angles found by pseudoinverse allocation
%               15/04-2016 Preben Frederich
% Version 1.4 : Quadratic control allocation modified to optimize around
%               the different thrusters when they are in forbidden zones
%               20/04-2016 Preben Frederich
% Version 1.5 : Implemented constraints at forbidden zones varying depending 
%               on length between each thruster. Retrived from Initfile as [C].
%               22/04-2016 Preben Frederich
% Version 1.6 : Implemented possibilities for using real model values for
%               the quadratic regulator
%               25/04-2016 Preben Frederich


switch flag,

  % Initialization
  case 0,
    [sys,ThrusterPos,str,ts]=mdlInitializeSizes();

  % Output
  case 3,
    sys=mdlOutputs(t,x,u);

  % Update  
  case 2,
    sys=mdlUpdate(t,x,u); 
    
      case {1,4,}
    sys=[];

  % Case 9 not yet implemented. Used for terminate signal if errors where
  % to occure.
  case 9,
      sys=mdlTerminate(t,x,u);

  % Unexpected flags
  otherwise
    error(['Unhandled flag = ',num2str(flag)]);

end

function [sys,x0,str,ts]=mdlInitializeSizes(Thruster)
% Only used when starting the system

% Maps out the different states
sizes = simsizes;  

sizes.NumContStates  = 0;   % Number of continuous states in the system, 
sizes.NumDiscStates  = 12;  % Number of discrete states in the system 
sizes.NumOutputs     = 12;  % Number of outputs (Output of each angle of each thruster and desired thrust of each thruster)
sizes.NumInputs      = 16;  % Number of inputs2 (Input: Desired angle and Desired thrust vector)
sizes.DirFeedthrough = 0;   % No element which is sent directly through the system
sizes.NumSampleTimes = 1;  
sys = simsizes(sizes); 


%% Determines initial angles on thrusters + initial thrust. (FORSØK SITT INITIAL ANGLE INN SOM EGEN VARIABLE)
x0 = [0 0 0 0 0 0 0 0 0 0 0 0];%[Thruster.T1(3) Thruster.T2(3) Thruster.T3(3) Thruster.T4(3) Thruster.T5(3) Thruster.T6(3)  0 0 0 0 0 0 ]';

str = [];  

ts  = [-1 0];


function sys=mdlUpdate(t,x,u)
% Complete system goes here!

D = 3.7/90;

Thruster.T1 = [ 96.1/90  0         0   2];    %[m,m,Deg,Deg/s]
Thruster.T2 = [ 84.1/90  9.9/90    90  2];    %[m,m,Deg,Deg/s] 45
Thruster.T3 = [ 84.1/90 -9.9/90    -90 2];    %[m,m,Deg,Deg/s] -45
Thruster.T4 = [-104.8/90 0         180 2];    %[m,m,Deg,Deg/s] 179.5
Thruster.T5 = [-89.2/90 -14.9/90   -135 2];    %[m,m,Deg,Deg/s] 135
Thruster.T6 = [-89.2/90  14.9/90   135 2];    %[m,m,Deg,Deg/s] -135

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
C4 = [ atan2d((Thruster.T5(2)-Thruster.T4(2)),(Thruster.T5(1)-Thruster.T4(1)))-C45/2 atan2d((Thruster.T5(2)-Thruster.T4(2)),(Thruster.T5(1)-Thruster.T4(1)))+C45/2 ...
    atan2d((Thruster.T6(2)-Thruster.T4(2)),(Thruster.T6(1)-Thruster.T4(1)))+C46/2 atan2d((Thruster.T6(2)-Thruster.T4(2)),(Thruster.T6(1)-Thruster.T4(1)))-C46/2];
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

r = 0;

ThrusterPosX = [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1) Thruster.T4(1) Thruster.T5(1) Thruster.T6(1)];%[x(1),x(2),x(3),x(4),x(5),x(6)]';
ThrusterPosY = [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2) Thruster.T4(2) Thruster.T5(2) Thruster.T6(2)];%[x(7),x(8),x(9),x(10),x(11),x(12)]';
% Parameters thrusters
tc =  [u(1),u(2),u(3)]'; 
alpha = [u(4),u(5),u(6),u(7),u(8),u(9)]';
%alpha0 = [x(1),x(2),x(3),x(4),x(5),x(6)]';
% tprev = u(17);
% Td_prev = [u(11) u(12) u(13) u(14) u(15) u(16)];
epsilon = u(10);


n_t = length(ThrusterPosX); % number of thrusters
T_surge = zeros(n_t,1); % Shells for faster computing
T_sway = zeros(n_t,1);  % Shells for faster computing
T_yaw = zeros(n_t,1);   % Shells for faster computing

for i = 1:1:n_t
  T_surge(i) = cosd(alpha(i));     %Thrust in x-direction for cartesian
  T_sway(i) = sind(alpha(i));      %Thrust in y-direction for cartesian
  T_yaw(i) = (sind(alpha(i))*ThrusterPosX(i) - cosd(alpha(i))*ThrusterPosY(i));
end

% Constraints for Thruster-Thruster interaction. Can be seen in "Initfile"
% how they are found
C1 = C(1,:);
C2 = C(2,:);
C3 = C(3,:);
C4 = C(4,:);
C5 = C(5,:);
C6 = C(6,:);

K = ones(1,6);

if alpha(1) < C1(1)-0.1  && alpha(1) > C1(2)+0.1 || alpha(1) > C1(3)+0.1 && alpha(1) < C1(4)-0.1
    K(1) = 0;
else 
    K(1) = K(1);
end

if alpha(2) > C2(1)-0.1  && alpha(2) < C2(2)+0.1 || alpha(2) > C2(3)-0.1 && alpha(2) < C2(4)+0.1
    K(2) = 0;
else 
    K(2) = K(2);
end

if alpha(3) < C3(1)+0.1  && alpha(3) > C3(2)-0.1 || alpha(3) < C3(3)+0.1 && alpha(3) > C3(4)-0.1
    K(3) = 0;
else 
    K(3) = K(3);
end

if alpha(4) > C4(1)+0.1  && alpha(4) < C4(2)-0.1 || alpha(4) < C4(3)-0.1 && alpha(4) > C4(4)+0.1
    K(4) = 0;
else 
    K(4) = K(4);
end

if alpha(5) < C5(1)-0.1  && alpha(5) > C5(2)+0.1 || alpha(5) < C5(3)-0.1 && alpha(5) > C5(4)+0.1
    K(5) = 0;
else 
    K(5) = K(5);
end

if alpha(6) > C6(1)+0.1  && alpha(6) < C6(2)-0.1 || alpha(6) > C6(3)+0.1 && alpha(6) < C6(4)-0.1
    K(6) = 0;
else 
    K(6) = K(6);
end


B = [T_surge,T_sway,T_yaw]';
B = B*diag(K); 
Te = [1 0 1 0 1 0 1 0 1 0 1 0;
      0 1 0 1 0 1 0 1 0 1 0 1;
      ThrusterPosY(1) ThrusterPosX(1) ThrusterPosY(2) ThrusterPosX(2) ThrusterPosY(3) ThrusterPosX(3) ...
      ThrusterPosY(4) ThrusterPosX(4) ThrusterPosY(5) ThrusterPosX(5) ThrusterPosY(6) ThrusterPosX(6)];
[U_singular,S_singular,V_singular] = svd(Te,'econ');
S_singular_cross = 1./S_singular;
S_singular_cross(~isfinite(S_singular_cross))=0;
 if (S_singular_cross(3,3)>2*S_singular_cross(2,2)) 
     S_singular_cross(3,3)=0;
 end
T0 = V_singular*S_singular_cross*U_singular'*tc;
alpha1 = [atan2d(T0(2),T0(1)) atan2d(T0(4),T0(3)) atan2d(T0(6),T0(5)) atan2d(T0(8),T0(7)) atan2d(T0(10),T0(9)) atan2d(T0(12),T0(11))];

% Må kanskje ha denne for alpha in også
for i=1:1:n_t
  if alpha1(i) > 180
      alpha1(i) = alpha1(i) - 360;
  elseif alpha1(i) < -180
      alpha1(i) = alpha1(i) + 360;
  else
      alpha1(i);
  end
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% NOT IMPLEMENTED YET                                                     %
% Want to try to see if it can be used                                    %
% Cost function based upon error between desired angle and actual angle   %
% Angle_error = abs(alpha)-abs(alpha1');                                  %
% CostW = (abs(Angle_error)+1)/100;                                       %
% if CostW >= 1                                                           %
%     CostW = 1;                                                          %
% end                                                                     %
% K = eye(n_t);%diag([ 5 5 5 5 5 5]);                                     %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

W = eye(6);
q = sum(W);
Q = 1000*diag([((q(1)+q(4))/2) ((q(2)+q(5))/2) ((q(3)+q(6))/2)])*10;
zero2H = zeros(6,3);
%zero3  = zeros(3,6);
H = [W zero2H; zero2H' Q];
f = zeros(9,1);
Aeq = [B -eye(3)];%; zeros(12,15)];
Beq = tc; %[diag(tc) zeros(3,2)];
if r == 0
ub = [0.89 0.89 0.89 0.89 0.89 0.89 0.01 0.01 0.01]*1.1';
elseif r == 1
ub = [10000 10000 10000 10000 10000 10000 10 10 10]';
end
lb = -ub;
X0 = [u(11),u(12),u(13),u(14),u(15),u(16)]';
options = optimoptions('quadprog',...
    'Algorithm','interior-point-convex','Display','off');
X = quadprog(H,f,[],[],Aeq,Beq,lb,ub,X0,options);
if numel(X) <= 6 
    X = [0 0 0 0 0 0 0 0 0];
end
% if sum(abs(X)) >= 10
%     X = [0 0 0 0 0 0 0 0 0];
% end

T_d = [X(1) X(2) X(3) X(4) X(5) X(6)];       % Optimized Thrust



  
%% Constraints
% Thruster 1 OK
%C1 = [151 130 -151 -130 ];
if alpha1(1) < C1(1)  && alpha1(1) > C1(2) && T_d(1) > 0 || alpha1(1) < C1(1)  && alpha1(1) > C1(2) && T_d(1) < 0
    c1 = [C1(1) C1(2)];
    [C_1,alpha_new1] = min(abs(c1-alpha1(1)));
    Alpha1(1) = c1(alpha_new1);
elseif alpha1(1) > C1(3) && alpha1(1) < C1(4) && T_d(1) > 0 || alpha1(1) > C1(3) && alpha1(1) < C1(4) && T_d(1) < 0
    c1 = [C1(3) C1(4)];
    [C_1,alpha_new1] = min(abs(c1-alpha1(1)));
    Alpha1(1) = c1(alpha_new1);
else 
    Alpha1(1) = alpha1(1);
end
if alpha(1) < C1(1)-0.1  && alpha(1) > C1(2)+0.1 || alpha(1) > C1(3)+0.1 && alpha(1) < C1(4)-0.1
    T_d(1) = 0;
else 
    T_d(1) = T_d(1);
end

% Thruster 2 
%C2 = [-99.85 -80.15 -50 -29];
if alpha1(2) < C2(1)  && alpha1(2) > C2(2) && T_d(2) > 0 || alpha1(2) < C2(1)  && alpha1(2) > C2(2) && T_d(2) < 0 
    c2 = [C2(1) C2(2)];
    [C_2,alpha_new2] = min(abs(c2-alpha1(2)));
    Alpha1(2) = c2(alpha_new2);
elseif alpha1(2) < C2(2) && alpha1(2) > C2(4) && T_d(2) > 0 || alpha1(2) < C2(2) && alpha1(2) > C2(4) && T_d(2) < 0
    c2 = [C2(2) C2(4)];
    [C_2,alpha_new2] = min(abs(c2-alpha1(2)));
    Alpha1(2) = c2(alpha_new2);
else 
    Alpha1(2) = alpha1(2);
end
if alpha(2) < C2(1)-0.1  && alpha(2) > C2(2)+0.1 || alpha(2) < C2(2)-0.1 && alpha(2) > C2(4)+0.1
    T_d(2) = 0;
else 
    T_d(2) = T_d(2);
end

% Thruster 3 
% C3 = [99.85 80.15 50 29]; 

if alpha1(3) > C3(1)  && alpha1(3) < C3(3) && T_d(3) > 0 || alpha1(3) > C3(1)  && alpha1(3) < C3(3) && T_d(3) < 0
    c3 = [C3(1) C3(3)];
    [C_3,alpha_new3] = min(abs(c3-alpha1(3)));
    Alpha1(3) = c3(alpha_new3);
elseif alpha1(3) > C3(3) && alpha1(3) < C3(4) && T_d(3) > 0 || alpha1(3) > C3(3) && alpha1(3) < C3(4) && T_d(3) < 0 
    c3 = [C3(3) C3(4)];
    [C_3,alpha_new3] = min(abs(c3-alpha1(3)));
    Alpha1(3) = c3(alpha_new3);
else 
    Alpha1(3) = alpha1(3);
end
if alpha(3) > C3(1)+0.1  && alpha(3) < C3(3)-0.1 || alpha(3) > C3(3)+0.1 && alpha(3) < C3(4)-0.1
    T_d(3) = 0;
else 
    T_d(3) = T_d(3);
end

% Thruster 4 OK
%C4 = [-52.8 -34.2 52.8 34.2]; 
if alpha1(4) > C4(1)  && alpha1(4) < C4(2) && T_d(4) > 0 || alpha1(4) > C4(1)  && alpha1(4) < C4(2) && T_d(4) < 0
    c4 = [C4(1) C4(2)];
    [C_4,alpha_new4] = min(abs(c4-alpha1(4)));
    Alpha1(4) = c4(alpha_new4);
elseif alpha1(4) < C4(3) && alpha1(4) > C4(4) && T_d(4) > 0 || alpha1(4) < C4(3) && alpha1(4) > C4(4) && T_d(4) < 0 
    c4 = [C4(3) C4(4)];
    [C_4,alpha_new4] = min(abs(c4-alpha1(4)));
    Alpha1(4) = c4(alpha_new4);
else 
    Alpha1(4) = alpha1(4);
end
if alpha(4) > C4(1)+0.1  && alpha(4) < C4(2)-0.1 || alpha(4) < C4(3)-0.1 && alpha(4) > C4(4)+0.1
    T_d(4) = 0;
else 
    T_d(4) = T_d(4);
end

% Thruster 5
%C5 = [-98.25 -81.75 -145.8 -127.2];
if alpha1(5) < C5(1)  && alpha1(5) > C5(2) && T_d(5) > 0 || alpha1(5) < C5(1)  && alpha1(5) > C5(2) && T_d(5) < 0
    c5 = [C5(1) C5(2)];
    [C_5,alpha_new5] = min(abs(c5-alpha1(5)));
    Alpha1(5) = c5(alpha_new5);
elseif alpha1(5) < C5(3) && alpha1(5) > C5(4) && T_d(5) > 0  || alpha1(5) < C5(3) && alpha1(5) > C5(4) && T_d(5) < 0
    c5 = [C5(3) C5(4)];
    [C_5,alpha_new5] = min(abs(c5-alpha1(5)));
    Alpha1(5) = c5(alpha_new5);
else 
    Alpha1(5) = alpha1(5);
end
if alpha(5) < C5(1)-0.1  && alpha(5) > C5(2)+0.1 || alpha(5) < C5(3)-0.1 && alpha(5) > C5(4)+0.1
    T_d(5) = 0;
else 
    T_d(5) = T_d(5);
end

% Thruster 6
%C6 = [98.75 81.75 145.8 127.2];
if alpha1(6) > C6(1)  && alpha1(6) < C6(2) && T_d(6) > 0 || alpha1(6) > C6(1)  && alpha1(6) < C6(2) && T_d(6) < 0
    c6 = [C6(1) C6(2)];
    [C_6,alpha_new6] = min(abs(c6-alpha1(6)));
    Alpha1(6) = c6(alpha_new6);
elseif alpha1(6) > C6(3) && alpha1(6) < C6(4) && T_d(6) > 0 || alpha1(6) > C6(3) && alpha1(6) < C6(4) && T_d(6) < 0
    c6 = [C6(3) C6(4)];
    [C_6,alpha_new6] = min(abs(c6-alpha1(6)));
    Alpha1(6) = c6(alpha_new6);
else 
    Alpha1(6) = alpha1(6);
end
if alpha(6) > C6(1)+0.1  && alpha(6) < C6(2)-0.1 || alpha(6) > C6(3)+0.1 && alpha(6) < C6(4)-0.1
    T_d(6) = 0;
else 
    T_d(6) = T_d(6);
end

% Thruster 2&3 
if Alpha1(2) == C2(2)
    Alpha1(3) = alpha1(2) - (C2(2) - alpha1(2));
elseif Alpha1(2) == C2(1)
    Alpha1(3) = alpha1(2) - (C2(1) - alpha1(2));
elseif Alpha1(2) == C2(3)
    Alpha1(3) = alpha1(2) - (C2(3) - alpha1(2));
elseif Alpha1(2) == C2(4)
    Alpha1(3) = alpha1(2) - (C2(4) - alpha1(2));
    
elseif Alpha1(3) == C3(2)
    Alpha1(2) = alpha1(3) - (C3(2) - alpha1(3));
elseif Alpha1(3) == C3(1)
    Alpha1(2) = alpha1(3) - (C3(1) - alpha1(3));
elseif Alpha1(3) == C3(3)
    Alpha1(2) = alpha1(3) - (C3(3) - alpha1(3));
elseif Alpha1(3) == C3(4)
    Alpha1(2) = alpha1(3) - (C3(4) - alpha1(3));
end

% Thruster 5&6
if Alpha1(5) == C5(2)
    Alpha1(6) = alpha1(5) - (C5(2) - alpha1(5));
elseif Alpha1(5) == C5(1)
    Alpha1(6) = alpha1(5) - (C5(1) - alpha1(5));
elseif Alpha1(5) == C5(3)
    Alpha1(6) = alpha1(5) - (C5(3) - alpha1(5));
elseif Alpha1(5) == C5(4)
    Alpha1(6) = alpha1(5) - (C5(4) - alpha1(5));
    
elseif Alpha1(6) == C6(2)
    Alpha1(5) = alpha1(6) - (C6(2) - alpha1(6));
elseif Alpha1(6) == C6(1)
    Alpha1(5) = alpha1(6) - (C6(1) - alpha1(6));
elseif Alpha1(6) == C6(3)
    Alpha1(5) = alpha1(6) - (C6(3) - alpha1(6));
elseif Alpha1(6) == C6(4)
    Alpha1(5) = alpha1(6) - (C6(4) - alpha1(6));
end
% Thruster 4 & 1
if     Alpha1(4) == C4(2)
    Alpha1(1) = alpha1(4) - (C4(2) - alpha1(4));
elseif Alpha1(4) == C4(1)
    Alpha1(1) = alpha1(4) - (C4(1) - alpha1(4));
elseif Alpha1(4) == C4(3)
    Alpha1(1) = alpha1(4) - (C4(3) - alpha1(4));
elseif Alpha1(4) == C4(4)
    Alpha1(1) = alpha1(4) - (C4(4) - alpha1(4));
end

if     Alpha1(1) == C1(2)
    Alpha1(4) = alpha1(1) - (C1(2) - alpha1(1));
elseif Alpha1(1) == C1(1)
    Alpha1(4) = alpha1(1) - (C1(1) - alpha1(1));
elseif Alpha1(1) == C1(3)
    Alpha1(4) = alpha1(1) - (C1(3) - alpha1(1));
elseif Alpha1(1) == C1(4)
    Alpha1(4) = alpha1(1) - (C1(4) - alpha1(1));
end

Alpha1 = [Alpha1(1) Alpha1(2) Alpha1(3) Alpha1(4) Alpha1(5) Alpha1(6)]';    
Desired_thrust = [T_d(1) T_d(2) T_d(3) T_d(4) T_d(5) T_d(6)]';
alpha_desired =  Alpha1;
T_d = Desired_thrust;
%% Update outputs
sys = [alpha_desired',T_d'];

function sys=mdlOutputs(t,x,u)
% Giving the desired angle output [7 8 9 10 11 12][ 1 2 3 4 5 6] together with desired
% thrust [7 8 9 10 11 12]
sys=[x(1),x(2),x(3),x(4),x(5),x(6),x(7),x(8),x(9),x(10),x(11),x(12)];

function sys=mdlTerminate(t,x,u) 
% Not yet implemented
sys = [];