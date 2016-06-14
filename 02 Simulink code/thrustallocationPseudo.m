function [sys,ThrusterPos,str,ts] = thrustallocationPseudo(t,x,u,flag,Thruster) 
% Function for finding the optimal path to desired angle
% Work in progress  
% Author: Preben Frederich
% 12/12-2015

% Version 1.0 : Pseudo inverse optimalization created
%               12/12-2015 Preben Frederich
% Version 1.1 : Desired angle implemented
%               02/03-2016 Preben Frederich
% Version 1.2 : Individual & coupled constrained thrust allocation implemented
%               07/04-2016 Preben Frederih

switch flag,

  % Initialization
  case 0,
    [sys,ThrusterPos,str,ts]=mdlInitializeSizes(Thruster);

  % Output
  case 3,
    sys=mdlOutputs(t,x,u,Thruster);

  % Update  
  case 2,
    sys=mdlUpdate(t,x,u,Thruster); 
    
      case {1,4,}
    sys=[];

  % Case 9 not yet implemented. Used for terminate signal if errors where
  % to occure.
  case 9,
      sys=mdlTerminate(t,x,u,Thruster);

  % Unexpected flags
  otherwise
    error(['Unhandled flag = ',num2str(flag)]);

end

function [sys,x0,str,ts]=mdlInitializeSizes(Thruster)
% Only used when starting the system


sizes = simsizes;  

sizes.NumContStates  = 0;   % Number of continuous states in the system, 
sizes.NumDiscStates  = 12;  % Number of discrete states in the system 
sizes.NumOutputs     = 12;  % Number of outputs (Output of each angle of each thruster and desired thrust of each thruster)
sizes.NumInputs      = 10;  % Number of inputs2 (Input: Desired angle and Desired thrust vector)
sizes.DirFeedthrough = 0;   % No element which is sent directly through the system
sizes.NumSampleTimes = 1;  
sys = simsizes(sizes); 


%% Determines initial angles on thrusters + initial thrust. (FORSØK SITT INITIAL ANGLE INN SOM EGEN VARIABLE)
x0 = [Thruster.T1(3) Thruster.T2(3) Thruster.T3(3) Thruster.T4(3) Thruster.T5(3) Thruster.T6(3)  0 0 0 0 0 0]';

str = [];  

ts  = [-1 0];


function sys=mdlUpdate(t,x,u,Thruster)
% Complete system goes here!

ThrusterPosX = [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1) Thruster.T4(1) Thruster.T5(1) Thruster.T6(1)];%[x(1),x(2),x(3),x(4),x(5),x(6)]';
ThrusterPosY = [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2) Thruster.T4(2) Thruster.T5(2) Thruster.T6(2)];%[x(7),x(8),x(9),x(10),x(11),x(12)]';
% Parameters thrusters
tc =  [u(1),u(2),u(3)]'; 
alpha = [u(4),u(5),u(6),u(7),u(8),u(9)]';
%alpha0 = [x(1),x(2),x(3),x(4),x(5),x(6)]';

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

B = [T_surge,T_sway,T_yaw]';
[U_singular,S_singular,V_singular] = svd(B,'econ');
S_singular_cross = 1./S_singular;
S_singular_cross(~isfinite(S_singular_cross))=0;
 if (S_singular_cross(3,3)>2*S_singular_cross(2,2)) 
     S_singular_cross(3,3)=0;
 end
%   if (S_singular_cross(2,2)<1*S_singular_cross(1,1)) 
%      S_singular_cross(2,2)=0;
%   end
%    if (S_singular_cross(1,1)>10*S_singular_cross(2,2)) 
%      S_singular_cross(1,1)=0;
%    end
%  disp(S_singular_cross)
T_optimized = V_singular*S_singular_cross*U_singular';
%K = eye(n_t);%diag([ 5 5 5 5 5 5]);
T_d = T_optimized*tc+(tc(1)+tc(2)+tc(3))*epsilon;           % Optimized Thrust

