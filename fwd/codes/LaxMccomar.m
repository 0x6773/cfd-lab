% Dushyant

clc; clear all; close all;      
L = 1;				
T = 0.2;			
a = 2.5;			
alpha = 0.005;			
Uo = 1.0;                       

%% Analytical Solution
xa = 0:0.001:L;                 
xo = 0.2;			

Ua = 1-0.5*(1+erf((xa-xo-a*T)/(2*sqrt(alpha*T))))'; 

%% Initialization 

dx = 0.015;                     
dt = (0.05*dx^2)/alpha;        
d = alpha*dt/dx^2;              
c = a*dt/dx;                    
Rec = a*dx/alpha;               
x = [0:dx:L]';                  
t = [0:dt:T];                   
numT = length(t);               
numX = length(x);               


U = zeros(numX,numT);           

U(1,:) = Uo;                    
U(numX,:) = 0;                  

for i=1:numX                    
    if x(i)<0.2
       U(i,1) = 1.0;            
    end
    if x(i)==0.2
        U(i,1) = 0.5;           
    end
    if x(i)>0.2
        U(i,1) = 0.0;           
    end
end



Uvftcs=U;
for j=2:numT
    for i=2:numX-1
        Uvftcs(i,j) = Uvftcs(i,j-1) - (c/2)*( Uvftcs(i+1,j-1) - Uvftcs(i-1,j-1) ) + d*( Uvftcs(i+1,j-1) - 2*Uvftcs(i,j-1) + Uvftcs(i-1,j-1) );
    end
end



Uvuf=U;
for j=2:numT
    for i=2:numX-1
        Uvuf(i,j) = Uvuf(i,j-1) - c*( Uvuf(i,j-1) - Uvuf(i-1,j-1) ) + d*( Uvuf(i+1,j-1) - 2*Uvuf(i,j-1) + Uvuf(i-1,j-1) );
    end
end



Uftcs=U;
for j=2:numT
    for i=2:numX-1
        Uftcs(i,j) = Uftcs(i,j-1) - (c/2)*( Uftcs(i+1,j-1) - Uftcs(i-1,j-1) ) + d*( Uftcs(i+1,j-1) - 2*Uftcs(i,j-1) + Uftcs(i-1,j-1) );
    end
end

Uuf=U;
for j=2:numT
    for i=2:numX-1
        Uuf(i,j) = Uuf(i,j-1) - c*( Uuf(i,j-1) - Uuf(i-1,j-1) ) + d*( Uuf(i+1,j-1) - 2*Uuf(i,j-1) + Uuf(i-1,j-1) );
    end
end

%% Finite Difference - Lax-Wendroff Convection 

Ulwf=U;
for j=2:numT
    for i=2:numX-1
        Ulwf(i,j) = Ulwf(i,j-1) - (c/2)*( Ulwf(i+1,j-1) - Ulwf(i-1,j-1) ) + (c^2/2)*( Ulwf(i+1,j-1) - 2*Ulwf(i,j-1) + Ulwf(i-1,j-1) ) + d*( Ulwf(i+1,j-1) - 2*Ulwf(i,j-1) + Ulwf(i-1,j-1) );
    end
end

%% Finite Difference - MacCormack Convection / FTCS Diffusion

Umf=U;
Umfs=Umf;
for j=1:numT-1
    for i=2:numX-1
        Umfs(i,j) = Umf(i,j) - c*( Umf(i+1,j) - Umf(i,j) ) + d*( Umf(i+1,j) - 2*Umf(i,j) + Umf(i-1,j) );
    end
    for i=2:numX-1
        Umf(i,j+1) = 0.5*( Umf(i,j) + Umfs(i,j)  - c*( Umfs(i,j) - Umfs(i-1,j) )) + d*( Umfs(i+1,j) - 2*Umfs(i,j) + Umfs(i-1,j) );
    end
end


%% Plot Results
figure;
hold on
%plot(x,Uftcs(:,numT),'ro--');
%plot(x,Uuf(:,numT),'m+--');
plot(x,Ulwf(:,numT),'g*--');
plot(x,Umf(:,numT),'kx--');
plot(xa,Ua,'-');
ylabel('U (m/s)');
xlabel('X (m)');
legend('Lax-Wendroff/FTCS','MacCormack/FTCS','Exact');
title(['Analytical vs Finite Difference Schemes at T=',num2str(T),'s , \Deltax=',num2str(dx),'m , Rec=',num2str(Rec)])

