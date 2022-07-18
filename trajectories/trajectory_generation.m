syms t

x = quinticpoly(0,10,0,5,0,0,0,0);
x = simplify(x);

y = quinticpoly(0,10,0,20,0,0,0,0);
y = simplify(y);

theta = atan(y / x);
theta = simplify(theta);

x_d = diff(x);
x_dd = diff(x_d);

y_d = diff(y);
y_dd = diff(y_d);

theta_d = diff(theta);
theta_dd = diff(theta_d);

time = 0:1:10;

x_desired = zeros(10,0);
y_desired = zeros(10,0);
theta_desired = zeros(10,0);
x_d_desired = zeros(10,0);
y_d_desired = zeros(10,0);
theta_d_desired = zeros(10,0);
x_dd_desired = zeros(10,0);
y_dd_desired = zeros(10,0);
theta_dd_desired = zeros(10,0);


for i = 1:1:11
    x_desired(i) = subs(x(t), t, time(i));
    y_desired(i) = subs(y(t), t, time(i));
    theta_desired(i) = subs(theta(t), t, time(i));
    
    x_d_desired(i) = subs(x_d(t), t, time(i));
    y_d_desired(i) = subs(y_d(t), t, time(i));
    theta_d_desired(i) = subs(theta_d(t), t, time(i));
    
    x_dd_desired(i) = subs(x_dd(t), t, time(i));
    y_dd_desired(i) = subs(y_dd(t), t, time(i));
    theta_dd_desired(i) = subs(theta_dd(t), t, time(i));
end

figure();
plot(x_desired)
figure();
plot(y_desired)
figure();
plot(theta_desired)

figure();
plot(x_d_desired)
figure();
plot(y_d_desired)
figure();
plot(theta_d_desired)

figure();
plot(x_dd_desired)
figure();
plot(y_dd_desired)
figure();
plot(theta_dd_desired)


function q = quinticpoly(t0,tf,q0,qf,qd0,qdf,qdd0,qddf)
    A1 = [1 t0 t0^2 t0^3 t0^4 t0^5;...
    0 1 2*t0 3*t0^2 4*t0^3 5*t0^4;...
    0 0 2 6*t0 12*t0^2 20*t0^3;...
    1 tf tf^2 tf^3 tf^4 tf^5;...
    0 1 2*tf 3*tf^2 4*tf^3 5*tf^4;...
    0 0 2 6*tf 12*tf^2 20*tf^3];
    b1 = [q0 qd0 qdd0 qf qdf qddf]';
    
    A = A1\b1;
    syms t;
    q(t) = A(1) + A(2) * t + A(3) * t^2 + A(4) * t^3 + A(5) * t^4 + A(6) * t^5;
end