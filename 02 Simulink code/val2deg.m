function posdeg = val2deg(positionData)

puls = 32768; 
degpp = 23002/puls; %Degrees pr. pulse.
% positionData = uint32(positionData); %Convert from double to uint32

%Convertion to signed data:
counterNBits = 15; %Bits in the encoder reading
signedThreshold = 2^(counterNBits-1); %Treshold for convertion to signed pos. values
signedData = positionData;
signedData(signedData > signedThreshold) = signedData(signedData > signedThreshold) - 2^counterNBits;

posdeg = signedData*degpp;

end