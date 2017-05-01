% Dushyant Kumar Mishra

clear all; close all; clc;

%% Parameters
a = 0.5;
a_m = min(0,a);
a_p = max(0,a);
dx = 0.01;
cfl = 0.9;
dt = cfl*dx/abs(a);
t_end = 0.6;

%% Discretization of Domain
x = 1:dx:2;
t = 0:dt:t_end;

%% Initial Condition
n = length(x);
%u_0 = zeros(1,n);
u0(1:ceil(n/2)) = 1;
u0((ceil(n/2)+1):n) = 2;

%% Main Loop
% Initilize vector variables
u_next = zeros(size(u0)); 
u_bar1 = zeros(size(u0)); 
u_bar2 = zeros(size(u0)); 

% Load Initial condition
u = u0;

% Main Loop
for k = t
    % plot every time step
    plot(x,u,'.')
    
    for j = 2:n-1    
        % Single Sided Upwind
        
        
        % Double Sided Upwind
        u_next(j) = u(j) - a_p*dt/dx*(u(j)-u(j-1)) - a_m*dt/dx*(u(j+1)-u(j));
        
        % Comparing to Lax-Wendroff:
        
    end
    % BC
    u_next(1) = u_next(2);      
    u_next(n) = u_next(n-1);    
    
    % UPDATE info
    u = u_next(1:n);
    
    % update figure
    pause(0.05); drawnow
end
    
%% Plot final Result
plot(x,u,'.')


