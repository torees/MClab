clear
angle = -200;
angle_d = 0;



if isempty(angle)
    angle = 0;
end


angle_tmp = 0;

tmp = mod(abs(angle),360)*sign(angle);

if tmp >= 0
    if tmp <= 180
        tmp_out = tmp;
    else 
        tmp_out = -360 + tmp;
    end
else
    if tmp >= -180
        tmp_out = tmp;
    else 
        tmp_out = 360 + tmp;
    end
end

% if sign(angle_d) == sign(tmp_out)
%     halfplane = 1;
% elseif sign(angle_d) ~= sign(tmp_out)
%     halfplane = 0;
% end
    
if (sign(tmp_out) == -1 || sign(tmp_out) == 0) && tmp_out <= angle_d 
    if sign(angle_d) == sign(tmp_out)
        up = abs(tmp_out) + angle_d;
        down = 360 - abs(tmp_out) - angle_d;
        if abs(up) >= abs(down)
            angle_tmp = angle - abs(down);
        else
            angle_tmp = angle + abs(up);
        end
    else
        up = abs(tmp_out) + angle_d;
        down = abs(tmp_out) - angle_d;
        if abs(up) >= abs(down)
            angle_tmp = angle - abs(down);
        else
            angle_tmp = angle + abs(up);
        end
    end
end

if sign(tmp_out) == -1  && tmp_out > angle_d 
    if sign(angle_d) == sign(tmp_out)
        up = 360 + abs(tmp_out) - abs(angle_d);
        down = abs(tmp_out) - abs(angle_d);
        if abs(up) >= abs(down)
            angle_tmp = angle - abs(down);
        else
            angle_tmp = angle + abs(up);
        end
    else
        up = abs(tmp_out) + angle_d;
        down = 360-abs(tmp_out) - angle_d;
        if abs(up) >= abs(down)
            angle_tmp = angle - abs(down);
        else
            angle_tmp = angle + abs(up);
        end
    end
end

if (sign(tmp_out) == 1 || sign(tmp_out) == 0) && tmp_out >= angle_d 
    if sign(angle_d) == sign(tmp_out)
        up = 360 - abs(tmp_out) + abs(angle_d);
        down = - abs(tmp_out) + abs(angle_d);
        if abs(up) >= abs(down)
            angle_tmp = angle - abs(down);
        else
            angle_tmp = angle + abs(up);
        end
    else
        up = 360 - abs(tmp_out) - abs(angle_d);
        down = abs(tmp_out) + abs(angle_d);
        if abs(up) >= abs(down)
            angle_tmp = angle - abs(down);
        else
            angle_tmp = angle + abs(up);
        end
    end
end

if sign(tmp_out) == 1 && tmp_out < angle_d
    if sign(angle_d) == sign(tmp_out)
        up = - abs(tmp_out) + abs(angle_d);
        down = abs(tmp_out) + 360 - abs(angle_d);
        if abs(up) > abs(down)
            angle_tmp = angle - abs(down);
        else
            angle_tmp = angle + abs(up);
        end
    else
        up = 360 - abs(tmp_out) - abs(angle_d);
        down = abs(tmp_out) + abs(angle_d);
        if abs(up) >= abs(down)
            angle_tmp = angle - abs(down);
        else
            angle_tmp = angle + abs(up);
        end
    end
end
    
angle_out = angle_tmp;
    