% if alpha(1) < 90 && alpha(1) > 70
%     T_d(1) = 0;
% else
%     T_d(1);
% end
% 
% T_dirx = zeros(1,n_t);
% T_diry = zeros(1,n_t);
% for i = 1:1:n_t
% T_dirx(i) = [T_d(i)'*cosd(alpha(i))];%+cosd(alpha(i))*ThrusterPosY(i)];
% T_diry(i) = [T_d(i)'*sind(alpha(i))];%+sind(alpha(i))*ThrusterPosX(i)];
% end
% 
% Alpha_surge =[T_d(1)*cosd(alpha(1)) T_d(2)*cosd(alpha(2)) T_d(3)*cosd(alpha(3)) T_d(4)*cosd(alpha(4)) T_d(5)*cosd(alpha(5)) T_d(6)*cosd(alpha(6))];  
% Alpha_sway = [T_d(1)*sind(alpha(1)) T_d(2)*sind(alpha(2)) T_d(3)*sind(alpha(3)) T_d(4)*sind(alpha(4)) T_d(5)*sind(alpha(5)) T_d(6)*sind(alpha(6))];
% 
% 
% T_dir = [Alpha_surge' ; Alpha_sway'];
% T1 = [T_dir(1),T_dir(7),atan2d(T_dir(7),T_dir(1))];
% T2 = [T_dir(2),T_dir(8),atan2d(T_dir(8),T_dir(2))];
% T3 = [T_dir(3),T_dir(9),atan2d(T_dir(9),T_dir(3))];
% T4 = [T_dir(4),T_dir(10),atan2d(T_dir(10),T_dir(4))];
% T5 = [T_dir(5),T_dir(11),atan2d(T_dir(11),T_dir(5))];
% T6 = [T_dir(6),T_dir(12),atan2d(T_dir(12),T_dir(6))];
% 
% 
% %% Finding Desired angle for optimal thrust
% 
% % Without yaw motion
% if tc(3) == 0  
%  if tc(1) >= 0 && tc(2) >= 0
%   alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180;   
%  elseif tc(1) < 0 && tc(2) >= 0
%      alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180;
%  elseif tc(1) < 0 && tc(2) < 0
%      alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180;
%  elseif tc(1) >= 0 && tc(2) < 0
%      alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180;
%  end
% end
%  % With positive yaw motion
%  if tc(3) < 0 
%      if  tc(2) == 0 && tc(1) == 0
%         alpha1 = [90 90 90 -90 -90 -90]';
%      elseif tc(2) >= 0 && tc(1) >= 0 
%         alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180;
%         alpha1 = [90 alpha1(2) alpha1(3) -90 alpha1(5) alpha1(6)]'+180;
%      elseif tc(2) >= 0 && tc(1) < 0
%         alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180;
%         alpha1 = [90 alpha1(2) alpha1(3) -90 alpha1(5) alpha1(6)]';
%      elseif tc(1) < 0 && tc(2) < 0
%         alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180;
%         alpha1 = [90 alpha1(2) alpha1(3) -90 alpha1(5) alpha1(6)]';
%      elseif tc(1) >= 0 && tc(2) < 0
%         alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180;
%         alpha1 = [90 alpha1(2) alpha1(3) -90 alpha1(5) alpha1(6)]';
%      end
%  end
%  
%  % With negative yaw motion
%   if tc(3) > 0 
%      if  tc(2) == 0 && tc(1) == 0
%         alpha1 = [-90 -90 -90 90 90 90]';
%      elseif tc(2) >= 0 && tc(1) >= 0 
%         alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180;
%         alpha1 = [-90 alpha1(2) alpha1(3) 90 alpha1(5) alpha1(6)]';
%      elseif tc(2) >= 0 && tc(1) < 0
%         alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180;
%         alpha1 = [-90 alpha1(2) alpha1(3) 90 alpha1(5) alpha1(6)]';
%      elseif tc(1) < 0 && tc(2) < 0
%         alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180;
%         alpha1 = [-90 alpha1(2) alpha1(3) 90 alpha1(5) alpha1(6)]';
%      elseif tc(1) >= 0 && tc(2) < 0
%         alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180;
%         alpha1 = [-90 alpha1(2) alpha1(3) 90 alpha1(5) alpha1(6)]';
%      end
%   end
% for i=1:1:n_t
%   if alpha1(i) > 180
%       alpha1(i) = alpha1(i) - 360;
%   elseif alpha1(i) < -180
%       alpha1(i) = alpha1(i) + 360;
%   else
%       alpha1(i);
%   end
% end
% 
% B = [T_surge,T_sway,T_yaw]';
% B = B*diag(K); 
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

%% Constraints
% Thruster 1 OK
C1 = [151 130 -151 -130 ];
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
C2 = [-99.85 -80.15 -50 -29];
if alpha1(2) > C2(1)  && alpha1(2) < C2(2) && T_d(2) > 0 || alpha1(2) > C2(1)  && alpha1(2) < C2(2) && T_d(2) < 0
    c2 = [C2(1) C2(2)];
    [C_2,alpha_new2] = min(abs(c2-alpha1(2)));
    Alpha1(2) = c2(alpha_new2);
elseif alpha1(2) > C2(3) && alpha1(2) < C2(4) && T_d(2) > 0 || alpha1(2) > C2(3) && alpha1(2) < C2(4) && T_d(2) < 0 
    c2 = [C2(3) C2(4)];
    [C_2,alpha_new2] = min(abs(c2-alpha1(2)));
    Alpha1(2) = c2(alpha_new2);
else 
    Alpha1(2) = alpha1(2);
end
if alpha(2) > C2(1)+0.1  && alpha(2) < C2(2)-0.1 || alpha(2) > C2(3)+0.1 && alpha(2) < C2(4)-0.1
    T_d(2) = 0;
else 
    T_d(2) = T_d(2);
end

% Thruster 3 
C3 = [99.85 80.15 50 29]; 
if alpha1(3) < C3(1)  && alpha1(3) > C3(2) && T_d(3) > 0 || alpha1(3) < C3(1)  && alpha1(3) > C3(2) && T_d(3) < 0 
    c3 = [C3(1) C3(2)];
    [C_3,alpha_new3] = min(abs(c3-alpha1(3)));
    Alpha1(3) = c3(alpha_new3);
elseif alpha1(3) < C3(3) && alpha1(3) > C3(4) && T_d(3) > 0 || alpha1(3) < C3(3) && alpha1(3) > C3(4) && T_d(3) < 0
    c3 = [C3(3) C3(4)];
    [C_3,alpha_new3] = min(abs(c3-alpha1(3)));
    Alpha1(3) = c3(alpha_new3);
else 
    Alpha1(3) = alpha1(3);
end
if alpha(3) < C3(1)-0.1  && alpha(3) > C3(2)+0.1 || alpha(3) < C3(3)-0.1 && alpha(3) > C3(4)+0.1
    T_d(3) = 0;
else 
    T_d(3) = T_d(3);
end

% Thruster 4 OK
C4 = [-52.8 -34.2 52.8 34.2]; 
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
C5 = [-98.25 -81.75 -145.8 -127.2];
if alpha1(5) > C5(1)  && alpha1(5) < C5(2) && T_d(5) > 0 || alpha1(5) > C5(1)  && alpha1(5) < C5(2) && T_d(5) < 0
    c5 = [C5(1) C5(2)];
    [C_5,alpha_new5] = min(abs(c5-alpha1(5)));
    Alpha1(5) = c5(alpha_new5);
elseif alpha1(5) > C5(3) && alpha1(5) < C5(4) && T_d(5) > 0 || alpha1(5) > C5(3) && alpha1(5) < C5(4) && T_d(5) < 0
    c5 = [C5(3) C5(4)];
    [C_5,alpha_new5] = min(abs(c5-alpha1(5)));
    Alpha1(5) = c5(alpha_new5);
else 
    Alpha1(5) = alpha1(5);
end
if alpha(5) > C5(1)+0.1  && alpha(5) < C5(2)-0.1 || alpha(5) > C5(3)+0.1 && alpha(5) < C5(4)-0.1
    T_d(5) = 0;
else 
    T_d(5) = T_d(5);
end

% Thruster 6
C6 = [98.75 81.75 145.8 127.2];
if alpha1(6) < C6(1)  && alpha1(6) > C6(2) && T_d(6) > 0 || alpha1(6) < C6(1)  && alpha1(6) > C6(2) && T_d(6) < 0
    c6 = [C6(1) C6(2)];
    [C_6,alpha_new6] = min(abs(c6-alpha1(6)));
    Alpha1(6) = c6(alpha_new6);
elseif alpha1(6) < C6(3) && alpha1(6) > C6(4) && T_d(6) > 0  || alpha1(6) < C6(3) && alpha1(6) > C6(4) && T_d(6) < 0
    c6 = [C6(3) C6(4)];
    [C_6,alpha_new6] = min(abs(c6-alpha1(6)));
    Alpha1(6) = c6(alpha_new6);
else 
    Alpha1(6) = alpha1(6);
end
if alpha(6) < C6(1)-0.1  && alpha(6) > C6(2)+0.1 || alpha(6) < C6(3)-0.1 && alpha(6) > C6(4)+0.1
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
alpha_desired = Alpha1;

% T_d = -Desired_thrust;
%% Update outputs
sys = [alpha_desired',T_d'];

function sys=mdlOutputs(t,x,u,Thruster)
% Giving the desired angle output [7 8 9 10 11 12][ 1 2 3 4 5 6] together with desired
% thrust [7 8 9 10 11 12]
sys=[x(1),x(2),x(3),x(4),x(5),x(6),x(7),x(8),x(9),x(10),x(11),x(12)];

function sys=mdlTerminate(t,x,u,Thruster) 
% Not yet implemented
sys = [];