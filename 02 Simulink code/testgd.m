
alpha_deg = [900.2,900.1,900,1620.5,1260.3,-1260];
alpha = alpha_deg*pi/180;

tc = [-1,0,0]';

Thruster.T1 = [ 96.1/90  0         ];    %[m,m]
Thruster.T2 = [ 89.2/90  9.9/90    ];    %[m,m]
Thruster.T3 = [ 89.2/90 -9.9/90    ];    %[m,m]
Thruster.T4 = [-104.8/90 0         ];    %[m,m] 
Thruster.T5 = [-89.2/90 -14.9/90   ];    %[m,m]
Thruster.T6 = [-89.2/90  14.9/90   ];    %[m,m]
ThrusterPosX = [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1) Thruster.T4(1) Thruster.T5(1) Thruster.T6(1)];%[x(1),x(2),x(3),x(4),x(5),x(6)]';
ThrusterPosY = [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2) Thruster.T4(2) Thruster.T5(2) Thruster.T6(2)];%[x(7),x(8),x(9),x(10),x(11),x(12)]';


n_t = length(ThrusterPosX);

T_surge = zeros(n_t,1); % Shells for faster computing
T_sway = zeros(n_t,1);  % Shells for faster computing
T_yaw = zeros(n_t,1);   % Shells for faster computing

for i = 1:1:n_t
  T_surge(i) = cos(alpha(i));     %Thrust in x-direction for cartesian
  T_sway(i) = sin(alpha(i));      %Thrust in y-direction for cartesian
  T_yaw(i) = (sin(alpha(i))*ThrusterPosX(i) - cos(alpha(i))*ThrusterPosY(i));
end

B = [T_surge,T_sway,T_yaw]'

[U_singular,S_singular,V_singular] = svd(B,'econ');
S_singular_cross = 1./S_singular;
S_singular_cross(~isfinite(S_singular_cross))=0;
 if (S_singular_cross(3,3)>2*S_singular_cross(2,2)) 
     S_singular_cross(3,3)=0;
 end
 
T_optimized = V_singular*S_singular_cross*U_singular';
T_d = T_optimized*tc; 


Te = [1 0 1 0 1 0 1 0 1 0 1 0;
      0 1 0 1 0 1 0 1 0 1 0 1;
      ThrusterPosY(1) ThrusterPosX(1) ThrusterPosY(2) ThrusterPosX(2) ThrusterPosY(3) ThrusterPosX(3) ...
      ThrusterPosY(4) ThrusterPosX(4) ThrusterPosY(5) ThrusterPosX(5) ThrusterPosY(6) ThrusterPosX(6)];
[U_ang,S_ang,V_ang] = svd(Te,'econ');
S_ang = 1./S_ang;
S_ang(~isfinite(S_ang))=0;
 if (S_ang(3,3)>2*S_ang(2,2)) 
     S_ang(3,3)=0;
 end
T0 = V_ang*S_ang*U_ang'*tc;
alpha1 = [atan2(T0(2),T0(1)) atan2(T0(4),T0(3)) atan2(T0(6),T0(5)) atan2(T0(8),T0(7)) atan2(T0(10),T0(9)) atan2(T0(12),T0(11))];

% for i=1:1:n_t
%   if alpha1(i) > 180
%       alpha1(i) = alpha1(i) - 360;
%   elseif alpha1(i) < -180
%       alpha1(i) = alpha1(i) + 360;
%   else
%       alpha1(i);
%   end
% end

u_out = T_d
alpha_out = alpha1'
