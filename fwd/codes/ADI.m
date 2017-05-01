% Dushyant
clc; clear all; close all;

%% Definitions

L = 0.01;			
h = 0.02;                       
To = 100;                       
dx = 0.0005;                    
dy = 0.0005;                    
x = [0:dx:L];                   
y = [0:dy:h];                   
T = zeros(length(x),length(y)); 

T(:,1) = To;                    
T(1,:) = 0;                     
T(:,end) = 0;                   

beta = dx/dy;                   
Pomega = 1.191;                 
Lomega = 1.29;                  
tol = 0.000001;                 


%% Analytical Solution

Ta = zeros(length(x),length(y));
tic;
for i=1:length(x);
    for j=1:length(y);
        SUM=0;
        temp=0;
        for n=1:10000;
            temp=((2*To)/(n*pi*(1-exp(-n*pi*h/L)))) * (1-cos(n*pi)) * (exp(-n*pi*y(j)/(2*L))-exp((-n*pi/L)*(h-((y(j))/2)))) * sin(n*pi*x(i)/(2*L));
            SUM=SUM+temp;
        end
        Ta(i,j)=SUM;
    end
end
Tatime=toc


%% Alternating Direction Iteration (ADI)

ADiff = 1;                      % Initial Value for ADI Difference, ADiff
ATold=T;                        % Create Numerical Matrix ATold
ATnew=T;                        % Create Numerical Matrix ATnew
AIter=1;                        % Start Iterations at O
Ares=ones(5,1);

tic;
while min(Ares)>tol

% First step
for j=2:length(y)-1;

    for i=1:length(x);
        if i==1
        ax(i)=0;
        dx(i)=1;
        bx(i)=0;
        cx(i)=0;
        
        elseif i==length(x);
        ax(i)=1;
        dx(i)=ax(i-1) - 3*bx(i-1);
        bx(i)=dx(i-1) + 4*bx(i-1);
        cx(i)=cx(i-1);
        
        else
        ax(i)=1;
        dx(i)=-2*(1+beta^2);
        bx(i)=1;
        cx(i)=(-beta^2)*(ATold(i,j+1)+ATnew(i,j-1));
        end
        
    end
    Xx=diag(dx)+diag(ax(1:end-1),1)+diag(bx(2:end),-1);
    yx=cx';
    ATnew(:,j)=Xx\yx;
end 

% Second step
for i=2:length(x)-1;

    for j=1:length(y);
        if j==1
        ay(j)=0;
        dy(j)=1;
        by(j)=0;
        cy(j)=To;
        
        elseif j==length(y);
        ay(j)=0;
        dy(j)=1;
        by(j)=0;
        cy(j)=0;
        
        else
        ay(j)=beta^2;
        dy(j)=-2*(1+beta^2);
        by(j)=beta^2;
        cy(j)=-ATnew(i+1,j)-ATnew(i-1,j);
        end
    end
    
    Xy=diag(dy)+diag(ay(1:end-1),1)+diag(by(2:end),-1);
    yy=cy';
    ATnew(i,:)=Xy\yy;
end 
    Ares(AIter,1)=norm(ATnew(:)-ATold(:))/norm(ATnew(:));
    ADiff=max(ATnew(:)-Ta(:));      % Will break loop if tolerance is met
    ATold=ATnew;                    % Otherwise continue
    AIter=AIter+1;                  % Increment AIter
end

ADItime=toc


